'''********************************************************
 * Copyright (c) 2017 by Sunplus Technology Co., Ltd.
 *    ____               __
 *   / __/_ _____  ___  / /_ _____
 *  _\ \/ // / _ \/ _ \/ / // (_-<
 * /___/\_,_/_//_/ .__/_/\_,_/___/
 *              /_/
 * Sunplus Technology Co. 19, Innovation First Road,
 * Science-Based Industrial Park, Hsin-Chu, Taiwan, R.O.C.
 * ------------------------------------------------------
 *
 * Description : ELF file to hex for zebu memory fill
 * ------------------------------------------------------
 * Rev  Date          Author(s)      Status & Comments
 * ======================================================
 * 0.1  2017/09/27    nz.lu          initial version
'''
import sys, re
from struct import pack, unpack
from subprocess import Popen, PIPE
# parse target example
# Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
# LOAD           0x008000 0x00200000 0x00200000 0x0f8c9 0x0fc00 RWE 0x8000
# LOAD           0x01a000 0x00232000 0x00232000 0x00244 0x01384 RW  0x8000

program_header_regexp = re.compile(
								r"\bLOAD\s+"
								r"(?P<offset>0x[0-9a-f]+)\s+"
								r"(?P<virtaddr>0x[0-9a-f]+)\s+"
								r"(?P<physaddr>0x[0-9a-f]+)\s+"
								r"(?P<filesiz>0x[0-9a-f]+)\s+"
								r"(?P<memsiz>0x[0-9a-f]+)\s+"
								r"[RWE]+\s+"
								r"(?P<align>0x[0-9a-f]+)")

if __name__ == '__main__':
	# get args
	input_elf, output_hex, tool_chain_prefix = sys.argv[1:]

	# parse section info from elf
	cmd = [tool_chain_prefix+"readelf", "-l", input_elf]
	proc = Popen(cmd, stdout=PIPE)
	program_header, err = proc.communicate()

	section_list = list()
	index = 0
	for section_info in program_header_regexp.finditer(program_header):
		dc = section_info.groupdict()
		if int(dc['filesiz'], 16) == 0:
			continue
		print "Section[%d]"%index
		print "\t", "\n\t".join("%-8s : %-8s"%(key, value) for key, value in dc.iteritems())
		index += 1
		section_list.append(dc)

	# gen zmem.hex file
	with open(input_elf, 'r') as fp:
		result = str()
		output_result_list = list()
		for index in range(len(section_list)):
			offset   = int(section_list[index]['offset'], 16)
			filesiz  = int(section_list[index]['filesiz'], 16)
			physaddr = int(section_list[index]['physaddr'], 16) / 16
			fp.seek(offset)
			prog_buf = fp.read(filesiz)

			if filesiz & 0xF != 0:
				padding_cnt = 16 - (filesiz & 0xF)
				# padding zero to fit 16 byte alignment
				prog_buf += pack('B'*padding_cnt, *([0]*padding_cnt))


			data_list_8B = [unpack('<Q', prog_buf[x:x+8])[0] for x in xrange(0, len(prog_buf), 8)]
			data_list = [(data_list_8B[x+1] << 64) + data_list_8B[x] for x in xrange(0, len(data_list_8B), 2)]

			addr_list = range(physaddr, physaddr + len(prog_buf)/16)
			data_pair = zip( addr_list, data_list)
			output_str_buf = '\n'.join("@{0:x} {1:032x}".format(addr, data) for addr, data in data_pair)
			output_result_list.append(output_str_buf)
		result = '\n'.join(x for x in output_result_list)

	with open(output_hex, 'w') as fp:
		fp.write(result)

