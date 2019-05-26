#include <iostream>
#include <cstdio>
using namespace std;
int n,a[1000],d[30010],bj[30010];
void kp(int l,int r){
	int l1=l,r1=r,k,m=a[(l+r)/2];
	while(l<=r){
		while(a[l]<m)l++;
		while(a[r]>m)r--;
		if(l<=r){
			k=a[l];a[l]=a[r];a[r]=k;
			l++;r--;
		}
	}
	if(l<r1)kp(l,r1);
	if(l1<r)kp(l1,r);
	return;
}
void sr(){
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	kp(1,n);
	a[0]=0;
	for(i=1;i<=n;i++)if(a[i]==a[i-1])a[i]=0;
	j=0;
	for(i=1;i<=n;i++)if(a[i]!=0){
		j++;a[j]=a[i];
	}
	for(i=1;i<=30000;i++){
	d[i]=-1;bj[i]=0;
	}
	for(i=1;i<=n;i++)bj[a[i]]=1;
	return;
}
int dp(int s){
	if(bj[s]==1) return 1;
	if(d[s]!=-1)return d[s];
	for(int i=1;a[i]<s&&i<=n;i++) if(dp(s-a[i])==1) d[s]=1;
	if(d[s]!=1) d[s]=0;
	return d[s];
}
void cl(){
	int i,j,ans=0;
	for(i=n;i>=1;i--)
	for(j=1;j<i;j++)
	d[a[i]]=max(d[a[i]],dp(a[i]-a[j]));
	for(i=1;i<=n;i++) if(d[a[i]]==0)ans++;
	printf("%d\n",ans+1);
	return;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
	sr();
	cl();	
	}
	return 0;
}
