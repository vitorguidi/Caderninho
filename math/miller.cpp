#include "bits/stdc++.h"
using namespace std;

typedef unsigned long long ull;
typedef long double ld;
 
ull fmul(ull a, ull b, ull m) {
  ull q = (ld) a * (ld) b / (ld) m;
  ull r = a * b - q * m;
  return (r + m) % m;
}
 
ull fexp(ull x, ull e, ull mod) {
  ull ans = 1;
  for(; e > 0; e /= 2) {
    if(e & 1) {
      ans = fmul(ans, x, mod);
    }
    x = fmul(x, x, mod);
  }
  return ans;
}
 
bool miller(ull p, ull a) {
  ull s = p - 1;
  while (s % 2 == 0) s >>= 1;
  while (a >= p) a >>= 1;
  ull mod = fexp(a, s, p);
  while (s != p - 1 && mod != 1 && mod != p - 1) {
    mod = fmul(mod, mod, p);
    s <<= 1;
  }
  if (mod != p - 1 && s % 2 == 0) return false;
  return true;
}
 
bool prime(ull p) {
  if (p <= 3) return true;
  if (p % 2 == 0) return false;
  return miller(p, 2) && miller(p, 3)
        && miller(p, 5) && miller(p, 7)
        && miller(p, 11) && miller(p, 13)
        && miller(p, 17) && miller(p, 19)
        && miller(p, 23) && miller(p, 29)
        && miller(p, 31) && miller(p, 37);
}
 