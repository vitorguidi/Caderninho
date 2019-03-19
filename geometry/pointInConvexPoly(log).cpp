#include "bits/stdc++.h"
using namespace std;

const int INF = 0x3f3f3f3f;

struct point{
	long long int x,y;
	point(){};
	point(long long int a, long long int b){x=a;y=b;};
	long long int operator^(point p){return x*p.y-y*p.x;};
	long long int operator*(point p){return x*p.x+y*p.y;};
	point operator-(point p){return{x-p.x,y-p.y};};
};
int sign(long long int x){
	if(x==0)	return 0;
	return x/abs(x);
}
long long int area(point a, point b, point c){
	return abs((a-b)^(c-b));
}
bool insideSegment(point c, point a, point b){
	if( (c-a)^(c-b) )	return false;
	if((c-a)*(b-a)<0)	return false;
	return (c-a)*(b-a)<=(b-a)*(b-a);
}

bool check(point p, vector<point>& v){

	int k = v.size();
	point from = point(0,0);

	if( (v[1]^p)!=0 && sign(v[1]^p)!=sign(v[1]^v[k-1]) )		return false;		//se nao ta, em angulo, entre v[1] e v[k-1], ja cagou
	if( (v[k-1]^p)!=0 && sign(v[k-1]^p)!=sign(v[k-1]^v[1]) )	return false;

	if(insideSegment(p,from,v[k-1]))	return true;								//corner: o ultimo triangulo eh degenerado, ve na mao

	int ini=1;
	int end = k-1;
	int last=-1;

	while(ini<=end){																//faz busca binaria pra ver o ultimo cara que a orientacao eh anti horaria ate o pto p
		int mid = (ini+end)>>1;														// que eu desejo (indice i)		
		if(sign(v[mid]^p)>=0){
			last=mid;
			ini=mid+1;
		}
		else	end=mid-1;
	}

	int total = abs(area(from,v[last],v[last+1]));									//verifica se o pto ta no triangulo OriPiPi+1
	int a1 = abs(area(from,p,v[last]));
	int a2 = abs(area(from,p,v[last+1]));
	int a3 = abs(area(p,v[last],v[last+1]));

	return total == (a1+a2+a3);


}

//esse codigo passa o problema https://codeforces.com/problemsets/acmsguru/problem/99999/253

int main(){

	int n,m,k; cin >> n >> m >> k;

	vector<point> v;
	point pivot = point(INF,INF);	//assume poligono em sentido anti-horario
	int pos;

	for(int i=0;i<n;i++){			//pega o cara mais a esquerda(desempata por menor coord y) pra ser o pivo
		int x,y;
		cin >> x >> y;
		point p = point(x,y);
		v.push_back(p);
		if(p.x<pivot.x){
			pos=i;
			pivot = p;
		}
		else if(p.x==pivot.x){
			pos=i;
			pivot.y=min(p.y,pivot.y);
		}
		
	}

	rotate(v.begin(),v.begin()+pos,v.end());		//joga o pivo pra posicao 0 e mantem ordneacao anti-hraria
	for(int i=1;i<=n-1;i++)	v[i]=v[i]-v[0];

	int cnt = 0; 

	while(m--){
		//verifica se o pto pertence ao poligono (offset com o pivot)
		int x,y;
		cin >> x >> y;
		point p = point(x,y);
		if(check(p-v[0],v))	
			cnt++;
	}

	cout << (cnt>=k ? "YES" : "NO") << endl;


}