#include "bits/stdc++.h"
using namespace std;

int seg[400400];
int lazy[400400];

void build(int node, int l, int r){		//constroi igual a seg normal

	if(l==r){
		seg[node]=v[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	seg[node]=seg[2*node]+seg[2*node+1];

}

void unlazy(int node, int l, int r){

	seg[node]+=(r-l+1)*lazy[node];
	if(l!=r){
		lazy[2*node]+=lazy[node];
		lazy[2*node+1]+=lazy[node];
	}
	lazy[node]=0;

}

void update(int node, int l, int r, int a, int b, int val){

	int lc=2*node;	int rc=2*node+1;	int mid = (l+r)/2;

	unlazy(node,l,r);

	if(r<a || l>b || l>r)	return;		//intervalo invalido

	else if(a<=l && r<=b){		//update cobre o no
		seg[node]+=val*(r-l+1);
		if(r!=l){
			lazy[lc]+=val;
			lazy[rc]+=val;
		}
	}

	else{		//no parcialmente contido
		update(2*node,l,mid,a,b,val);
		update(2*node+1,mid+1,r,a,b,val);
		seg[node]=seg[lc]+seg[rc];
	}

}

int query(int node, int l, int r, int a, int b){

	int lc=2*node; int rc=2*node+1; int mid = (l+r)/2;

	unlazy(node,l,r);

	if(r<a || l>b || l>r)	return	0;	//ou qualquer indicador invalido, depende

	else if(a<=l && r<=b)	return seg[node];

	else	return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);

}