//
// Created by yaoyayao on 2021/9/9.
//
#define _CRT_SECURE_NO_WARNINGS   //这样可以避免要求使用sprintf_s的警告
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <io.h>  //access
#include <direct.h> //mkdir
#include "logUtils.h"

using namespace std;

ofstream outfile;   //声明处理文件的ofstream对象 全局共享
char pStrLogPath[320]; //存放日志文件名称 注意char的大小，如果文件名太长会出现中断
//char logDir[11] = "..\\OCR_log";
//extern char logDir[]; 在别的文件里使用这个全局变量, 数组的大小在全局变量中声明


tm * getCurrentTime()  //返回当前时间对象指针
{
	time_t currTime;
	struct tm *mt;
	currTime = time(NULL);
	mt = localtime(&currTime);
	return mt;
}

void get_hour_time()  //获取日志文件名称,截止到小时
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour);
}

void get_min_time()  //获取日志文件名称,截止到分钟
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d:%02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min);
}

void get_sec_time()  //获取日志文件名称,截止到秒
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d:%02d:%02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);
}

void get_curr_sec_time()  //获取当前时间，截至到秒，日志每行记录前面需打印
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%d_%02d_%02d %02d:%02d:%02d", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);
}

void writeLog(string log) //写日志
{
	get_hour_time();
	
	if (_access(LOG_DIR, 0) == -1)    //如果文件夹不存在则创建
		_mkdir(LOG_DIR);
	outfile.open(pStrLogPath, ios::app);  //加上第二个参数可以实现文件内容追加
	if (!outfile) //检查文件是否正常打开//不是用于检查文件是否存在
	{
		cout << ("%s.txt can't open", pStrLogPath) << pStrLogPath << endl;
		abort(); //打开失败，结束程序
	}
	else
	{
		
		outfile << log << endl;
		outfile.close();
	}
}

void debug(int level, string log)
{	
	if (level <= DEBUG_LEVEL)
	{
		get_curr_sec_time();
		string current_time = pStrLogPath;
		string prefix;
		switch (level) {
		case DEBUG_ERROR:
			prefix = "[DEBUG_ERROR]";
			break;
		case DEBUG_WARING:
			prefix = "[DEBUG_WARING]";
			break;
		case DEBUG_INFO:
			prefix = "[DEBUG_INFO]";
			break;
		case DEBUG_DEBUG:
			prefix = "[DEBUG_DEBUG]";
			break;
		default:
			prefix = "";  //level随便给个负数，就可以不打印[DEBUG标识]只输入 当前时间+log内容
		}
		string entire_log = prefix + " " + current_time + " " + log;
		writeLog(entire_log);
	}
}