#include "bits/stdc++.h"
using namespace std;

void build(int node, int l, int r){		//constroi igual a seg normal

	if(l==r){
		segtree[node]=v[i];
		return;
	}

	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	segtree[node]=segtree[2*node]+segtree[2*node+1];

}

void update(int node, int l, int r, int a, int b, int val){

	int lc=2*node;	int rc=2*node+1;	int mid = (l+r)/2;

	if(lazy[node]){		//lida com atualizacao pendente. so preciso aplicar no inicio de uma consulta ou update
		segtree[node]+=lazy[node]*(r-l+1);
		if(l!=r){
			lazy[lc]+=lazy[node];
			lazy[rc]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(r<a || l>b)	return;		//intervalo invalido

	else if(a<=l && r<=b){		//update cobre o no
		segtree[node]+=val*(r-l+1);
		if(r!=l){
			lazy[lc]+=val;
			lazy[rc]+=val;
		}
	}

	else{		//no parcialmente contido
		update(2*node,l,mid,a,b,val);
		update(2*node+1,mid+1,a,b,val);
		segtree[node]=segtree[lc]+segtree[rc];
	}

}

int query(int node, int l, int r, int a, int b){

	int lc=2*node; int rc=2*node+1; int mid = (l+r)/2;

	if(lazy[node]){
		segtree[node]+=lazy[node]*(r-l+1);
		if(l!=r){
			lazy[lc]+=lazy[node];
			lazy[rc]+=lazy[node];
		}
		lazy[node]=0;
	}	

	if(r<a || l>b)	return	0;	//ou qualquer indicador invalido, depende

	else if(a<=l && r<=b)	return segree[node];

	else	return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);

	

}