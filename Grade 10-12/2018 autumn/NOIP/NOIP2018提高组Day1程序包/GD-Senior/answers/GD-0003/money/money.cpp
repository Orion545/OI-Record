#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;

int n,tmp[105],arr[105],cans[105];
bool sh[30005];

void solve2(){
	if((tmp[1]%tmp[0])==0)printf("1");
	else printf("2");
}

void d(){
	int mx=arr[n-1];
	int f=0;
	for(int i=1;i<=mx;i++){
		for(int j=0;j<n;j++){
			if(arr[j]>i)break;
			sh[i]|=sh[i-arr[j]];
		}
		while(i==arr[f]){
			cans[f]=sh[i];
			sh[i]=true;
			f++;
		}
	}
}

void solveo(){
	int rmn=n,ind=0;
	arr[ind++]=tmp[0];
	for(int i=1;i<n;i++){
		if(tmp[i]!=tmp[i-1]){
			arr[ind++]=tmp[i];
		}else rmn--;
	}
	n=rmn;
	//for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	d();
	int r=n;
	for(int i=0;i<n;i++){
		if(cans[i])r--;
	}
	cout<<r<<endl;
}

void solve(){
	memset(sh,0,sizeof(sh));
	memset(cans,0,sizeof(cans));
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&tmp[i]);
	}
	
	sort(tmp,tmp+n);
	
	if(n==2)solve2();
	else solveo();
}


int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		solve();
	}
	return 0;
}
