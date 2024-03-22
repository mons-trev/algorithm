#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 1001;
    
    if(s.size()==1) return 1;
        
    for(int i=1; i<=s.size()/2; ++i) {
        stack<string> st;
        string per="";
        st.push(s.substr(0,i));

        for(int j=i; j<s.size(); j+=(i)) {
            
            string prev=st.top();
            string now = s.substr(j,i);
            if(prev==now) {
                st.push(now);
            }
            else {
                int cnt = 0;
                while(!st.empty()){
                    st.pop();
                    cnt++;
                }
                if(cnt==1) {
                    per+=prev;
                }
                else {
                    per+=to_string(cnt);
                    per+=prev;
                }
                st.push(now);
            }
        }
        int cnt=0;
        string p="";
        while(!st.empty()) {
            p=st.top();
            st.pop();
            cnt++;
        }
        if(cnt==0) {
            continue;
        }
        else if(cnt==1) {
            per+=p;
        }
        else {
            per+=to_string(cnt);
            per+=p;
        }
        if(per.size()<answer) {
            answer=per.size();
        }
    }
    
    return answer;
}