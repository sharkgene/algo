#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <map>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

set<string> all_lcs; //注意这里要用set去除重复的LCS
//最长公共子串（LCS）
//二维数组veca[i][j]记录的是两个字符串Xi和Yj的LCS长度
int LCS_length(const string &str1, const string &str2, vector<vector<int> > &veca) {
	int i, j;
	int biggest = 0;
	if (str1 == "" || str2 == "")
		return 0;

	for (i = 0; i <= str1.length(); i++) {
		veca[i][0] = 0;
	}
	for (j = 0; j <= str2.length(); j++) {
		veca[0][j] = 0;
	}
	for (i = 1; i <= str1.length(); i++) {
		for (j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				veca[i][j] = veca[i - 1][j - 1] + 1;
			}
			else {
				if (veca[i - 1][j] >= veca[i][j - 1])
					veca[i][j] = veca[i - 1][j];
				else
					veca[i][j] = veca[i][j-1];
			}
		}
	}
	return veca[str1.length()][str2.length()];
}

//该函数找出所有的LCS的序列，并将其存在vector中
void PrintAllLCS(string &str1, string &str2, int i, int j, 
	             vector<vector<int> > &veca, string lcs_str) {
//注意这里形参lcs_str不可以为引用，这里需要每次调用lcs_str都重新生成一个对象
	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			lcs_str = str1[i - 1] + lcs_str; //逆向存放
			--i;
			--j;
		}
		else {
			if (veca[i - 1][j] > veca[i][j - 1]) //向左走
				--i;
			else if (veca[i - 1][j] < veca[i][j - 1]) //向上走
				--j;
			else { //此时向上向右均为LCS的元素
				PrintAllLCS(str1, str2, i - 1, j, veca, lcs_str);
				PrintAllLCS(str1, str2, i, j - 1, veca, lcs_str);
				return;
			}
		}
	}
	cout << "   " << lcs_str << endl;
	all_lcs.insert(lcs_str);
}
int main() {
	string input;
	getline(cin, input);
	stringstream ss(input);
	string str1, str2;
	ss >> str1;
	ss >> str2;
	//将veca初始化为一个二维数组,其行列值分别为str1和str2的长度加1
	//二维数组veca记录的是两个字符串Xi和Yj的LCS长度
	vector<vector<int> > veca(str1.length() + 1, vector<int>(str2.length() + 1));
	cout << LCS_length(str1, str2, veca) << endl;

	string lcs_str;
	PrintAllLCS(str1, str2, str1.length(), str2.length(), veca, lcs_str);
	cout << "Print all lcs" << endl;
	set<string>::iterator iter = all_lcs.begin();
	while (iter != all_lcs.end()) {
		cout << *iter++ << endl;
	}
	return 0;
}
