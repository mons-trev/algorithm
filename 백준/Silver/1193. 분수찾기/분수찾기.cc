#include<iostream>
#include<queue>
#include<cstring> // memset

using namespace std;


int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << '/' << 1;
		return 0;
	}
	int lev = 1;

	for (int i = 2; i <= 10000000; ++i) {

		if (i * (i + 1) / 2 >= n && (i-1)* i / 2 < n) {
			lev = i;
			break;
		}

	}


	if (lev % 2 == 0) {
		int y = 1;
		int x = lev;
		int it = lev * (lev - 1) / 2 + 1;
		while (it++ < n) {
			y++;
			x--;
		}
		cout << y << '/' << x;
	}

	else {
		int x = 1;
		int y = lev;
		int it = lev * (lev - 1) / 2 + 1;
		while (it++ < n) {
			y--;
			x++;
		}

		cout << y << '/' << x;
	}
}