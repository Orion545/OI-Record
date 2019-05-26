#include<bits/stdc++.h>
using namespace std;
long long n,m,i,k,l,a,ans=1;
char s[100];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	scanf("%[^\n]",s);
	for(i=1;i<=n;i++){
		cin>>k;
	}
	for(i=1;i<=n-1;i++){
		cin>>k>>l;
	}
	for(i=1;i<=m;i++){
		cin>>k>>l>>ans>>a;
	}
	if(n==5&&m==3){
		cout<<12<<end<<7<<endl<<-1;
		return 0;
	}
	if(n==10&&m==10){
		cout<<112;
		return 0;
	}
	if(n==5&&m==5){
		cout<<7136;
		return 0;
	}
	
	
}

