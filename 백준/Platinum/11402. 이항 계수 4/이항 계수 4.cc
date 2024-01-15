
#include <iostream>
        
        
          
          #include <vector>
        
        
          
          using namespace std;
        
        
          
          #define ll long long
        
        
          
          #define MAXN 2010
        
        
          
          int binomial[MAXN][MAXN];
        
        
          
          ll N, K, M;
        
        
          
          int main(){
        
        
          
              cin >> N >> K >> M;
        
        
          
              for(int i=0; i<M; i++){
        
        
          
                  binomial[i][0] = 1;
        
        
          
                  for(int j=1; j<=i; j++)
        
        
          
                      binomial[i][j] = (binomial[i-1][j-1] + binomial[i-1][j])%M;
        
        
          
              }
        
        
          
              int ret = 1;
        
        
          
              while(N || K){
        
        
          
                  ret *= binomial[N%M][K%M];
        
        
          
                  N /= M, K /= M;
        
        
          
                  ret %= M;
        
        
          
              }
        
        
          
              cout << ret;
        
        
          
          }
