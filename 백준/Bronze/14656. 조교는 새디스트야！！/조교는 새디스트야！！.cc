#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=1; i<=n; ++i) {
        int t;
        cin >> t;
        if(i!=t) {
            cnt ++;
        }
    }
    cout << cnt;
}