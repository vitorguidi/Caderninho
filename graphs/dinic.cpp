//roubado descaradamente do macacario ITA
//https://github.com/splucs/Competitive-Programming/blob/master/Macac%C3%A1rio/Graphs/dinic.cpp
#include "bits/stdc++.h"
using namespace std;

const int MAXN=100100;
const int MAXM=1001001;

int ned;
int first[MAXN],dist[MAXN],work[MAXN];
int nxt[MAXM],to[MAXM],cap[MAXM];

void init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u,int v, int f){
	
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;

}

int dfs(int u, int f, int s, int t){

	if(u==t)	return f;
	int df,v;

	for(int &e = work[u];e!=-1;e=nxt[e]){
	
		v=to[e];
		if(dist[v]==dist[u]+1 && cap[e]>0){

			df=dfs(v,min(f,cap[e]),s,t);
			
			if(df>0){
				cap[e]-=df;
				cap[e^1]+=df;
				return df;
			}

		}

	}

	return 0;

}

bool bfs(int s, int t){
	
	int u,v;
	memset(&dist,-1,sizeof(dist));
	
	dist[s]=0;
	queue<int> q;q.push(s);
	
	while(!q.empty()){

		u=q.front();q.pop();
	
		for(int e = first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]<0 && cap[e]>0){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}

	}

	return dist[t]>=0;

}

int dinic(int s,int t){
	int result=0,f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(f=dfs(s,INF,s,t))	result+=f;
	}
	return result;
}

int main(){

	init();
	//do stuff here

}