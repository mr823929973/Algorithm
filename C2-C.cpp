#include <cstdio>
#include <algorithm>
#include <cstring>
#define max 0x7FFFFFFF
int w[1005];
int r[1005];
int min(int a ,int b)
{
    if(a<=b) return a;
    else return b;
}
int main()
{
    int n,i,j,tmp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for(i=1;i<=n;i++)
        {
            tmp=max;
            for(j=1;j<=i;j++)
            {
                tmp=min(tmp,w[j]+r[i-j]);
            }
            r[i]=tmp;
        }
        printf("%d\n",r[n]);
       memset(w,0,1005*4);
       memset(r,0,1005*4);
    }
    return 0;
}