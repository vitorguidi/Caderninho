#include "bits/stdc++.h"
using namespace std;

#define MAXN 	100100
#define LMAXN	20		//ceil(log2(MAXN))

vector<int> nodes[MAXN];

int memo[MAXN][LMAXN];
int hgt[MAXN];
int vis[MAXN]
int n;

void dfs(int v){

	vis[v]=1;
	
	for(auto filho : nodes[v]){
	
		if(vis[filho])	continue;
	
		memo[filho][0]=v;		//seta o pai do cara
		hgt[filho]=hgt[v]+1;
		
		for(int i=1;i<LMAX;i++)	
			memo[filho][i]=memo[memo[filho][i-1]][i-1];
								//gera a sparse table na propria dfs (dependencias ja estao calculadas, por inducao)
		dfs(filho);
	}

}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

	for(int i=LMAXN-1; i>=0; i-- ){						//bota a e b na mesma altura
		if(hgt[ memo[a][i] ] >= hgt[b])	a=memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return a;	//se forem iguais, retorna o LCA

	for(int i=LMAXN-1; i>=0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		
		if(memo[a][i]!=-1 && memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}

	}

	return memo[b][0];	//sobe um nivel e retorna o lca

}

//ver http://www.spoj.com/problems/LCASQ/





