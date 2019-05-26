#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define do for
#define cin fin
#define cout fout
using namespace std;
ifstream fin("money.in.txt");
ofstream fout("money.out.txt");
int t,n;
int a[200],ai[200];
bool b[27000];
int p;
int n1;
inline int dp(register int sum,register int j){
	if(sum<a[n]){
		for(register int i=j;i<=n;++i){
			b[sum+a[i]]=1;
	     	dp(sum+a[i],i);
     	}
	}
    return 0;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		n1=0;
		
		do(register int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+1+n);
		do(register int i=1;i<=a[n];++i) b[i]=0;
		//cout<<a[n]<<endl;
		do(register int i=1;i<=n;++i){
			dp(a[i],i);
		}
	    do(register int i=1;i<=n;++i){
	    	
	    	if(!b[a[i]]) ++n1;
	    }
	    cout<<n1<<endl;
	}
	return 0;
}
