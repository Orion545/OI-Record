#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
//KDTREE
struct node{
	double lx,ly,lz,rx,ry,rz,posx,posy,posz;
	int lc,rc,num,in;
}x[200010],kdtr[200010];int L,root,back[200010];
inline bool operator <(const node p,const node o){
	if(!L) return p.posx<o.posx;
	else if(L==1) return p.posy<o.posy;
	else return p.posz<o.posz;
}
void updatel(int pos){
	if(!kdtr[pos].lc) return;
	
    kdtr[pos].lx=min(kdtr[pos].lx,kdtr[kdtr[pos].lc].lx);
    kdtr[pos].rx=max(kdtr[pos].rx,kdtr[kdtr[pos].lc].rx);
    
    kdtr[pos].ly=min(kdtr[pos].ly,kdtr[kdtr[pos].lc].ly);
    kdtr[pos].ry=max(kdtr[pos].ry,kdtr[kdtr[pos].lc].ry);
    
    kdtr[pos].lz=min(kdtr[pos].lz,kdtr[kdtr[pos].lc].lz);
    kdtr[pos].rz=max(kdtr[pos].rz,kdtr[kdtr[pos].lc].rz);
//	cout<<"update "<<pos<<' '<<kdtr[pos].num<<' '<<kdtr[pos].lx<<' '<<kdtr[pos].rx<<' '<<kdtr[pos].ly<<' '<<kdtr[pos].ry<<' '<<kdtr[pos].lz<<' '<<kdtr[pos].rz<<'\n';
	
}
void updater(int pos){
	if(!kdtr[pos].rc) return;
    
    kdtr[pos].lx=min(kdtr[pos].lx,kdtr[kdtr[pos].rc].lx);
    kdtr[pos].rx=max(kdtr[pos].rx,kdtr[kdtr[pos].rc].rx);
    
    kdtr[pos].ly=min(kdtr[pos].ly,kdtr[kdtr[pos].rc].ly);
    kdtr[pos].ry=max(kdtr[pos].ry,kdtr[kdtr[pos].rc].ry);
    
    kdtr[pos].lz=min(kdtr[pos].lz,kdtr[kdtr[pos].rc].lz);
    kdtr[pos].rz=max(kdtr[pos].rz,kdtr[kdtr[pos].rc].rz);
    
}
int build(int l,int r,int now){
	int mid=(l+r)>>1;L=now;
	nth_element(x+l,x+mid,x+r+1);
//	cout<<"build "<<l<<' '<<r<<' '<<mid<<' '<<x[mid].num<<'\n';
	kdtr[mid]=x[mid];kdtr[mid].in=1;back[kdtr[mid].num]=mid;
	if(mid>l) kdtr[mid].lc=build(l,mid-1,(now+1)%3);
	if(mid<r) kdtr[mid].rc=build(mid+1,r,(now+1)%3);
    kdtr[mid].lx=kdtr[mid].posx;
    kdtr[mid].ly=kdtr[mid].posy;
    kdtr[mid].lz=kdtr[mid].posz;
    kdtr[mid].rx=kdtr[mid].posx;
    kdtr[mid].ry=kdtr[mid].posy;
    kdtr[mid].rz=kdtr[mid].posz;
    updatel(mid);updater(mid);
//    cout<<"finish build "<<kdtr[mid].lx<<' '<<kdtr[mid].rx<<' '<<kdtr[mid].ly<<' '<<kdtr[mid].ry<<' '<<kdtr[mid].lz<<' '<<kdtr[mid].rz<<'\n';
	return mid;
}
double X,Y,Z,R;int NUM;
double getd(double xx,double yy,double zz){
//	cout<<"GETD "<<X-xx<<' '<<Y-yy<<' '<<Z-zz<<'\n';
	return (X-xx)*(X-xx)+(Y-yy)*(Y-yy)+(Z-zz)*(Z-zz);
}
double dis1(int p){
	double xx=0,yy=0,zz=0;
	xx=max((double)0.0,max(kdtr[p].lx-X,X-kdtr[p].rx));
//	xx=min(fabs(X-kdtr[p].lx),fabs(kdtr[p].rx-X));
//	if(kdtr[p].lx-(1e-4)<=X&&X<=kdtr[p].rx+(1e-4)) xx=0;
	
	yy=max((double)0.0,max(kdtr[p].ly-Y,Y-kdtr[p].ry));
//	yy=min(fabs(Y-kdtr[p].ly),fabs(kdtr[p].ry-Y));
//	if(kdtr[p].ly-(1e-4)<=Y&&Y<=kdtr[p].ry+(1e-4)) yy=0;
	
	zz=max((double)0.0,max(kdtr[p].lz-Z,Z-kdtr[p].rz));
//	zz=min(fabs(Z-kdtr[p].lz),fabs(kdtr[p].rz-Z));
//	if(kdtr[p].lz-(1e-4)<=Z&&Z<=kdtr[p].rz+(1e-4)) zz=0;
	
	return xx*xx+yy*yy+zz*zz;
}

