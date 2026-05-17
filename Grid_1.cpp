/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M=1e9+7;



void Schrodinger(){
    
    int h,w;
    cin>>h>>w;

    vector<vector<int>>grid(h,vector<int>(w));

    vector<vector<int>>dp(h,vector<int>(w,0));
    dp[0][0]=1;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            grid[i][j]=(c=='#');    //REPLACING # WITH 1 AND . WITH 0 FOR SIMPLICITY
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){

            if(grid[i][j]){
                continue;       //SKIP WALLS
            }

            if(i>0){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
            }
            if(j>0){
                dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
            }
        }
    }

    cout<<dp[h-1][w-1]<<endl;

}


int32_t main(){

    Schrodinger();
}
