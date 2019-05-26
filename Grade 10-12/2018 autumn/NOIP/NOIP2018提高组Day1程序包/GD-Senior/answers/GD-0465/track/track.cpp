#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[50001];
int b[50001];
int l[50001];
int ans=0;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		cin>>a[i]>>b[i]>>l[i];
	}
	int ji[50001];
	bool pd[50001];
	for(int i=1;i<=50001;i++){
		pd[i]=false;
	}
    for(int i=1;i<=n-1;i++){
    	ji[a[i]]++;
    	ji[b[i]]++;
    }
    int js;
	for(int i=1;i<=n;i++){
		if(ji[i]==1){
			b[i]=true;
			js=i;
		}
	}
	ans+=l[js];
	cout<<ans;
	return 0;
}
