#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
char s[200010],t[200010];int n,ext[100010],m,extend[100010];
void getnext(){
	int i,j,p,a,l;
	ext[0]=n;a=0;
	while(a<n&&t[a]==t[a+1]) a++;
	ext[1]=a;a=1;
	for(i=2;i<n;i++){
		p=a+ext[a]-1;l=ext[i-a];
		if(l+i-1>=p){
			j=max(p-i+1,0);
			while(i+j<n&&t[i+j]==t[j]) j++;
			ext[i]=j;a=i;
		}
		else ext[i]=l;
//		cout<<i<<' '<<ext[i]<<'\n';
	}
}
void exkmp(){
	int i,j,p,a,l;
	a=0;
	while(a<n&&s[a]==t[a]) a++;
	extend[0]=a;a=0;
	for(i=1;i<m;i++){
		p=a+extend[a]-1;l=ext[i-a];
		if(i+l-1>=p){
			j=max(p-i+1,0);
			while(i+j<m&&j<n&&s[i+j]==s[j]) j++;
			extend[i]=j;a=i;
		}
		else extend[i]=l;
//		cout<<i<<' '<<extend[i]<<'\n';
	}
}
int main(){
	int T;scanf("%d",&T);
	for(int ca=1;ca<=T;ca++){
		memset(s,0,sizeof(s));memset(t,0,sizeof(t));memset(ext,0,sizeof(ext));
		memset(extend,0,sizeof(extend));
		scanf("%s",t);n=strlen(t);int i,ans1=0,ans2=0,ans3=0,tmp;
		getnext();
		for(i=0;i<n;i++) s[i]=s[i+n]=t[i];
		m=strlen(s);
		exkmp();
		for(i=0;i<n;i++){
			if(extend[i]==n) ans2++;
			else{
				if(t[extend[i]]<s[extend[i]+i]) ans3++;
				else ans1++;
			}
		}
		printf("Case %d: %d %d %d\n",ca,ans1,(ans2!=0),ans3);
	}
}
