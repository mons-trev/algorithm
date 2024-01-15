#include<iostream>

using namespace std;

long long n;
long long k, m;
int b[2001][2001];

int main() {
	cin >> n >> k >> m;

	for (int i = 0; i < m; ++i) { //n
		b[i][0] = 1;
		for (int j = 1; j <= i; ++j) { //k
			b[i][j] = (b[i - 1][j - 1] + b[i - 1][j]) % m; // 포함하거나 안하거나
		}
	}
	int ret = 1;

	while (n || k) {
		ret *= b[n % m][k % m];
		n /= m;
		k /= m;
		ret %= m;
	}
	cout << ret;
}