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
// 若 一点的坐标在前面两点的右边，则更新右端点 
int n;

int dcmp(double x)  // 三态函数 ，在下面用于是否在精度 
{
	if(fabs(x)<eps)return 0;
	else return x>0?1:-1;
} 
#define Vector Point
struct Point 
{
	double x,y;
	inline Point(double x=0,double y=0):x(x),y(y){}
}p[10000+5],ch[10000+5];

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
inline double Cross(Vector A,Vector B)  // 计算叉积
{
	return A.x * B.y - A.y * B.x;
}
int ConvexHull()
{
	sort(p,p+n,myCmp);
	int m=0;
	for(int i=0;i<n;i++){  
	// 求下曲包，当该点在前进方向的右边时（使用叉积判断），删除前进的右端点，
	// 循环，直到不在，并将该点加入，不在右边，则直接加入 
		while(m>1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0)m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){  // 因 pn-1 已经遍历过，故从n-2开始 
		// 求上凸包，最终形成合围，为完整凸包
		while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0)m--;
		ch[m++]=p[i]; 
	}
	if(n>1)m--;  // 因要形成凸包，故起始点重复，减1
	return m;  //返回顶点个数
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
	
	//下面是计算凸包周长的 
	double ans=0.0; 
	for(int i=0;i<m-1;i++)
	  ans+=Dis(ch[i],ch[i+1]);
	ans+=Dis(ch[m-1],ch[0]);
	printf("%.2f ",ans);
	// 下面是计算凸包面积的
	 
    ans=0.0;
	ch[m]=ch[0];
	for(int i=0;i<m;i++){
		ans+=(ch[i].x*ch[i+1].y-ch[i+1].x*ch[i].y);
	}
	ans=ans/2;
	printf("%.2f",ans); 
} 
