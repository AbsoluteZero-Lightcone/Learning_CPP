﻿/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.3.1
  * @date    2024-03-06
  * @brief   A demonstration of the class Date.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "date.h"

// 用回调函数实现了在类外自定义输出格式
void output(int year, int month, int day) {
    cout << year << "年" << month << "月" << day << "日" << endl;
}
void output(string s){
    cout << "提示信息：" << s << endl;
}

int main(){
    //system("chcp 65001");
    int year,month,day;
    while(1){
        cout << "输入date1：";
        cin >> year>>month >>day;
        if(Date::isValid(year,month,day))break;// 调用静态函数接口
        cout << "请输入正确的日期。"<< endl;
    }
    Date date1(year,month,day, output, output);
    while(1){
        cout << "输入date2：";
        cin >> year>>month >>day;
        if(Date::isValid(year,month,day))break;// 调用静态函数接口
        cout << "请输入正确的日期。"<< endl;
    }
    Date date2(year,month,day, output, output);
    while(1){
        cout << "输入today：";
        cin >> year>>month >>day;
        if(Date::isValid(year,month,day))break;// 调用静态函数接口
        cout << "请输入正确的日期。"<< endl;
    }
    Date today(year,month,day, output, output);
    cout << "today = ";today.showDate();
    today++;// 重载了自增自减运算符
    cout << "today = ";today.showDate();
     today++++++++;// 并可以链式调用
     cout << "today = ";today.showDate();
     today+=6;// 重载+=运算符
     cout << "today = ";today.showDate();
     today.setDate(0, 0, 0);// 带有合法性检查的set函数
     cout << "today = ";today.showDate();
     today.getNextDay().getNextDay().getNextDay().showDate();
     cout << "today = ";today.showDate();
    system("pause");
    return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
