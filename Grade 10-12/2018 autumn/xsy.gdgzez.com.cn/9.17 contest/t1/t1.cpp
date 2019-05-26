#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct node{
	ll key,num;
};
bool operator <(node l,node r){
	return l.key<r.key;
}
map<ll,ll>visl,visr;
vector<node>s[200010],sgo[200010],t[200010],tgo[200010];
ll cntl,cntr,x[200010],y[200010],vis[200010];
ll dis(ll A,ll B,ll C,ll x0,ll y0){
	return abs(A*x0+B*y0+C);
}
ll n,opx,opy,que[200010];
int main(){
//	freopen("in.txt","r",stdin);
	n=read();opx=read();opy=read();ll i,t1,t2,t3,t4,u;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		t3=((t1>t2)?1:-1)*dis(1,-1,0,t1,t2);
		t4=((t1>(-t2))?1:-1)*dis(1,1,0,t1,t2);
		x[i]=t3;y[i]=t4;
//		cout<<"input "<<i<<' '<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
		//row
		if(visl.count(t3)==0) visl[t3]=++cntl;
		s[visl[t3]].push_back((node){t4,i});
		sgo[visl[t3]].push_back((node){t4,i});
		//column
		if(visr.count(t4)==0) visr[t4]=++cntr;
		t[visr[t4]].push_back((node){t3,i});
		tgo[visr[t4]].push_back((node){t3,i});
	}
	
	for(i=1;i<=cntl;i++) sort(s[i].begin(),s[i].end()),sort(sgo[i].begin(),sgo[i].end());
	for(i=1;i<=cntr;i++) sort(t[i].begin(),t[i].end()),sort(tgo[i].begin(),tgo[i].end());
//	for(i=1;i<=cntl;i++) cout<<i<<' '<<sgo[i].size()<<' '<<sgo[i][0].key<<'\n';
//	for(i=1;i<=cntr;i++) cout<<i<<' '<<tgo[i].size()<<' '<<tgo[i][0].key<<'\n';
	
	ll head=0,tail=2,dis=max(abs(x[opx]-x[opy]),abs(y[opx]-y[opy])),ans=0,cur;
	ll p,q;vector<node>::iterator l,r,k;
	que[0]=opx;que[1]=opy;
	while(head<tail){
//		cout<<"begin bfs "<<head<<' '<<tail<<'\n';
		u=que[head++];
		if(vis[u]) continue;
		vis[u]=1;
		//getans
		//up
		t3=x[u];t4=y[u];
//		cout<<"bfs "<<u<<' '<<t3<<' '<<t4<<' '<<dis<<'\n';
		if(visr[t4+dis]){
			cur=visr[t4+dis];
			p=lower_bound(t[cur].begin(),t[cur].end(),(node){t3-dis,0})-t[cur].begin();
			q=upper_bound(t[cur].begin(),t[cur].end(),(node){t3+dis,0})-t[cur].begin();
//			cout<<"	cntans up "<<t4+dis<<' '<<t3-dis<<' '<<t3+dis<<' '<<p<<' '<<q<<'\n';
			ans+=(q-p);
		}
		//down
		if(visr[t4-(dis)]){
			cur=visr[t4-(dis)];
			p=lower_bound(t[cur].begin(),t[cur].end(),(node){t3-dis,0})-t[cur].begin();
			q=upper_bound(t[cur].begin(),t[cur].end(),(node){t3+dis,0})-t[cur].begin();
//			cout<<"	cntans down "<<t4-dis<<' '<<t3-dis<<' '<<t3+dis<<' '<<p<<' '<<q<<'\n';
			ans+=(q-p);
		}
		//left
		if(visl[t3+(dis)]){
			cur=visl[t3+(dis)];
			p=upper_bound(s[cur].begin(),s[cur].end(),(node){t4-dis,0})-s[cur].begin();
			q=lower_bound(s[cur].begin(),s[cur].end(),(node){t4+dis,0})-s[cur].begin();
//			cout<<"	cntans right "<<t3+dis<<' '<<t4-dis<<' '<<t4+dis<<' '<<p<<' '<<q<<'\n';
			ans+=(q-p);
		}
		//right
		if(visl[t3-(dis)]){
			cur=visl[t3-(dis)];
			p=upper_bound(s[cur].begin(),s[cur].end(),(node){t4-dis,0})-s[cur].begin();
			q=lower_bound(s[cur].begin(),s[cur].end(),(node){t4+dis,0})-s[cur].begin();
//			cout<<"	cntans left "<<t3-dis<<' '<<t4-dis<<' '<<t4+dis<<' '<<p<<' '<<q<<'\n';
			ans+=(q-p);
		}
		//extend
		//up
		if(visr[t4-(dis)]){
			cur=visr[t4-(dis)];
			l=lower_bound(tgo[cur].begin(),tgo[cur].end(),(node){t3-dis,0});
			r=upper_bound(tgo[cur].begin(),tgo[cur].end(),(node){t3+dis,0});
			for(k=l;k!=r;k++) que[tail++]=(*k).num;
			tgo[cur].erase(l,r);
		}
		//down
		if(visr[t4+(dis)]){
			cur=visr[t4+(dis)];
			l=lower_bound(tgo[cur].begin(),tgo[cur].end(),(node){t3-dis,0});
			r=upper_bound(tgo[cur].begin(),tgo[cur].end(),(node){t3+dis,0});
			for(k=l;k!=r;k++) que[tail++]=(*k).num;
			tgo[cur].erase(l,r);
		}
		//left
		if(visl[t3-(dis)]){
			cur=visl[t3-(dis)];
			l=upper_bound(sgo[cur].begin(),sgo[cur].end(),(node){t4-dis,0});
			r=lower_bound(sgo[cur].begin(),sgo[cur].end(),(node){t4+dis,0});
			for(k=l;k!=r;k++) que[tail++]=(*k).num;
			sgo[cur].erase(l,r);
		}
		//right
		if(visl[t3+(dis)]){
			cur=visl[t3+(dis)];
			l=upper_bound(sgo[cur].begin(),sgo[cur].end(),(node){t4-dis,0});
			r=lower_bound(sgo[cur].begin(),sgo[cur].end(),(node){t4+dis,0});
			for(k=l;k!=r;k++) que[tail++]=(*k).num;
			sgo[cur].erase(l,r);
		}
	}
	printf("%lld\n",ans/2);
}
//Û¤·¤Æ¤ë£¡ 
