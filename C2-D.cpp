#include <cstdio>
#include<cstring>
int p1[505];
int p2[505];
int t1[505];
int t2[505];
int f[505];
int f1[505];
int f2[505];
int min(int a ,int b)
{
    if(a<=b) return a;
    else return b;
}
int main()
{
    int n,i,j,tmp1,tmp2;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        scanf("%d",&p1[i]);
        for(i=1;i<=n;i++)
        scanf("%d",&p2[i]);
        for(i=1;i<n;i++)
        scanf("%d",&t1[i]);
        for(i=1;i<n;i++)
        scanf("%d",&t2[i]);
        f1[1]=p1[1];
        f2[1]=p2[1];
        f[1]=min(f1[1],f2[1]);
        for(i=2;i<=n;i++)
        {
            f1[i]=min(f1[i-1]+p1[i],f2[i-1]+p1[i]+t2[i-1]);
            f2[i]=min(f2[i-1]+p2[i],f1[i-1]+p2[i]+t1[i-1]);
            f[i]=min(f1[i],f2[i]);
        }
        printf("%d\n",f[n]);
        memset(p1,0,505*4);
        memset(p2,0,505*4);
        memset(t1,0,505*4);
        memset(t2,0,505*4);
        memset(f1,0,505*4);
        memset(f2,0,505*4);
        memset(f,0,505*4);

    }
    return 0;
}