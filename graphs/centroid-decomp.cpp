#include "bits/stdc++.h"
using namespace std;

const int MAXN=100100;

vector<int> nodes[MAXN];
int pai[MAXN],sz[MAXN];

int get_size(int u, int p){
	sz[u]=1;
	for(auto x : nodes[u]){
		if(x==p || pai[x])	continue;
		sz[u]+=get_size(x,u);
	}
	return sz[u];
}
int get_centroid(int u,int p,int amt){
	for(auto x : nodes[u])
		if(x!=p && sz[x]>amt/2 && !pai[x])
			return get_centroid(x,u,amt);
	return u;
}
void build(int u,int p){

	int amt = get_size(u,p);
	int centroid = get_centroid(u,p,amt);
	if(p==0)	p=centroid;
	pai[centroid] = p;

	for(auto x : nodes[centroid]){
		if(pai[x])	continue;
		build(x,centroid);
	}

}
int main(){
	
	build(1,0);

}