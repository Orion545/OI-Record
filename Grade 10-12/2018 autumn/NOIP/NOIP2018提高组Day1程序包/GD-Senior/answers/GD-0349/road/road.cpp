#include<bits/stdc++.h>
using namespace std;
int n,ans,i,k,t;
struct code{
	int d,id;
}s[110000];
bool f[110000];
bool cmp(code a,code b){
	return a.d<b.d;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&s[i].d);
		s[i].id=i;
	}
	sort(s+1,s+n+1,cmp);
	k=1;
	for (i=1;i<=s[n].d;i++) {
		if (s[k].d>=i) ans+=(t+1);
		else {
			while (s[k].d==s[k+1].d) {
				t++;
				f[s[k].id]=true;
				if ((f[s[k].id+1]==true)||(s[k].id==n)) t--;
				if ((f[s[k].id-1]==true)||(s[k].id==1)) t--;
				k++;
			}
			t++;
			f[s[k].id]=true;
			if ((f[s[k].id+1]==true)||(s[k].id==n)) t--;
			if ((f[s[k].id-1]==true)||(s[k].id==1)) t--;
			k++;
			ans+=(t+1);
		}
	}
	printf("%d",ans);
}
