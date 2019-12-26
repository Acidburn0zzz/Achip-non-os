
TOP=../../..

export PATH=$PATH:$TOP/nonos/Achip-non-os/isp/

cp ../../../boot/xboot/bin/xboot.img ./
cp ../../../boot/uboot/u-boot.img ./
mv ../bin/out.bin uImage

X=xboot.img
U=u-boot.img
K=uImage

# Partition name = file name
cp $X xboot0
cp $U uboot0
cp $X xboot1
cp $U uboot1
cp $U uboot2
cp $K kernel

NONOS_SIZE=0x2000000

isp pack_image ISPBOOOT.BIN \
	xboot0 uboot0 \
	xboot1 0x100000 \
	uboot1 $NONOS_SIZE \
	uboot2 $NONOS_SIZE \
	kernel $NONOS_SIZE \

rm -rf xboot0
rm -rf uboot0
rm -rf xboot1
rm -rf uboot1
rm -rf uboot2
rm -rf kernel


mkdir -p boot2linux_SDcard

dd if=/dev/zero of=ISPBOOOT_SD.BIN bs=1M count=$(($NONOS_SIZE/1024/1024))
dd if=xboot.img of=ISPBOOOT_SD.BIN conv=notrunc 
dd if=uImage of=ISPBOOOT_SD.BIN bs=1k seek=64 conv=notrunc    
mv ISPBOOOT_SD.BIN ./boot2linux_SDcard/ISPBOOOT.BIN

rm -rf $X
rm -rf $U
rm -rf $K


