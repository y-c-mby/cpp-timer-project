#include "my_time.h"

#include <string>
char Time:: m_ddelimiter='.';
char Time:: m_delimiter=':';
Time::Time(unsigned int h,unsigned char m,unsigned char s)throw(std::invalid_argument):m_hours(h),m_minutes(m),m_seconds(s)
{
	std::string str;
	if(s>59)
	{
		str+="the seconds is not in the range";
	    	
	}
	if(m>59)
	{
		str+="the minutes is not in the range";
	}
	if(h>100000)
	{
		str+="the hours is not in the range";
	}
	if(str!="\0")
	{
		throw std::invalid_argument(str); 
	}
}
std::string Time::get_as_str(m_bool is_using_days) const
{
	char days;
	char buffer[20];
	std::string str;
	if(is_using_days==1)
	{
		sprintf(buffer,"%02d%c%02d%c%02d",m_hours,m_delimiter,m_minutes,m_delimiter,m_seconds);
	}
	else
	{
		days=(char)(m_hours/24);
		sprintf(buffer,"%02d%c%02d%c%02d%c%02d",days,m_ddelimiter,(m_hours%24),m_delimiter,m_minutes,m_delimiter,m_seconds);
	}
	str=buffer;
	return str;
	
}
Time& Time::operator+=(Time t)
{
	Time b(get_seconds()+t.get_seconds());
	*this=b;
	return *this;
}
char compare(Time& t,Time& t1)
{
	if(t.get_seconds()<t1.get_seconds())
	{
		return 1;
	}
	else
	{
		if(t.get_seconds()>t1.get_seconds())
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

