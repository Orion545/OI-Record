#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,l,ans,answ[51000],max1,max2,t,k[51000];
struct code{
	vector <int> to,dis;
}s[51000];
bool f,ff;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		scanf("%d%d%d",&u,&v,&l);
		if ((u-v!=1)&&(v-u!=1)) f=true;
		if (u!=1) ff=true;
		s[u].to.push_back(v);
		s[u].dis.push_back(l);
		s[v].to.push_back(u);
		s[v].dis.push_back(l);
	}
	if (ff==false) {
		ans=100000;
		if (m<=(n-1)/2) {
			memset(k,0,sizeof(k));
			for (int i=0;i<s[1].to.size();i++) k[s[1].to[i]]=s[1].dis[i];
			sort(k+1,k+n+1);
			for (int i=n-2*m+1;i<=n-m;i++) ans=min(ans,k[i]+k[2*n-i-2*m+1]);
			printf("%d",ans);
		} else {
			memset(k,0,sizeof(k));
			for (int i=0;i<s[1].to.size();i++) k[s[1].to[i]]=s[1].dis[i];
			sort(k+1,k+n+1);
			for (int i=2;i<=n-m;i++) ans=min(ans,k[i]+k[2*n-i-2*m+1]);
			for (int i=2*n-2*m;i<=n;i++) ans=min(ans,k[i]);
			printf("%d",ans);
		}
	} else {
		if (f==false) {
			for (int i=2;i<=n;i++) 
				if (s[i].to[0]==i-1) k[i]=s[i].dis[0];
				else k[i]=s[i].dis[1];
			int j=1;
			for (int i=2;i<=n;i++) t+=k[i];
			t/=m;
			for (int i=2;i<=n;i++) {
				if (answ[j]+k[i]-t<=t-answ[j]) answ[j]+=k[i];
				else {
					j++;
					answ[j]=k[i];
				}
			}
			sort(answ+1,answ+m+1);
			printf("%d",answ[1]);
		}
	}
}
