#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

double tl[100001];
int N;
double L;
int Q;
int ql[500001];
double suml[500001];

int main() {
	cin >> N;
	cout << fixed;
	cout.precision(2);


	for (int i = 1; i <= N; ++i) {
		cin >> tl[i];
		if (i == 1) suml[i] = tl[i];
		else {
			suml[i] = suml[i - 1] + tl[i];
		}
	}
	cin >> L >> Q;
	double display_mid = L / 2.0;

	for (int i = 0; i < Q; ++i) {
		cin >> ql[i];
	}
	for (int i = 0; i < Q; ++i) {
		int tab = ql[i]; //누르는 탭의 번호
		double left, right;
		if (tab == 1) { // 탭이 하나보다 많은데 tab이 맨 첫번째 것이 주어진 경우
			left = tl[1] / 2.0;
			right = suml[N] - left;
		}
		else { // 탭이 하나보다 많은데 중간 탭이 주어진 경우
			left = suml[tab - 1] + tl[tab] / 2.0;
			right = suml[N] - left;
		}

		if (suml[N] <= L) {//항상 맨 왼쪽을 가리키는 경우
			cout << "0.00\n";
		}
		else if (left <= display_mid) {
			cout << "0.00\n";
		}
		else if (right <= display_mid) {
			cout.precision(2);

			cout << suml[N] - L << "\n";
		}
		else {
			cout.precision(2);

			cout<< (left - display_mid) << "\n";
		}
	}

}

