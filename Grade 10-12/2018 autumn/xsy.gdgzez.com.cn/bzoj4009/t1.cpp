#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<queue>
#include<cmath>
#define las DEEP_DARK_FANTASY
#define lowbit(x) (x&(-x))
#define mp make_pair
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;
		return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;int __fg=1;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1,__c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
        __x*=__fg;
    }
    inline void readd(double &__x)
    {
        __x=0;double __fg=1.0;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1.0,__c=getc();
        while(isdigit(__c)) __x=__x*10.0+__c-'0',__c=getc();
        if(__c!='.'){__x=__x*__fg;return;}else while(!isdigit(__c)) __c=getc();
        double __t=1e-1;while(isdigit(__c)) __x=__x+1.0*(__c-'0')*__t,__t=__t*0.1,__c=getc();
        __x=__x*__fg;
    }
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(__c<'a'||__c>'z') __c=getc();
        while(__c>='a'&&__c<='z') __s[++__tot]=__c,__c=getc();
        __s[++__tot]='\0';
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];int __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        if(__x<0) putc('-'),__x=-__x;
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void prints(const char *__s,const int __x)
    {
        int __len=strlen(__s+__x);
        for(int __i=__x;__i<__len+__x;__i++) putc(__s[__i]);
    }
    inline void printd(long double __x,int __d)
    {
        long long __t=(long long)floor(__x);print(__t);putc('.');__x-=(double)__t;
        while(__d--)
        {
            long double __y=__x*10.0;__x*=10.0;
            int __c=(int)floor(__y+1e-9);if(__c==10) __c--;
            putc(__c+'0');__x-=floor(__y);
        }
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;

inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,k,first[40010],cnte,dfn[40010],las[40010],st[40010][20],dep[40010],clk;
struct edge{
	int to,next;
}a[100010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	st[u][0]=f;dep[u]=dep[f]+1;
	dfn[u]=++clk;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<dfn[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
	las[u]=clk;
}
void ST(){
	int i,j;
	for(j=1;j<=16;j++)
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
}
int getpre(int l,int r){
	int i;
	if(l==r) return l;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=16;i>=0;i--) if(dep[st[r][i]]>dep[l]) r=st[r][i];
	if(st[r][0]==l) return r;
	else return 0;
}
struct mat{
	int lx,rx,ly,ry,val,id;
}p[100010];int cntp;
inline bool cmp(mat l,mat r){
	return l.val<r.val;
}
struct fru{
	int x,y,id,ans,k;
}f[40010];
struct ele{
	int l,r,id;
};
namespace BIT{
	int a[100010];
	void Add(int x,int val){
		for(;x<=n;x+=lowbit(x)) a[x]+=val;
	}
	void add(int l,int r,int val){
//		cout<<"			BIT ADD "<<l<<' '<<r<<' '<<val<<'\n';
		Add(l,val);Add(r+1,-val);
	}
	int sum(int x){
//		cout<<"			BIT SUM "<<x<<' ';
		int re=0;
		for(;x>0;x-=lowbit(x)) re+=a[x];
//		cout<<re<<'\n';
		return re;
	}
}
queue<ele>q;
vector<int>s,le,ri;
vector<pair<int,int> >t;
inline bool cmps(int l,int r){
	return f[l].x<f[r].x;
}
inline bool cmpt(pair<int,int>l,pair<int,int>r){
	int vl,vr;
	if(l.second) vl=p[l.first].rx;
	else vl=p[l.first].lx;
	if(r.second) vr=p[r.first].rx;
	else vr=p[r.first].lx;
	return vl<vr;
}
void solve(){
	ele cur;int i,l,r,mid,j,tmp,tval;
	for(i=1;i<=k;i++) q.push((ele){1,cntp,i});

	while(!q.empty()){
		cur=q.front();q.pop();
		if(cur.l==cur.r){f[cur.id].ans=p[cur.l].val;continue;}
		l=cur.l;
		r=cur.r;
		s.clear();
		s.push_back(cur.id);
		mid=(l+r)>>1;t.clear();
//		if(s[0]==1) cout<<"follow "<<l<<' '<<r<<' '<<mid<<' '<<f[1].k<<'\n';
//		fflush(stdout);

		while(!q.empty()&&q.front().l==l&&q.front().r==r){
//			if(q.front().id==1) cout<<"follow "<<l<<' '<<r<<' '<<mid<<' '<<f[1].k<<'\n';
 //			fflush(stdout);
			s.push_back(q.front().id);
			q.pop();
		}
		sort(s.begin(),s.end(),cmps);

		for(i=l;i<=mid;i++){
			t.push_back(mp(i,0));
			t.push_back(mp(i,1));
		}
		sort(t.begin(),t.end(),cmpt);

//		cout<<"do binary "<<l<<' '<<r<<' '<<mid<<' '<<s.size()<<' '<<t.size()<<' '<<q.size()<<'\n';
//		for(auto ss:s) cout<<ss<<' ';
//		cout<<'\n';
//		for(auto tt:t) cout<<tt.first<<' '<<tt.second<<'\n';
//		cout<<"finish check\n";

		j=-1;le.clear();ri.clear();
		for(i=0;i<t.size();i++){
			if(t[i].second) tmp=p[t[i].first].rx;
			else tmp=p[t[i].first].lx;
//			cout<<"	check "<<i<<' '<<tmp<<' '<<j<<' '<<s[j+1]<<' '<<f[s[j+1]].x<<' '<<s.size()<<'\n';

			while((j<((int)s.size()-1))&&(f[s[j+1]].x<tmp)){
//				cout<<"		suc\n";
				j++;tval=BIT::sum(f[s[j]].y);
				if(tval<f[s[j]].k){
					f[s[j]].k-=tval;
					ri.push_back(s[j]);
//					q.push((ele){mid+1,r,s[j]});
				}
				else{
					le.push_back(s[j]);
//					q.push((ele){l,mid,s[j]});
				}
			}
			if(t[i].second) BIT::add(p[t[i].first].ly,p[t[i].first].ry,-1);
			else BIT::add(p[t[i].first].ly,p[t[i].first].ry,1);
		}
		while(j<((int)s.size()-1)){
			j++;tval=BIT::sum(f[s[j]].y);
			if(tval<f[s[j]].k){
				f[s[j]].k-=tval;
				ri.push_back(s[j]);
			}
			else{
				le.push_back(s[j]);
			}
		}
		for(auto lef:le) q.push((ele){l,mid,lef});
		for(auto rig:ri) q.push((ele){mid+1,r,rig});
	}
}
int main(){
	read(n);read(m);read(k);
	int i,t1,t2,t3,tmp;
	memset(first,-1,sizeof(first));
	for(i=1;i<n;i++){
		read(t1);read(t2);
		add(t1,t2);
	}
	dfs(1,0);ST();
	for(i=1;i<=m;i++){
		read(t1);read(t2);read(t3);
		if(dep[t2]<dep[t1]) swap(t1,t2);
		tmp=getpre(t1,t2);
		if(tmp){
//			cout<<"enter tp2 "<<tmp<<' '<<dfn[tmp]<<' '<<las[tmp]<<'\n';
			if(dfn[tmp]>1) p[++cntp]=(mat){1,dfn[tmp]-1+1,dfn[t2],las[t2],t3,i};
			if(las[tmp]<n) p[++cntp]=(mat){dfn[t2],las[t2]+1,las[tmp]+1,n,t3,i};
		}
		else{
			if(dfn[t2]<dfn[t1]) swap(t1,t2);
			p[++cntp]=(mat){dfn[t1],las[t1]+1,dfn[t2],las[t2],t3,i};
		}
	}
	
//	for(i=1;i<=cntp;i++) cout<<"check p "<<i<<' '<<p[i].lx<<' '<<p[i].rx<<' '<<p[i].ly<<' '<<p[i].ry<<' '<<p[i].val<<'\n';
	sort(p+1,p+cntp+1,cmp);
//	for(i=1;i<=cntp;i++) cout<<"check p "<<i<<' '<<p[i].lx<<' '<<p[i].rx<<' '<<p[i].ly<<' '<<p[i].ry<<' '<<p[i].val<<'\n';

	for(i=1;i<=k;i++){
		read(t1);read(t2);read(t3);
		if(dfn[t1]>dfn[t2]) swap(t1,t2);
		f[i]=(fru){dfn[t1],dfn[t2],i,0,t3};
	}
	solve();
	for(i=1;i<=k;i++) print(f[i].ans),el();
	flush();
}
