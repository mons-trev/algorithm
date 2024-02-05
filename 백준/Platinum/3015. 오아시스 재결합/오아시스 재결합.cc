#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

long long list[500000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long a;
		scanf("%lld", &a);
		list[i] = a;
	}
	stack<pair<long long, long long>> s;
	s.push({ list[0],1 });
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		long long x = list[i];
		int same = 1;

		while (!s.empty()) {
			
			if (s.top().first == x) {
				same+=s.top().second;
				ans+=s.top().second;
				s.pop();
			}
			else if (s.top().first<x){
				ans += s.top().second;
				s.pop();
			}
			else {
				break;
			}

		}
		if (!s.empty()) {
			ans++;
		}
		s.push({ x,same });
		//cout << x << " " << ans << endl;
	}
	printf("%lld", ans);
}