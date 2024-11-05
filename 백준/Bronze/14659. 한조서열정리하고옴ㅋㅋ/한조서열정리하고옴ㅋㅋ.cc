#include<iostream>
#include<stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;
    int cnt = 0;
    int first;
    cin >> first;
    st.push(first);
    int m = first;
    for(int i=1; i<n; ++i) {
        int t; cin >> t;
        if(m>t) {
            st.push(t);
        }
        else {
            int c = 0;
            while(!st.empty()) {
                st.pop();
                c++;
            }
            m=t;
            st.push(t);
            cnt = max(c-1, cnt);
        }
    }
    int c = 0;

    while(!st.empty()) {
        st.pop();
        c++;
    }
    cnt = max(c-1, cnt);
    
    cout << cnt;
}