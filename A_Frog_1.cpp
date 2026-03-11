/*--------------------------------------------SCHRODINGER----------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int no_of_stones;
vector<int>stones,dp;

int Solve(int curStone){

    if(curStone<=0)return 0;
    if(dp[curStone]!=-1)return dp[curStone];

    int ans=1e18;
    if(curStone>=2){
        ans=min(ans,Solve(curStone-2)+abs(stones[curStone]-stones[curStone-2]));
    }
    ans=min(ans,Solve(curStone-1)+abs(stones[curStone]-stones[curStone-1]));
    return dp[curStone]=ans;

}

void Schrodinger(){

    cin>>no_of_stones;
    stones.assign(no_of_stones,0);
    dp.assign(no_of_stones,-1);
    for(int stone=0;stone<no_of_stones;stone++){
        cin>>stones[stone];
    }

    cout<<Solve(no_of_stones-1);



}

int32_t main(){

    Schrodinger();

}