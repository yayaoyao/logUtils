#include <iostream>
#include <fstream>
#include <string>
#include "logUtils.h"  //Ԥ���봦����־�ĸ�����
using namespace std;

int main()
{
	string log = "i am log";
	writeLog(log);
	debug(-1, log);
	debug(DEBUG_ERROR, log);
	return 0;
}