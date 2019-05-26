#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
inline int rd(){
	char c=getchar();int x=0,flag=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*flag;
}
struct edge{
	int to,data,nxt;
}e[100010];
int n,m,cnt,head[50010]={0};
int dfs(int u,int fa,int x){
	deque<int>q,qq;
	for(;!q.empty();q.pop_back());
	for(;!qq.empty();qq.pop_back());
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)
			continue;
		int tmp=dfs(v,u,x)+e[i].data;
		if(tmp>=x)
			cnt++;
		else
			q.push_back(tmp);
	}
	if(q.empty())
		return 0;
 	sort(q.begin(),q.end());
	int maxn=0;
	while(q.size()>1){
		int ft=q.front();
		q.pop_front();
		while(q.size()){
			int bk=q.back();
			q.pop_back();
			if(q.size()&&ft+q.back()>=x)
				qq.push_front(bk);
			else{
				if(ft+bk>=x)
					cnt++;
				else{
					if(qq.size()){
						cnt++;
						qq.pop_front();
					}
					maxn=max(maxn,ft);
					q.push_back(bk);
				}
				break;
			}
		}
	}
	for(;!q.empty();q.pop_front())
		if(qq.size()){
			qq.pop_front();
			cnt++;
		}
		else
			maxn=max(maxn,q.front());
	cnt+=qq.size()/2;
	if(qq.size()&1)
		maxn=max(maxn,qq.back());
	return maxn;
}
bool solve(int x){
	cnt=0;
	if(dfs(1,0,x)>=x)
		cnt++;
	return cnt>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int l=0,r=0,ans=0;
	n=rd();m=rd();
	for(int i=1;i<n;i++){
		int u=rd(),v=rd(),w=rd();
		e[i]=(edge){v,w,head[u]};
		head[u]=i;
		e[n+i]=(edge){u,w,head[v]};
		head[v]=n+i;
		r+=w;
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(solve(mid))
			ans=mid,l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
