
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

struct node{int val,id;}d[100010];
int n,have=0,ans=0,need=0,k=1,a[100010];
bool vis[100010];

//inline int read(){
//	int sum=0;bool flag=false;char c=getchar();
//	while(c<'0'||c>'9') {if(c=='-') flag=true; c=getchar();}
//	while(c>='0'&&c<='9') {sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
//	return ((flag)?-sum:sum);
//	
//}
bool cmp(node a,node b){
	return a.val<b.val;
}



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);//n=read();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i].val=a[i];//=read();
		d[i].id=i;
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(have<d[i].val){
			ans+=k*(d[i].val-have);
			have=d[i].val;
			vis[d[i].id]=true;
		}
		else if(have>=d[i].val){
			ans+=k*(d[i].val-have);
			vis[d[i].id]=true;
		}
		if(d[i].id==1){
			if(vis[d[i].id+1]){
				k--;
			}
			else{
				
			}
		}
		else if(d[i].id==n){
			if(vis[d[i].id-1]){
				k--;
			}
			else{
				
			}			
		}
		else{
			if(vis[d[i].id+1]){
				if(vis[d[i].id-1]){
					k--;
				}
				else{
					
				}
			}
			else{
				if(vis[d[i].id-1]){
					
				}
				else{
					k++;
				}
			}	
		}

	}
	printf("%d\n",ans);
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}







