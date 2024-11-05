#include<iostream>
#include<string>
#define mod 1000000009

using namespace std;
long long dp[3][33334] = {0, };

void b(int full, int n, int sum) {
    if (full == n) {
        dp[sum % 3][full] += 1;
        return;
    }
    for (int i = 0; i <= 2; ++i) {
        if (n == 0 && i == 0) {
            continue;
        }
        b(full, n + 1, sum + i);
    }
}

int main() {
    int n;
    cin >> n;
    b(2, 0, 0); // [][2] 채움

    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                dp[j][i] = (dp[j][i] + (dp[k][i - 1])) % mod;
            }
        }
    }
    
    cout << dp[0][n];
}