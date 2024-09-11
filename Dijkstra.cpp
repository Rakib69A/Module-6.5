#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<vector<int>> adj[N];
void dijkstra(int s, vector<int>& dis){
    queue<pair<int,int>> q;
    q.push({s,0});
    dis[s] = 0;
    while(!q.empty()){
        pair<int,int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        for(auto child : adj[node]){
            int childNode = child[0];
            int childCost = child[1];
            if(cost + childCost < dis[childNode]){
                dis[childNode] = cost + childCost;
                q.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int> dis(n,INT_MAX);
    dijkstra(0,dis);
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
    
    return 0;
}