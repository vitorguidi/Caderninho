#include "bits/stdc++.h"
using namespace std;

void build_table(){		//intervalo aberto na ponta direita

	for(int i=0;i<n;i++)
		memo[i][0]=v[i];

	for(int i=1; i<23; i++ ){

		for(int j=0; j + (1<<i) <= n ; j++){

			int meio = j + (1<<(i-1));
			memo[j][i]=min( memo[j][i-1], memo[meio][i-1] );
		
		}
		
	}

}

int query(int x, int y){

	if(x>y)
		swap(x,y);

	int k = 31 - __builtin_clz(y-x+1);
	int meio = y-(1<<k)+1;
	return min( memo[x][k] , memo[meio][k] );

}
