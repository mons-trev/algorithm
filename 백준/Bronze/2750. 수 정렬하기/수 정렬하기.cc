/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int arr[1001];

int main()
{
    int start = 1;
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> arr[i];
    }
    
    for(int i=1; i<n; ++i) {
        int change_idx = i;
        int min = arr[i];
        for (int j=i+1; j<=n; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                change_idx = j;
            }
        }
        
        int tmp = arr[i];
        arr[i] = arr[change_idx];
        arr[change_idx]=tmp;
    }
    
    // cout << '\n';
    for(int i=1; i<=n; ++i) {
        cout << arr[i] << '\n';
    }
    return 0;
}