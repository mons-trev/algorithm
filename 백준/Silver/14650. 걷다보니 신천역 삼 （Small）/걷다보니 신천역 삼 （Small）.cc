#include<iostream>
#include<string>

using namespace std;

int b(int full, int n, int sum) {
    if (full == n) {
        if (sum % 3 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int ret = 0;

    for (int i = 0; i <= 2; ++i) {
        if (n == 0 && i == 0) { // 0번째 채워야 되는데, 0이면
            continue;
        }
        ret += b(full, n + 1, sum + i);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;

 
    cnt += b(n, 0, 0);

    cout << cnt;
}