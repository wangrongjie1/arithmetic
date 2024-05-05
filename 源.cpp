#include<vector>
#include<stack>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <ctime>
#include <random>
#include<queue>

using namespace std;
vector<string> FAP;//Four arithmetic problems
int topicCount = 0;//题目总数
string choiceOpe = "+";//运算符
int maxNumber = 0;//最大的运算结果
bool judgeDeci = 0;//是否有小数
bool judgeDrac = 0;//是否有括号
int howMany = 0;//多少个数参与运算
void function() {
	default_random_engine ran_num1;
	uniform_int_distribution<int> scopeInt(0, 10000);
	ran_num1.seed(time(0));
	for (int n = 0; n < topicCount; ++n) {
		queue<string> number;
		queue<char> oper;
		char tempChar = '#';
		FAP.push_back(string());
		int len = 0;
		int signBrac = 0;
		for (int i = 0; i < howMany; ++i) {
			int tempInt = scopeInt(ran_num1) % maxNumber;
			if (tempChar == '(') {
				tempChar = choiceOpe[scopeInt(ran_num1) % (choiceOpe.size() - 3)];
				oper.push(tempChar);
				number.push('(' + to_string(tempInt));
				signBrac++;
			}
			else if (tempChar == ')')
			{
				tempChar = choiceOpe[scopeInt(ran_num1) % (choiceOpe.size() - 3)];
				oper.push(tempChar);
				number.push(to_string(tempInt) + ')');
				signBrac--;
			}
			else {
				oper.push(tempChar);
				number.push(to_string(tempInt));
			}

			tempChar = choiceOpe[scopeInt(ran_num1) % (choiceOpe.size() - len)];
			len = 0;
			if (tempChar == '.') {
				len = 1;
				i--;
			}
			if (!signBrac && tempChar == ')') {
				tempChar = choiceOpe[scopeInt(ran_num1) % (choiceOpe.size() - 2)];
			}

		}

		oper.pop();
		while (!oper.empty()) {
			FAP[n].append(number.front());
			number.pop();
			FAP[n].append(1, oper.front());
			oper.pop();
		}
		FAP[n].append(number.front());
		for (int i = signBrac; i > 0; --i) {
			FAP[n].append(1, ')');
		}
		FAP[n].append(1, '=');
	}
}

int main() {
	cout << "输入题目总数：";
	cin >> topicCount;
	cout << "运算符：";
	cin >> choiceOpe;
	cout << "最大的运算数：";
	cin >> maxNumber;
	cout << "是否有小数运算(1、是，0、否)：";
	cin >> judgeDeci;
	cout << "是否带小括号(1、是，0、否)：";
	cin >> judgeDrac;
	cout << "多少个数参与运算：";
	cin >> howMany;
	if (judgeDrac)
		choiceOpe.append("()");
	if (judgeDeci)
		choiceOpe.append(1, '.');
	function();
	cout << "1、输入到文件，2、输出到打印机：";
	int flag = 0;
	cin >> flag;
	if (flag == 1) {
		fstream file("D:\\编程文件\\Visual Studio\\日常练习\\四则运算题目.txt", fstream::out | ios_base::trunc);
		if (file.is_open())
		{
			cout << "文件开始输入" << endl;
			for (auto i : FAP)
				file << i << endl;
			cout << "输入完成" << endl;
		}
	}
	else
	{
		cout << "文件开始打印" << endl;
		for (auto i : FAP)
			cout << i << endl;
		cout << "打印完成" << endl;

	}
	return 0;
}

