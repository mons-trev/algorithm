#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, m;
vector<int> list;
int check[2000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
	}

	int c;
	int a = 9 * m;
	if (a % 10 == 0) {
		c = a / 10;
	}
	else {
		c = (a / 10) + 1;
	}
	//cout << c << endl;

	for (int i = 0; i < m; ++i) {
		int tar = list[i];
		check[tar]++;
		if (check[tar] >= c) {
			cout << "YES";
			return 0;
		}
	}

	for (int i = 1; i + m <= n; ++i) {
		//cout << i << " " << i + m - 1 << "\n";
		check[list[i - 1]]--;
		check[list[i+m-1]]++;
		if (check[list[i + m - 1]] >= c) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}