#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5 + 10;
const long long INF =1e15 + 7;
int a[maxn];
vector <int>p[maxn];
int q,w,e,r;
int n,Q,x,y;
long long ans;
long long sum;
bool Choose[maxn];
bool flag;
char c[10];

void get_choose(int num){
	memset(Choose,0,sizeof(Choose));
	int p=1;
	while(num){
		if(num%2==1) Choose[p]=1;
		p++;
		num/=2;
	}
}

bool Check(int u){
	if(Choose[u]) return false;
	for(int i=0;i<(int)p[u].size();i++) if(!Choose[p[u][i]]) return true;
	return false;
}

void Solve(){
	for(int i=0;i<(1<<n);i++){
		sum=0;
		get_choose(i);
		flag=1;
		for(int i=1;i<=n;i++)
		for(int i=1;i<=n && flag;i++) if(Check(i)) flag=0;
		if(!flag) continue;	
		if(Choose[q]!=w || Choose[e]!=r) continue;
		for(int i=1;i<=n;i++){
			if(Choose[i]) sum+=a[i];
		}
		ans=min(ans,sum);
//		for(int i=1;i<=n;i++) cout<<Choose[i]<<' ';
//		cout<<endl;
//		cout<<ans<<endl;
	} 
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&Q,c);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
/*	for(int i=1;i<=n;i++){
		cout<<i<<": ";
		for(int j=0;j<p[i].size();j++) cout<<p[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=1;i<=Q;i++){
		scanf("%d%d%d%d",&q,&w,&e,&r);
		ans=INF;
		Solve();
		if(ans==INF) printf("-1\n");
			else printf("%lld\n",ans);
	}
	return 0;
}
