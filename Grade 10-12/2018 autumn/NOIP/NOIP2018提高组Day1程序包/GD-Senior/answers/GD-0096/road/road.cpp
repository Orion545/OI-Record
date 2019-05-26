#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node{
	int d,id;
}a[110000];int b[110000];
struct trnode{
	int l,r,lc,rc,bk;
}tr[410000];int len=0;
int mymax(int x,int y) {return x>y?x:y;}
int cmp(const void *xx,const void *yy){
	node n1=*(node *)xx;
	node n2=*(node *)yy;
	return n1.d-n2.d;
}
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;tr[now].bk=0;
	tr[now].lc=tr[now].rc=-1;
	if(l<r){
		int mid=(l+r)/2;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void change(int now,int k){
	if(tr[now].l==tr[now].r) {tr[now].bk=1;return ;}
	int mid=(tr[now].l+tr[now].r)/2;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) change(lc,k);
	else change(rc,k);
	tr[now].bk=tr[lc].bk+tr[rc].bk;
}
int find(int now,int k){
	if(tr[now].l==tr[now].r) return tr[now].bk;
	int mid=(tr[now].l+tr[now].r)/2;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) return find(lc,k);
	else return tr[lc].bk+find(rc,k);
}
int find2(int now,int k){
	if(tr[now].l==tr[now].r) return tr[now].l;
	int mid=(tr[now].l+tr[now].r)/2;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=tr[lc].bk) return find2(lc,k);
	else return find2(rc,k-tr[lc].bk);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].d),a[i].id=i,b[i]=a[i].d;
	qsort(a+1,n,sizeof(node),cmp);
	build(0,n+1);
	a[0].d=a[n+1].d=0;
	change(1,0);change(1,n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		change(1,a[i].id);
		int temp=find(1,a[i].id);
		int x=find2(1,temp-1),y=find2(1,temp+1);
		int maxn=mymax(b[x],b[y]);
		ans+=a[i].d-maxn;
	}
	printf("%d\n",ans);
	return 0;
}
