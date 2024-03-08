#include <string>
#include <vector>
#include <iostream>
#define mod 1000000007
using namespace std;

long long dp[5001];
int solution(int n) {
    if(n%2==1) return 0;
    dp[2]=3;
    dp[4]= 2+dp[2]*3; // 11
    long long cur=2+2*dp[2];
    for(int i=6; i<=n; i++) {
        if(i%2!=0) continue;
        dp[i]=(cur+3*dp[i-2])%mod;
        cur+=(2*dp[i-2])%mod;
        cur%=mod;
        //cout << dp[i] << endl;
    }
    
    return dp[n];
}