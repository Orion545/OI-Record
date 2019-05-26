#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int x,y,next;
}a[11000];int len,last[5100];
struct lr
{
	int x,y;
}t[21000];
bool cmp(lr t1,lr t2)
{
	if (t1.x<t2.x)return true;
	if (t1.x>t2.x)return false;
	if (t1.y>t2.y)return true;
	if (t1.y<t2.y)return false;
	return true;
}
int n,m;
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int trlen,tr[11000],fa[11000];
void treedp(int x)
{
	trlen++;tr[trlen]=x;
	for (int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if (y!=fa[x]){
			fa[y]=x;
			treedp(y);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	len=0;memset(last,0,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		t[i].x=x;t[i].y=y;
		t[i+m].x=y;t[i+m].y=x;
	}
	sort(t+1,t+2*m+1,cmp);
	for (int i=1;i<=2*m;i++){
		ins(t[i].x,t[i].y);
	}
	trlen=0;fa[1]=0;
	treedp(1);
	for (int i=1;i<trlen;i++)printf("%d ",tr[i]);printf("%d\n",tr[trlen]);
	return 0;
}

