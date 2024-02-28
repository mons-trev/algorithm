//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <iostream>
using namespace std;
int n[9];
int ans[7];

bool back(int idx, int cnt, int sum) {
	//cout << idx << " " << cnt << " " << sum << "\n";
	if(cnt==7 && sum==100) {
		return true;
	}
	if(cnt>7) {
		return false;
	}
	for(int i=idx+1; i<9; ++i) {
		bool ret= back(i, cnt+1, sum+n[i]);
		ans[cnt]=n[i];
		if(ret) {
			return true;
		}
	}
	return false;
}

int main() {
	for(int i=0; i<9; ++i) {
		cin >> n[i];
	}
	back(-1,0, 0);
	for(int i=0; i<7; ++i) {
		cout << ans[i] << " ";
	}
}