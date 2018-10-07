#include "bits/stdc++.h"
using namespace std;

//esse codigo foi chupinhado do LoppA

string s,p;
int pi[2100100];

void pre () {

	p += '#';
	pi[0] = pi[1] = 0;

	for (int i = 2; i <= p.size(); i++) {		//indexando a string de 1, p[i-1] eh pra compensar isso

		pi[i] = pi[i-1];

		while (pi[i] > 0 and p[pi[i]] != p[i-1])
			pi[i] = pi[pi[i]];

		if (p[pi[i]] == p[i-1])
			pi[i]++;

	}
}

vi kmp(){

	pre ();

	vi ans;
	int k = 0;
	int m = p.size() - 1;

	for (int i = 0; i < s.size(); i++) {
		
		while (k > 0 and p[k] != s[i])
			k = pi[k];
		
		if (p[k] == s[i])
			k++;

		if (k == m)
			ans.pb(i-m+1);	//retorna os indices de ocorrencia 0-indexed
	}

	return ans;

}
