// 1����ֽ���� 
//���ֽ�����ŷ�����?�ϣ�Ȼ���ֽ�����±�����?���ۣ�ѹ���ۺۺ���չ ����
//��ʱ��1���ۺۣ�ͻ���?��ָ��ֽ���ı�?�������ۺ۽������¡��ۺ� ��ͻ���?��ָ��ֽ����?���ۺ۽������ϡ��ۺۡ�
//���ÿ�ζ����±�����? ���ۣ�����N�Ρ�����ϵ��´�ӡ�����ۺ۵ķ��� 

// SomeCodes.cpp : �������̨Ӧ�ó������ڵ㡣
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

//�ݹ�ʵ�� 0 �����¡��ۺۣ� 1 �����ϡ��ۺ�
//���ۺ� �� �����ۺ۵�λ�ý� ֽ�� �ֳ������֣�
//�ۺ� �Ϸ����֣��ۺ��·����֣�
//ͬʱ �ۺ��·� �ķ������仯 ��ԭ����ߵ�
//�ȴ������µߵ��� �ִ���������ߵ�����Ҫע��
//���µߵ��� ����˳�����ı䣬
//������ߵ��� �����ۺ۷����ı�
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