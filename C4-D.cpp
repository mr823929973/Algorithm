#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[450][600];
string in;
int n,k;
long long g[450];
long long cut(int l,int r){
    long long end = 0;
    for(int i = l;i <= r;i++)
        end = end * 10 + g[i];
    return end;
}
int main(){
   while( cin >> k >> in)
   {
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    n=in.length();
    for(int i = 1;i <= n;i++)
        g[i] = in[i - 1] - '0';
    for(int i=1;i<=n;i++)
        f[i][0] = cut(1,i);
    for(int i = 2;i <= n;i++){ 
        for(int a = 1;a <= min(i-1,k);a++){ 
            for(int b = a;b < i;b++){ 
                 f[i][a] = max(f[i][a],f[b][a-1] * cut(b + 1,i));
            }
        }
    }
    cout<<f[n][k]<<endl;
   }
    return 0;
}
