#include<stdio.h>
#include<math.h>
using namespace std;

bool ch[1000001];
int m, n;

void era() {
	int n = sqrt(1000001);
	ch[0] = ch[1] = true;
	for (int i = 2; i < n; ++i) {
		if (!ch[i]) {
			for (int j = i * i; j < 1000001; j = i + j) {
				ch[j] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	//memset(ch, false, 1000001 * sizeof(bool));
	era();

	for (int i = m; i <= n; ++i) {
		if (!ch[i]) {
			printf("%d\n", i);
		}
	}
}