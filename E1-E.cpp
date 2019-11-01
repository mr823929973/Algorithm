#include<iostream>
using namespace std ;
#define MAXN 1000005
int a[MAXN] , c[MAXN] , n;
long long ans = 0 ;
void msort(int b,int e)
{
    if(b == e)  
        return;
    int mid = (b + e) >> 1 , i = b , j = mid + 1 , k = b;
    msort(b,mid);
	msort(mid+1,e);
    while(i <= mid && j <= e)
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else
		{
            c[k++] = a[j++];
			ans += mid - i + 1;
		}	
    while(i <= mid)
        c[k++] = a[i++];
    while(j <= e)
        c[k++] = a[j++];
    for(int l = b;l <= e;l++)
        a[l] = c[l];
} 
int main()
{
	int i ;
    cin >> n ;
    for(i = 1; i <= n ; i++)
        cin >> a[i] ;
    msort(1,n) ;
	cout << ans ;
    return 0 ;
}