#ifndef __MSG_PRINTER_H__
#define __MSG_PRINTER_H__
#include <iostream>
#include <string>
#include <cstring>
class msg_printer
{
	public:
	msg_printer(const std::string& s);
	const std::string& getMessage() const;
	virtual ~msg_printer();
	virtual void print() const;
	private:
	std::string m_message;
};
class MsgPrinterSurrounding:public msg_printer{
	public:
	MsgPrinterSurrounding(const std::string &s);
	MsgPrinterSurrounding(const std::string &s,const std::string& before_msg ,const std::string &after_msg );
	MsgPrinterSurrounding(const MsgPrinterSurrounding &mps);
	MsgPrinterSurrounding& operator=(const MsgPrinterSurrounding &msg);
	
	virtual ~MsgPrinterSurrounding();
	/*virtual*/ void print() const;
	protected:
	virtual void printBefore() const;
	virtual void printAfter() const ;
	private:
	
	char* m_before;
	char* m_after;
};
class msgPrinterMultipleSurrounding:public MsgPrinterSurrounding {
	public:
	~msgPrinterMultipleSurrounding();
	msgPrinterMultipleSurrounding(const std::string &s ,unsigned char num=2);
	msgPrinterMultipleSurrounding(const std::string &s,const std::string& before_msg
	 ,const std::string &after_msg,unsigned char num=2);
	void setTimes(unsigned char c);
	unsigned char getTimes() const;
	/*virtual*/void printBefore() const;
	/*virtual*/void printAfter() const;
	private:
	unsigned char m_times;	
};
/*msg_printer members function*/
inline const std::string& msg_printer:: getMessage() const
{
	return m_message;
}
inline msg_printer::msg_printer(const std::string &s)
{
	m_message=s;
}
inline void msg_printer::print() const
{
	std::cout<<"Message: "<<m_message<<std::endl;
}
inline msg_printer::~msg_printer()
{
	std::cout<<"End of MsgPrinter "<<m_message<<std::endl;
	
	
}
/*MsgPrinterSurrounding members function*/
inline MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string &s):msg_printer(s)
,m_before(0)
,m_after(0)
{
			
}
inline MsgPrinterSurrounding& MsgPrinterSurrounding:: operator=( const MsgPrinterSurrounding &msg)
{
	
	
		msg_printer::operator=(msg);
		delete [] m_before;
		m_before=new char[strlen(msg.m_before)];
		strcpy(m_before,msg.m_before);
		delete[]m_after;
		m_after=new char[strlen(msg.m_after)];
		strcpy(m_after,msg.m_after);
	
	return *this;
	
}
inline 
inline  MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &mps):msg_printer(mps)
{
	m_before=new char[strlen(mps.m_before)];
	strcpy(m_before,mps.m_before);
	m_after=new char[strlen(mps.m_after)];
	strcpy(m_after,mps.m_after);
}
inline MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string &s,const std::string& before_msg,const std::string &after_msg):
msg_printer(s),m_before(0),m_after(0)
{
	if(before_msg!="\0")
	{
		m_before=new char[before_msg.length()];
		strcpy( m_before,before_msg.c_str());
	}
	if(after_msg!="\0")
	{
		m_after=new char[after_msg.length()];
		strcpy(m_after,after_msg.c_str());
	}			
}
inline void MsgPrinterSurrounding::printBefore() const{
	
		std::cout<<"msg_before "<<m_before<<std::endl;
	
}
inline void MsgPrinterSurrounding::printAfter() const{
	
		std::cout<<"msg_after "<<m_after<<std::endl;
	
}
inline void MsgPrinterSurrounding::print() const{
	printBefore();
	msg_printer::print();
	printAfter();
}
inline  MsgPrinterSurrounding::~MsgPrinterSurrounding()
{
	delete[]m_before;
	delete[]m_after;
	std::cout<<"end of MsgPrinterSurrounding "<<std::endl;
	msg_printer::print();
}

/* msgPrinterMultipleSurrounding members function*/
inline msgPrinterMultipleSurrounding::msgPrinterMultipleSurrounding(const std::string &s,unsigned char num):
MsgPrinterSurrounding(s),
m_times(num)
{
}
inline msgPrinterMultipleSurrounding::msgPrinterMultipleSurrounding(const std::string &s,const std::string& before_msg,const std::string &after_msg,unsigned char num):
MsgPrinterSurrounding(s,before_msg,after_msg)
,m_times(num)
{
}
inline void msgPrinterMultipleSurrounding::setTimes(unsigned char c)
{
	m_times=c;
}
inline unsigned char msgPrinterMultipleSurrounding::getTimes() const
{
	return m_times;
}
inline void msgPrinterMultipleSurrounding::printBefore() const{
	int top=(int)m_times;
	int i;
	for(i=0;i<top;i++)
	{
		MsgPrinterSurrounding::printBefore();
	}
}
inline void msgPrinterMultipleSurrounding::printAfter() const{
	int top=(int)m_times;
	int i;
	for(i=0;i<top;i++)
	{
		MsgPrinterSurrounding::printAfter();
	}
}
inline msgPrinterMultipleSurrounding::~msgPrinterMultipleSurrounding()
{
	std::cout<<"end of msgPrinterMultipleSurrounding "<<std::endl;
	msg_printer::print();
}
#endif
