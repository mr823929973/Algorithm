#include<cstdio>
#include<algorithm>
using namespace std;
struct food{int w,v;double p;}a[100005]; 
bool cmp(const food &x,const food &y) 
{
    return x.p>y.p;
}
int main()
{
    int s,n;
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].w,&a[i].v);
        a[i].p=double(a[i].v)/double(a[i].w);
    }
    sort(a+1,a+n+1,cmp); 
    double price=0;
    for(int i=1;i<=n;i++)
    {
        if(s-a[i].w>=0) 
        {
            price+=a[i].w*a[i].p; 
            s-=a[i].w; 
        }
        else 
        {
            price+=s*a[i].p;
            break;
        }
    }
    printf("%.2f",price); 
    return 0;
}
