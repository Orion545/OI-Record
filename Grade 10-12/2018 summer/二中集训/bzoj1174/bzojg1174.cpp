#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int son[9000010],bro[9000010],num[9000010],n,cnt,ans=0;short ch[9000010];string ss;
void insert(string s){
	int len=s.length(),i,cur=0,val,tmp;
	for(i=0;i<len;i++){
		if(s[i]>='A'&&s[i]<='Z') val=s[i]-'A'+1;
		if(s[i]>='a'&&s[i]<='z') val=s[i]-'a'+27;
		if(s[i]==' ') val=53;
		for(tmp=son[cur];tmp;tmp=bro[tmp]) if(ch[tmp]==val) break;
		if(!tmp){
			tmp=++cnt;
			bro[tmp]=son[cur];
			son[cur]=tmp;ch[tmp]=val;
		}
		num[tmp]++;
		ans=max(ans,num[tmp]*(i+1));
		cur=tmp;
	}
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++){
		getline(cin,ss);
		insert(ss);
	}
	cout<<ans;
}
