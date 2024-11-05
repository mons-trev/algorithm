#include<iostream>
#include<vector>

using namespace std;
// 가위, 바위, 보
// 짐, 이김
// 1,2 / 2,3 / 3,1
int main() {
    int n;
    cin >> n;
    int x = -1;
    vector<int> a;
    vector<int> b;
    for(int i=0; i<n; ++i) {
        int t; cin >> t;
        a.push_back(t);
    }
    for(int i=0; i<n; ++i) {
        int t; cin >> t;
        b.push_back(t);
    }
    
    int m;
    if(a[0]%3 +1 == b[0]) { // a가 이기는 경우
        m=1; // 1팀의 1번이 이김
    }
    else {
        m=2; // 2팀의 1번이 이김
    }

    int ans = 1;
    int cnt = 1;
    
    for(int i=1; i<n; ++i) {
        int win = 0;
        if(a[i]%3+1 == b[i]) { // a가 이기는 경우
            win =1;
        }
        else if(b[i]%3+1 == a[i]) { // b가 이기는 경우
            win =2;
        }
        else {
            win = -1;
        }
        
        if(win == m) {
            cnt++;
        }
        else{
            ans = max(ans, cnt);
            m = m%2 + 1;
            cnt = 1;
        }
    }
    
    ans = max(ans, cnt);
    
    cout << ans;
}