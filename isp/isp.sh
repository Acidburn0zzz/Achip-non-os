
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


isp pack_image ISPBOOOT.BIN \
	xboot0 uboot0 \
	xboot1 0x100000 \
	uboot1 0x100000 \
	uboot2 0x100000 \
	kernel 0xf00000 \

rm -rf xboot0
rm -rf uboot0
rm -rf xboot1
rm -rf uboot1
rm -rf uboot2
rm -rf kernel
rm -rf $X
rm -rf $U
rm -rf $K

