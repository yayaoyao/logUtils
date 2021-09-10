#include <iostream>
#include <fstream>
#include <string>
#include "logUtils.h"  //预编译处理日志的各种类
using namespace std;

int main()
{
	string log = "i am log";
	writeLog(log);
	debug(-1, log);
	debug(DEBUG_ERROR, log);
	return 0;
}