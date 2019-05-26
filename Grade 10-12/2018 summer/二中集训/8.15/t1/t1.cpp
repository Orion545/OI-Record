#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
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
int n,a[200010];
bool check(int mid){
//	cout<<"check "<<mid<<'\n';
	int i;
	//其实好像不用特判全部交错的情况，只要扫完全都没有连续，就是交错图了 
	//因为是奇数所以最左边的会上位 
	//话说如果两边一个是连续0一个是连续1怎么办呢
	//（上面那行划掉）
	//因为是中间开始的奇数计数，所以本来就不会有相同的两边同时开始的连续01段吧 
	//大概是对的吧...... 
	for(i=0;i<n;i++){
//		if(((a[n-i]>=mid&&a[n-i-1]>=mid)&&(a[n+i]<mid&&a[n+i+1]<mid))||((a[n+i]>=mid&&a[n+i+1]>=mid)&&(a[n-i]<mid&&a[n-i-1]<mid)))
		if((a[n-i]>=mid&&a[n-i-1]>=mid)||(a[n+i]>=mid&&a[n+i+1]>=mid)) return 1;
		if((a[n-i]<mid&&a[n-i-1]<mid)||(a[n+i]<mid&&a[n+i+1]<mid)) return 0;
	}
	if(a[1]>=mid) return 1;
	else return 0;
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();int i,l,r,mid;
	for(i=1;i<(n<<1);i++) a[i]=read();
	l=1;r=(n<<1)-1;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
