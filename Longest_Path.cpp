/*--------------------------------------------SCHRODINGER----------------------------------------------------*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
vector<vector<int>>adj;
vector<int>vis;
stack<int>topo;

//VERY IMP CATEGORY
//NOT EXACTLY DP BUT VERY GOOD USE OF TOPO SORT (KIND OF DP)

void DFS(int node){
    vis[node]=1;

    for(auto neighbor:adj[node]){

        if(!vis[neighbor]){
            DFS(neighbor);
        }
    }

    topo.push(node);

}

void Schrodinger(){

    cin>>n>>m;
    adj.assign(n,vector<int>());
    vis.assign(n,0);

    for(int edge=0;edge<m;edge++){

        int node1,node2;
        cin>>node1>>node2;

        node1--;node2--;
        adj[node1].push_back(node2);
    }

    for(int node=0;node<n;node++){

        if(!vis[node]){
            DFS(node);
        }
    }

    vector<int>dis(n,0);
    int ans=0;

    while(!topo.empty()){

        int node=topo.top();
        topo.pop();

        ans=max(ans,dis[node]);

        for(auto neighbor:adj[node]){

            if(dis[neighbor]<dis[node]+1){

                dis[neighbor]=dis[node]+1;
            }
        }
    }

    cout<<ans<<endl;

}


int32_t main(){

    Schrodinger();
}
