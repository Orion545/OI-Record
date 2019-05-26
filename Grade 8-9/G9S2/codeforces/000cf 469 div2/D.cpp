#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int a[200010];
int main(){
	int n=16,i,j;
	a[1]=1;i=1;
	for(j=2;j<=n;j++){
		while(a[i]){
			i++;
			if(i>n) i-=n;
		}
		i++;if(i>n) i-=n;
		while(a[i]){
			i++;
			if(i>n) i-=n;
		}
		a[i]=j;
	}
	for(i=1;i<=n;i++) cout<<a[i]<<ends;cout<<endl;
}
/*
1 2 3 4 5 6 7 8 9-10
1 2 3 4 5 6 7 8-10-9
1 2 3 4 5 6 7-9-8-10
1 2 3 4 5 6-10-7-9-8
1 2 3 4 5-8-6-10-7-9
1 2 3 4-9-5-8-6-10-7
1 2 3-7-4-9-5-8-6-10
1 2-10-3-7-4-9-5-8-6
1-6-2-10-3-7-4-9-5-8
*/
