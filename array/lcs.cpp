#include <iostream>
#include <vector>
//#include <math>

using namespace std;
int lcsLength(const string &str1, const string &str2, vector<vector<int>> &veca)
{
    for (auto i = 0; i <= str1.length(); i++)
        veca[i][0] = 0;
    for (auto i = 0; i <= str2.length(); i++)
        veca[0][i] = 0;
    int i, j;
    for (i = 1; i <= str1.length(); i++)
    {

        for (j = 1; j <= str2.length(); j++)
        {
            //std::cout << "i = "<< i << ", j = " << j << ", s1: " << str1[i-1] << ", s2: " << str2[j-1] << std::endl;
            if (str1[i-1] == str2[j-1])
            {
                veca[i][j] = veca[i - 1][j - 1] + 1;
            }
            else
            {
                veca[i][j] = max(veca[i - 1][j], veca[i][j - 1]);
            }
        }
    }
    //cout << "lcs length is " << veca[i-1][j-1] << endl;
    return veca[str1.length()][str2.length()];
}

int main()
{
    string s1 = "hish";
    string s2 = "hiish";
    vector<vector<int>> veca(s1.length() + 1, vector<int>(s2.length() + 1));
    auto len = lcsLength(s1, s2, veca);
    cout << "return len " << len << endl;
}
