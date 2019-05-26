#include<bits/stdc++.h>
using namespace std;
int n,a[100001],l,mi,ans=0,r;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;i++)
	cin>>a[i];
	while(1){
	l=-1;
	for(register int i=1;i<=n;i++)
		if(a[i]!=0){
		l=i;
		mi=a[i];
		break;
		} 
	if(l==-1)
	break;
	r=l;
	for(register int i=l+1;i<=n;i++){
		if(a[i]!=0){
			r++; mi=min(mi,a[i]);
		}
        else
        break;
	}
	for(register int i=l;i<=r;i++)
	a[i]=a[i]-mi;
	ans=ans+mi;
	}
	cout<<ans;
	return 0;
}
