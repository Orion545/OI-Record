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
	//��ʵ����������ȫ������������ֻҪɨ��ȫ��û�����������ǽ���ͼ�� 
	//��Ϊ��������������ߵĻ���λ 
	//��˵�������һ��������0һ��������1��ô����
	//���������л�����
	//��Ϊ���м俪ʼ���������������Ա����Ͳ�������ͬ������ͬʱ��ʼ������01�ΰ� 
	//����ǶԵİ�...... 
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
