#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#include<vector>
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
int n,m,from[100010],to[100010],a[100010],len[100010]={0};
vector<int>d[100010];
int main(){
//	d[0].push_back(1);cout<<(upper_bound(d[0].begin(),d[0].end(),0)-d[0].begin());
	n=read();m=read();int i;
	for(i=1;i<=m;i++) from[i]=read(),to[i]=read(),a[i]=read();
	d[to[1]].push_back(a[1]);len[to[1]]=1;
	for(i=2;i<=m;i++){
//		cout<<len[from[i]]<<ends<<len[to[i]]<<ends<<a[i]<<endl;
//		if(len[from[i]]) cout<<d[from[i]][len[from[i]]-1]<<endl;
		if(len[from[i]]==0||d[from[i]][len[from[i]]-1]<a[i]){
			int pos=upper_bound(d[to[i]].begin(),d[to[i]].end(),a[i])-d[to[i]].begin();
			while(pos<d[to[i]].size()&&pos<(len[from[i]]+1)){
				d[to[i]][pos]=a[i];pos++;
			}
			if(len[to[i]]<len[from[i]]+1){
				while(d[to[i]].size()<=len[from[i]]) d[to[i]].push_back(a[i]);
			}
//			else d[to[i]][len[from[i]]]=min(d[to[i]][len[from[i]]],a[i]);
			len[to[i]]=max(len[to[i]],len[from[i]]+1);
		}
		else{
			int pos=lower_bound(d[from[i]].begin(),d[from[i]].end(),a[i])-d[from[i]].begin();
//			cout<<"second "<<pos<<endl;
			int ppos=upper_bound(d[to[i]].begin(),d[to[i]].end(),a[i])-d[to[i]].begin();
			while(ppos<d[to[i]].size()&&ppos<(pos+1)){
				d[to[i]][ppos]=a[i];ppos++;
			}
			if(len[to[i]]<pos+1){
				while(d[to[i]].size()<=pos) d[to[i]].push_back(a[i]);
			}
//			else d[to[i]][pos]=min(d[to[i]][pos],a[i]);
			len[to[i]]=max(len[to[i]],pos+1);
		}
	}
	int ans=0;
	for(i=1;i<=n;i++) ans=max(ans,len[i]);
	cout<<ans;
}

