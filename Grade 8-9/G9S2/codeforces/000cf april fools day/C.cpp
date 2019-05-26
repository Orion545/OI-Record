#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#define ll long long
using namespace std;
int main(){
	int n,a[110],l[110],r[110];cin>>n;
	int i,j,lmost=1;
	for(i=1;i<=n;i++) cin>>a[i],l[i]=i-1,r[i]=i+1;
	l[1]=r[n]=0;
	for(j=1;j<=n;j++){
//		cout<<j<<ends<<lmost<<endl;
		i=lmost;
		while(r[i]){
			if(abs(a[i]-a[r[i]])>=2){
				puts("NO");return 0;
			}
			i=r[i];
		}
		int maxn=0,tmp;i=lmost;
		while(i){
			if(maxn<a[i]) maxn=a[i],tmp=i;
			i=r[i];
		}
//		cout<<maxn<<ends<<tmp<<endl;
		if(j==n) break;
		if(lmost==tmp){
//			cout<<"tp 1"<<endl;
			l[r[tmp]]=0;lmost=r[tmp];r[tmp]=0;
		}
		else if(r[i]){
//			cout<<"tp 2"<<endl;
			l[r[tmp]]=l[tmp];r[l[tmp]]=r[tmp];
			l[tmp]=r[tmp]=0;
		}
		else{
//			cout<<"tp 3"<<endl;
			r[l[tmp]]=0;l[tmp]=0;
		}
	}
	puts("YES");
}
