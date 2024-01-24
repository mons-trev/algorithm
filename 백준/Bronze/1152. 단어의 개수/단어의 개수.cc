#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	stack <int> st;
	st.push(-1);
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			if (st.size() > 0) {
				if (st.top() + 1 != i) {
					ans++;
				}
				st.pop();
				st.push(i);
			}
		}
	}
	if (st.size() > 0 && s[s.size()-1]!=' ') ans++;
	cout << ans;
}