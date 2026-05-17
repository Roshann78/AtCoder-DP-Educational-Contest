/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int n;
vector<ld>coins;
vector<vector<ld>>dp;

//NICE...

ld solve(int ind,int curHead){

    if(ind>=n){

        if(curHead>n/2){
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[ind][curHead]!=-1){
        return dp[ind][curHead];
    }

    return dp[ind][curHead]=coins[ind]*solve(ind+1,curHead+1)+(1-coins[ind])*solve(ind+1,curHead);

}

void Schrodinger(){
    
    cin>>n;

    coins.assign(n,0);

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    dp.assign(n,vector<ld>(n,-1));

    cout<<fixed<<setprecision(10)<<solve(0,0)<<endl;
}


int32_t main(){

    Schrodinger();
}
