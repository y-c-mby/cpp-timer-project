#include "test_t.h"
#include "test_ti.h"
#include "my_timer.h"
/*#include <thread>*/
#include <unistd.h>
/*#include <chrono>*/
void run_timer_1()
	{
		int i;
		msg_printer p("hello world");
		msg_printer* ptr=&p;
		Time t(1,30,0);
		Timer stop(t,ptr);
		for(i=0;i<50;i++)
		{
			std::cout<<i<<std::endl;
			stop.tick("Min",2);
			
		}

	}
void run_timer_2()
{
	int i;
	msg_printer p("seven seconds");
	msg_printer* ptr=&p;
	Time t(7);
	Timer stop(t,ptr);
	for(i=0;i<10;i++)
	{
		std::cout<<i<<std::endl;
		stop.tick();
		sleep(1);
	}
}
int main()
{

	create_time();
	checkplus();
	checkpluse();
	checkratio();
	checkchange();
	/*creat_timer();*/
	run_timer_1();
	run_timer_2();
	

	return 0;	
}
