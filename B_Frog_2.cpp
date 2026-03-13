/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long 

void Schrodinger(){

    int n,k;
    cin>>n>>k;

    vector<int>stones(n);

    for(int i=0;i<n;i++){
        cin>>stones[i];
    }

    vector<int>dp(n,1e18);
    dp[0]=0;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+abs(stones[i]-stones[i-j]));
            }
        }
    }

    cout<<dp[n-1]<<endl;

}

int32_t main(){
    Schrodinger();
}