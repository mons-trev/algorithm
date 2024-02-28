#include <iostream>
#include <stack>
using namespace std;
int main() {
	int m;
	cin >> m;
	stack<int> s;
	for(int i=0; i<m; ++i) {
		char a; cin >> a;
		if(a == '+') {
			int h=s.top();
			s.pop();
			int j=s.top();
			s.pop();
			s.push(j+h);
		}
		else if (a == '-') {
			int h=s.top();
			s.pop();
			int j=s.top();
			s.pop();
			s.push(j-h);
		}
		else if(a == '*') {
			int h=s.top();
			s.pop();
			int j=s.top();
			s.pop();
			s.push(j*h);
		}
		else if (a == '/') {
			int h=s.top();
			s.pop();
			int j=s.top();
			s.pop();
			s.push(j/h);
		}
		else {
			s.push(a-'0');
		}
	}
	cout << s.top();
	return 0;
}