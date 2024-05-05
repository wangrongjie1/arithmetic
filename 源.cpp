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
int topicCount = 0;//��Ŀ����
string choiceOpe = "+";//�����
int maxNumber = 0;//����������
bool judgeDeci = 0;//�Ƿ���С��
bool judgeDrac = 0;//�Ƿ�������
int howMany = 0;//���ٸ�����������
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
	cout << "������Ŀ������";
	cin >> topicCount;
	cout << "�������";
	cin >> choiceOpe;
	cout << "������������";
	cin >> maxNumber;
	cout << "�Ƿ���С������(1���ǣ�0����)��";
	cin >> judgeDeci;
	cout << "�Ƿ��С����(1���ǣ�0����)��";
	cin >> judgeDrac;
	cout << "���ٸ����������㣺";
	cin >> howMany;
	if (judgeDrac)
		choiceOpe.append("()");
	if (judgeDeci)
		choiceOpe.append(1, '.');
	function();
	cout << "1�����뵽�ļ���2���������ӡ����";
	int flag = 0;
	cin >> flag;
	if (flag == 1) {
		fstream file("D:\\����ļ�\\Visual Studio\\�ճ���ϰ\\����������Ŀ.txt", fstream::out | ios_base::trunc);
		if (file.is_open())
		{
			cout << "�ļ���ʼ����" << endl;
			for (auto i : FAP)
				file << i << endl;
			cout << "�������" << endl;
		}
	}
	else
	{
		cout << "�ļ���ʼ��ӡ" << endl;
		for (auto i : FAP)
			cout << i << endl;
		cout << "��ӡ���" << endl;

	}
	return 0;
}