double dis2(int p){
	double xx=0,yy=0,zz=0;
	xx=max((X-kdtr[p].lx),(kdtr[p].rx-X));
	
	yy=max((Y-kdtr[p].ly),(kdtr[p].ry-Y));
	
	zz=max((Z-kdtr[p].lz),(kdtr[p].rz-Z));
	
	return xx*xx+yy*yy+zz*zz;
	
//	cout<<"	getdis "<<p<<' '<<R*R<<' '<<dis1<<' '<<dis2<<'\n';
//	printf("	%.10Lf %.10Lf\n",(dis1-R*R),(R*R-dis2));
}
int ans,cnt;
void query(int pos){
//	cout<<"query "<<pos<<' '<<X<<' '<<Y<<' '<<Z<<' '<<R<<' '<<kdtr[pos].num<<' '<<kdtr[pos].lc<<' '<<kdtr[pos].rc<<'\n';
	assert(pos);
	if(kdtr[pos].in){
		double d=getd(kdtr[pos].posx,kdtr[pos].posy,kdtr[pos].posz);
//		cout<<"	in "<<d<<'\n';
		if(fabs(d-R*R)<1e-4){
			ans=kdtr[pos].num;
			return ;
		}
	}
	double dl1=dis1(kdtr[pos].lc),dr1=dis1(kdtr[pos].rc);
	double dl2=dis2(kdtr[pos].lc),dr2=dis2(kdtr[pos].rc);
//	cout<<"	getdis "<<dl1<<' '<<dl2<<' '<<dr1<<' '<<dr2<<'\n';
	if(dl2<dr2){
		if(dl1-(1e-4)<=R*R&&dl2+(1e-4)>=R*R) query(kdtr[pos].lc);
		if(ans) return;
		if(dr1-(1e-4)<=R*R&&dr2+(1e-4)>=R*R) query(kdtr[pos].rc);
	}
	else{
		if(dr1-(1e-4)<=R*R&&dr2+(1e-4)>=R*R) query(kdtr[pos].rc);
		if(ans) return;
		if(dl1-(1e-4)<=R*R&&dl2+(1e-4)>=R*R) query(kdtr[pos].lc);
	}
	return ;
}
void del(int pos){
//	cout<<"del "<<pos<<' '<<kdtr[pos].num<<' '<<NUM<<' '<<X<<' '<<Y<<' '<<Z<<' '<<kdtr[pos].lx<<' '<<kdtr[pos].rx<<' '<<kdtr[pos].ly<<' '<<kdtr[pos].ry<<' '<<kdtr[pos].lz<<' '<<kdtr[pos].rz<<'\n';
	pos=back[pos];
	kdtr[pos].in=0;
    kdtr[pos].lx=kdtr[pos].ly=kdtr[pos].lz=100000;
    kdtr[pos].rx=kdtr[pos].ry=kdtr[pos].rz=-100000;
    updatel(pos);updater(pos); 
}
void insert(int pos,int num){
//	cout<<"insert "<<pos<<' '<<num<<'\n';
	if(x[num]<kdtr[pos]){
		if(kdtr[pos].lc) (L+=1)%=3,insert(kdtr[pos].lc,num);
		else{
			kdtr[pos].lc=num;
			kdtr[num].in=1;
    		kdtr[num].lx=kdtr[num].posx;
    		kdtr[num].ly=kdtr[num].posy;
    		kdtr[num].lz=kdtr[num].posz;
    		kdtr[num].rx=kdtr[num].posx;
    		kdtr[num].ry=kdtr[num].posy;
    		kdtr[num].rz=kdtr[num].posz;
		}
		updatel(pos);
	}
	else{
		if(kdtr[pos].rc) (L+=1)%=3,insert(kdtr[pos].rc,num);
		else{
			kdtr[pos].rc=num;
			kdtr[num].in=1;
    		kdtr[num].lx=kdtr[num].posx;
    		kdtr[num].ly=kdtr[num].posy;
    		kdtr[num].lz=kdtr[num].posz;
    		kdtr[num].rx=kdtr[num].posx;
    		kdtr[num].ry=kdtr[num].posy;
    		kdtr[num].rz=kdtr[num].posz;
		}
		updater(pos);
	}
}
double cx[200010],cy[200010],cz[200010];double a,b;
double dc(double lim,double last)
{
//	cout<<"decode "<<lim<<' '<<last<<'\n';
    double x=-100000,y=100000;
    while(y-x>1e-9)
    {
        double mid = (x+y)*0.5,tmp=mid*last+1.0;
        if(a*tmp-b*sin(tmp)<lim) x = mid; else y = mid;
    }
//    cout<<"final "<<x<<' '<<y<<'\n';
    return (x+y)*0.5;
}
double dc_sp(double lim,double last)
{
//	cout<<"decode "<<lim<<' '<<last<<'\n';
    double x=0,y=100010;
    while(y-x>1e-2)
    {
        double mid = (x+y)*0.5,tmp=mid*last+1.0;
        if(a*tmp-b*sin(tmp)<lim) x = mid; else y = mid;
    }
//    cout<<"final "<<x<<' '<<y<<'\n';
    return (x+y)*0.5;
}
int main(){
//	freopen("10.in","r",stdin);
//	freopen("my.out","w",stdout);
	int n,m,tp;double t1,t2,t3,t4,last=0.1;
	n=read();m=read();cnt=n;
//	int tt1=0,tt2=0,tt0=0,tmp1,tmp2;
	scanf("%lf%lf",&a,&b);
//	tmp1=clock();
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&t1,&t2,&t3);
		x[i].posx=cx[i]=t1;
		x[i].posy=cy[i]=t2;
		x[i].posz=cz[i]=t3;
		x[i].num=i;
	}
