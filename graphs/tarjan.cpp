#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define ms(x,v) memset(x,v,sizeof x)
#define mp make_pair

const int INF = 0x3f3f3f3f;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

void dfs(int v){

	low[v]=pre[v]=clk++;
	vis[v]=1;
	pilha.push(v);

	for (auto filho : nodes[v]){
	
		if(!vis[filho])
			dfs(filho);
		
		low[v]=min(low[filho],low[v]);	
		
	}
	
	if(pre[v]==low[v]){

		int node;
		vi temp;

		do{
			node=pilha.top();pilha.pop();
			comp[node]=val;
			low[node]=INF;
			temp.pb(node);
		}	while(node!=v && !pilha.empty());

		val++;
		scc.pb(temp);

	}
}
