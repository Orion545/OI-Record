#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
int n,m,f,f1,ans,x[100001],y[100001],z[100001],vn[100001],s[100001],sw[100001],dp1[100001],dp2[100001];
void bui(int v,int l){
	dp1[v]=0;dp2[v]=0;
	for(int i=vn[v];i<vn[v+1];++i){
		if(s[i]!=l){
			bui(s[i],v);
			if(dp1[s[i]]+sw[i]>dp1[v]){
				dp2[v]=dp1[v];
				dp1[v]=dp1[s[i]]+sw[i];
			}
			else if(dp1[s[i]]+sw[i]>dp2[v])dp2[v]=dp1[s[i]]+sw[i];
		}
	}
	//cout<<v<<" "<<l<<endl;for(int i=1;i<=n;++i)cout<<dp1[i]<<" ";cout<<endl;for(int i=1;i<=n;++i)cout<<dp2[i]<<" ";cout<<endl;
}
void erfen(int l,int r){
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		ans=l;
		return ;
	}
	int mid=(l+r)/2+1;
	f=0;f1=0;
	for(int i=0;i<n-1;++i){
		if(f+z[i]<mid){
			f+=z[i];
		}
		else {
			f=0;
			f1++;
		}
	}
	//cout<<mid<<" "<<f1<<endl;
	if(f1>=m)erfen(mid,r);
	else (l,mid-1);
}
signed main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	f=1;f1=1;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n-1;++i){
		scanf("%lld %lld %lld",x+i,y+i,z+i);
		vn[x[i]]++;
		vn[y[i]]++;
		if(y[i]-x[i]!=1)f=0;
		if(x[i]!=1)f1=0;
	}
	for(int i=1;i<=n+1;++i)vn[i]+=vn[i-1];
	for(int i=0;i<n-1;++i){
		s[--vn[x[i]]]=y[i];
		sw[vn[x[i]]]=z[i];
		s[--vn[y[i]]]=x[i];
		sw[vn[y[i]]]=z[i];
	}
	if(f){
		f1=3;
		for(int i=0;i<n-1;++i)f1+=z[i];
		erfen(1,f1/3+1);
		printf("%lld",ans);
		return 0;
	}
	if(f1){
		sort(z,z+n-1);
		if(2*m>n-1){
			printf("%lld",z[2*n-2*m-3]);
		}
		else {
			ans=0x7ffffffffff;
			for(int i=n-1-m-m,j=n-1;i<j;++i,--j){
				if(z[i]+z[j]<ans)ans=z[i]+z[j];
			}
			printf("%lld",ans);
		}
		return 0;
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;++i){
			bui(i,0);
			if(dp1[i]+dp2[i]>ans)ans=dp1[i]+dp2[i];
			for(int j=1;j<=n;++j)dp1[j]=0,dp2[j]=0;
		}
		
		//for(int i=1;i<=n;++i)cout<<dp1[i]<<" ";cout<<endl;for(int i=1;i<=n;++i)cout<<dp2[i]<<" ";
		//tree(1,0);
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
