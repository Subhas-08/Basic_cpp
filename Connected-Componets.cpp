#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
void dfs(int s,int vis[],vector<vector<int>>&v)
{
    vis[s]=1;
    for(auto it:v[s])
    {
        if(vis[it]==0)
        {
            dfs(it,vis,v);
        }
    }
}
int main()
{   
     cin>>n>>m;  vector<vector<int>>v(n+10); int vis[n+10]; 
     memset(vis,0,sizeof(vis));
     for(int i=1;i<=m;i++)
     {
         cin>>x>>y; 
         v[x].push_back(y); v[y].push_back(x);
     }
     int count=0;
     for(int i=1;i<=n;i++)
     {
         if(vis[i]==0)
         {
             dfs(i,vis,v); 
             count++;
         }
     }
     cout<<count;
}
