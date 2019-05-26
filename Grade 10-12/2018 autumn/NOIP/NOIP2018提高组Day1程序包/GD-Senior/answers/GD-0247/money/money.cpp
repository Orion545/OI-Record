#include<cstdio>
#include<cstring>
#define maxn 10001
#define inf 100000

void judge() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
}

int min(int a,int b) {
	return a<b?a:b;
}

bool check(int a,int b,int c) {
	if(a<b&&a<c) return false;
	for(int i=0;i<=a/b+1;i++) {
		for(int j=0;j<=a/c+1;j++) {
			if(b*i+c*j==a) return true;
		}
	}
	return false;
}

int f2(int n1,int n2) {
	if(!(n1%n2)||!(n2%n1)) {
		return 1;
	} else {
		return 2;
	}
}

int f3(int n1,int n2,int n3) {
	if(!(n2%n1||n3%n1)) return 1;
	else if(!(n1%n2||n3%n2)) return 1;
	else if(!(n1%n3||n2%n3)) return 1;
	else if(check(n1,n2,n3)||check(n2,n1,n3)||check(n3,n1,n2))return 2;
	else return 3;
}

int f4(int n1,int n2,int n3,int n4) {
	int tar,num[4];
	int ans=inf;
	bool dp[maxn];
	for(int i=1;i<=4;i++) {
		if(i==1) {tar=n1;num[1]=n2;num[2]=n3;num[3]=n4;}
		if(i==2) {tar=n2;num[1]=n1;num[2]=n3;num[3]=n4;}
		if(i==3) {tar=n3;num[1]=n1;num[2]=n2;num[3]=n4;}
		if(i==4) {tar=n4;num[1]=n1;num[2]=n2;num[3]=n3;}
		memset(dp,0,sizeof(dp));
		dp[0]=true;
		for(int j=1;j<=3;j++) {
			for(int k=num[j];k<=tar;k++) {
				dp[k]=dp[k-num[j]];
			}
		}
		int tn=f3(num[1],num[2],num[3]);
		if(dp[tar]) {
			ans=min(ans,tn);
		} else {
			ans=min(ans,tn+1);
		}
	}
	return ans;
}

int f5(int n1,int n2,int n3,int n4,int n5) {
	int tar,num[5];
	int ans=inf;
	bool dp[maxn];
	for(int i=1;i<=5;i++) {
		if(i==1) {tar=n1;num[1]=n2;num[2]=n3;num[3]=n4;num[4]=n5;}
		if(i==2) {tar=n2;num[1]=n1;num[2]=n3;num[3]=n4;num[4]=n5;}
		if(i==3) {tar=n3;num[1]=n1;num[2]=n2;num[3]=n4;num[4]=n5;}
		if(i==4) {tar=n4;num[1]=n1;num[2]=n2;num[3]=n3;num[4]=n5;}
		if(i==5) {tar=n5;num[1]=n1;num[2]=n2;num[3]=n3;num[4]=n4;}
		memset(dp,0,sizeof(dp));
		dp[0]=true;
		for(int j=1;j<=4;j++) {
			for(int k=num[j];k<=tar;k++) {
				dp[k]=dp[k-num[j]];
			}
		}
		int tn=f4(num[1],num[2],num[3],num[4]);
		if(dp[tar]) {
			ans=min(ans,tn);
		} else {
			ans=min(ans,tn+1);
		}
	}
	return ans;
}

int main() {
	judge();
	int T;
	scanf("%d",&T);
	while(T--) {
		int a;
		scanf("%d",&a);
		if(a==1) printf("1\n");
		if(a==2) {
			int n1,n2;
			scanf("%d%d",&n1,&n2);
			printf("%d\n",f2(n1,n2));
		}
		if(a==3) {
			int n1,n2,n3;
			scanf("%d%d%d",&n1,&n2,&n3);
			printf("%d\n",f3(n1,n2,n3));
		}
		if(a==4) {
			int n1,n2,n3,n4;
			scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
			printf("%d\n",f4(n1,n2,n3,n4));
		}
		if(a==5) {
			int n1,n2,n3,n4,n5;
			scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);
			printf("%d\n",f5(n1,n2,n3,n4,n5));
		}
	}
}

