#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

const double eps = 1e-8,pi=3.14159265;

int n;

int dcmp(double x)  
{
	if(fabs(x)<eps)return 0;
	else return x>0?1:-1;
} 
#define Vector Point
struct Point 
{
	double x,y;
	inline Point(double x=0,double y=0):x(x),y(y){}
}p[100000+5],ch[100000+5];

bool myCmp(Point A,Point B){
	if(A.x!=B.x)return A.x<B.x;
	else return A.y<B.y;
}

Vector operator + (Vector A,Vector B){
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
bool operator == (const Vector& A,const Vector& B){
	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0;
}
inline double Cross(Vector A,Vector B)  
{
	return A.x * B.y - A.y * B.x;
}
int ConvexHull()
{
	sort(p,p+n,myCmp);
	int m=0;
	for(int i=0;i<n;i++){  

		while(m>1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0)m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){ 
		while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0)m--;
		ch[m++]=p[i]; 
	}
	if(n>1)m--;  
	return m; 
}
double Dis(Point A,Point B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int main(){
	int m;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		p[i]=Point(a,b);
	}
	m=ConvexHull();

	double ans=0.0; 
	for(int i=0;i<m-1;i++)
	  ans+=Dis(ch[i],ch[i+1]);
	ans+=Dis(ch[m-1],ch[0]);
	printf("%.2f ",ans);
	 
    ans=0.0;
	ch[m]=ch[0];
	for(int i=0;i<m;i++){
		ans+=(ch[i].x*ch[i+1].y-ch[i+1].x*ch[i].y);
	}
	ans=ans/2;
	printf("%.2f",ans); 
} 
