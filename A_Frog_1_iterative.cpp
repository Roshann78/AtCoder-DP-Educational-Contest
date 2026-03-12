#include<bits/stdc++.h>
using namespace std;

void Schrodinger(){

    int no_of_stones;
    cin>>no_of_stones;
    vector<int>stones(no_of_stones),dp(no_of_stones);

    for(int stone=0;stone<no_of_stones;stone++){
        cin>>stones[stone];
    }

    dp[0]=0;
    dp[1]=abs(stones[1]-stones[0]);

    for(int stone=2;stone<no_of_stones;stone++){
        dp[stone]=min(dp[stone-1]+abs(stones[stone-1]-stones[stone]),dp[stone-2]+abs(stones[stone-2]-stones[stone]));
    }

    /*   CAN BE OPTIMIZED FURTHER AS THE CURRENT STATE DEPENDS ONLY ON THE PREVIOUS TWO STATES 
         SO WE CAN JUST DO VARIABLE SWAPPING  */

    cout<<dp[no_of_stones-1]<<endl;
}

int32_t main(){

    Schrodinger();

}