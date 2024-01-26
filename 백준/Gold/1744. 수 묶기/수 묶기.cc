#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

short n;
vector<int> m;
vector<int> p;
short one = 0;
short zero=0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {
			if (tmp == 1) {
				one++;
			}
			else {
				p.push_back(tmp);
			}
		}
		else if (tmp < 0) {
			m.push_back(tmp);
		}
		else {
			zero++;
		}
	}
	sort(m.begin(), m.end());
	sort(p.begin(), p.end());
	
	int sum = 0;

	for (int i = 0; i < m.size(); ) {
		if (i + 1 < m.size()) {
			sum += m[i] * m[i + 1];
		}
		i += 2;
	}
	if (m.size() % 2 != 0) {
		if (zero == 0) { // 0이 있다면 상쇄시키기
			sum += m[m.size() - 1];
		}
	}
	for (int i = p.size()-1; i >= 0; ) {
		if (i - 1 >= 0) {
			sum += p[i] * p[i - 1];
		}
		i -= 2;
	}
	if (p.size() % 2 != 0) {
		sum += p[0];
	}
	sum += one;
	printf("%d", sum);
}