/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

void Schrodinger(){

    string s,t;
    cin>>s>>t;

    int n1=s.size(),n2=t.size();

    vector<vector<int>>dp(n1,vector<int>(n2,0));

    dp[0][0]=(s[0]==t[0]);

    for(int i=1;i<n2;i++){
        
        dp[0][i]=max(dp[0][i-1],(s[0]==t[i])*1LL);
    }

    for(int i=1;i<n1;i++){

        dp[i][0]=max(dp[i-1][0],(s[i]==t[0])*1LL);
    }.

    for(int i=1;i<n1;i++){
        for(int j=1;j<n2;j++){

            if(s[i]==t[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                continue;
            }

            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string ans="";

    int i=n1-1,j=n2-1;

    while(i>=0 && j>=0){

        if(s[i]==t[j]){

            ans=s[i]+ans;
            i--;j--;
            continue;
        }
        
        int check1=0,check2=0;
        if(i>0){
            check1=dp[i-1][j];
        }
        if(j>0){
            check2=dp[i][j-1];
        }

        if(check1>check2){

            i--;
            continue;
        }

        j--;

    }

    cout<<ans<<endl;

}


int32_t main(){

    Schrodinger();

}