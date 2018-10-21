#include <iostream>

using namespace std;
const int maxn = 10000;
void ArrayJose() {
	bool jose[maxn] = {0};   //设置一个数组来模拟N个人
	int m_count = 0; //记录当前报的数
	int i = 0;  //记录当前遍历的是数组的第几个元素
	int out_count = 0; //记录当前出局的人数
	int n, m;
	cin >> n >> m;
	do 
	{
		++i;
		if (i > n)    //所有人报数完后从头开始报数
			i = 1;
		if (!jose[i])  //若数组元素为0，即这个人没出局
			m_count++;
		if (m_count == m) {  //报数为m的人出局
			m_count = 0;      //重新开始报数
			cout << i << " "; //输出出局人编号
			jose[i] = 1;      //将这个人所在位置标记为出局：1
			out_count++;      //出局人数加1
		}
	} while (out_count != n);
}

int main()
{
	ArrayJose();
}
