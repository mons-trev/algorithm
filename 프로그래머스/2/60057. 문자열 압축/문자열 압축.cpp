#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    if(s.size()==1) {
        return 1;
    }
    int answer=1001;
    string ans="";
    
    for(int i=1; i<=s.size()/2; ++i) {
        string prev=s.substr(0,i); // 0번째부터 i만큼 자른다
        int cnt=1;
        string per="";
        for(int j=i; j<s.size(); j+=i) {
            string now = s.substr(j, i);
            if(prev==now) {
                cnt++;
            }
            else { // 다르면 이전거 붙여줘야 함
                if(cnt==1) {
                    per+=prev;
                }
                else {
                    per+=(to_string(cnt)+prev);
                    cnt=1;
                }
            }
            prev=now;
        }
        if(cnt==1) {
            per+=prev;
        }
        else {
            per+=(to_string(cnt)+prev);
        }
        if(per.size()<answer) {
            answer=per.size();
            ans=per;
        }
    }
    return answer;
}