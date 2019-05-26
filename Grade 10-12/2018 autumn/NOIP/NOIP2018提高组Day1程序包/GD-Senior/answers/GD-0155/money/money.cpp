#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int a[110],s[25],cnt=0;
bool tag[25010];
void dfs(int k,int m){
	if(k>25000) return;
	if(tag[k]) return ;
	tag[k]=1;
	for(int i=1;i<=m;i++)
	dfs(k+a[i],m);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int g=1;g<=t;g++){
		memset(tag,0,sizeof(tag));
		int ans=0;
		cnt++;
		scanf("%d",&s[cnt]);
		for(int i=1;i<=s[cnt];i++){
		scanf("%d",&a[i]);
		}
		sort(a+1,a+1+s[cnt]);
		for(int i=1;i<=s[cnt];i++){
			int temp=a[i];
			for(int j=1;j<=s[cnt];j++)
			dfs(temp+a[j],s[cnt]);
		}
		for(int i=1;i<=s[cnt];i++){
			if(!tag[a[i]]) ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
