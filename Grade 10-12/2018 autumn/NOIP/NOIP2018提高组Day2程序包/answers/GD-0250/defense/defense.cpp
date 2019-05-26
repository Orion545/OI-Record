#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,mp[100086],p[100086];
long long ans;
string s;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	if(s[0]!='A')for(int i=1;i<=m;i++)printf("-1\n");
	else{
		int a,b,x,y;
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<n;i++)scanf("%d%d",&a,&b);
		for(int ii=1;ii<=m;ii++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(((a-b==1)||(b-a==1))&&x+y==0)printf("-1\n");
		else{
			memset(mp,0,sizeof(mp));
			if(x==1)mp[a]=1;
			if(y==1)mp[b]=1;
			if(x==0)mp[a-1]=1,mp[a+1]=1;
			if(y==0)mp[b-1]=1,mp[b+1]=1;
			p[0]=0;
			for(int i=1;i<n;i++){
				if(!mp[i]){
					if(!mp[i+1]){
						if(p[i]>(1-mp[i-1])*p[i-1]+p[i+1])mp[i+1]=1;
						else mp[i]=1;
					}
				}
			}
			if(!mp[n-1])mp[n]=1;
			ans=0;
			for(int i=1;i<=n;i++)ans+=mp[i]*p[i];
			printf("%lld\n",ans);
		}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;	
}
