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

vi nodes[100100];
int pre[100100],low[100100];		//vetores de preorder number e low
int vis[100100],clk,root;			//clk eh tempo globa, root eh a raiz da arvore
vii bridge;
vi articulation;

void dfs(int v, int caller){		//v eh o vertice que estou visitando,
 
	low[v]=pre[v]=clk++;
	vis[v]=1;	
	int nf=0;	bool any=false;	//numero de filhos do node e flag pra dizer se V eh de corte ou nao

	for(auto filho : nodes[v]){
	
		if(filho==caller)
			continue;

		else if( !vis[filho] ){			//situação em que estou lidando com uma tree edge

			dfs(filho,v);	
			nf++;

			if(low[filho]>=pre[v])
				any=true;		//o filho nao conseguiu escapar da subtree, entao eh vertice de corte

			if(low[filho]>pre[v])	
				bridge.push_back({v,filho});	//se a aresta em questao nao faz parte de um ciclo, eh uma ponte

			low[v]=min(low[v],low[filho]);	//atualizo o low do vertice atual com o de seus filhos
		}
		
		else
			low[v]=min(low[v],pre[filho]);	//lida com a situação de back edge. low do atual = min( low[atual],pre[filho])
											//nao pode ser min com low[filho] pq senao eu pego arestas de retorno de segunda ordem
	}

	if(v==root && nf>1)					//depois que eu calculo o preorder number e os lows dos filhos da subtree, posso decidir
		articulation.push_back(v);					//se o vertice atual eh de corte ou nao

	else if(v!=root && any)				//se o vertice eh raiz e tem mais de um filho, ou se eh vertice interno e sua subtree nao vai alem
		articulation.push_back(v);					//dele proprio, entao eh cut vertex

}