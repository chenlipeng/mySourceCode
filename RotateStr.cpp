/**
 *@author<chenlipeng><15038134525@163.com>
 */
 
//3���ַ�����ת���� 
//����һ���ַ���str����һ���Ǹ�������i����str�е�λ��
//����iλ�����ڵ� ��ಿ�����Ƶ��ұ�����iλ���ұߵ�λ�����Ƶ����������д����ʵ�֡�
//���磺 str = "ABCDEFGH"; i = 4; �������Ϊ��"FGHABCDE"
//Ҫ��ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(1)�� 


// SomeCodes.cpp : �������̨Ӧ�ó������ڵ㡣
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

//�ݹ�ʵ��
//����һЩ���� ����һ�δ���� ����λ�� ��������λ��
//ʣ�µ� �� ���õݹ� ����
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