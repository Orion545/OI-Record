#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int n;
//n的意义与题目描述相同 
int l[10000010],r[10000010],cnt=0,num[21];
//星际运输线路将会保存在l和r数组中，运输线i以l[i]为开头，r[i]为结尾
//第i个公司的总航路数量为num[i] 
int random(ll l,ll r){
	ll x1=rand(),x2=rand();
	return (int)((x1*x2)%(r-l+1)+l);
}
void gen(int s1,ll s2,ll s3,ll s4){//在主函数中调用 
	srand(abs((s2<<12ll)+(1ll<<(s1%40))-s3*s4));
	for(int i=1;i<=s1;i++){
		cnt++;num[i]++;
		l[cnt]=random(1,n);r[cnt]=random(1,n);
	}
}
int main(){
	int s1=10;ll s2=998244353,s3=23333,s4=66666;
	gen(s1,s2,s3,s4);//调用方法 
}
