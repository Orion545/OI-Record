#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int cnt,tot,root,rt[200010],ch[10000010][2],siz[10000010],tag[10000010];
int add(int val=1){
	tot++;
	ch[tot][0]=ch[tot][1]=0;
	tag[tot]=val-1;
	siz[tot]=(1<<tag[tot]);
	return tot;
}
void push(int pos){
	if(!tag[pos]) return;
	ch[pos][0]=add(tag[pos]);
	ch[pos][1]=add(tag[pos]);
	tag[pos]=0;
	return;
}
int split(int val){
	int cur=++tot,re=cur,pre=root;
	push(pre);
	if(val>siz[pre]) return -1;
	while(ch[pre][0]||ch[pre][1]){
//		cout<<"split "<<cur<<' '<<pre<<' '<<siz[pre]<<' '<<val<<' '<<siz[ch[pre][0]]<<' '<<siz[ch[pre][1]]<<' '<<ch[pre][0]<<' '<<ch[pre][1]<<'\n';
		tag[cur]=0;siz[cur]=val;siz[pre]-=val;
		if(val<=siz[ch[pre][0]]){
			ch[cur][0]=add();ch[cur][1]=0;
			cur=ch[cur][0];pre=ch[pre][0];
		}
		else{
			ch[cur][1]=add();ch[cur][0]=ch[pre][0];
			val-=siz[ch[cur][0]];ch[pre][0]=0;
			cur=ch[cur][1];pre=ch[pre][1];
		}
		push(pre);
	}
	tag[cur]=tag[pre]=0;
	siz[cur]=val;siz[pre]-=val;
//	cout<<"split "<<cur<<' '<<pre<<' '<<siz[cur]<<' '<<siz[pre]<<'\n';
	return re;
}
int merge(int pre,int cur){
//	cout<<"merge "<<pre<<' '<<cur<<' '<<siz[cur]<<' '<<siz[pre]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<ch[pre][0]<<' '<<ch[pre][1]<<'\n';
	if(!pre||!cur) return pre+cur;
	push(cur);push(pre);
	ch[cur][0]=merge(ch[pre][0],ch[cur][0]);
	ch[cur][1]=merge(ch[pre][1],ch[cur][1]);
	siz[cur]+=siz[pre];
	return cur;
}
int query(int pos,int val){
	int cur=rt[pos],re=0;
	if(pos>cnt||siz[cur]<=val) return -1;
	while(ch[cur][0]||ch[cur][1]){
		re<<=1;
//		cout<<"query "<<cur<<' '<<siz[cur]<<' '<<val<<' '<<re<<'\n';
		if(ch[cur][0]&&siz[ch[cur][0]]>val){
			cur=ch[cur][0];
		}
		else{
			val-=siz[ch[cur][0]];re|=1;
			cur=ch[cur][1];
		}
	}
	return (1<<tag[cur])*re+val;
}
int alloc(int val){
	rt[++cnt]=0;
	int tmp=split(val);
	if(tmp==-1) return tmp;
	rt[cnt]=tmp;return 1;
}
int free(int val){
	if(val>cnt||!rt[val]) return -1;
	root=merge(rt[val],root);
	rt[val]=0;return 1;
}
int main(){
	int T=read(),n,t1,t2,t3;
	while(T--){
		tot=cnt=0;
		root=add(31);
		n=read();
		while(n--){
			t1=read();
			if(t1==1){
				t2=read();
				puts((~alloc(t2))?"ok":"failed");
			}
			if(t1==2){
				t2=read();
				puts((~free(t2))?"ok":"failed");
			}
			if(t1==3){
				t2=read();t3=read();
				int tmp=query(t2,t3);
				if(~tmp) printf("%d\n",tmp);
				else puts("failed");
			}
		}
	}
}
