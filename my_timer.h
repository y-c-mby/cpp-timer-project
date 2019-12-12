/*#include <stdexcept>*/
#include "my_time.h"
#include "msg_printer.h"

class Timer{
	public:
	Timer(Time t,msg_printer* m);
	void tick();
	void tick(unsigned char sum);
	void tick(std::string s,unsigned char sum=60) throw(std::invalid_argument);
	private:
	Time m_target;
	Time m_clock;
	msg_printer* m_pprinter;
};

inline Timer::Timer(Time t,msg_printer* m):m_target(t.get_seconds()),m_clock(0),m_pprinter(m)	
{
		
}
inline void Timer::tick()
{
	if((m_clock>=m_target))
	{
		m_pprinter->print();
		m_clock=0;
	}
	m_clock+=1;
}
inline void Timer::tick(unsigned char sum)
{
	if((m_clock>=m_target)==TRUE)
	{
		m_pprinter->print();
	}
	
	m_clock+=sum;
}
inline void Timer::tick(std::string s,unsigned char sum ) throw(std::invalid_argument)
{
	std::cout<<m_clock<<std::endl;
	
	std::cout<<m_target<<std::endl;
	if((m_clock>=m_target)==TRUE)
	{
		
		m_pprinter->print();
	}
	
	if(s=="M"||s=="m"||s=="min"||s=="Min"||s=="Minute"||s=="minute")
	{
		
		m_clock+=(sum*60);
	}
	else
	{
		if(s=="H"||s=="h"||s=="Hour"||s=="hour")
		{
			
			m_clock+=(sum);
		}
		else
		{
			throw std::invalid_argument("this is error");
		}
	}
	
}
