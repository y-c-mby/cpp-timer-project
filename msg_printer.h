#include <iostream>
class msg_printer
{
	public:
	msg_printer(std::string s=NULL);
	~msg_printer();
	virtual void print();
	private:
	std::string m_message;
};
inline msg_printer::msg_printer(std::string s)
{
	m_message=s;
}
inline void msg_printer::print()
{
	std::cout<<"Message:"<<m_message<<std::endl;
}
inline msg_printer::~msg_printer()
{
	std::cout<<"End of MsgPrinter"<<m_message<<std::endl;
	
}
