#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = INT_MAX;
vector<pair<int,int>> adj[N];
int dis[N];
class cmp{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
void dijkstra(int s){
    // queue<pair<int,int>> q;
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
    pq.push({s,0});
    dis[s] = 0;
    while(!pq.empty()){
        pair<int,int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        if(cost > dis[node]) continue;
        for(pair<int,int> child : adj[node]){
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dis[childNode]){
                dis[childNode] = cost + childCost;
                pq.push({childNode,dis[childNode]});
            }
        }
    }
}
int main()
{
    int n,s,f;
    cin>>n>>s>>f;
    s--;
    f--;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(mat[i][j] > 0){
                adj[i].push_back({j,mat[i][j]});
            }
        }
    }
    
    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }
    dijkstra(s);
    if(dis[f] == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<dis[f]<<endl;
    return 0;
}