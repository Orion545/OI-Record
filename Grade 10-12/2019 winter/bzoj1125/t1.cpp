#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<unordered_map>
#define MOD 19260817
#define hash DEEP_DARK_FANTASY
#define ll unsigned long long
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
inline int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n,m,len,root[800010],num=0,ans[2010];ll hash[1010],p[1010];char s[1010][110];
unordered_map<ll,int>mp;
namespace t{
	int ch[8000010][2],siz[800010],tag[800010],key[800010],pos[800010],cnt;
	inline void push(int cur){
		if(tag[cur]==-1) return;
		tag[ch[cur][0]]=max(tag[cur],tag[ch[cur][0]]);
		tag[ch[cur][1]]=max(tag[cur],tag[ch[cur][1]]);
		ans[pos[ch[cur][0]]]=max(ans[pos[ch[cur][0]]],tag[cur]);
		ans[pos[ch[cur][1]]]=max(ans[pos[ch[cur][1]]],tag[cur]);
		tag[cur]=-1;
	}
	inline void update(int cur){
		if(!cur) return;
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
//		cout<<"		update "<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<siz[cur]<<'\n';
	}
	inline int newnode(int val){
		int cur=++cnt;
		ch[cur][0]=ch[cur][1]=0;siz[cur]=1;
		tag[cur]=-1;pos[cur]=val;key[cur]=random(1,1e9);
		return cur;
	}
	void split(int &curl,int &curr,int cur,int lim){
		if(!cur){curl=curr=0;return;}
		push(cur);
		if(pos[cur]>lim) curr=cur,split(curl,ch[curr][0],ch[cur][0],lim);
		else curl=cur,split(ch[curl][1],curr,ch[cur][1],lim);
		update(curl);update(curr);
	}
	void merge(int &cur,int curl,int curr){
		if(!curl||!curr){cur=curl^curr;return;}
		push(curl);push(curr);
		if(key[curl]<key[curr]) cur=curl,merge(ch[cur][1],ch[curl][1],curr);
		else cur=curr,merge(ch[cur][0],curl,ch[curr][0]);
		update(cur);
	}
	void erase(int &rt,int val){
		int le,mid,ri;
//		cout<<"	before erase "<<siz[rt]<<' '<<val<<'\n';
		split(le,ri,rt,val);
		split(le,mid,le,val-1);
		merge(rt,le,ri);
//		cout<<"	after erase "<<siz[rt]<<' '<<le<<' '<<pos[le]<<' '<<siz[le]<<' '<<ri<<' '<<pos[ri]<<' '<<siz[ri]<<'\n';
	}
	void insert(int &rt,int val){
		int le,ri;
		split(le,ri,rt,val);
		merge(le,le,newnode(val));
		merge(rt,le,ri);
		tag[rt]=max(tag[rt],siz[rt]);
		ans[pos[rt]]=max(ans[pos[rt]],siz[rt]);
//		cout<<"	finish insert "<<rt<<' '<<siz[rt]<<' '<<pos[rt]<<' '<<ans[pos[rt]]<<'\n';
	}
	void dfs(int cur){
		if(!cur) return;
		push(cur);
		dfs(ch[cur][0]);dfs(ch[cur][1]);
	}
}
int main(){
	n=read();len=read();m=read();int i,j,k,t1,t2,t3,t4;
	p[0]=1;
	for(i=1;i<=n;i++) p[i]=p[i-1]*MOD;
	for(i=1;i<=n;i++){
		scanf("%s",s[i]);
		for(j=0;j<len;j++)
			hash[i]=hash[i]*MOD+(ll)s[i][j];
		if(!mp[hash[i]]) mp[hash[i]]=++num;
		t::insert(root[mp[hash[i]]],i);
//		cout<<"finish input "<<i<<' '<<hash[i]<<'\n';
	}
	while(m--){
		t1=read();t2=read();t3=read();t4=read();
		t2--;t4--;
//		cout<<"change "<<t1<<' '<<t2<<' '<<hash[t1]<<' '<<t3<<' '<<t4<<' '<<hash[t3]<<'\n';
		t::erase(root[mp[hash[t1]]],t1);
		if(t1!=t3) t::erase(root[mp[hash[t3]]],t3);
		swap(s[t1][t2],s[t3][t4]);
		hash[t1]+=p[len-t2-1]*(ll)(s[t1][t2]-s[t3][t4]);
		hash[t3]+=p[len-t4-1]*(ll)(s[t3][t4]-s[t1][t2]);
		if(!mp[hash[t1]]) mp[hash[t1]]=++num;
		if(!mp[hash[t3]]) mp[hash[t3]]=++num;
//		cout<<"after change "<<t1<<' '<<hash[t1]<<' '<<mp[hash[t1]]<<' '<<t3<<' '<<hash[t3]<<' '<<mp[hash[t3]]<<'\n';
		t::insert(root[mp[hash[t1]]],t1);
		if(t1!=t3) t::insert(root[mp[hash[t3]]],t3);
	}
	for(i=1;i<=num;i++) t::dfs(root[i]);
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}
		
