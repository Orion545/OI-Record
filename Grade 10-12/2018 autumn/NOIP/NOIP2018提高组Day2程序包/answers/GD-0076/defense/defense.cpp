#include<cstdio>
#include<queue>
using namespace std;
const int N=100005;
#define ll long long
char ss[5];
int n,m,p[N],wen[N][4];
int head[N],to[N],nxt[N],tot;
long long sum[N][2],hou[N][2],linshi[N][2];
int read()
{
	int rt=0;	char ch=getchar();
	while(ch<'0'||ch>'9'){	ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-48;ch=getchar();}
	return rt;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
void add(int u,int v)
{
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void qinkuang1()
{
	for(int i=1;i<=n;i++){
		sum[i][1]=min(sum[i-1][0],sum[i-1][1])+p[i];
		sum[i][0]=sum[i-1][1];
	}
	for(int i=n;i>=1;i--){
		hou[i][1]=min(hou[i+1][1],hou[i+1][0])+p[i];
		hou[i][0]=hou[i+1][1];
	}
	for(int wei=1;wei<=m;wei++){
		int a,b,x,y;
		a=wen[wei][0];	x=wen[wei][1];	
		b=wen[wei][2];	y=wen[wei][3];
		if((a==b+1||b==a+1)&&x==0&&y==0){
			printf("-1\n");
			continue;
		}
		ll rt=0;
		if(a>b){//a<b
			a=a^b;	b=a^b;	a=a^b;
			x=x^y;	y=x^y;	x=y^x;
		}
		rt+=sum[a][x]+hou[b][y];
		if(x==0)	{
			linshi[a+1][0]=0x7fffff;
			linshi[a+1][1]=p[a+1];
		}
		else{
			linshi[a+1][1]=p[a+1];
			linshi[a+1][0]=0;
		}
		for(int kk=a+2;kk<b;kk++){
			linshi[kk][1]=min(linshi[kk-1][1],linshi[kk-1][0])+p[kk];
			linshi[kk][0]=linshi[kk-1][1];
		}
		if(y==1)rt+=min(linshi[b-1][1],linshi[b-1][0]);
		else{
			rt+=linshi[b-1][1];
		}
		printf("%lld\n",rt);
	}
	
	
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();	m=read();	scanf("%s",ss);
	for(int i=1;i<=n;i++)	p[i]=read();
	for(int i=1;i<n;i++){
		int uu,vv;	uu=read();	vv=read();
		add(uu,vv);
		add(vv,uu);
	}
	for(int i=1;i<=m;i++){
		wen[i][0]=read();
		wen[i][1]=read();
		wen[i][2]=read();
		wen[i][3]=read();
	}
	if(ss[0]=='A'){
		qinkuang1();
	}
	return 0;
}
