//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <iostream>
#include <string>

using namespace std;
int main() {
	string ans="";
	string s;
	cin >> s;
	if(s[0]=='1') {
		ans+="1";
	}
	char prev=s[0];
	int cnt=1;
	for(int i=1; i<s.size(); ++i) {
		if(prev==s[i]) {
			cnt++;
		}
		else {
			char a='A'+cnt-1;
			ans+=a;
			prev=s[i];
			cnt=1;
		}
	}
	ans+='A'+cnt-1;
	cout << ans;
}