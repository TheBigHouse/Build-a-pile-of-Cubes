// test1.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>  
#include <string.h>  
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <strstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using namespace std;

//using namespace std;
//class ASum
//{
//public:
//	static long long findNb(long long m) {
//		m = (long long) sqrt(m);
//		int i = 1; long long n = 0;
//		while (n < m) {
//			n += i;
//			i++;
//		}
//		printf("%a\n", m);
//		cout << "m:" << m << endl;
//		cout << "n:"<< n << endl;
//		return (n == m) ? (--i) : (-1);
//	};
//};


//int main()
//{
//      cout<< "name:" << ASum::findNb(24723578342962) << endl;
//	  system("pause");
//}

string lltoString(long long m) {
	string r;
	std::strstream ss;
	ss << m;
	ss >> r;
	return r;
}

void str2int(int &int_temp, const string &string_temp)
{
	stringstream stream(string_temp);
	stream >> int_temp;
}

long long join(vector<long long> g) {
	int len = g.size();
	
	string join = "";
	for (int i = 0; i < len; i++) {
		stringstream ss;
		string temp;
		ss << g[i];
		ss >> temp;
		join += temp;
	}
	stringstream ii;
	long long res;
	ii << join;
	ii >> res;
	return res;
}

long long mySqrt(long long m) {
	//手动开方过程
	//1.把数字从右到左每两位一组分开
	//2.
	string r = lltoString(m);
	//strcpy_s(*p, r.c_str());
	//_strrev(p);
	vector<long long> zz;
	int i = r.length() - 1;
	while (i >= 0) {
		stringstream ss;
		if (i == 0) {
			ss << r[0];
		}
		else {
			ss << r[i - 1] << r[i];
		}	
		zz.push_back(atoi(ss.str().c_str()));
		i-=2;
	}
	reverse(zz.begin(), zz.end());
	int j = zz.size();
	int yushu = 0;
	int shang = 0;
	vector<long long> g;
	while (g.size() < j) {
		int step = g.size();
		cout << "step:" << step << endl;
		if (step == 0) {
			g.push_back(sqrt(zz[0]));
			cout << "zz" << zz[0] << endl;
			yushu = zz[0] - g[0] * g[0];
		}
		else {
			shang = yushu * 100 + zz[step];
			//算除数个位数,个位数和乘数一样，上位数是目前所得结果乘以20
			int gw = 0;
			while (gw < 10) {
				if ((join(g) * 20 + gw) * gw <= shang && shang < (join(g) * 20 + gw + 1) * (gw + 1)) {
					break;
				}
				gw++;
			}
			cout << "gw" << join(g) << endl;
			yushu = shang - (join(g) * 20 + gw) * gw;
			g.push_back(gw);
		}
	}
	return yushu == 0?join(g):-1;
}

int main()
{
	//重点
	//1.1^3 + 2^3 + ... n^3 = (1+2+...+n)^2
	//2.手动开方数字。C++sqrt 函数是double型，long long数字会丢失精度。
	cout << "end:" << mySqrt(4) << endl;
	system("PAUSE ");
}

