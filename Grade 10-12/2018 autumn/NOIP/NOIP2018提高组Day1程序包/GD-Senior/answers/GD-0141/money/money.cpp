#include<iostream>
#include<stdio.h>
using namespace std;
int a[1001],d[1001];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,b;
	cin>>t;
	b=1;
	while(b<=t){
		int l,n,m,n1,o;
		l=0;
		o=0;
		cin>>n;
		m=10000000;
		n1=0;
		//cout<<1<<endl;
		if(n==1) cout<<1<<endl;
		else{
		for(int i=1;i<=1000;i++) a[i]=0,d[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) if(a[i]==1) o=1;
		if(o==1) cout<<1<<endl;
		else{
		for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	    	if(i!=j){
	        //cout<<a[j]<<" "<<a[i]*(a[j]/a[i])<<endl;
	    	if(a[j]==a[i]*(a[j]/a[i])) a[j]=10000;	
	    }	 
	}
}
		//for(int i=1;i<=n;i++) cout<<a[i]<<endl;
		for(int i=1;i<=n;i++) if(a[i]!=1) d[i]=a[i],n1++;	
		for(int i=1;i<=n1;i++) 
            for(int j=i+1;j<=n1;j++) if((d[i]*d[j]-d[i]-d[j])<m) m=(d[i]*d[j]-d[i]-d[j]);  
		for(int i=1;i<=n;i++){
		if(d[i]>m) n1--;
    }
        cout<<n1<<endl;
    }
}
    b++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
