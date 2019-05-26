#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,root[2010],m,l[2010],r[2010],cnt,rk[2010];
char s[2000010],ts[2000010],s1[2000010],s2[2000010];
inline int cmp(int x,int y){
	int curl=l[x],curr=l[y];
	while(curl<=r[x]&&curr<=r[y]){
		if(s[curl]!=s[curr]) return s[curl]<s[curr];
		curl++,curr++;
	}
	if(r[x]-curl<r[y]-curr) return 1;
	return 0;
}
namespace tr{
	int ch[2000010][26],l[2000010],r[2000010],cnt;
	void init(){
		cnt=0;
		for(int i=1;i<=2000000;i++) l[i]=1e9;
	}
	void insert(int ql,int qr,int num){
		int cur=0,i;
//		cout<<"insert "<<ql<<' '<<qr<<' '<<num<<'\n';
		for(i=ql;i<=qr;i++){
			if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++cnt;
			cur=ch[cur][s[i]-'a'];
			l[cur]=min(l[cur],num);r[cur]=max(r[cur],num);
//			cout<<"	do "<<i<<' '<<s[i]<<' '<<cur<<' '<<l[cur]<<' '<<r[cur]<<'\n';
		}
	}
	int query(char s[]){
		int cur=0,i,len=strlen(s);
		for(i=0;i<len;i++){
			cur=ch[cur][s[i]-'a'];
//			cout<<"query "<<i<<' '<<s[i]<<' '<<cur<<' '<<l[cur]<<' '<<r[cur]<<'\n';
			if(!cur) return 0;
		}
		return cur;
	}
}
namespace tri{
	int ch[2000010][26],num[2000010],cnt;
	int insert(int pre,int ql,int qr){
		int i,cur=++cnt;int re=cnt;
		for(i=qr;i>=ql;i--){
			num[cur]=num[pre]+1;
			memcpy(ch[cur],ch[pre],sizeof(ch[pre]));
			ch[cur][s[i]-'a']=++cnt;
//			cout<<"	do "<<i<<' '<<s[i]<<' '<<cur<<' '<<num[cur]<<'\n';
			cur=ch[cur][s[i]-'a'];
			pre=ch[pre][s[i]-'a'];
		}
		num[cur]=num[pre]+1;
		memcpy(ch[cur],ch[pre],sizeof(ch[pre]));
		return re;
	}
	int query(int pre,int cur,char s[]){
		int i,len=strlen(s);
//		cout<<"QUERY "<<pre<<' '<<cur<<' '<<s<<'\n';
		for(i=0;i<len;i++){
			cur=ch[cur][s[i]-'a'];
			pre=ch[pre][s[i]-'a'];
//			cout<<"	DO "<<i<<' '<<s[i]<<' '<<cur<<' '<<pre<<' '<<num[cur]<<' '<<num[pre]<<'\n';
		}
		return num[cur]-num[pre];
	}
}
int main(){
	freopen("1.in","r",stdin);
	freopen("my.out","w",stdout);
	n=read();int i,lastans=0,t1,t2,j;cnt=0;
	for(i=1;i<=n;i++){
		scanf("%s",ts);
		l[i]=cnt+1;
		for(j=1;j<=strlen(ts);j++) s[++cnt]=ts[j-1];
		r[i]=cnt;
//		cout<<"readin "<<i<<' '<<ts<<' '<<l[i]<<' '<<r[i]<<'\n';
	}
	for(i=1;i<=n;i++) rk[i]=i;
	
	sort(rk+1,rk+n+1,cmp);
	tr::init();
	
	for(i=1;i<=n;i++) tr::insert(l[rk[i]],r[rk[i]],i);
	for(i=1;i<=n;i++){
		root[i]=tri::insert(root[i-1],l[rk[i]],r[rk[i]]);
//		cout<<"TRI root "<<i<<' '<<root[i]<<'\n';
	}
	m=read();
	while(m--){
		scanf("%s",s1);scanf("%s",s2);
		t1=strlen(s1);t2=strlen(s2);
		for(i=0;i<t1;i++) s1[i]=(s1[i]-'a'+lastans)%26+'a';
		for(i=0;i<t2;i++) s2[i]=(s2[i]-'a'+lastans)%26+'a';
		reverse(s2,s2+t2);
		t1=tr::query(s1);
//		cout<<"********	half query "<<t1<<' '<<tr::l[t1]<<' '<<tr::r[t1]<<'\n';
		t2=tri::query(root[tr::l[t1]-1],root[tr::r[t1]],s2);
		printf("%d\n",lastans=t2);
	}
}
