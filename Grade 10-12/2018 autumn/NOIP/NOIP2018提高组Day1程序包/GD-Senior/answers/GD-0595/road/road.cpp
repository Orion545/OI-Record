//NOIP2018day1T1	2018.11.10	st表维护区间最小值的位置,然后类似快排递归求解 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100100],f[100100][20],yu[100100],n,i,k;
int read(){
	int ans=0;char c=getchar();
	while(c < '0' || c > '9')	c=getchar();
	while(c >= '0' && c <= '9'){ans=(ans<<1)+(ans<<3)+c-48;c=getchar();}
	return ans;
}
int lo(int x){
	if(x == 0)	return -1;
	int ans=0;
	while(x != 1){x=(x>>1);ans++;}
	return ans;
}
int find(int l,int r,int k){
	if(l > r)	return 0;
	if(l == r)	return (a[l]-k);
	int mid;
	if(a[f[l][yu[r-l]]] < a[f[r-(1<<yu[r-l])+1][yu[r-l]]])	mid=f[l][yu[r-l]];
	else	mid=f[r-(1<<yu[r-l])+1][yu[r-l]];
	return	find(l,mid-1,a[mid])+find(mid+1,r,a[mid])+a[mid]-k;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(i=1;i <= n;i++)	a[i]=read();
	for(i=1;i <= n;i++)	f[i][0]=i;
	for(k=1;k <= lo(n);k++)//预处理出区间最小值的位置 
		for(i=1;i <= n;i++)
			if(i+(1<<k)-1 <= n)
				if(a[f[i][k-1]] < a[f[i+(1<<(k-1))][k-1]])	f[i][k]=f[i][k-1];
				else	f[i][k]=f[i+(1<<(k-1))][k-1];
	for(i=1;i <= n;i++)	yu[i]=lo(i);//nlogn预处理出log2
	printf("%d",find(1,n,0));
	return 0;
}
