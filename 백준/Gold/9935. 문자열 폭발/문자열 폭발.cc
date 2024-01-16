#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<stack>

using namespace std;

int check[37]; // 0으로 초기화

int main() {
	string a; cin >> a;
	string b; cin >> b;

	stack<char> s;
	int pointer = 0;
	for (int i = 0; i < a.size(); ++i) {
		char c = a[i];
		s.push(c);
		if (c == b[b.size() - 1]) { // 맨 마지막 것이라면
			stack<int> tmp;
			for (int j = b.size()-1; j >= 0; --j) {
				if (s.empty()) {
					break;
				}
				else {
					if (s.top() == b[j]) {
						tmp.push(s.top());
						s.pop();
					}
					else {
						break;
					}
				}
			}
			if (tmp.size() != b.size()) {
				while (!tmp.empty()) {
					s.push(tmp.top());
					tmp.pop();
				}
			}
		}
	}
	if (s.size() == 0) {
		cout << "FRULA";
		return 0;
	}
	stack<char> ans;
	while (!s.empty()) {
		char c = s.top();
		s.pop();
		ans.push(c);
	}
	while (!ans.empty()) {
		
		cout << ans.top();
		ans.pop();
	}
}