#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int sz[maxn],tp[maxn]; 
int n=1;
int p=1;
int main(){
    int x;
    cin >>x;
	while(cin>>sz[n]) n++;
	tp[1] = sz[1];
	memset(tp,0,sizeof(tp));
	tp[1]=sz[1];
	p=1;
	for(int i=2;i<=n;i++){
		if(sz[i] > tp[p]) tp[++p] = sz[i];
		else{
			int l=1,r=p,mid=p>>1;
			while(l!=r){
				if(sz[i] <= tp[mid] ) r = mid;
				else l = mid+1;
				mid = (l+r)>>1;
			}
			tp[l] = sz[i];
		}
	}
	cout<<p<<endl;
	return 0;
}
