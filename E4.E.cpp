#include<iostream>
using namespace std;
long long a[1000000];
int main()
{
    //freopen("in","r",stdin);
    //freopen("out1","w",stdout);
    int T,i,j;
    cin >> T;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    i=3;
    while(a[i-1]<INT32_MAX/2)
    {
        j=i-12>0 ? i-12:0;
        a[i]=a[i-1]+a[i-2]-a[j];
        i++;
    }
    while(T--)
    {
        cin>>i;
        cout<<((i>20)?2*(a[i]-a[i-20]):2*a[i])<< endl;
    }
}