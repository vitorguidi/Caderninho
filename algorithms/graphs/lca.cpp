#include "bits/stdc++.h"
using namespace std;

#define MAXN 	100100
#define LMAXN	20		//ceil(log2(MAXN))

vector<int> nodes[MAXN];

int memo[MAXN][LMAXN];
int pai[MAXN];
int hgt[MAXN];
int vis[MAXN]
int n;

void dfs(int v){
	vis[v]=1;
	for(auto filho : nodes[v]){
		if(vis[filho])	continue;
		pai[filho]=v;
		hgt[filho]=hgt[v]+1;
		dfs(filho);
	}
}

void build_table(){

	dfs(0);	//seta alturas a partir da raiz
	
	for(int i=0;i<n;i++)	memo[i][0]=pai[i];	//inicializa pai de ordem 2^0 de todos como o pai deles

	for(int i=1; i<=LMAXN;i++)											//calcula a sparse table pras potencias de 2 apropriadas
		for(int j=0;j<n;j++)	memo[j][i]=memo[ memo[j][i-1] ][i-1];	//calcula o role pra todos os vertices		

}

int lca(int a, int b){
	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

	for(int i=LMAXN; i>=0; i-- ){						//bota a e b na mesma altura
		if(hgt[ memo[a][i] ] >= hgt[b])	a=memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return a;	//se forem iguais, retorna o LCA

	for(int i=LMAXN; i>=0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		
		if(memo[a][i]!=-1 && memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}

	}

	return memo[b][0];

}

//ver http://www.spoj.com/problems/LCASQ/





