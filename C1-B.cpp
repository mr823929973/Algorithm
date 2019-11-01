#include<iostream>
using namespace std;
int a[100005];
void adjust(int k[ ],int i,int n)
{

	int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n)
	{
		if(j<n-1 && k[j]<k[j+1]) j++;
        if(temp>=k[j]) break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
	k[(j-1)/2]=temp;
    return;
}
void heapSort(int k[ ],int n)
{
    int i;
    int temp;
    for(i=n/2-1;i>=0;i--) adjust(k,i,n);
}
int main()
{

    int n , k ,i;
    long long sum=0;
    while(cin >> n >> k)
    {
        sum=0;
        for(i=0;i<n;i++)
            cin>> a[i];
        heapSort(a,n);
        while(k--)
        {
            a[0]/=2;
            adjust(a,0,n);
        }
        for(i=0;i<n;i++)
            sum+=a[i];
        cout << sum <<endl;
    }
    return 0;
}