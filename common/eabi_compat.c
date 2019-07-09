#include <common.h>

int raise (int signum)
{
	prn_string("raise: Signal #");
	prn_decimal(signum);
	return 0;
}
