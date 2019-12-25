/*#include <stdexcept>*/
#include "my_time.h"
#include "msg_printer.h"

class Timer{
	public:
	Timer(Time t,msg_printer* m);
	void tick();
	void tick(unsigned char sum);
	void tick(const std::string& s,unsigned char sum=60);
	private:
	Time m_target;
	Time m_clock;
	msg_printer* m_pprinter;
	bool check();
	bool validMin(const std::string& s);
	bool validHour(const std::string& s);
};

inline Timer::Timer(Time t,msg_printer* m):m_target(t.get_seconds()),m_clock(0),m_pprinter(m)	
{
		
}
inline bool Timer::check()
{
	if((m_clock>=m_target))
	{
		return true;
	}
	return false;
}
inline void Timer::tick()
{
	if(check()==true)
	{
		m_pprinter->print();
		m_clock=0;
	}
	m_clock+=1;
}
inline void Timer::tick(unsigned char sum)
{
	if(check()==true)
	{
		m_pprinter->print();
	}
	
	m_clock+=sum;
}
inline bool Timer::validMin(const std::string& s){
	if(s=="M"||s=="m"||s=="min"||s=="Min"||s=="Minute"||s=="minute")
	{
		return true;
	}
	return false;
}
inline bool Timer::validHour(const std::string& s){
	if(s=="H"||s=="h"||s=="Hour"||s=="hour")
	{
		return true;
	}
	return false;
}
inline void Timer::tick(const std::string& s,unsigned char sum ) 
{
	std::cout<<m_clock<<std::endl;
	
	std::cout<<m_target<<std::endl;
	if(check()==true)
	{
		
		m_pprinter->print();
	}
	
	if(validMin(s)==true)
	{
		
		m_clock+=(sum*60);
	}
	else
	{
		if(validHour(s)==true)
		{
			
			m_clock+=(sum);
		}
		else
		{
			throw std::invalid_argument("this is error");
		}
	}
	
}
