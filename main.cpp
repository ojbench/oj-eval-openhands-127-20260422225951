#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> b;
    b.reserve(n+2);
    b.push_back(1);
    for(int i=0;i<n;i++) b.push_back(a[i]);
    b.push_back(1);
    int m = n+2;
    vector<vector<unsigned long long>> dp(m, vector<unsigned long long>(m, 0));
    for(int len=2; len<m; ++len){
        for(int i=0; i+len<m; ++i){
            int j = i+len;
            unsigned long long best = 0ULL;
            unsigned long long bi = (unsigned long long)b[i];
            unsigned long long bj = (unsigned long long)b[j];
            for(int k=i+1; k<j; ++k){
                unsigned long long val = dp[i][k] + dp[k][j] + bi * (unsigned long long)b[k] * bj;
                if(val > best) best = val;
            }
            dp[i][j] = best;
        }
    }
    cout<< dp[0][m-1] <<"\n";
    return 0;
}
