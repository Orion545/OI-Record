#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();;
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int L;
struct node{
	double d[3],r;int id;
	double operator [](int num){return d[num];}
	node(double x=0,double y=0,double z=0,int w=0){d[0]=x;d[1]=y;d[2]=z;id=w;}
	inline bool operator <(const node b)const{return d[L]<b.d[L];}
}x[100010];
double d[100010][3],maxn[100010][3],minn[100010][3];
int lc[100010],rc[100010],id[100010],at[100010],in[100010],n,cnt,root;

double sqr(double x){return x*x;}
double dis(int o,node &p){double re=0;for(int i=0;i<3;i++) re+=sqr(d[o][i]-p[i]);return re;}
double dis1(int o,node &p){double re=0;for(int i=0;i<3;i++) re+=sqr(max(0.0,max(p[i]-maxn[o][i],minn[o][i]-p[i])));return re;}
double dis2(int o,node &p){double re=0;for(int i=0;i<3;i++) re+=sqr(max(maxn[o][i]-p[i],p[i]-minn[o][i]));return re;}

void update(int u,int v){
	if(!v) return ;
	for(int i=0;i<3;i++) maxn[u][i]=max(maxn[u][i],maxn[v][i]);
	for(int i=0;i<3;i++) minn[u][i]=min(minn[u][i],minn[v][i]);
}
int newnode(node &p){
	cnt++;
	for(int i=0;i<3;i++) d[cnt][i]=maxn[cnt][i]=minn[cnt][i]=p[i];
	id[cnt]=p.id;at[p.id]=cnt;lc[cnt]=rc[cnt]=0;in[cnt]=1;
	return cnt;
}

void build(int &o,int l,int r){
	if(l>r) return;
	int mid=(l+r)>>1;L++;L%=3;
	nth_element(x+l,x+mid+1,x+r+1);
	o=newnode(x[mid]);
//	cout<<"build "<<o<<' '<<l<<' '<<r<<' '<<id[o]<<'\n';
	build(lc[o],l,mid-1);build(rc[o],mid+1,r);
	update(o,lc[o]);update(o,rc[o]);
//	cout<<"finish build "<<d[o][0]<<' '<<d[o][1]<<' '<<d[o][2]<<' '<<id[o]<<'\n';
}

int ans;
void query(int pos,node &p){
	double d=dis(pos,p);
//	cout<<"query "<<pos<<' '<<p[0]<<' '<<p[1]<<' '<<p[2]<<' '<<p.r<<' '<<d<<' '<<id[pos]<<'\n';
	if(in[pos]&&fabs(d-p.r)<=1e-4){ans=id[pos];return;}
	double dl1=dis1(lc[pos],p),dl2=dis2(lc[pos],p);
	double dr1=dis1(rc[pos],p),dr2=dis2(rc[pos],p);
	if(dl2<dr2){
		if(dl1-(1e-4)<=p.r&&p.r<=dl2+(1e-4)) query(lc[pos],p);
		if(ans) return;
		if(dr1-(1e-4)<=p.r&&p.r<=dr2+(1e-4)) query(rc[pos],p);
	}
	else{
		if(dr1-(1e-4)<=p.r&&p.r<=dr2+(1e-4)) query(rc[pos],p);
		if(ans) return;
		if(dl1-(1e-4)<=p.r&&p.r<=dl2+(1e-4)) query(lc[pos],p);
	}
}
void del(int pos){
//	cout<<"del "<<pos<<' '<<at[pos]<<'\n';
	pos=at[pos];in[pos]=0;
	for(int i=0;i<3;i++) maxn[pos][i]=-1e5,minn[pos][i]=1e5;
	update(pos,lc[pos]);update(pos,rc[pos]);
}
void insert(int &o,node &p){
	if(!o){o=newnode(p);return;}
	L++;L%=3;
	if(p[L]<=d[o][L]) insert(lc[o],p),update(o,lc[o]);
	else insert(rc[o],p),update(o,rc[o]);
}
double a,b,last=0.1;
double f(double x){x=x*last+1.0;return a*x-b*sin(x);}
double dc(double x,double l,double r){
	double mid;
	while(r-l>=1e-9){
		mid=(l+r)*0.5;
//		cout<<"binary "<<mid<<' '<<f(mid)<<'\n';
		if(f(mid)<x) l=mid;
		else r=mid;
	}
	return (l+r)*0.5;
}
int main(){
//	freopen("4.in","r",stdin);
//	freopen("my.out","w",stdout);
	int Q;scanf("%d%d",&n,&Q);
	scanf("%lf%lf",&a,&b);
	double t1,t2,t3,t4;int type,i;
	for(i=1;i<=n;i++){
		scanf("%lf%lf%lf",&t1,&t2,&t3);
		x[i]=node(t1,t2,t3,i);
	}
	build(root,1,n);
	while(Q--){
		scanf("%d",&type);
		scanf("%lf%lf%lf%lf",&t1,&t2,&t3,&t4);
//		cout<<"input "<<type<<' '<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<' '<<a<<' '<<b<<' '<<f(0)<<'\n';
		if(type){
			t1=dc(t1,-100,100);
			t2=dc(t2,-100,100);
			t3=dc(t3,-100,100);
			t4=dc(t4,-1000,1000);
			node p(t1,t2,t3);p.r=sqr(t4);
			ans=0;query(root,p);
			last=ans;printf("%d\n",ans);
			assert(last);
		}
		else{
			int num;
			num=dc(t1,-100000,100000)+0.5;
			del(num);
			t2=dc(t2,-100,100);
			t3=dc(t3,-100,100);
			t4=dc(t4,-100,100);
			node p(t2,t3,t4,num);L=0;
			insert(root,p);
		}
	}
}

