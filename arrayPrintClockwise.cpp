/**
 * @author<chenlipeng> <15038134525@163.com>
 * @datetime<2015/09/19>
 * @location<XiDian university>
 */

//˳ʱ�롢��ʱ���ӡ����

// SomeCodes.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>

template<unsigned M, unsigned N>
void arrayPrintClockwise(int (&arr)[M][N]);

template<unsigned M, unsigned N>
void arrayPrintAntiClockwise(int (&arr)[M][N]);

int main()
{
	const int m = 4, n = 4;
	int arr[m][n];
	int val = 1;
	for(int i=0;i<m;++i) {
		for(int j=0;j<n;++j) {
			arr[i][j] = val++;
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	arrayPrintClockwise(arr);
	arrayPrintAntiClockwise(arr);
	return 0;
}

//ʵ����ʱ����ת��ӡ����
//˼·��ʹ���ĸ������ֱ��¼����ʼ�У������У���ʼ�У�������
//Ȼ���� ��ӡ��ʼ�У������У������У���ʼ�н���˳ʱ���ӡ
template<unsigned M, unsigned N>
void arrayPrintAntiClockwise(int (&arr)[M][N]) {
	int lineStart = 0, lineStop = M - 1;
	int columStart = 0, columStop = N - 1;

	while(lineStart <= lineStop && columStart <= columStop) {
		for(int i=lineStart; i<=lineStop; ++i) {
			std::cout << arr[i][columStart] << ' ';
		}
		++columStart;

		if(lineStart > lineStop) {
			break;
		}
		for(int i=columStart; i<=columStop; ++i) {
			std::cout << arr[lineStop][i] << ' ';
		}
		--lineStop;
		
		if(columStart > columStop) {
			break;
		}
		for(int i=lineStop; i>=lineStart; --i) {
			std::cout << arr[i][columStop] << ' ';
		}
		--columStop;

		if(lineStart > lineStop) {
			break;
		}
		for(int i=columStop; i>=columStart; --i) {
			std::cout << arr[lineStart][i] << ' ';
		}
		++lineStart;
	}
	std::cout << std::endl;
}


//ʵ��˳ʱ����ת��ӡ����
//˼·��ʹ���ĸ������ֱ��¼����ʼ�У������У���ʼ�У�������
//Ȼ���� ��ӡ��ʼ�У������У������У���ʼ�У�����˳ʱ���ӡ
template<unsigned M, unsigned N>
void arrayPrintClockwise(int (&arr)[M][N]) {
	int lineStart = 0, lineStop = M - 1;
	int columStart = 0, columStop = N - 1;
	
	while(lineStart <= lineStop && columStart <= columStop) {
		for(int i=columStart; i<=columStop; ++i) {
			std::cout << arr[lineStart][i] << ' ';
		}
		++lineStart;

		if(columStart > columStop) {
			break;
		}
		for(int i=lineStart; i<=lineStop; ++i) {
			std::cout << arr[i][columStop] << ' ';
		}
		--columStop;

		if(lineStart > lineStop) {
			break;
		}
		for(int i=columStop; i>=columStart; --i) {
			std::cout << arr[lineStop][i] << ' ';
		}
		--lineStop;

		if(columStart > columStop) {
			break;
		}
		for(int i=lineStop; i>=lineStart; --i) {
			std::cout << arr[i][columStart] << ' ';
		}
		++columStart;
	}
	std::cout << std::endl;
}

