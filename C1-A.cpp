#include<iostream>
using namespace std;
int a[100005]={};
int t=0;
void bubbleSort(int n)
{     
	int i, j, flag=1;
    int temp;
    for(i=n-1;i>0&&flag==1;i--)
	{
    	flag=0;                      
        for(j=0;j<i;j++) 
        {
        	if(a[j]>a[j+1])
			{
            t++;
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;  
            flag=1;             
        	}
    	}
    }
    printf("%d",t);
    return;
}
int main()
{
    int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    bubbleSort(n);
    return 0;
}