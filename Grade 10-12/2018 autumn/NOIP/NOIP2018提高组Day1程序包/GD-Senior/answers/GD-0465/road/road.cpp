#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	int d[100001];
	int js;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	int ji=1;
	while(ji<=n){
		js=d[ji];
		for(int i=1;i<=js;i++){
		    ans++;
		    for(int k=ji;k<=n;k++){
		    	if(d[k]>0){
		    		d[k]--;
		    	}else{
		    		break;
		    	}
		    }
	    }
	    ji++;
	}
	cout<<ans;
	return 0;
}
