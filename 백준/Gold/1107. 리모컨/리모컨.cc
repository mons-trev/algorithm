#include<iostream>
#include<vector>
#include<string>
using namespace std;

int tar;
string target;
int n;
int minn = 999999;

vector<int> cap; // 누를 수 있는 버튼들
vector<int> list;

void search(string s) { // 재귀를 이용한 완전탐색
	int size = ((int)(s.size()) - (int)(target.size()));
	
	if (s!="" && (stoi(s) > 1000000 || size > 1  || s.size()>6 || (s[0]=='0'&&s.size()>1) )) return;
	if ((s!= "") && s.size() + abs(stoi(s) - tar) < minn) {
		minn = s.size() + abs(stoi(s) - tar);
	}
	//cout << s << endl;
	for (int i = 0; i < cap.size(); ++i) {
		string tmp = s;
		tmp.append(to_string(cap[i]));
		search(tmp);
	}
	
}

int main() {
	cin >> tar;
	target = to_string(tar);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		list.push_back(a);
	}
	int pointer = 0;
	for (int i = 0; i < 10; ++i) {
		bool flag = true;
		for (int j = 0; j < list.size(); ++j) {
			if (list[j] == i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cap.push_back(i);
		}
	}
	
	search("");
	
	cout << min(abs(tar - 100), minn);
}
