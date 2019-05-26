#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
#define MOD 19260817ll
#define ll unsigned long long
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
int pre1[50010],pre2[50010],fail[50010],n,m,lenn;
void getfail(char b[],int len){
	int i,j=0;fail[0]=fail[1]=0;
	for(i=1;i<len;i++){
		while(j&&b[i]!=b[j]) j=fail[j];
		j+=(b[i]==b[j]);
		fail[i+1]=j;
	}
}
char s1[50010],s2[50010],s3[10010];
void kmp(){
	int i,j=0;
	for(i=0;i<n;i++){
		pre1[i+1]=pre1[i];
		while(j&&s1[i]!=s3[j]) j=fail[j];
		j+=(s1[i]==s3[j]);
		if(j==lenn) pre1[i+1]++;
	}
	j=0;
	for(i=0;i<m;i++){
		pre2[i+1]=pre2[i];
		while(j&&s2[i]!=s3[j]) j=fail[j];
		j+=(s2[i]==s3[j]);
		if(j==lenn) pre2[i+1]++;
	}
}
ll hash1[50010],hash2[50010],ppow[50010];
void gethash(){
	int i;
	for(i=0;i<n;i++) hash1[i+1]=hash1[i]*MOD+s1[i];
	for(i=0;i<m;i++) hash2[i+1]=hash2[i]*MOD+s2[i];
	ppow[0]=1;
	for(i=0;i<max(n,m);i++) ppow[i+1]=ppow[i]*MOD;
//	for(i=1;i<=n;i++) cout<<hash1[i]-hash1[i-1]*ppow[1]<<' ';cout<<'\n';
}
map<ll,int>mp;
bool check(int len){
	mp.clear();int i,j,cnt=0;
	for(i=1;i<=n;i++){
		j=i+len-1;if(j>n) break;
		if(len>=lenn&&(pre1[j]-pre1[i+lenn-2])) continue;
//		cout<<"insert map "<<i<<' '<<j<<' '<<hash1[j]-ppow[len]*hash1[i-1]<<'\n';
		mp[hash1[j]-ppow[len]*hash1[i-1]]=++cnt;
	}
	for(i=1;i<=m;i++){
		j=i+len-1;if(j>m) break;
		if(len>=lenn&&(pre2[j]-pre2[i+lenn-2])) continue;
		if(mp[hash2[j]-ppow[len]*hash2[i-1]]){
//			cout<<"success check map "<<i<<' '<<j<<' '<<hash2[j]-ppow[len]*hash2[i-1]<<'\n';
			return 1;
		}
	}
	return 0;
}
int main(){
//	freopen("my.out","w",stdout);
	scanf("%s",s1);n=strlen(s1);
	scanf("%s",s2);m=strlen(s2);
	scanf("%s",s3);lenn=strlen(s3);
	int l,r,mid;
	getfail(s3,lenn);kmp();gethash();
//	for(int i=1;i<=n;i++) cout<<pre1[i]<<' '<<pre2[i]<<'\n';
	l=0;r=min(n,m);
	while(l<r){
//		cout<<l<<' '<<r<<'\n';
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
/*
cbbcbaaaca
bacccbacaa
b

*/
