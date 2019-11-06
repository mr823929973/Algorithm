#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int INF=100009 ;
int node[INF];
int main()
{
    long long T,n,i,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
         scanf("%d",&node[i]);
        sort(node,node+n);
        for(i=1;i<n;i++)
        {
            ans+=node[0]+node[i];
        }
        printf("%d\n",ans);
    }
}