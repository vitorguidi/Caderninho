#include "bits/stdc++.h"
using namespace std;

int n,mx;
ll bit[10000100],seq[2000200];
 
ll query(int ind){
    ll sum=0;
    for(int i=ind;i>0;i-=i&-i)  sum+=bit[i];
    return sum;
}
 
void update(int ind, int val){
    for(int i=ind;i<=mx;i+=i&-i)  bit[i]+=val;
}