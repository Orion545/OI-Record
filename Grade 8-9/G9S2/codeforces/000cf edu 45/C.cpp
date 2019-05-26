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
ll n,l[300010],cntl=0,r[300010],cntr=0,cntm=0;char s[500010];
int main(){
	n=read();ll i,j,len,tot,ti,tj,ans=0,flag;
	for(j=1;j<=n;j++){
		scanf("%s",s);len=strlen(s);
		if(s[0]=='('){
			tot=0;flag=1;
			for(i=0;i<len;i++){
				if(s[i]=='(') tot++;
				else tot--;
				if(tot<0) flag=0;
			}
			if(flag){
				l[++cntl]=tot;
			}
		}
		if(s[len-1]==')'){
			tot=0;flag=1;
			for(i=len-1;i>=0;i--){
				if(s[i]==')') tot++;
				else tot--;
				if(tot<0) flag=0;
			}
			if(flag) r[++cntr]=tot; 
		}
	}
	sort(r+1,r+cntr+1);sort(l+1,l+cntl+1);
	i=1;j=1;
	while(i<=cntl&&j<=cntr){
		ti=i;tj=j;
		if(l[i]<r[j]){
			i++;continue;
		}
		if(l[i]>r[j]){
			j++;continue;
		}
		ll tmp=l[i];
		while(l[i]==tmp&&i<=cntl) i++;
		while(r[j]==tmp&&j<=cntr) j++;
		ans+=(i-ti)*(j-tj);
		if(l[i]<r[j]){
			i++;continue;
		}
		if(l[i]>r[j]){
			j++;continue;
		}
	}
	cout<<ans+cntm*cntm;
}
