#include "my_timer.h"
#include "test_ti.h"
void creat_timer()
{
	Time y(56,30,12);
	msg_printer r("rgerger");
	msg_printer *p=&r;
	Timer t(y,p);
}
