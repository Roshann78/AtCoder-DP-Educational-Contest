/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long


int n,w;
vector<int>weights,value;
vector<vector<int>>dp;

void Schrodinger(){

    cin>>n>>w;

    weights.assign(n,0);
    value.assign(n,0);
    dp.assign(n,vector<int>(w+1,0));

    for(int i=0;i<n;i++){

        cin>>weights[i]>>value[i];
    }


    for(int i=weights[0];i<=w;i++){
        dp[0][i]=value[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=dp[i-1][j];
            if(weights[i]<=j){
                dp[i][j]=max(dp[i][j],value[i]+dp[i-1][j-weights[i]]);
            }
        }
    }

    cout<<dp[n-1][w];
    
}

int32_t main(){

    Schrodinger();

}