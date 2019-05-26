#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
struct node{
	int num,dep,fail,son[26];
	node(){num=fail=dep=0;memset(son,0,sizeof(son));}
}a[100010];int cnt=0;
inline void add(char s[]){
	int len=strlen(s),i,cur=0;
	for(i=0;i<len;i++){
		if(!a[cur].son[s[i]-'a']) a[cur].son[s[i]-'a']=++cnt;
		a[a[cur].son[s[i]-'a']].dep=a[cur].dep+1;cur=a[cur].son[s[i]-'a'];
//		cout<<"insert "<<s[i]<<ends<<cur<<endl;
	}
	a[cur].num++;
}
int q[100010];
void getfail(){
	int i,u,v,head=0,tail=0;
	for(i=0;i<26;i++){
		if(!a[0].son[i]) continue;
		a[a[0].son[i]].fail=0;q[tail++]=a[0].son[i];
	}
	while(head<tail){
		u=q[head++];
//		cout<<"bfs "<<u<<ends<<a[u].fail<<ends<<a[u].dep<<ends<<a[u].num<<endl;
		for(i=0;i<26;i++){
			v=a[u].son[i];
			if(v) a[v].fail=a[a[u].fail].son[i],q[tail++]=v;
			else a[u].son[i]=a[a[u].fail].son[i];
		}
	}
}
char x[100010],s[100010];int n;
int s1[100010]={0},s2[100010]={0},top1=0,top2=0;
int main(){
//	freopen("3121.in","r",stdin); 
//	freopen("3121.ans","w",stdout);
	scanf("%s",x);int i,j,len=strlen(x),cur,tmp,flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",s),add(s);
	getfail();
	
	cur=0;
	for(i=0;i<len;i++){
		tmp=x[i]-'a';flag=0;
		cur=a[cur].son[tmp];s1[++top1]=cur;s2[++top2]=i;
		if(!cur){
			while(top1--) s1[top1]=0;
//			while(top2--) s2[top2]=0;
			continue;
		}
//		cout<<"do "<<i<<ends<<x[i]<<ends<<cur<<ends<<a[cur].num<<endl;
//		for(tmp=cur;tmp;tmp=a[tmp].fail) 
//			if(a[tmp].num){
//				flag=1;break;
//			}
		flag=a[cur].num;
		if(!flag) continue;
		j=a[cur].dep;
//		cout<<"cleaned "<<j<<endl;
		while(j--) s1[top1--]=0,s2[top2--]=0;
		cur=s1[top1];
	}
	for(i=1;i<=top2;i++) putchar(x[s2[i]]);
}
