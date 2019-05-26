#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int head[maxn],cnt=0,n,m,f[maxn],temp=0,pp;
bool b[maxn];
struct edge{
	int to,w,next;
}e[maxn*2];
void add_edge(int s,int t,int w){
	e[++cnt].next=head[s];e[cnt].to=t;e[cnt].w=w;head[s]=cnt;
}
int dp(int s){
	b[s]=1;
	bool flag=1;
	vector<int>v;
	for(int i=head[s];i;i=e[i].next){
		if(!b[e[i].to]){
			flag=0;
			int ge=dp(e[i].to);
			v.push_back(ge+e[i].w);
		}
	}
	if(flag)return 0;
	sort(v.begin(),v.end());
	int l=0,r=v.size()-1,maxx=0;
	while(v[r]>=pp&&r>=0){
		--r,temp++;
	}
	if(l>r)return 0;
	while(l<=r){
		if(l!=r&&v[l]+v[r]>=pp){
			++l,--r,temp++;
		}
		else {
			maxx=max(maxx,v[l]);
			++l;
		}
	}
	return maxx;
}
bool pd(){
	temp=0;
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	dp(1);
	if(temp>=m)return 1;
	else return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int l=1,r=0,ans;
	cin>>n>>m;
	for(int i=1;i<=n-1;++i){
		int s,t,w;
		cin>>s>>t>>w;
		add_edge(s,t,w);
		add_edge(t,s,w);
		r+=w;
	}
	while(l<=r){
		int mid=(l+r)/2;
		pp=mid;
		if(pd()){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
