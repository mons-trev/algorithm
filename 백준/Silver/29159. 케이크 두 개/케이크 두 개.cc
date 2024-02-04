#include<iostream>

using namespace std;
int a[4][2];
int b[4][2];
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	long ax=0, ay=0, bx=0, by=0;
	
	for (int i = 0; i < 4; ++i) {
		cin >> a[i][0] >> a[i][1];
		ax += a[i][0];
		ay += a[i][1];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> b[i][0] >> b[i][1];
		bx += b[i][0];
		by += b[i][1];
	}
	long g = gcd(abs(by - ay), abs(bx - ax));
	long ansx = ((bx - ax) / g);
	long ansy = ((by - ay) / g);
	if (ansy % ansx == 0) {
		cout << ansy / ansx << " ";
	}
	else {
		if (ansy < 0 && ansx > 0 || ansy > 0 && ansx < 0) {
			cout << "-";
		}
		cout << abs(ansy) << "/" << abs(ansx) << " ";
	}
	long long an = ansx * 4;
	long long gg = gcd(abs(ansx * ay - ansy * ax), abs(an));

	long long any = ((ansx * ay - ansy * ax) / gg);
	long long anx = ((an) / gg);
	if (any % anx == 0) {
		cout << any / anx;
	}
	else {
		if (any > 0 && anx < 0 || any < 0 && anx > 0) {
			cout << "-";
		}
		cout << abs(any) << "/" << abs(anx);
	}
}