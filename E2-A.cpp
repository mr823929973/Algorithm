#include <iostream>
#include<cstring>
const int maxn = 50000;
long long n, W, w[maxn], v[maxn], f[maxn];
int main() {
  while(std::cin >> n >> W)
  {
  for (int i = 1; i <= n; i++) std::cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int l = W; l >= w[i]; l--)
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];
  std::cout << f[W]<<std::endl;
  memset(w,0,maxn*sizeof(long long));
  memset(v,0,maxn*sizeof(long long));
  memset(f,0,maxn*sizeof(long long));
  }
  return 0;
}