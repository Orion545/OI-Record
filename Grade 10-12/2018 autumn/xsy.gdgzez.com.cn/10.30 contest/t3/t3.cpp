/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#define ll long long
#define id(x,y) ((x*300000ll)+y*1ll)
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;char __c=getc();
        while(!isdigit(__c)) __c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
    }
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(__c<'A'||__c>'Z') __c=getc();
        while(__c>='A'&&__c<='Z') __s[++__tot]=__c,__c=getc();
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
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;

int vis[300010],pos[300010];
struct path{
	int s,t;ll a[2],b[2];vector<int>x;
	
	path(){a[0]=a[1]=1e9; b[0]=b[1]=2e9+10;x.clear();s=t=0;}
	
	ll solve(){
		
//		cout<<"begin solve "<<x.size()<<' '<<a[0]<<' '<<a[1]<<' '<<b[0]<<' '<<b[1]<<'\n';
		
		int n=x.size(),i,cur,tot;ll ans=0;
		for(i=0;i<=n;i++) vis[i]=0;
		
		if(b[1]<b[0]){
			swap(a[1],a[0]);swap(b[1],b[0]);
			for(i=0;i<n;i++) x[i]^=1;
		}
		a[0]=min(a[0],b[0]);a[1]=min(a[1],b[1]);
		
		if(a[0]+a[1]<=b[0]){
			
//			cout<<"debug type 1\n";
			
			for(i=0;i<n;i++) ans+=a[x[i]];
			return ans;
		}
		
		if(a[0]+a[1]<=b[1]){
			
//			cout<<"debug type 2\n";
			
			cur=0;tot=0;
			for(i=0;i<n;i++) tot+=x[i];
			
			for(i=0;i<n;i++){
				
//				cout<<"	checking stacklike "<<i<<' '<<x[i]<<' '<<cur<<' '<<tot<<'\n';
				
				if(!x[i]&&cur<tot){
					cur++;
					vis[i]=1;
					ans+=b[0];
				}
				if(x[i]){
					tot--;
					if(cur) cur--,vis[i]=1;
				}
			}
			
			for(i=0;i<n;i++){
				if(!vis[i]) ans+=a[x[i]];
			}
			return ans;
		}
		else{
			
//			cout<<"debug type 3\n";
			
			cur=0;tot=0;
			for(i=0;i<n;i++) tot+=x[i];
			
			for(i=0;i<n;i++){
				if(!x[i]&&cur<tot){
					cur++;
					vis[i]=1;
					ans+=b[0];
				}
				if(x[i]){
					tot--;
					if(cur) cur--,vis[i]=1;
				}
			}
			
			tot=0;cur=0;
			for(i=0;i<n;i++){
				if(!vis[i]) tot+=x[i]^1;
			}
			
			for(i=0;i<n;i++){
				if(vis[i]) continue;
				if(x[i]&&cur<tot){
					vis[i]=1;
					cur++;
					ans+=b[1];
				}
				if(!x[i]){
					tot--;
					if(cur) vis[i]=1,cur--;
				}
			}
			
			for(i=0;i<n;i++){
				if(!vis[i]) ans+=a[x[i]];
			}
			return ans;
		}
	}
}a[300010];int cnta;
unordered_map<ll,path*>mp;
int n,m,k;
int main(){
//	freopen("in.in","r",stdin);
	
//	cout<<"begin input\n";
	
	read(n);read(m);
	int i,t1,t2,flag;;ll t3;char str[10];path *tmp;
	for(i=1;i<=m;i++) read(pos[i]);
	for(i=1;i<m;i++){
		if(!mp.count(id(pos[i],pos[i+1]))){
			cnta++;
			mp[id(pos[i],pos[i+1])]=&a[cnta];
			mp[id(pos[i+1],pos[i])]=&a[cnta];
			a[cnta].s=pos[i];
			a[cnta].t=pos[i+1];
			a[cnta].x.push_back(0);
		}
		else{
			tmp=mp[id(pos[i],pos[i+1])];
			tmp->x.push_back(pos[i]!=tmp->s);
		}
	}
	
//	cout<<"finish readin\n";
	
	read(k);
	for(i=1;i<=k;i++){
		read(t1);read(t2);reads(str,0);read(t3);
		if(!mp.count(id(t1,t2))) continue;
		tmp=mp[id(t1,t2)];
		
		if(str[0]=='O'){
			flag=(t1!=tmp->s);
			tmp->a[flag]=min(tmp->a[flag],t3);
		}
		else{
			flag=(t1!=tmp->s);
			tmp->b[flag]=min(tmp->b[flag],t3);
		}
	}
	
//	cout<<"finish readin\n";
	
	ll ans=0;
	for(i=1;i<=cnta;i++) ans+=a[i].solve();
	
	print(ans);el();flush();
}
