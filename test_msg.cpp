#include "test_msg.h"
void create_messages()
{
	msg_printer msg("hello");
	msg_printer msg1(msg);
	msgPrinterMultipleSurrounding msgPMS ("hello","b","a");
	MsgPrinterSurrounding msgPS("hello","b","a");
	MsgPrinterSurrounding msgPS1(msgPS);
	
}
void check_copyctor()
{
	msg_printer msg("hello");
	msg_printer msg1(msg);
	MsgPrinterSurrounding msgPS("hello","b","a");
	MsgPrinterSurrounding msgPS1(msgPS);
}
void check_asiment()
{
	MsgPrinterSurrounding msgPS("hello","b","a");
	MsgPrinterSurrounding msgPS1("yaeli","b2","a2");
	msgPS1=msgPS;


}
