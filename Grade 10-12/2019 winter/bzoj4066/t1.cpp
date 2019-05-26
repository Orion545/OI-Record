#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,cnt,dim;
struct node{
	int pos[2],val,minn[2],maxn[2],ch[2],fa,sum;
	inline bool operator ==(node &b){
		return pos[0]==b.pos[0]&&pos[1]==b.pos[1];
	}
	inline bool operator <(const node &b)const{
		return pos[dim]<b.pos[dim];
	}
}a[200010],lis[200010];
inline void update(int cur){
	int ls=a[cur].ch[0],rs=a[cur].ch[1],i;
	for(i=0;i<2;i++){
		a[cur].minn[i]=a[cur].maxn[i]=a[cur].pos[i];
		if(ls){
			a[cur].minn[i]=min(a[cur].minn[i],a[ls].minn[i]);
			a[cur].maxn[i]=max(a[cur].maxn[i],a[ls].maxn[i]);
		}
		if(rs){
			a[cur].minn[i]=min(a[cur].minn[i],a[rs].minn[i]);
			a[cur].maxn[i]=max(a[cur].maxn[i],a[rs].maxn[i]);
		}
	}
	a[cur].sum=a[cur].val+a[ls].sum+a[rs].sum;
}
void insert(int &cur,node &x,int from){
	if(!cur){
		cur=++cnt;
		a[cur]=x;
		a[cur].fa=from;
		return;
	}
	dim^=1;
	if(a[cur]==x){
		a[cur].val+=x.val;a[cur].sum+=x.val;
		return;
	}
	if(a[cur]<x) insert(a[cur].ch[1],x,cur);
	else insert(a[cur].ch[0],x,cur);
	update(cur);
}
int query(int cur,int x1,int x2,int y1,int y2){
//	cout<<"query "<<cur<<' '<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' '<<a[cur].val<<' '<<a[cur].pos[0]<<' '<<a[cur].pos[1]<<'\n';
	if(!cur) return 0;
	if(x1<=a[cur].minn[0]&&x2>=a[cur].maxn[0]&&y1<=a[cur].minn[1]&&y2>=a[cur].maxn[1]) return a[cur].sum;
	if(x1>a[cur].maxn[0]||x2<a[cur].minn[0]||y1>a[cur].maxn[1]||y2<a[cur].minn[1]) return 0;
	int re=0;
	if(x1<=a[cur].pos[0]&&x2>=a[cur].pos[0]&&y1<=a[cur].pos[1]&&y2>=a[cur].pos[1]) re=a[cur].val;
	re+=query(a[cur].ch[0],x1,x2,y1,y2)+query(a[cur].ch[1],x1,x2,y1,y2);
	return re;
}
int rebuild(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	dim^=1;
	nth_element(lis+l,lis+mid,lis+r+1);
	a[mid]=lis[mid];
	a[mid].ch[0]=rebuild(l,mid-1);
	a[mid].ch[1]=rebuild(mid+1,r);
	update(mid);return mid;
}
int main(){
	n=read();int t1,t2,t3,t4,t5,i,j=0,tmp,root=0,lim=10000,lastans=0;node cur;
	while((t5=read())&&(t5!=3)){
		t1=read()^lastans;t2=read()^lastans;t3=read()^lastans;
		if(t5==1){
			cur.ch[0]=cur.ch[1]=0;
			cur.pos[0]=cur.minn[0]=cur.maxn[0]=t1;
			cur.pos[1]=cur.minn[1]=cur.maxn[1]=t2;
			cur.val=cur.sum=t3;
			lis[++j]=cur;
			dim=0;
			insert(root,cur,0);
		}
		if(t5==2){
			t4=read()^lastans;
			printf("%d\n",lastans=query(root,t1,t3,t2,t4));
		}
		if(j==lim){
			dim=0;
			root=rebuild(1,j);
			lim+=10000;
		}
	}
}
