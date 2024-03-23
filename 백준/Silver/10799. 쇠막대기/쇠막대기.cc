#include <iostream>
#include <string>
#include<stack>


using namespace std;

int main() {
	string str;
	stack<int> s;
	getline(cin, str);
	int count = 0;
	int i = 0;
	while (i < str.length()) {
		char ch = str[i];
		if (ch == '(') {
			s.push(i);
		}
		else {
			if (i - s.top() == 1) {
				s.pop();
				count += s.size();
			}
			else {
				count +=1;
				s.pop();
			}
		}
		i++;
	}


	cout << count;
}