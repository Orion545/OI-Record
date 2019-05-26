#include<iostream>
#include<stdio.h>
using namespace std;
int n,p,z,s;
int d[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	s=0;
	z=0;
	for(int i=1;i<=n;i++) cin>>d[i];
	//for(int i=1;i<=n;i++) cout<<d[i];
	for(int i=1;i<=n;i++) if(d[i]==0) z++;
	d[n+1]=0;
	d[n+2]=1;
	while(z!=n){
    int j,k,len,m,ma;
	int l,r;
	j=1;
	k=1;
	m=0;
	ma=100000;
	while(1){
	int j1=j;
	while(d[j]>0) j++,k++;
	//len=j-j1;
    l=j1,r=j-1;
	//cout<<l<<r<<endl;
	if(k>n) break;
	while(d[j]==0) j++,k++;
	if(k>n) break;
	}
	//cout<<l<<" "<<r<<" "<<m<<endl;
	for(int i=l;i<=r;i++) if(d[i]<ma) ma=d[i];
	s=s+ma;
	for(int i=l;i<=r;i++){
	d[i]=d[i]-ma;	
	if(d[i]==0) z++;
	//cout<<z<<endl;
	}
}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
