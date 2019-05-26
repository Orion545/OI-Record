#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=5005;
int n,m,f[N],x,y,k,xu[N],huan[N],father[N],h[N],l,d1,d2,p,q;
struct node{
	int b[105];
	int num;
	int son;
};
node a[N];

void dfs1(int pos)
{
	f[pos]=1;
	xu[++xu[0]]=pos;
	sort(a[pos].b+1,a[pos].b+1+a[pos].num);
	for(int i=1;i<=a[pos].num;i++){
		if(f[a[pos].b[i]]==0)
			dfs1(a[pos].b[i]);
	}
}
int find(int x1)
{
	if(father[x1]!=x1) father[x1]=find(father[x1]);
	return father[x1];
}
void merge(int x1,int y1)
{
	father[find(x1)]=find(y1);
}
void _huan(int x1,int st)
{
	if(f[st]==1&&x1==st){
		huan[st]=1;
		h[l]=st;
		l++;
		int k=a[st].son;
		while(k!=st){
			huan[k]=1;
			h[l]=k;
			l++;
			k=a[k].son;
		}
		return ;
	}
	for(int i=1;i<=a[x1].num;i++){
		if(f[a[x1].b[i]]==0){
			a[x1].son=a[x1].b[i];
			f[a[x1].b[i]]=1;
			_huan(a[x1].b[i],st);
		}	
	}
}
void dfs2(int pos)
{
	f[pos]=1;
	xu[++xu[0]]=pos;
	sort(a[pos].b+1,a[pos].b+1+a[pos].num);
	if(huan[pos]==1&&p==0){
		p=1;
		for(int i=a[pos].num;i>=1;i--){
			if(a[pos].b[i]<d1&&huan[a[pos].b[i]]==1){
				d2=d1;
				d1=a[pos].b[i];
			}
		}
	}
		for(int i=1;i<=a[pos].num;i++){
			if(huan[a[pos].b[i]]==1&&a[pos].b[i]>d2&&f[a[pos].b[i]]==0&&q==0){
				q=1;
				return ;
			}
			else if(f[a[pos].b[i]]==0)
				dfs2(a[pos].b[i]);
		}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			a[x].num++;
			a[x].b[a[x].num]=y;
			a[y].num++;
			a[y].b[a[y].num]=x;
		}
		dfs1(1);
		for(int i=1;i<=n;i++)
			printf("%d ",xu[i]);
	}
	else if(m==n){
		for(int i=1;i<=n;i++) f[i]=2;
		for(int i=1;i<=m;i++) father[i]=i;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			f[x]=0; f[y]=0;
			a[x].num++;
			a[x].b[a[x].num]=y;
			a[y].num++;
			a[y].b[a[y].num]=x;
			if(find(x)!=find(y)) merge(x,y);
			else {
				_huan(x,x);
			}
		}
		memset(f,0,sizeof(f));
		d1=0x9fffff;
		d2=0x9fffff;
		dfs2(1);
		for(int i=1;i<=n;i++) printf("%d ",xu[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
