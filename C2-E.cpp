#include<iostream>
using namespace std;
int main()
{
    long long n,i,currentFib,f0=1,f1=1;
    cin>>n;
        currentFib=2;
        f0=1;f1=1;
        for(i = 1;i <= n;i++)
        {
            currentFib = (f0 + f1);
            f0 = f1;
            f1 = currentFib;
        }
    cout<<currentFib<<endl;       
    return 0;
}