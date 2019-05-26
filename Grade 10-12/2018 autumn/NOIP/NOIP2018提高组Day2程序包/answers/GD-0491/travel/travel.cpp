#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5002;
struct Edge{
	int to,next;
}ed[maxn*2];

int head[maxn],nued;
void aded(int from,int to){
	nued++;
	ed[nued].next=head[from];
	ed[nued].to=to;
	head[from]=nued;
	return;
}
int n,m,ans[maxn],com[maxn],choose=1;
bool used[maxn];
int finh[maxn],huan;
/*void check(){
	for(int i=1;i<=n;i++){
		if(com[i]<ans[i])
			for(int j=1;j<=n;j++)ans[j]=com[j];
		if(com[i]>ans[i])return;
	}
	return;
}*/

void dfs(int x){
	used[x]=1;
	while(1){
		int find=19260817;
		for(int i=head[x];i;i=ed[i].next){
			int t=ed[i].to;
			if(!used[t]&&t<find){
				find=t;
			}
		}
		if(find==19260817)return;
		ans[++ans[0]]=find;
		dfs(find);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		aded(a,b),aded(b,a);
		ans[i]=19260817;
		finh[a]++;finh[b]++;
		if(finh[a]==3)huan=a;
		if(finh[b]==3)huan=b;
	}
	ans[n]=19260817;//³õÊ¼»¯
	ans[++ans[0]]=1;
	 dfs(1);
	 for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	 return 0;
}
