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
        if (current == height) 
            return false;
        data[current] = d;
        current++;
        return true;
    }
    T *pop(T d) {
        if (current == 0)
            return nullptr;
        current--;
        return data[current];
    }
    T *top() {
        return data[current];
    }
};


map<string, int> cals;

int cal(const string &str) {
    mystack<int> ms;
    mystack<string> sl;
    for (auto i = 0; i < str.length(); i++) {
        auto iter = cals.find(str.substr(i, 1));
        if (iter == cals.end()) {
            ms.push(stoi(str.substr(i, 1)));
        } else {
            sl.push(str.substr(i,1));
        }
    }

}

int main() {
    cals.insert(pair<string, int>("+", 1));
    cals.insert(pair<string, int>("-", 1));
    cals.insert(pair<string, int>("*", 2));
    cals.insert(pair<string, int>("/", 2));
}