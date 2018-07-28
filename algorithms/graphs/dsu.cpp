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

int id[100100],sz[100100];

int find(int p){

	if(id[p]==p)
		return p;

	return id[p]=find(id[p]);
}

void join(int p, int q){
	
	p=find(p);q=find(q);

	if(id[p]==id[q])
		return;
	
	if(sz[p]>sz[q])
		swap(p,q);
	
	id[p]=q;
	sz[q]+=sz[p];
}


int main(){
	int n;
	cin >> n;
	fr(i,n)
		id[i]=i;
}