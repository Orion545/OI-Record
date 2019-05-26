#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}

int n,m;
vector<int> bn[5010];
int tp[5010];
struct Edge{
	int frm,to,nxt;
}edge[10010];
int cnt,last[5010];
void addedge(int x,int y)
{
	edge[++cnt]=(Edge){x,y,last[x]},last[x]=cnt;
//	edge[++cnt]=(Edge){x,last[y],false},last[y]=cnt;
}

int ans[5010];
int rec[5010];
bool vis[5010];
int A,B;
void dfs(int cur)
{
	vis[cur]=true;
	rec[++(*rec)]=cur;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (!(cur==A&&edge[i].to==B||cur==B&&edge[i].to==A)&&!vis[edge[i].to])
			dfs(edge[i].to);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	memset(ans,0x7f,sizeof ans);
	read(n);read(m);
	for (int i=1,x,y;i<=m;i++)
	{
		read(x);read(y);
		bn[x].push_back(y);
		bn[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		int tmp=bn[i].size();
		for (int j=0;j<tmp;j++) tp[j]=bn[i][j];
		sort(tp,tp+tmp);
		for (int j=tmp-1;~j;j--) /*printf("from %d to %d\n",i,tp[j]),*/addedge(i,tp[j]);
	}
	if (m==n-1)
	{
		dfs(1);
		for (int i=1;i<=n;i++) printf("%d ",rec[i]);
		putchar('\n');
		
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for (int i=1;i<=cnt;i++)
	{
		if (edge[i].frm>edge[i].to) continue;
		A=edge[i].frm; B=edge[i].to;
		memset(vis,false,sizeof vis);
		(*rec)=0;
		dfs(1);
		if ((*rec)!=n)
		{
			continue;
		}
		bool flg=false;
		for (int j=1;j<=n;j++)
			if (rec[j]!=ans[j])
			{
				if (rec[j]<ans[j]) flg=true;
				break;
			}
		if (flg)
		{
			for (int j=1;j<=n;j++)
				ans[j]=rec[j];
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	putchar('\n');

	fclose(stdin);fclose(stdout);
	return 0;
}
