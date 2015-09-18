/**
 *@author<chenlipeng><15038134525@163.com>
 */
 
//3、字符串旋转问题 
//给定一个字符串str，和一个非负的整数i代表str中的位置
//包括i位置在内的 左侧部分想移到右边来，i位置右边的位置想移到左边来，请写函数实现。
//例如： str = "ABCDEFGH"; i = 4; 调整结果为："FGHABCDE"
//要求：时间复杂度为O(N)，额外空间复杂度为O(1)。 


// SomeCodes.cpp : 定义控制台应用程序的入口点。
// 

#include "stdafx.h"

#include <iostream>
void RotateStr(char str[], int i, int len);

int main()
{
	for(int i=-1; i<30; ++i) {
		char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		RotateStr(str, i, sizeof(str)/sizeof(char) - 1);
		std::cout << str << std::endl;
	}
	return 0;
}

//递归实现
//总有一些数据 经过一次处理后 所在位置 是其最终位置
//剩下的 则 采用递归 处理
void RotateStr(char str[], int i, int len) {
	if(NULL == str || i < 0 || len < 1 || i >= len-1)
		return ;
	int temp = len - 1, temp1 = i;
	while(temp > i && temp1 >= 0) {
		std::swap(str[temp], str[temp1]);
		--temp;
		--temp1;
	}
	if(temp > i) {
		RotateStr(str, temp - i - 1, temp + 1);
	}
	if(temp1 >= 0) {
		RotateStr(str, temp1, temp + 1);
	}
}