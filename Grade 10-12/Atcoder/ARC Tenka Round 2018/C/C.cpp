/*

���桪��
��������֮�£��и���֮��������֮����
���ʥ��֮����������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ����ǳɾ�����һ������֮�ˣ�������������һ�����֮�ˣ�
������֮����������ͽ�����Ǵ������Ĳ����ߣ�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,a[200010],b[200010];
int main(){
	n=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(n&1){
		ll ans=0;int mid=n/2+1,f=0,l=2,r=n;
		b[mid]=a[1];
		for(i=1;i<=n/2;i++){
			if(f) b[mid+i]=a[l++],b[mid-i]=a[l++];
			else b[mid+i]=a[r--],b[mid-i]=a[r--];
			f^=1;
		}
		for(i=1;i<n;i++) ans+=abs(b[i+1]-b[i]);
		ll tmp=0;l=1;r=n-1;f=1;
		b[mid]=a[n];
		for(i=1;i<=n/2;i++){
			if(f) b[mid+i]=a[l++],b[mid-i]=a[l++];
			else b[mid+i]=a[r--],b[mid-i]=a[r--];
			f^=1;
		}
		for(i=1;i<n;i++) tmp+=abs(b[i+1]-b[i]);
		cout<<max(ans,tmp);
	}
	else{
		ll ans=0;int mid,f,l,r;
		mid=n/2,f=1,l=2,r=n-1;
		b[mid]=a[1];b[mid+1]=a[n];
		for(i=1;i<n/2;i++){
			if(f) b[mid+i+1]=a[l++],b[mid-i]=a[r--];
			else b[mid+i+1]=a[r--],b[mid-i]=a[l++];
			f^=1;
		}
		for(i=1;i<n;i++) ans+=abs(b[i+1]-b[i]);
		cout<<ans<<'\n';
	}
}

