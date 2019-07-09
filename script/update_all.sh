
####################
# output image
IMG_OUT=$1

if [ "IMG_OUT" = "" ];then
	echo "Error: no output file name"
	exit 1
fi

CFG=pack.conf

# source OLD config if availabe
if [ -f $CFG ];then
	. $CFG
fi

#
# Platform Type
#
def_val=$pf_type
[ "$def_val" = "" ] && def_val=z
echo "* Select IC Type : (default type = z)"
echo "--------------------"
echo " [z] USE zebu simulate "
echo " [s] USE 8388 platform "
echo " -> "

pf_type=z
# read pf_type
# [ "$pf_type" = "" ] && pf_type=$def_val
echo "$pf_type"
echo "pf_type=$pf_type" >$CFG


echo "--------------"
echo "Configuration"
echo "--------------"
cat $CFG

####################
BOOTROM=bootRom.bin
XBOOT=xboot.img
#DRAMINIT=draminit.img
ROMCODE=rom.img
UBOOT=u-boot.img
echo "* Gen $IMG_OUT ..."
pwd
if [ "$pf_type" = "z" ];then
	dd if=./bootfile/bootRom.bin.zero     of=./bin/$IMG_OUT conv=notrunc
	dd if=./bootfile/zebu_xboot.img       of=bin/$IMG_OUT conv=notrunc bs=1k seek=64
	dd if=./bootfile/zebuboot.img	      of=bin/$IMG_OUT conv=notrunc bs=1k seek=128
	dd if=bin/$ROMCODE       	      of=bin/$IMG_OUT conv=notrunc bs=1k seek=1024
	source ./script/gen_hex.sh bin/$IMG_OUT bin/zebu.hex
	#rm -f bin/$IMG_OUT
	ls -lh bin/zebu.hex

elif [ "$pf_type" = "s" ];then
	dd if=./bootfile/$BOOTROM     of=./bin/$IMG_OUT conv=notrunc
	dd if=./bootfile/$XBOOT       of=./bin/$IMG_OUT conv=notrunc bs=1k seek=64
	dd if=./bootfile/$UBOOT				of=./bin/$IMG_OUT conv=notrunc bs=1k seek=128
	dd if=./bin/$ROMCODE       		of=./bin/$IMG_OUT conv=notrunc bs=1k seek=1024
	ls -lh bin/$IMG_OUT
fi







