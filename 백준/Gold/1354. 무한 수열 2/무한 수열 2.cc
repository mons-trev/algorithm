#include<iostream>
#include<map>

using namespace std;

long long n;
long long p,q,x,y;
map<long long,long long> m;

long long sol(long long tmp) {
	if (tmp <= 0) { // 초기 조건
		return 1;
	}
	if (m.find(tmp) != m.end()) { // 맵을 dp로 쓰기
		return m[tmp];
	}
	long long a = sol((tmp / p) - x);
	long long b = sol((tmp / q) - y);
	m.insert({ tmp, a + b });
	return m[tmp];
}

int main() {
	cin >> n;
	cin >> p >> q >> x >> y;
	cout << sol(n);
	
}