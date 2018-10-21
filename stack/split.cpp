#include <iostream>
#include <string>
#include <vector>
 
//字符串分割函数
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
 
int main()
{
    std::string str;
    std::cout<<"Please input str:"<<std::endl;
    //std::cin>>str;
    getline(std::cin,str);
    std::string pattern;
    std::cout<<"Please input pattern:"<<std::endl;
    //std::cin>>pattern;
    getline(std::cin,pattern);//用于获取含空格的字符串
    std::vector<std::string> result=split(str,pattern);
    std::cout<<"The result:"<<std::endl;
    for(int i=0; i<result.size(); i++)
    {
        std::cout<<result[i]<<std::endl;
    }
    
    std::cin.get();
    std::cin.get();
    return 0;
}
