#include <iostream>
#include <sstream>
#include <map>

using namespace std;

template <class T>
class mystack {
    private:
    T data[100];
    int current;
    int height;

    public:
    mystack() {
        height = 100;
        current = 0;
    }
    bool push(T d) {
        //std::cout << "push " << d << endl;
        if (current == height) 
            return false;
        data[current] = d;
        current++;
        return true;
    }
    T pop() {
        if (current == 0)
            return "";
        T d = data[--current];
        return d;
    }
    T top() {
        if (current == 0)
            return "";
        return data[current-1];
    }
};

int main() {
    mystack<string> ms;
	string input;
	//getline(cin, input);
	//stringstream ss(input);
    /*
    while (1) {
	    string str;
        ss >> str;
        if (str == "quit")
            break;
        ms.push(str);
    }
    */
   ms.push("1234");
   ms.push("abcd");
   ms.push("AAA");
    cout << "pop all data:" << endl;
    string str;
    cout << "top " << ms.top() << endl;
    while (1) {
        str = ms.pop();
        if (str.length() == 0)
            break;
        cout << "out: " << str << endl;
    }
}