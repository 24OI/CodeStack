
#include <cstdio>
#include <algorithm>

typedef long long LL;// NOLINT
typedef std::pair<LL,int> P;

int n, k, i, b, l;
LL x, a, ans;
P y, h[100033];

inline void read(LL &a) {// NOLINT
  char c;
  while(!(((c = getchar()) >= '0') && (c <= '9')));
  a = c - '0';
  while(((c = getchar()) >= '0') && (c <= '9'))(a *= 10) += c - '0';
}

inline void put(P x) {
  h[++l] = x;
  for (int i = l;i > 1 && h[i] < h[i >> 1];i >>= 1)std::swap(h[i],h[i >> 1]);
}

inline void get(){
  y = h[1]; h[1] = h[l--];
  for(int i = 1;;) {
    P tee = h[i];
    int j = 0;
    if ((i << 1) <= l && h[i << 1] < tee)tee = h[ j = i << 1 ];
    if ((i << 1|1) <= l && h[i << 1|1] < tee)j = i << 1|1;
    if (j){
      std::swap(h[i],h[j]);
      i = j;
    } else {
      return;
    }
  }
}

int main() {
  for (scanf("%d%d", &n, &k); --n; put(P(x,0)))read(x);
  if (k > 2)while (l % (k - 1) != 1)put(P(0,0));
  for (;l > 1;ans += a, put(P(a,b + 1)))for (i = a = b = 0; i < k; i++) {
    get();
    a += y.first;
    b = std::max(b,y.second);
  }
  printf("%lld\n%d",ans,h[1].second);
  return 0;
}

