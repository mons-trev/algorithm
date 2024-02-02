#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

long long a, b;

bool isprime[10000001];

void era() {
	for (long long i = 2; i*i < 10000001; ++i) {
		if (!isprime[i]) {
			for (int j= i * 2; j < 10000001; j += i) {
				isprime[j] = true;
			}
		}
	}
}

long long check() {
	long long ans = 0;
	for (long long i = 2; i < 10000001; ++i) {
		if (!isprime[i]) {
			for (long long j = i; j <= b/i;) {
				j *= i;
				if (j >= a && j<=b) {
					ans++;
				}
			}
		}
	}
	return ans;
}


int main() {

	scanf("%lld %lld", &a, &b);

	
	era();

	long long ans = check();

	printf("%lld", ans);

	return 0;
}