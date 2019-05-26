#include<cstdio>
#include<fstream>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

ifstream fin("road.in");
ofstream fout("road.out");

const int N=1e5+10;
int n,a[N],f[1<<19];

#define A v+v
#define B v+v+1

int trans(int x,int y){return a[x]>a[y]?y:x;}

void build(int v,int l,int r){
	if(l==r){f[v]=l;return;}
	int m=l+r>>1;
	build(A,l,m),build(B,m+1,r),f[v]=trans(f[A],f[B]);
}

int query(int v,int l,int r,int x,int y){
	if(l==x&&r==y)return f[v];
	int m=l+r>>1;
	if(y<=m)return query(A,l,m,x,y);
	if(x>m)return query(B,m+1,r,x,y);
	return trans(query(A,l,m,x,m),query(B,m+1,r,m+1,y));
}

int Getans(int l,int r,int dep){
	if(l==r)return a[l]-dep;
	int m=query(1,1,n,l,r),res=0;
	if(l<m)res+=Getans(l,m-1,a[m]);
	if(m<r)res+=Getans(m+1,r,a[m]);
	return res+a[m]-dep;
}

int main(){
	fin>>n;
	rep(i,1,n)fin>>a[i];
	
	build(1,1,n);
	fout<<Getans(1,n,0);
	
	return 0;
}

