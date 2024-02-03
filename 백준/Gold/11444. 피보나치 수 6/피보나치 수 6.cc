#include<iostream>
#include<map>

using namespace std;


long long n;
map <long long, long long> m;

long long fibo(long long a) {
	if (m[a]) {
		return m[a];
	}
	else {
		if (a % 2 == 0) {
			return m[a] = ((fibo(a / 2 + 2) * fibo(a / 2)) + (fibo((a / 2) +1) * fibo((a / 2)-1))) % 1000000007;
		}
		else {
			return m[a] = ((fibo((a+3) / 2) * fibo((a+1) / 2)) + (fibo((a+1) / 2) * fibo((a-1) / 2))) % 1000000007;
		}
	}
}

int main() {
	cin >> n;
	m[1] = 0;
	m[2] = 1;
	m[3] = 1;
	m[4] = 2;
	
	cout << fibo(n+1);
}