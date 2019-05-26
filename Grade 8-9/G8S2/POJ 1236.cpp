#include<iostream>
#include<cstring>
using namespace std;
int index=0,qlt[110];
struct erickin{
	int data,next;
}edge[50010];
struct Stack{
	int a[200],top;
	Stack(){
		memset(a,0,sizeof(a));top=0;
	}
	void push(int k){a[++top]=k;}
	void pop(){a[top--]=0;}
	void pop_to_k(int k){
		index++;
		if(a[top]==k){
			qlt[a[top]]=index;a[top--]=0;
		}
		else{
			while(a[top]!=k){
				qlt[a[top]]=index;a[top--]=0;
			}
			qlt[a[top]]=index;a[top--]=0;
		}
		return;
	}
}s;
int n,m=0,first[110];
int dfn[110]={0},low[110]={0},times=0;
bool vis[110]={0};
void tarjan(int k){
	dfn[k]=low[k]=++times;
	vis[k]=1;s.push(k);
	int p=first[k];
	while(p!=-1){
		if(!vis[edge[p].data]){
			tarjan(edge[p].data);low[k]=min(low[k],low[edge[p].data]);
		}
		else if(!qlt[edge[p].data]) low[k]=min(low[k],dfn[edge[p].data]);
		p=edge[p].next;
	}
	if(low[k]==dfn[k]) s.pop_to_k(k);
	return;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;int input,tt[110];
	memset(tt,-1,sizeof(tt));memset(first,-1,sizeof(first));
	for(int i=1;i<=n;i++){
		while(cin>>input&&input){
			m++;
			edge[m].data=input;edge[m].next=tt[i];
			first[i]=tt[i]=m;
		}
	}
	int in[110]={0},out[110]={0};
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		int p=first[i];
		while(p!=-1){
			if(qlt[i]!=qlt[edge[p].data]){
				in[qlt[edge[p].data]]++;out[qlt[i]]++;
			}
			p=edge[p].next;
		}
	}
	int s1=0,s2=0;
	for(int i=1;i<=index;i++){
		if(!in[i]) s1++;
		if(!out[i]) s2++;
	}
	cout<<s1<<endl<<s2;
}
