#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
vector<long double> y;
vector<long double> x;

long double shoe(){
	long double sum1=0;
	
	for (int i = 0; i < n; ++i) {
		sum1 += y[i] * x[(i + 1) % n];
		sum1 -= x[i] * y[(i + 1) % n];
	}
	sum1 = abs(sum1);
	sum1 /= 2;
	return sum1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long double tmp1; long double tmp2;
		scanf("%Lf %Lf", &tmp1, &tmp2);
		y.push_back(tmp1);
		x.push_back(tmp2);
	}
	printf("%0.1Lf", shoe());
}