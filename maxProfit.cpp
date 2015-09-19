

// SomeCodes.cpp : �������̨Ӧ�ó������ڵ㡣
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

//��ӡn*n���飬�����Ͻ�֮���δ�ӡ�����½�
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

//ÿ������ڹ��н���������������i�Σ�0<= i <=2,
//�����Խ��еĲ��� ����->����->����->����
//��ÿ����������
//����Ϊһϵ�й�Ʊ�۸�
//������������������
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