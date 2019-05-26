#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std ;
int n ,m;
int a[5005][2];
int f[5005];
bool s[5005];
void pr(int num){
	for (int i=0;i<m;i++){
		if (a[i][0]==num&&s[i]) {s[i]=false;f[a[i][1]]=num; pr(a[i][1]);} 	
		if (a[i][1]==num&&s[i]) {s[i]=false;f[a[i][0]]=num; pr(a[i][0]);}
	}
}
void pt(int num){
	cout << num<<" ";
	for (int i=2;i<=n;i++)	{
	if (f[i]==num) pt(i);
	}
}
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >>n>>m;
	int  l,r;
	for (int i=0;i<=5000;i++) s[i]=true;
	for (int i=0;i<m;i++) {
		scanf("%d",&a[i][0]);
		scanf("%d",&a[i][1]);
		
	}
	pr(1);
	pt(1);
	return 0;
}
