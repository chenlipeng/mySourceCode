/**
 *@author<chenlipeng><15038134525@163.com>
 */

//2015/09/15 360 C++ 校园招聘
//输入一个数字，，
//输出 其 质因子
//输出格式 比较特殊， 即如我们日常看到的电子表一样的格式，，
//不同质因子之间用*连接起来

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
bool IsPrime(int val);
void AppendMultiply(std::string &line1, std::string &line2, std::string &line3, std::string &line4, std::string &line5);
void Append(int val, std::string &line1, std::string &line2, std::string &line3, std::string &line4, std::string &line5);
int main() {
	int val;
	while(std::cin >> val) {
		int temp = val;
		std::vector<int> res;
		for(int i=2; i<=temp; ++i) {
			if(IsPrime(i) && temp % i == 0) {
				res.push_back(i);
				temp /= i;
				i = 1;
			}
		}
		std::string line1, line2, line3, line4, line5;
		for(int i=0; i<res.size(); ++i) {
			if(i!=0) {
				AppendMultiply(line1, line2, line3, line4, line5);
			}
			int num = res[i];
			std::vector<int> tempval;
			while(num > 0) {
				tempval.push_back(num%10);
				num /= 10;
			}
			for(int j=tempval.size()-1; j>=0; --j) {
				Append(tempval[j], line1, line2, line3, line4, line5);
			}
		}
		std::cout << line1 << std::endl;
		std::cout << line2 << std::endl;
		std::cout << line3 << std::endl;
		std::cout << line4 << std::endl;
		std::cout << line5 << std::endl;
	}
	return 0;

	std::cout << " - " << " " << "   " << std::endl;
	std::cout << "| |" << " " << " | " << std::endl;
	std::cout << "   " << " " << "   " << std::endl;
	std::cout << "| |" << " " << " | " << std::endl;
	std::cout << " - " << " " << "   " << std::endl;
	return 0;
}
void Append(int val, std::string &line1, std::string &line2, std::string &line3, std::string &line4, std::string &line5) {
	std::string word1 = " -     -  -     -  -  -  -  - ";
	std::string word2 = "| | |   |  || ||  |    || || |";
	std::string word3 = "       -  -  -  -  -     -  - ";   
	std::string word4 = "| | | |    |  |  || |  || |  |";
	std::string word5 = " -     -  -     -  -     -  - ";

	line1.insert(line1.end(), word1.begin() + val * 3, word1.begin() + val * 3 + 3);
	line2.insert(line2.end(), word2.begin() + val * 3, word2.begin() + val * 3 + 3);
	line3.insert(line3.end(), word3.begin() + val * 3, word3.begin() + val * 3 + 3);
	line4.insert(line4.end(), word4.begin() + val * 3, word4.begin() + val * 3 + 3);
	line5.insert(line5.end(), word5.begin() + val * 3, word5.begin() + val * 3 + 3);
}

void AppendMultiply(std::string &line1, std::string &line2, std::string &line3, std::string &line4, std::string &line5) {
	line1.push_back(' ');
	line2.push_back(' ');
	line3.push_back('*');
	line4.push_back(' ');
	line5.push_back(' ');
}

bool IsPrime(int val) {
	for(int i=2; i<= sqrt(static_cast<double>(val)); ++i) {
		if(val % i == 0) {
			return false;
		}
	}
	return true;
}
