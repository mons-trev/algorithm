#include <string>
#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;

long long dp[5001] = {0,};

int solution(int n) {
    dp[2]=3;
    dp[4]=11;
    if(n%2!=0) return 0;
    for(int i=6; i<=n; ++i) {
        if(i%2==0) {
            for(int j=2; j<i; ++j) {
                if(j%2!=0) continue;
                if(j==i-2) {
                    dp[i]+=3*(dp[j])%mod;
                    dp[i]%=mod;
                }
                else {
                    dp[i]+=2*(dp[j])%mod;
                    dp[i]%=mod;
                }
            }
            dp[i]+=2;
            dp[i]%=mod;
        }
    }
    return dp[n]%mod;
}