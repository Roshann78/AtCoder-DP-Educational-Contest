/*--------------------------------------------SCHRODINGER----------------------------------------------------*/




#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,w;
vector<int>weights,value;
vector<vector<int>>dp;

// TOO GOOD QUES
// NO RELATION WITH DP
// JUST A GOOD WAY OF THINKING WITH THE HELP OF CONSTRAINTS

int solve(int i,int remVal){
    
    if(remVal==0){
        return 0;
    }
    if(i>=n){
        return 1e18;
    }

    if(dp[i][remVal]!=-1){
        return dp[i][remVal];
    }
    int ans=solve(i+1,remVal);
    
    if(remVal-value[i]>=0){

        ans=min(weights[i]+solve(i+1,remVal-value[i]),ans);
    }
    

    return dp[i][remVal]=ans;
    
    
}


void Schrodinger(){

    cin>>n>>w;

    weights.assign(n,0);
    value.assign(n,0);
    dp.assign(n ,vector<int>(1e5+1,-1));

    int totalVal=0;
    for(int i=0;i<n;i++){

        cin>>weights[i]>>value[i];
        totalVal+=value[i];

    }

    solve(0,totalVal);

    int ans=0;
    
    for(int i=0;i<1e5+1;i++){

        if(solve(0,i)<=w){

            ans=max(ans,i);
        }
    }

    cout<<ans<<endl;

}


int32_t main(){

    Schrodinger();

}