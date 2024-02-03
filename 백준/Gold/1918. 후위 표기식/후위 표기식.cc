#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> ans;
	stack<char> tmp;

	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c >= 'A' && c<='Z') {
			ans.push(c);
		}
		else {
			switch (c) {
				case '(':
					tmp.push(c);
					break;
				case '*':
					if (tmp.size() > 0) {
						while (!tmp.empty()) {
							if (tmp.top() == '*' || tmp.top() == '/') {
								ans.push(tmp.top());
								tmp.pop();
							}
							else {
								break;
							}
						}

					}
					tmp.push(c);
					break;
				case '/':
					if (tmp.size() > 0) {
						while (!tmp.empty()) {
							if (tmp.top() == '*' || tmp.top() == '/') {
								ans.push(tmp.top());
								tmp.pop();
							}
							else {
								break;
							}
						}

					}
					tmp.push(c);
					break;
				case '+' :
					if (tmp.size() > 0) {
							while (!tmp.empty()) {
								if (tmp.top() == '(') {
									break;
								}
								//if (tmp.top() == '+' || tmp.top() == '-') break;
								ans.push(tmp.top());
								tmp.pop();
							}
						
					}
					tmp.push(c);
					break;
				case '-':
					if (tmp.size() > 0) {
							while (!tmp.empty()) {
								if (tmp.top() == '(') {
									break;
								}
								//if (tmp.top() == '+' || tmp.top() == '-') break;
								ans.push(tmp.top());
								tmp.pop();
							}
						
					}
					tmp.push(c);
					break;
				case ')':
					while (!tmp.empty()) {
						if (tmp.top() == '(') {
							tmp.pop();
							break;
						}
						ans.push(tmp.top());
						tmp.pop();
					}
					break;

			}
		}
	}

	while (!tmp.empty()) {
		ans.push(tmp.top());
		tmp.pop();
	}
	string answer = "";
	while (!ans.empty()) {
		answer = ans.top() + answer;
		ans.pop();
	}
	cout << answer;

}