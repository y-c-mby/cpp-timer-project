#include "test_t.h"
#include "test_ti.h"
#include "my_timer.h"
/*#include <thread>*/
#include <unistd.h>
#include "test_msg.h"
#include <list>
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
void run_timer_3()
{
	msg_printer ** arr=new msg_printer*[3];
	int i;
	msg_printer *s=new msg_printer("this is a message");
	arr[0]=s;
	MsgPrinterSurrounding* mps=new MsgPrinterSurrounding("surrounded","--start--","--End--");
	arr[1]=mps;
	msgPrinterMultipleSurrounding* mpms=new msgPrinterMultipleSurrounding("really surrounded",">>>>>>>>","<<<<<<<<<" ,3);
	arr[2]=mpms;
	Timer t1(10,arr[0]);
	Timer t2(15,arr[1]);
	Timer t3(20,arr[1]);
	Timer t4(25,arr[2]);
	Timer t5(30,arr[2]);
	for(i=0;i<40;i++)
	{
		std::cout<<i<<std::endl;
		t1.tick();
		t2.tick();
		t3.tick();
		t4.tick();
		t5.tick();
	}

}
void run_timer_4()
{
	msg_printer ** arr=new msg_printer*[3];
	msg_printer *s=new msg_printer("this is a message");
	arr[0]=s;
	MsgPrinterSurrounding* mps=new MsgPrinterSurrounding("surrounded","--start--","--End--");
	arr[1]=mps;
	msgPrinterMultipleSurrounding* mpms=new msgPrinterMultipleSurrounding("really surrounded",">>>>>>>>","<<<<<<<<<" ,3);
	arr[2]=mpms;
	std::list<Timer> timers_list;
	
	timers_list.push_back(Timer (10,arr[0]));
	timers_list.push_back(Timer (15,arr[1]));
	timers_list.push_back(Timer (20,arr[1]));
	timers_list.push_back(Timer (25,arr[2]));
	timers_list.push_back(Timer (30,arr[2]));
	int i=0;
	for (;i<80;i++)
	{
		for(std::list<Timer>::iterator it=timers_list.begin();it!=timers_list.end();it++)
		{
			it->tick();
		}
		std::cout<<i<<std::endl;
	}
}
int main()
{

	create_time();
	checkplus();
	checkpluse();
	checkratio();
	checkchange();
	creat_timer();
	run_timer_3();
	run_timer_4();
	create_messages();
	check_asiment();
	run_timer_1();
	run_timer_2();
	

	return 0;	
}
