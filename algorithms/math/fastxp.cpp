#include "bits/stdc++.h"
using namespace std;

int fastxp(int a, int b){

	if(b==0)
		return 1;

	int ans = fastxp(a,b/2);
	ans=ans*ans;
	if(b%2==1)
		ans=ans*a;

	return ans;

}

int fxp(int a, int b){

	int ans=1;

	while(b>0){
		if(b%2)
			ans*=a;
		a*=a;
		b=b/2;
	}
	return ans;

}

int main(){

	int x,y;
	cin >> x >> y;
	cout << fxp(x,y) << endl;
	
}