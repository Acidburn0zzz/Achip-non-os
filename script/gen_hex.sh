BIN=$1
HEX=$2

if [ "$BIN" = "" -o "$HEX" = "" ];then
	echo "$0: bad args"
	exit 1
fi

if [ "$pf_type" = "z" ];then
perl -pe 'BEGIN{$\="\n";$/=\1};$_=unpack("H*",$_)' $BIN > $HEX
fi