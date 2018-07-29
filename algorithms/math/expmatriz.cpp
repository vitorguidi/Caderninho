#include "bits/stdc++.h"
using namespace std;

const int mod = 1000000007;
typedef vector< vector<ll> > matrix;

int m,n;

matrix operator*(matrix& a, matrix& b){

	int a1=a.size(); int a2=a[0].size();
	int b1=b.size(); int b2=[0].size();

	matrix aux; aux.resize(a1);
	
	for(int i=0;i<m;i++)
		aux[i].resize(b2);
	
	for(int i=0;i<a1;i++){
		for(int j=0;j<b2;j++){
			aux[i][j]=0ll;
			for(int k=0;k<a2;k++){
				aux[i][j]+=a[i][k] * b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}
		}
	}
	return aux;
}

matrix id(int x){
	matrix v;
	v.resize(x);
	for(int i=0;i<x;i++){
		v[i].resize(x);
		v[i][i]=1ll;
	}
	return v;
}

matrix exp(matrix& a, ll x){
	matrix ans = id(m);
	while(x>0){
		if(x%2==1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}
	return ans;
}
