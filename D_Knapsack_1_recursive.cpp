/*--------------------------------------------SCHRODINGER----------------------------------------------------*/




#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,w;
vector<int>weights,value;
vector<vector<int>>dp;


int solve(int i,int remWeight){

    if(i>=n){
        return 0;
    }
    if(dp[i][remWeight]!=-1){
        return dp[i][remWeight];
    }

    int ans=0;
    if(remWeight>=weights[i]){
        ans=value[i]+solve(i+1,remWeight-weights[i]);
    }
    ans=max(ans,solve(i+1,remWeight));

    return dp[i][remWeight]=ans;
    
}


void Schrodinger(){

    cin>>n>>w;

    weights.assign(n,0);
    value.assign(n,0);
    dp.assign(n,vector<int>(w+1,-1));

    for(int i=0;i<n;i++){

        cin>>weights[i]>>value[i];
    }

    cout<<solve(0,w);

}


int32_t main(){

    Schrodinger();

}