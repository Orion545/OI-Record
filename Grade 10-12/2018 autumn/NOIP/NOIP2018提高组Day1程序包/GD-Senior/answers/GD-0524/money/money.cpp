#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[111],m;
bool f[25111];
int main() {
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	int i,j;
	cin>>t;
	memset(f,false,sizeof(f));
	f[2]=true;f[3]=true;f[5]=true;f[7]=true;f[11]=true;
	f[23]=true;f[13]=true;f[29]=true;f[17]=true;f[19]=true;
	int ma=30,fr=30;
	while(t--) {
	    bool x=false;
		cin>>n;m=0;
	    for(i=1;i<=n;i++) {
		    scanf("%d",&a[i]);
		    if(a[i]==1)x=true;
		    ma=max(ma,a[i]);
	    }
	    for(i=fr;i<=ma;i++) {
	    	if(f[i]==false) {
	    		f[i]=true;
	    		for(j=2;j<ma;j++) {
	    			if(j*j>i)j=ma;
	    			if(i%j==0) {
	    				f[i]=false;j=ma;
	    			}
	    		}
	    	}
	    }
	    fr=ma;
	    for(i=1;i<=n;i++)if(f[a[i]]==true)m++;
	    if(x==true)cout<<'1'<<endl;else
	    if(m<n)cout<<m<<endl;else cout<<n<<endl;
	}
	return 0;
}