//	tmp2=clock();
//	tt0=tmp2-tmp1;
	root=build(1,n,0);
	while(m--){
		tp=read();
		if(tp){
//			tmp1=clock();
			scanf("%lf%lf%lf%lf",&t1,&t2,&t3,&t4);
			X=dc(t1,last);
			Y=dc(t2,last);
			Z=dc(t3,last);
			R=dc(t4,last);
			ans=0;query(root);
			printf("%d\n",(int)(last=ans));
			assert(last);
//			tmp2=clock();
//			tt1+=tmp2-tmp1;
		}
		else{
//			tmp1=clock();
			scanf("%lf%lf%lf%lf",&t4,&t1,&t2,&t3);
			NUM=(dc(t4,last)+0.5);
			del(NUM);
//			cout<<"***getans "<<ans<<'\n';
			cx[NUM]=X=dc(t1,last);
			cy[NUM]=Y=dc(t2,last);
			cz[NUM]=Z=dc(t3,last);
			cnt++;back[NUM]=cnt++;
			kdtr[cnt].posx=X;kdtr[cnt].posy=Y;kdtr[cnt].posz=Z;kdtr[cnt].num=NUM;
			insert(root,cnt);
//			tmp2=clock();
//			tt2+=tmp2-tmp1;
		}
	}
//	cout<<tt0<<' '<<tt1<<' '<<tt2<<'\n';
}
