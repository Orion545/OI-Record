#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int a[1000],p[1000],ans=0,n;
int search1(int x,int y)
{
	if (x==0) return false;								//�����û������ 
	if (p[x]!=0) return search1(x-1,y); 				//�Ƿ�Ϊ���е��� 
	if (y%a[x]==0) return true;							//���Ա����� 
	else {
		int r=y;
		while (y-a[x]>=0) {
			if (search1(x-1,y-a[x]))return true;		//ö�����е���� 
			y-=a[x];
		}
		if (search1(x-1,r))return true;					//��ǰ�����е����ı��� 
	}
}
int search(int x)
{
	int r=a[x];
	for (int i=x-1;i>=1;--i){
		if (p[i]==1) continue;			//��ȡ  
		if (search1(i,r)) p[x]=1,++ans;//���ӵ��Ͳ��� 
		break;
	}
	if (x+1<=n)search(x+1);
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	for (int z=1;z<=t;++z){
		memset(a,0,1010);
		memset(p,0,1010);
		ans=0;
		cin>>n;
		for (int i=1;i<=n;++i){
			cin>>a[i];
		}
		sort (a+1,a+n+1);				//���ܷ�Լ��,��ӵ� 
		if (a[1]==1) {cout<<1<<endl;continue;};
		if (a[1]==2&&a[2]==3) {cout<<2<<endl;continue;};
		search(2);
		cout<<n-ans<<endl;
	}
	return 0;
}
