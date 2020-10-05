#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	
}

void printGraph(vector<int> adj[], int V)
{
	cout<<"normal graph"<<endl;
	for(int i=0;i<V;i++)
	{
		for(auto x:adj[i])
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
	
}

void bfs(vector<int> adj[], int V)
{
	queue<int> q;
	bool visited[V]={false};
	q.push(0);
	cout<<"bfs"<<" ";
	cout<<0<<" ";
	visited[0]=true;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(auto x:adj[s])
		{
			if(!visited[x])
			{
				cout<<x<<" ";
				visited[x]=true;
				q.push(x);
			}
		}
	}
	cout<<endl;
}

void dfs(vector<int> adj[], int e, vector<bool> &visited)
{
	cout<<e<<" ";
	visited[e]=true;
	for(auto v:adj[e])
	{
		if(!visited[v])
		{
			//visited[v]=true;
			dfs(adj,v,visited);
		}
		else continue;
	}
	return;
}

void solve(vector<int> adj[], vector<bool> &visited, stack<int> &s, int e)
{
    visited[e]=true;
    vector<int>::iterator itr;
    
    for(itr=adj[e].begin();itr!=adj[e].end();itr++)
    {
        if(!visited[*itr]) solve(adj,visited,s,*itr);
    }
    s.push(e);
    return;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited;
    stack<int> s;
    vector<int> v;
    for(int i=0;i<V;i++) visited.push_back(false);
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            solve(adj,visited,s,i);
    }
    while(!s.empty())
    {
    	v.push_back(s.top());
    	s.pop();
	}
    return v;
}

int main()
{
	int V=6;
	vector<int> adj[V];
	addEdge(adj, 5, 0);
	addEdge(adj, 5, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 4, 0);
	addEdge(adj, 4, 1);
	addEdge(adj, 1, 3);
	
	printGraph(adj, V);
	bfs(adj,V);
	cout<<"dfs"<<" ";
	vector<bool> visited;
	for(int i=0;i<V;i++)
	{
		visited.push_back(false);
	}
	dfs(adj,0,visited);
	
	cout<<endl<<"topological sort";
	vector<int> v=topoSort(V,adj);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}
