#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
struct node{
	int len,a[5010];
}nod[5010]={0};
int n,m,cnt=0,deep[5010]={0};
vector<int>vec[5010],v[2];
void dfs(int u,int fa){
	printf("%d ",u);
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if(v==fa)
			continue;
		dfs(v,u);
	}
	return;
}
void solve_tree(){
	dfs(1,0);puts("");
	return;
}
void dfs(int u,int fa,int x,int y){
	nod[cnt].a[++nod[cnt].len]=u;
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if(v==fa||((u==x&&v==y)||(u==y&&v==x)))
			continue;
		dfs(v,u,x,y);
	}
	return;
}
void print(int id){
	for(int i=1;i<=n;i++)
		printf("%d ",nod[id].a[i]);
	puts("");
	return;
}
void array_sort(){
	int minn=0x3f3f3f3f,op=0;
	v[0].clear();
	for(int i=1;i<=cnt;i++)
		if(nod[i].a[2]==minn)
			v[0].push_back(i);
		else if(nod[i].a[2]<minn){
			v[0].clear();
			v[0].push_back(i);
			minn=nod[i].a[2];
		}
	for(int i=3;i<=n;i++,op^=1){
		minn=0x3f3f3f3f;
		v[op^1].clear();
		for(int j=0;j<v[op].size();j++){
			int k=v[op][j];
			if(nod[k].a[i]==minn)
				v[op^1].push_back(k);
			else if(nod[k].a[i]<minn){
				v[op^1].clear();
				v[op^1].push_back(k);
				minn=nod[k].a[i];
			}
		}
		if(v[op^1].size()==1){
			print(v[op^1][0]);
			return;
		}
	}
	print(v[op][0]);
	return;
}
void solve_cirtree(){
	queue<int>q;
	for(;!q.empty();q.pop());
	for(int i=1;i<=n;i++)
		if(deep[i]==1)
			q.push(i);
	for(;!q.empty();q.pop()){
		int u=q.front();
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i];
			if(deep[v]==1)
				continue;
			deep[v]--;
			if(deep[v]==1)
				q.push(v);
		}
	}
	int st;
	for(int i=1;i<=n;i++)
		if(deep[i]==2){
			st=i;break;
		}
	int now=st,lst=0;
	do{
		for(int i=0;i<vec[now].size();i++){
			int nxt=vec[now][i];
			if(deep[nxt]==2&&nxt!=lst){
				cnt++;
				dfs(1,0,now,nxt);
				lst=now;now=nxt;
				break;
			}
		}
	}while(now!=st);
	array_sort();
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;i++)
		vec[i].clear();
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd();
		vec[u].push_back(v);
		vec[v].push_back(u);
		deep[u]++;deep[v]++;
	}
	for(int i=1;i<=n;i++)
		sort(vec[i].begin(),vec[i].end());
	if(m==n-1)
		solve_tree();
	else
		solve_cirtree();
	return 0;
}
