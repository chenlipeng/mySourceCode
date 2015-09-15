//2015/09/15 C++ 360应届生校园招聘编程题
//相对比较简单，未设计什么算法，，
//就是考研 有政治，英语，数学，专业课
//要求 政治分数不少于60分，英语分数不少于60分， 数学分数不少于90分， 专业课分数不少于90分，总分不少于310分
//如果不满足以上条件 则失败Fail
//如果分数大于等于350， 则享受公费Gongfei ， 负责自费Zifei
//So easy!
//author chenlipeng <chenlipeng@oneniceapp.com>
#include <iostream>
using namespace std;
int main() {
	int n;
	if(std::cin >> n && n > 0) {
		int politics, english, math, major;
		int total;
		while(n > 0) {
			--n;
			if(std::cin >> politics >> english >> math >> major) {
				total = politics + english + math + major;
				if(total < 310 || politics < 60 || english < 60 || math < 90 || major < 90) {
					std::cout << "Fail" << std::endl;
					continue;
				}
				if(total >= 350) {
					std::cout << "Gongfei" << std::endl;
				}
				else {
					std::cout << "Zifei" << std::endl;
				}
			}
		}
	}
	return 0;
}
