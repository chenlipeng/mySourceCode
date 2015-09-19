

// SomeCodes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
int maxProfit(int *prices, int length);
int *arrayPrint(int **arr, int n);
int main()
{
	int *arr1 = new int[16];
	for(int i=0; i<16; ++i) {
		arr1[i] = i + 1;
	}
	int *res = arrayPrint(&arr1, 4);
	return 0;

	int arr[] = { 10, 22, 5, 75, 65, 80};
	std::cout << maxProfit(arr, sizeof(arr)/sizeof(int)) << std::endl;
	return 0;
}

//打印n*n数组，从右上角之字形打印至左下角
int *arrayPrint(int **arr, int n) {
	int *res = new int[n*n];
	int l = 0;
	int *temp = *arr;
	for(int i=n-1; i>=0; --i) {
		for(int j=0,k=i; j<n && k<n; ++j,++k) {
			res[l++] = temp[j * n + k];
			std::cout << temp[j * n + k] << ' ';
		}
	}
	for(int i=1; i<n; ++i) {
		for(int j=i,k=0; j<n && k<n; ++j,++k) {
			res[l++] = temp[j * n + k];
			std::cout << temp[j * n + k] << ' ';
		}
	}
	for(int i=0; i< n*n; ++i) {
		temp[i] = res[i];
	}
	delete [] res;
	std::cout << std::endl;
	return res;
}

//每天可以在股市进行买入卖出操作i次，0<= i <=2,
//即可以进行的操作 买入->卖出->买入->卖出
//求每天的最大收益
//输入为一系列股票价格
//输出今天理论最大收益
int maxProfitHelp(int *prices, int length) {
	int res = 0;
	if(length <= 1) {
		return res;
	}
	for(int i=0; i<length; ++i) {
		for(int j=i+1; j<length; ++j) {
			if(res < prices[j] - prices[i]) {
				res = prices[j] - prices[i];
			}
		}
	}
	return res;
}

int maxProfit(int *prices, int length) {
	int res = 0, res1 = 0, res2 = 0;
	for(int i = 0; i<=length; ++i) {
		res1 = maxProfitHelp(prices, i);
		res2 = maxProfitHelp(prices + i, length - i);
		if(res1 + res2 > res) {
			res = res1 + res2;
		}
	}
	return res;
}