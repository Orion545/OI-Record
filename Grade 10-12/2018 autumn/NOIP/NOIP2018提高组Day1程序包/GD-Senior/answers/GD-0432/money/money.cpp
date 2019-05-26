#include<bits/stdc++.h>
using namespace std;

int T,n,len,ans;
int a[110],temp[110];
bool tf[110];
bool v[110];
struct node
{
	int d,id;
	bool friend operator <(node x,node y)
	{
		if (x.d!=y.d) return x.d>y.d;
		else return x.id<y.id;
	}
}cnt[110];

inline int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if (c=='-') f=0;c=getchar();}
	while (c>='0' && c<='9') x=x*10+(c^48),c=getchar();
	return f?x:-x;
}

void init()
{
	len=0,ans=0;
	for (int i=1;i<=n;i++) a[i]=temp[i]=tf[i]=v[i]=0;
}

int gcd(int x,int y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}

void exgcd(int a,int b,int &x,int &y)
{
	if (!b) {x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
}

bool solve(int a,int b,int x,int y,int d)
{
	double ans1=(double)-x*d/b;
	double ans2=(double)y*d/a;
	if (floor(ans2)>=ceil(ans1)) return true;
	return false;
}

bool solution(int a,int b,int c)
{
	int x,y,d=gcd(a,b);
	if (c%d!=0 || a>c || b>c) return false;
	exgcd(a,b,x,y);
	x*=c/d,y*=c/d;
	if (solve(a,b,x,y,d)) return true;
	return false;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while (T--)
	{
		n=read();init();
		for (int i=1;i<=n;i++)
		{
			temp[i]=read();
			for (int j=1;j<i;j++)
			{
				if (temp[j]%temp[i]==0) tf[j]=true;
				if (temp[i]%temp[j]==0 && temp[i]!=temp[j]) tf[i]=true;
			}
		}
		for (int i=1;i<=n;i++) if (!tf[i]) a[++len]=temp[i],cnt[len].id=len,cnt[len].d=0;
		if (len==2 || len==1) {printf("%d\n",len);continue;}

		vector<int> f[110][110];
		vector<int> q;
		
		for (int i=1;i<=len;i++)
			for (int j=1;j<=len;j++)
			{
				if (i==j) continue;
				for (int k=1;k<=len;k++)
				{
					if (i==k || j==k) continue;
					if (solution(a[i],a[j],a[k]))
					{
						cnt[i].d++;cnt[j].d++;
						f[i][j].push_back(k);
					}
				}
			}
		
		int p=len-2;ans=2;
		sort(cnt+1,cnt+len+1);
		q.push_back(cnt[1].id);v[cnt[1].id]=true;
		q.push_back(cnt[2].id);v[cnt[2].id]=true;
		for (int i=0;i<f[q[0]][q[1]].size();i++) v[f[q[0]][q[1]][i]]=true,p--;
		for (int k=3;k<=len;k++)
		{
			if (p==0) break;
			if (v[cnt[k].id]==false) q.push_back(cnt[k].id),ans++,v[cnt[k].id]=true,p--;
			for (int i=0;i<q.size();i++)
				for (int j=0;j<f[q[i]][cnt[k].id].size();j++)
					if (v[f[q[i]][cnt[k].id][j]]==false)
					{
						v[f[q[i]][cnt[k].id][j]]=true;
						p--;
					}
		}
		printf("%d\n",ans);
	}
	return 0;
}
