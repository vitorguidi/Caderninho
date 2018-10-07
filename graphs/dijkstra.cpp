#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define ms(x,v) memset(x,v,sizeof x)
#define mp make_pair

const int INF = 0x3f3f3f3f;

typedef pair<int,int> pii;
typedef vector<pii> vii;

vii nodes[100100];
int dist[100100];

void dijkstra(int v){
 
    set<pii> fila; //declara a min heap pra guardar os nos a serem procesasdos
    ms(dist,INF);   //iniciliza distancia pro infinito

    dist[v]=0;      //inicializ a raiz
    fila.insert({0,v}); //coloca a root na pq (set.begin() eh o menor elemento, mais limpo que uma std::pq)
 
    while( !fila.empty() ){
        
        pii pai = *fila.begin(); 
        fila.erase( fila.begin() );
        
        if(pai.fst > dist[pai.snd])  continue;   //ja foi atualizado para uma distancia menor
        
        for( auto filho : nodes[pai.snd] ){

            if(dist[filho.snd] > pai.fst + filho.snd){

                dist[filho.snd] = pai.fst + filho.snd;
                fila.insert( {dist[filho.snd],filho.snd} );

            }
        }      

    }

}
