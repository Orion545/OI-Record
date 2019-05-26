#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std ;
int allnum[26][20];
int nnn[26];
int os(int o,int num){
	bool a[45];
	for (int i=0;i<=40;i++) a[i]=true;
	int ans=num;
	for (int i=0;i<nnn[o];i++){
		for (int t=allnum[o][i];t<=40;t+=allnum[o][i]){
			for (int n=1;n<nnn[o];n++){
				for (int s=0;s+t<=40;s+=allnum[o][n]){
					if (t==allnum[o][i]&&s==0)	break;
					a[s+t]=false;
				}
			}
		}
	}
	for (int i=0;i<nnn[o];i++){
		if (!a[allnum[o][i]]) ans--;
	}
	return ans;
}
int  main (){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int num,lsnum;
	cin >> num;
	for (int i=0;i<num;i++){
		cin >>nnn[i];
		for (int t=0;t<nnn[i];t++)	scanf("%d",&allnum[i][t]);
	}
	
	for (int i=0;i<num;i++)	cout <<os(i,nnn[i])<<endl;
	return 0;
}
