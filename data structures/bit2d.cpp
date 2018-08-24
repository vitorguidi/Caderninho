#include <bits/stdc++.h>
using namespace std;

int bit[MAXN]; // vetor que guarda as posições da BIT
	
int query(int x, int y){
		
	int resp=0;
	for(int i=x;i>0;i-=i&-i){
		for(int j=y;j>0;j-=j&-j)
			resp+=bit[i][j];
	}
	return resp;
}

void update(int x, int y, int delta){
		
	for(int i=x;i<MAXN;i+=i&-i){
		for(int j=y;j<MAXN;j+=j&-j)
			bit[i][j]+=delta;
	}
	
}