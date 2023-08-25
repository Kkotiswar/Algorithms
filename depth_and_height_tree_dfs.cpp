#include<bits/stdc++.h>

using namespace std;

vector<int>height(N),depth(N);

int dfs(vector<vector<int>>&adj, int index,vector<int>&vis,int par=0) {
    //take action on entering
    vis[index] = 1;

    for(auto x:adj[index]) {
        //take action on child before entering child
            if(x == par)continue;
            depth[x] = depth[index] = 1;
            dfs(adj,x,vis);
            height[x] = max(height[x],height[index]) + 1;
         //take action on child after entering child
    }

    //take action on vertex before leaving the vertex
}

int main() {
    int m,n;
    cin>>n>>m;
    vector<vector<int>>adj(n));
    for(int x=0;x<m;x++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n,0);
    cout<<solve(adj,0,vis)
}