#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define sec second
#define pb push_back

using namespace std;

// Implement Prims Algorithm for MST

ll par[1000001];
ll ran[1000001];

ll find_set(ll v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

bool union_set(ll a,ll b) {
    a = find_set(a);
    b = find_set(b);

    if(a!=b) {
        if(ran[a]<ran[b]) swap(a,b);
        par[b]=a;
        if(ran[a]==ran[b]) ran[a]++;
        return true;
    }
    return false;
}

int main() {
    ll n;      // Number of Nodes
    cin>>n;

    ll e;      // Number of Edges
    cin>>e;

    priority_queue<pair<ll,pii>,vector<pair<ll,pii> >, greater<pair<ll,pii> > > edges;
    for(ll i=0;i<e;i++) {
        ll s,d,w;
        cin>>s>>d>>w;
        edges.push({w,{s,d}});
    }

    for(ll i=1;i<=n;i++) {
        par[i]=i;
        ran[i]=1;
    }

    ll val=0;
    vector<pair<ll,pii> > mst;
    while(!edges.empty()) {
        pair<ll,pii> top = edges.top();
        edges.pop();

        ll s = top.sec.fi,d = top.sec.sec,w = top.fi;

        if(union_set(s,d)) {
            val += w;
            mst.pb({w,{s,d}});
        }
    }
    cout<<"Value of Minimum Spanning Tree = "<<val<<"\n";
    cout<<"Edges: \n";
    for(auto it: mst) {
        cout<<it.sec.fi<<"->"<<it.sec.sec<<" ("<<it.fi<<")\n";
    }
    return 0;

}
