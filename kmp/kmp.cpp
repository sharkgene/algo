#include <iostream>
#include <vector>

using namespace std;
int ViolenMatch(string &base, string &pattern)
{
    int i = 0, j = 0;
    while (i < base.length() && j < pattern.length()) {
        if (base[i] == pattern[j]){
            i++;
            j++;
        }else {
            i -= (j-1);
            j = 0;
        }
    }
    if (j == pattern.length()) {
        cout << "Match pos is " << i-j << endl;
        return i-j;
    }else 
        cout << "Not Match" << endl;
        return -1;
}

void GetNext(string p,vector<int> &next)
{
	int pLen = p.length();
 //   next.push_back(-1);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k]) 
		{
			++k;
			++j;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
		}
		else 
		{
			k = next[k];
		}
	}
}


int kmp(string &base, string &pattern) {
    int i, j = 0;
    vector<int> next(pattern.length());
    GetNext(pattern, next);
    for (auto n : next)
        cout << "next:" << n << endl;

    for (i = 0; i < base.length() && j < int(pattern.length()); ){
        //cout << "i = " << i << ", j = " << j << ", base " << base[i] << ", pattern " << pattern[j] << endl;
        if ( j == -1 || base[i] == pattern[j]) {
            i++;
            j++;
            continue;
        }
        j = next[j];
    }
    if (j == pattern.length()) {
        cout << "Match pos is " << i-j << endl;
        return i-j;
    }else 
        cout << "Not Match" << endl;
        return -1;
}

void get_bmB(const string& T, vector<int>& bmB) {
    int tLen = T.size();

    for (int i = 0; i < bmB.size(); ++i) 
        bmB[i] = tLen;
    for (int i = 0; i < tLen; ++i)
        bmB[T[i]] = tLen - 1 - i;
}

void get_bmG(const string& T, vector<int>& bmG){

}

int BM(const string& S, const string& T, vector<int>& bmG, vector<int>& bmB) 
{
    int sLen = S.length() - T.length();
    int tLen = T.length();
    int i = 0;

    get_bmB(T, bmB);
    get_bmG(T, bmG);

    while (i <= sLen) {
        int j = tLen - 1;
        for (; j > -1 && S[i+j] == T[j]; --j);
        //匹配成功
        if (j == -1)
            return i;
        // 选择好后缀与坏字符中移位最大者， tLen - 1 -j 表示的是该字符距字符串尾部的距离， bmB[S[i+j]]表示的是该字符出现在T中的最右位置距字符串尾部的距离
        i += max(bmG[j], bmB[S[i+j]] - (tLen - 1 -j));
    }
    return -1;
}

int getMoveLength(const string& T, vector<int>& moveLength) {
    int tLen = T.size();
    for (int i = 0; i < moveLength.size(); ++i)
        moveLength[i] = tLen + 1;

    for (int i = 0; i < tLen; ++i)
        moveLength[T[i]] = tLen - i;
    return 0;
}

int sunday(const string& S, const string& T) {
    vector<int> moveLength(1024);
    int tLen = T.size();
    int sLen = S.size();
    int i = 0;
    getMoveLength(T, moveLength);
    while (i < sLen) {
        int j = 0;
        for (; j < tLen && i+j < sLen && S[i+j] == T[j]; ++j);
        cout << "i = " << i << ", j = " << j ;

        if (j >= tLen) 
            return i;
        if (i + tLen >= sLen)
            return -1;
        //cout << ", S[i+tLen] = " << hex << S[i+tLen] << endl;
        //printf(", %02x\n", S.c_str()[i+tLen]);
        i += moveLength[S[i+tLen]];
    }
    return -1;

}

int main(int argc, char **argv) {
    string base, pattern;
    //cin >> base >> pattern;
    base = "测试机会中";
    pattern = "会中";
    //pattern = "机会";
    cout << hex << 192 << endl;
    for (auto i = 0; i < base.length(); i++){
        printf("%x,", base[i]);
    }
    cout << endl;
    ViolenMatch(base, pattern);
    kmp(base, pattern);
    cout << "sunday = " << sunday(base, pattern) <<endl;

}