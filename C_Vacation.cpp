/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}


void Schrodinger(){

    int n;
    cin>>n;

    vector<vector<int>>days(n,vector<int>(3));

    for(int i=0;i<n;i++){
        cin>>days[i][0]>>days[i][1]>>days[i][2];
    }

    vector<vector<int>>dp(n,vector<int>(3,-1));

    dp[0][0]=days[0][0];
    dp[0][1]=days[0][1];
    dp[0][2]=days[0][2];

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k){
                    dp[i][j]=max(dp[i][j],days[i][j]+dp[i-1][k]);
                }
            }
        }
    }

    /*
        HERE ALSO THE CURRENT STATE DEPENDS ONLY ON THE PREV STATE SO 
        IT CAN BE FURTHER OPTIMIZED BY USING JUST PAIRS OF 3 VARIABLES 
        ANS SWAPPING THEM
    */


    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;


}

int32_t main(){

    Schrodinger();

}