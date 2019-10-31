#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void dijstra(int s,vector<pair<int,int>>gr[],int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    vector<int>used(n+1);
    dist[s]=0;
    used[s]=1;
    pq.push({0,s});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto v : gr[u.second]){
            if(dist[v.first]>dist[u.second]+v.second&&!used[v.first]){
                dist[v.first]=dist[u.second]+v.second;
                pq.push({v.second,v.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=s){
            if(dist[i]!=INT_MAX)
                cout<<dist[i]<<" ";
            else
                cout<<"-1 ";
        }
    }
    cout<<endl;
}
int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>gr[n+1];
        while(k--){
            int u,v,w;
            cin>>u>>v>>w;
            gr[u].push_back({v,w});
            gr[v].push_back({u,w});
        }
        int s;
        cin>>s;
        dijstra(s,gr,n);
    }
}