#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n,bj,ling,sum;
int L=0,R=0,Now=0;
long long ans;
int a[100010],_min[100010];
int newmin[100010];
int main()
{

	 freopen("road.in","r",stdin);
	 freopen("road.out","w",stdout);
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	 {
	 scanf("%d",&a[i]);
	 _min[i]=a[i];
	 }
	 sort(_min+1,_min+n+1);
//	 for(int i=1;i<=n;i++) cout<<_min[i]<<" ";
	 for(int i=1;i<=n;i++)
	 {
	 	sum+=_min[i];
	 	//if(_min[i+1]-sum>0)
	 	_min[i+1]-=sum;
	 }
	 int k=0;
	 for(int i=1;i<=n;i++) 
	 {
	 	if(_min[i]!=0)
	 	newmin[++k]=_min[i];
	 }
//	 cout<<endl;
//	 for(int i=1;i<=k;i++)
//	 cout<<newmin[i]<<" ";
//	 cout<<endl;
	 for(int i=1;i<=k;i++)
	 {
	    if(newmin[i]==0) break;
	    bj=0;
	 for(int j=1;j<=n;j++)
	 {
	    if(a[j]==0&&bj==1) ans+=newmin[i],bj=0; 
	 	if(a[j]!=0&&j==n) a[j]-=newmin[i],bj=1,ans+=newmin[i];
		else if(a[j]!=0&&j!=n)
	 	a[j]-=newmin[i],bj=1;
	 	
	 }
     }
	 cout<<ans;
	 return 0;
}

