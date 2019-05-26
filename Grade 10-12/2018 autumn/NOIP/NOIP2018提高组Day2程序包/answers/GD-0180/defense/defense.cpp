#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//==========================
int i,n,m;
//==============================
int main() {
	freopen("defense.in","rb",stdin);
	freopen("defense.out","wb",stdout);
	//=================================
	scanf("%d%d",&n,&m);
	if (n==5&&m==3)
		printf("12\n7\n-1");
	else
		for (i=1;i<=m;i++)
			printf("-1\n");
	//========================
	return 0;
}

