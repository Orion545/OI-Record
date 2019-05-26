/*
ID: marcoli2
PROG: beads
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int n;string a,tt;
int main(){
	int i,j,ans=0,flag,tmp;
	char t;
	std::ios::sync_with_stdio(false);
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	cin>>n;cin>>tt;
	a=tt+tt+tt;
//	cout<<a<<endl;
	for(i=n-1;i<n*2;i++){
//		cout<<i<<endl;
		tmp=0;
		flag=1;
		for(j=i;j>=i-n+1;j--){
			if(flag){
				if(a[j]=='w') tmp++;
				else tmp++,t=a[j],flag=0;
			}
			else{
				if(t==a[j]||a[j]=='w') tmp++;
				else break;
			}
//			cout<<"	"<<j<<endl;
		} 
//		cout<<"middle "<<tmp<<endl;
		flag=1;
		for(j=i+1;j<=i+n;j++){
//			if(!flag&&(t==a[j]||a[j]=='w')) tmp++;
//			else if(!flag) break;
//			if(flag&&a[i]=='w') tmp++;
//			if(flag&&a[i]!='w') tmp++,t=a[j],flag=0;
			if(flag){
				if(a[j]=='w') tmp++;
				else tmp++,t=a[j],flag=0;
			}
			else{
				if(t==a[j]||a[j]=='w') tmp++;
				else break;
			}
//			cout<<"	"<<j<<endl;
		}
//		cout<<"final "<<tmp<<endl;
		ans=max(ans,min(tmp,n));
	}
	cout<<ans<<"\n";
}
