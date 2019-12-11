#include "my_time.h"
#include "test_t.h"
void create_time()
{
	int ans;
	try
	{
		
		Time t(24,30,12);
		std::cout<<t.get_as_str(TRUE)<<std::endl;
		print(t);
		ans=t.get_seconds();
		std::cout<<ans<<std::endl;
	}
	catch(std::invalid_argument& error)
	{
		std::cout<<error.what()<<std::endl;
	}
}
void checkplus()
{
	try
	{
		
		Time t(24,30,12);
		print(t);
		Time t1(23,10,10);
		print(t1);
		Time t2(0,0,0);
		t2=t+t1;
		print(t2);
	}
	catch(std::invalid_argument& error)
	{
		std::cout<<error.what()<<std::endl;
	}
	
}
void checkpluse()
{
	try
	{
		
		Time t(24,30,12);
		print(t);
		Time t2(0,50,30);
		t2+=t;
		t2+=5;
		print(t2);
		std::cout<<t2<<std::endl;
	}
	catch(std::invalid_argument& error)
	{
		std::cout<<error.what()<<std::endl;
	}
}
void checkratio()
{
	try
	{
		
		Time t(24,30,12);
		/*print(t);*/
		Time t2(0,50,30);
		std::cout<<(t==t2)<<std::endl;
		std::cout<<(t<t2)<<std::endl;
		std::cout<<(t>t2)<<std::endl;
	}
	catch(std::invalid_argument& error)
	{
		std::cout<<error.what()<<std::endl;
	}
}
void checkchange()
{
	try
	{
		Time t(24,30,12);
		t.change_delimiter('*','_');
		print(t);
		t.change_delimiter('7','_');
		
	}
	catch(std::invalid_argument& error)
	{
		std::cout<<error.what()<<std::endl;
	}
}
