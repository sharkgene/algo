#include <iostream>
#include <regex>

using namespace std;

int main() {
    //string text = "2018-7-12";
    //regex  pattern("[0-9]{4}-[0-9]{1,2}-[0-9]{1,2}");
	//regex pattern("([0-9]{4})-((?:[0-9]{1,2})|(?:Jan|Feb|Mar))-([0-9]{1,2})");
    string text = "23+2*2018-7-12";
	regex pattern("([0-9]{4})-((?:[0-9]{1,2})|(?:Jan|Feb|Mar))-([0-9]{1,2})");

	cout << stoi("234") << endl;
	cout << text.substr(1,1) << endl;
	cout << stoi(text.substr(1,1)) << endl;
    smatch results;
    if ( regex_match(text, results, pattern) ) {
        smatch::iterator it = results.begin();
        int i = 0;
        for(; it != results.end(); ++it, ++i)
            cout<<i<<": "<<*it<<endl;
    } else {
        cout << "match failed: " <<text<< endl;
    }
    return 0;
}
