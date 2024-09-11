#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int parent[N];
bool ans = false;
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child : v[par]){
            if(vis[child] && parent[par] != child){
                ans = true;
            }
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}