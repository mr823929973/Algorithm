#include<iostream>
#include<cstdio>
#include<cstring>
long long a[1000006];
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]+=a[i-1];
        }
        int l,r;
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",(a[r]-a[l-1])%10007);
        }
    }
}