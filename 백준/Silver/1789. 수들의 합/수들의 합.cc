#include<iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum =0;
    int cnt =0;
    for(int i=1; i<=n; ++i) {
        sum+=i;
        cnt++;
        if(sum>n) {
            cnt--;
            break;
        }
    }
    cout << cnt;
}