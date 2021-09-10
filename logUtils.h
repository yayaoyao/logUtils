//
// Created by yaoyayao on 2021/9/9
//
#pragma once
#ifndef __LOGUTILS_H__    //意思是  "if not define __XXX_H__" 也就是没包含XXX.h

#define __LOGUTILS_H__   //就定义__XXX_H__
#include <string>
using namespace std;
#define LOG_DIR ("..\\OCR_log")

//debug级别
#define DEBUG_LEVEL  2  //这里控制打印的最高debug级别

#define DEBUG_DEBUG 3
#define DEBUG_INFO  2
#define DEBUG_WARING 1
#define DEBUG_ERROR 0

void writeLog(string log);
void debug(int level, string log);

#endif       //否则不需要定义
