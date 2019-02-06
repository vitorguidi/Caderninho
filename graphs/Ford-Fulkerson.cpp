#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1000;
const int INF = 0x3f3f3f3f3f3f3f;

struct TEdge{
	int from,to,cap,f;
};

vector<TEdge> edges;
vector<int> adj[MAXN];
int vis[MAXN];
int edg_cnt,sink;

void add_edge(int from, int to, int cap){

	adj[from].push_back(edg_cnt++);		//aresta normal
	edges.push_back({from,to,cap,0});


	adj[to].push_back(edg_cnt++);		//aresta reversas
	edges.push_back({to,from,0,0});

}

int push(int v, int w,int sink){

	vis[v]=1;
	if(v==sink)	return w;

	for(auto ind : adj[v]){

		if(vis[edges[ind].to])	continue;
		if(edges[ind].f==edges[ind].cap)	continue;		//aresta saturada

		int res = push( edges[ind].to , min(w,edges[ind].cap-edges[ind].f) , sink);		//tenta enviar fluxo por essa aresta ate o sink
		if(res==0)	continue;

		edges[ind].f+=res;		//atualiza rede residual
		edges[ind^1].f-=res;

		return res;

	}

	return 0;

}

int maxflow(){
	int ans=0;
	int aug;
	while(aug=push(0,INF,sink)){
		ans+=aug;
		memset(vis,0,sizeof vis);	
	}
	return ans;
}
