#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 1005
#define maxx 50005
int T;
int n;
int a[maxn];
int gcd(int a,int b){
	if(!a||!b)return a+b;
	while(b^=a^=b^=a%=b);
	return a+b;
}
int tot;
int ans;
int temp;
bool can[maxn];
bool ca[maxx];
bool check(int val1,int val2,int ta){
	if(ta%val1==0||ta%val2==0)return true;
    while(ta>=0){
//    	if(ta%val1)cout<<"check"<<endl;
    	if(ta%val2==0)return true;
    	ta-=val1;
    }
    return false;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);    	ans=n;
    	for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
    	sort(a+1,a+n+1);
    	memset(can,false,sizeof(can));
    	memset(ca,false,sizeof(ca));
    	if(n>10){
    	int temp=0;
    	for(int i=1;i<=n;i++){
    		if(i>1&&a[i]%a[1]==0)ca[a[i]]=true;
    		if(ca[a[i]])continue;
    		temp++;
//    		cout<<a[i]<<endl;
    		ca[a[i]]=true;
    		for(int j=a[i]+1;j<=a[n];j++){
    			if(ca[j])continue;
    			for(int k=1;k<=a[n];k++){
    				if(!ca[k])continue;
    				for(int p=1;p<=a[n];p++){
    					if(!ca[p])continue;
//    					cout<<p<<" "<<k<<" "<<j<<endl;
                        if(p>j||k>j)break;
    					if(check(p,k,j)){
    						ca[j]=true;
    						break;
    					}
    				}
    			}    			
/*    			for(int k=1;k<i;k++){
//    				cout<<a[k]<<" "<<a[i]<<" "<<a[j]<<endl;
    				if(check(a[k],a[i],a[j])){
    					can[j]=true;
    					break;
    				}
    			}
    			if(can[j])continue;
/*    			for(int k=i+1;k<=n;k++){
//    				cout<<a[k]<<" "<<a[i]<<" "<<a[j]<<endl; 
                    if(!can[k])continue;
    				if(check(a[k],a[i],a[j])){
    					can[j]=true;
    					break;
    				}
    			}    */			
    		}
    	}
    	ans=min(ans,temp);
		cout<<ans<<endl;
		continue;    		
    	}
    	tot=1<<n;
    	for(int i=1;i<tot;i++){
    		bool mark=true;
    		temp=0;
    		memset(can,false,sizeof(can));
    		for(int j=1;j<=n;j++){
    			if((1<<(j-1))&i){
    				temp++;
    				can[j]=true;
    			}
    		//	cout<<i<<" "<<temp<<endl;
    		}
    		for(int j=1;j<=n;j++){
    			if(can[j])continue;
    			for(int k=1;k<=n;k++){
    				if(!can[k])continue;
    				if(can[j])break;
    				for(int p=k+1;p<=n;p++){
    					if(!can[p])continue;
    					if(check(a[k],a[p],a[j])){
    						can[j]=true;
    						break;
    					}
    				}
    			}
    		}
    		for(int j=1;j<=n;j++){
    			if(!can[j])mark=false;
    		}
    		if(mark)ans=min(ans,temp);
    	}
    	cout<<ans<<endl;
    }
}
