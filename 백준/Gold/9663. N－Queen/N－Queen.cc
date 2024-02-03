#include<iostream>

using namespace std;

int n;

bool vcol[15] = { false, };
bool vrd[30] = { false, };
bool vld[31] = { false, };
int ans = 0;

void bt(int idx) {
	if (idx >= n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (vcol[i] || vld[(idx-i)+15] || vrd[idx+i]) continue;
		else {
			vcol[i] = true;
			vld[idx - i + 15] = true;
			vrd[idx + i]=true;
			bt(idx + 1);
			vcol[i] = false;
			vld[idx - i+15] = false;
			vrd[idx + i] = false;
		}
	}
	return;
}

int main() {
	cin >> n;
	bt(0);
	cout << ans;
}