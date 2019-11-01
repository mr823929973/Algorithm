#include<iostream>
using namespace std;
#define mod 987654323
long long quick(long long a,long long b,long long c) //quickmod
{
	long long ans = 1;
	a %= c;
	while(b)
	{
		if(b & 1) ans=ans * a % c;
		a=a * a % c;	
		b >>= 1;
	}
	return ans % c;
}


long long sum(long long a,long long b,long long p)
{
	if(b == 0) return 1;
	if(a == 0) return 0;
	if(b & 1)
		return (( 1 + quick(a, b / 2 + 1 , p)) * sum(a, b / 2,p)) % p;
	else
		return ((1 + quick(a,b / 2 + 1 , p)) * sum(a, b / 2 - 1 ,p) + quick(a, b / 2,p)) % p;
}
int main()
{
    int t;
    int n , a , q;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> q ;
        cout<<a * (sum( q , n - 1 , mod)) % mod << endl;
    }
}