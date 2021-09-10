//
// Created by yaoyayao on 2021/9/9.
//
#define _CRT_SECURE_NO_WARNINGS   //�������Ա���Ҫ��ʹ��sprintf_s�ľ���
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <io.h>  //access
#include <direct.h> //mkdir
#include "logUtils.h"

using namespace std;

ofstream outfile;   //���������ļ���ofstream���� ȫ�ֹ���
char pStrLogPath[320]; //�����־�ļ����� ע��char�Ĵ�С������ļ���̫��������ж�
//char logDir[11] = "..\\OCR_log";
//extern char logDir[]; �ڱ���ļ���ʹ�����ȫ�ֱ���, ����Ĵ�С��ȫ�ֱ���������


tm * getCurrentTime()  //���ص�ǰʱ�����ָ��
{
	time_t currTime;
	struct tm *mt;
	currTime = time(NULL);
	mt = localtime(&currTime);
	return mt;
}

void get_hour_time()  //��ȡ��־�ļ�����,��ֹ��Сʱ
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour);
}

void get_min_time()  //��ȡ��־�ļ�����,��ֹ������
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d:%02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min);
}

void get_sec_time()  //��ȡ��־�ļ�����,��ֹ����
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%s\\%d_%02d_%02d %02d:%02d:%02d.txt", LOG_DIR, mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);
}

void get_curr_sec_time()  //��ȡ��ǰʱ�䣬�������룬��־ÿ�м�¼ǰ�����ӡ
{
	struct tm *mt;
	mt = getCurrentTime();
	sprintf(pStrLogPath, "%d_%02d_%02d %02d:%02d:%02d", mt->tm_year + 1900, mt->tm_mon + 1, mt->tm_mday, mt->tm_hour, mt->tm_min, mt->tm_sec);
}

void writeLog(string log) //д��־
{
	get_hour_time();
	
	if (_access(LOG_DIR, 0) == -1)    //����ļ��в������򴴽�
		_mkdir(LOG_DIR);
	outfile.open(pStrLogPath, ios::app);  //���ϵڶ�����������ʵ���ļ�����׷��
	if (!outfile) //����ļ��Ƿ�������//�������ڼ���ļ��Ƿ����
	{
		cout << ("%s.txt can't open", pStrLogPath) << pStrLogPath << endl;
		abort(); //��ʧ�ܣ���������
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
			prefix = "";  //level�������������Ϳ��Բ���ӡ[DEBUG��ʶ]ֻ���� ��ǰʱ��+log����
		}
		string entire_log = prefix + " " + current_time + " " + log;
		writeLog(entire_log);
	}
}