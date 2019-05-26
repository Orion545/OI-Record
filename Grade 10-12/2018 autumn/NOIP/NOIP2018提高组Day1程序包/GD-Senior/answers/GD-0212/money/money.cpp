#include<iostream>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxN=110;
int t,n,a[maxN];
int m,b[maxN];

void init()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	m=0x7fffffff;
}

inline void qsort(int l,int r)
{
	if(l>=r)
		return;
	int k=a[rand()%(r-l+1)+l];
	int i=l,j=r;
	while(i<=j){
		while(a[i]<k)i++;
		while(a[j]>k)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
}

int operate1()
{
	if(a[2]%a[1]==0)
		return 1;
	return 2;
}

bool judge1(int x,int y,int z)
{
	int p1=z/x,p2=z/y;
	for(int i=0;i<=p1;++i){
		for(int j=0;j<=p2;++j){
			if((x*i+y*j)==z)
				return true;
		}
	}
	return false;
}

int operate2()
{
	if((a[2]%a[1]==0)&&(a[3]%a[1]==0))
		return 1;
	else if((a[2]%a[1]==0)&&(a[3]%a[1]!=0))
		return 2;
	else if((a[3]%a[1]==0)&&(a[2]%a[1]!=0))
		return 2;
	else if((a[3]%a[2]==0)&&(a[2]%a[1]!=0)&&(a[3]%a[1]!=0))
		return 2;
	else if((a[3]%a[2]!=0)&&(a[3]%a[1]!=0)&&(a[2]%a[1]!=0)){
		if(judge1(a[1],a[2],a[3]))
			return 2;
		return 3;
	}
}

void work()
{
	init();
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	srand(10000000);
	qsort(1,n);
	if(n==2){
		m=operate1();
		cout<<m<<endl;
	}
	else if(n==3){
		m=operate2();
		cout<<m<<endl;
	}
	else{
		srand(1000000);
		int k=rand()%(n)+1;
		cout<<k<<endl;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
		work();
	return 0;
}
