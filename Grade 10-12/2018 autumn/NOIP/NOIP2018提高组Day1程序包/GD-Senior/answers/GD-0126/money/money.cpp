#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 105
using namespace std;

int t,n,cur,ans;
int a[MAXN];
bool flag;

void judge(int tar,int pos,int tot)
{
	if (tot==tar){
		flag=true; 
		return;
	}
	if (tot>tar) return;
	for (int i=1;i<pos;i++){
		if (!flag) judge(tar,pos,tot+a[i]);
		else return;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int s=1;s<=t;s++){
		scanf("%d",&n);
		ans=n;
		for (int i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=2;i<=n;i++){
			flag=false;
			judge(a[i],i,0);
			if (flag==true) ans--;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
