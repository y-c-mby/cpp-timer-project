#include <iostream>
#include <stdexcept>
#include <cstdio>
#include "stdlib.h"
typedef enum b
{
	TRUE,
	FALSE
}m_bool;
class Time{
	public:
	Time(unsigned int h,unsigned char m,unsigned char s) throw(std::invalid_argument);
	Time(int s);
	std::string get_as_str(m_bool is_using_days) const;
	unsigned int get_seconds() const;
	static void change_delimiter(char dd,char d) throw(std::invalid_argument); 
	Time& operator+=(Time t);
	friend void time_reset(Time* ptr);
	private:
	static const int s_m_secondsofhours=3600;
	static const int s_m_secondsinminute=60;
	unsigned int m_hours;
	unsigned char m_minutes;
	unsigned char m_seconds;
	static char m_ddelimiter;
	static char m_delimiter;
};
void time_reset(Time* ptr);
char compare(Time& t,Time& t1);
inline  void Time:: change_delimiter(char dd,char d)throw(std::invalid_argument)
{
	if(isdigit(dd)||isdigit(d))
	{
		throw std::invalid_argument("the input is num please enter char");
	}	
	m_ddelimiter=dd;
	m_delimiter=d;
}
inline bool operator==(Time& t,Time& t1)
{
	return(t.get_seconds()==t1.get_seconds());
}
inline bool operator!=(Time& t,Time& t1)
{
	return(t.get_seconds()!=t1.get_seconds());
}
inline bool operator<(Time& t,Time& t1)
{
	return(t.get_seconds()<t1.get_seconds());
}
inline bool operator<=(Time& t,Time& t1)
{
	return(t.get_seconds()<=t1.get_seconds());
	
}
inline bool operator>(Time& t,Time& t1)
{
	return(t.get_seconds()>t1.get_seconds());
	
}
inline bool operator>=(Time& t,Time& t1)
{
	return(t.get_seconds()>=t1.get_seconds());
	
}
inline Time::Time(int s):m_hours((s/s_m_secondsofhours)),m_minutes((unsigned char)((s%s_m_secondsofhours)/s_m_secondsinminute)),m_seconds((unsigned char)((s%s_m_secondsofhours)%s_m_secondsinminute))
{
	
			
}
inline void print(const Time& t)
{
	std::cout<<t.get_as_str(TRUE)<<std::endl;
}

inline unsigned int Time::get_seconds() const
{
	
	return (((m_hours*3600)+(m_minutes*60)+m_seconds));
}

inline Time operator+( const Time t1,const Time t2)
{
	
	Time new_time(t1.get_seconds()+t2.get_seconds());
	
	return new_time;
}
inline std::ostream& operator<<(std::ostream& cout, Time s)
{
	
	cout<<s.get_as_str(FALSE);
	return cout;
}




