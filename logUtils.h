//
// Created by yaoyayao on 2021/9/9
//
#pragma once
#ifndef __LOGUTILS_H__    //��˼��  "if not define __XXX_H__" Ҳ����û����XXX.h

#define __LOGUTILS_H__   //�Ͷ���__XXX_H__
#include <string>
using namespace std;
#define LOG_DIR ("..\\OCR_log")

//debug����
#define DEBUG_LEVEL  2  //������ƴ�ӡ�����debug����

#define DEBUG_DEBUG 3
#define DEBUG_INFO  2
#define DEBUG_WARING 1
#define DEBUG_ERROR 0

void writeLog(string log);
void debug(int level, string log);

#endif       //������Ҫ����
