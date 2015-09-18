// 1、折纸问题 
//请把纸条竖着放在桌?上，然后从纸条的下边向上?对折，压出折痕后再展 开。
//此时有1条折痕，突起的?向指向纸条的背?，这条折痕叫做“下”折痕 ；突起的?向指向纸条正?的折痕叫做“上”折痕。
//如果每次都从下边向上? 对折，对折N次。请从上到下打印所有折痕的方向。 

// SomeCodes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
void OutputFold(int n, bool facade = true);


int main()
{
	int n;
	while(std::cin >> n) {
		std::cout << "-------------------------------" << std::endl;
		OutputFold(n);
		std::cout << "-------------------------------" << std::endl;
	}
	return 0;
}

//递归实现 0 代表“下”折痕， 1 代表“上”折痕
//对折后 会 根据折痕的位置将 纸条 分成两部分：
//折痕 上方部分，折痕下方部分，
//同时 折痕下方 的方向发生变化 与原方向颠倒
//既存在上下颠倒， 又存在正反面颠倒。需要注意
//上下颠倒后， 处理顺序发生改变，
//正方面颠倒后 处理折痕发生改变
void OutputFold(int n, bool facade) {
	if(n < 1) {
		return ;
	}

	if(facade) {
		OutputFold(n - 1, facade);
		std::cout << 0 << std::endl;
		OutputFold(n - 1, !facade);
	} else {
		OutputFold(n - 1, !facade);
		std::cout << 1 << std::endl;
		OutputFold(n - 1, facade);
	}
}