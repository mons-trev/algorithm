#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int v[10000001];
vector<int> ans;

void min() {
	for (int i = 2; i < sqrt(10000001); ++i) {
		if (v[i] == i) {
			for (int j = i * i; j < 10000001; j+=i) {
				if (v[j] == j) {
					v[j] = i;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10000001; ++i) {
		v[i] = i; // 원래 자신을 가리키도록 초기화
	}
	min();
	while (n > 1) {
		printf("%d\n", v[n]);
		n /= v[n];
	}
}