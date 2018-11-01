#include "bits/stdc++.h"
using namespace std;

int seg[4*MAXN],v[MAXN];	//arvore soh tem 2*n pra n=power of 2

void build(int node, int l, int r){
	
	if(l==r){
		seg[node]=v[l];
		return;
	}
	
	int mid	= (l+r)/2;
	
	build(2*node,l,mid);		//constroi os filhos
	build(2*node+1,mid+1,r);

	seg[node] = seg[2*node] + seg[2*node+1];	//compoe os filhos pra atualizar no, estou interessado no produto

}

void update(int node, int l, int r, int id, int val){

	if(l==r){					//id= id do elemento que eu qro trocar em v, val eh o novo valor (1,0 ou -1)
		v[l]=val;					//se chego ao conjunto de 1 elemento, simplesmente atualizo valor
		return;
	}

	int mid = (l+r)/2;
	
	if(l<=id && id<=mid)	update(2*node,l,mid,id,val);			//se o cara estiver no filho da esquerda, atualizo filho esquerda
	else					update(2*node+1,mid+1,r,id,val);		//caso contrario, vou pra direita

	seg[node]=seg[2*node] + seg[2*node+1];	//estou interessado em produtos nos intervalos

}


int query(int node, int l, int r, int a, int b){	//procura o intervalo [a,b], e o noh eh o intervalo [l,r]

	if (a>r || b<l)		return 0;		//range invalida, [l,r] tem elementos fora de [a,b], q eh o intervalo original

	if(a<=l && r<=b)	return seg[node];	//range contida no intervalo de interesse, retorna resultado

	int mid=(l+r)/2;
	
	return query(2*node,l,mid,a,b) + query(2*node+1,mid+1,r,a,b);

}


