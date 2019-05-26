#include<bits/stdc++.h>
using namespace std;
int n,a[103],T,len,ans=0;
inline int ex_gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	else return ex_gcd(b,a%b);
}
int c[111];
bool bb[25010],uvis[110];bool sha[110];
int gc,dui[10200],p;
queue<int> q;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);len=n;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++)if(a[i]%a[j]==0){
				a[i]=1000000;len--;
				break;
			}
		}
		sort(a+1,a+n+1);
		if(len>1){
			ans=len;int cnt=0,cnt1=0;
		    for(int i=1;i<len;i++)
		    for(int j=i+1;j<=len;j++){
			    if(ex_gcd(a[i],a[j])==1)dui[++cnt]=a[i]*a[j]-a[i]-a[j];
		    }
	        sort(dui+1,dui+cnt+1);
		    for(int i=1;i<=len;i++){
		    	if(a[i]>dui[1]){
			        a[i]=1000000;ans--;
		        }
		    }
		    sort(a+1,a+len+1);
		    len=ans;int mb;
		    memset(sha,false,sizeof(sha));
		    for(int i=1;i<=len;i++){
		    	bool flag=false;
		    	memset(bb,false,sizeof(bb));
		    	memset(uvis,false,sizeof(uvis));
		    	mb=a[i];uvis[i]=true;
		    	while(!q.empty())q.pop();
		    	for(int j=1;j<=len;j++)if(j!=i){
		    		q.push(a[j]);bb[a[j]]=true;
		    	}
		    	for(int j=1;j<=5000;j++){
		    		int h=q.front();
					for(int k=1;k<=len;k++)if(!uvis[k]){
						if(h+a[k]>25000)continue;
						if(!bb[h+a[k]]){
							if(h+a[k]==mb){
								flag=true;goto lll;
							}
							bb[h+a[k]]=true;q.push(h+a[k]);
							
						}
					}
		    	}
		    	lll :
		    	if(flag)sha[i]=true;
		    }
		    for(int i=1;i<=len;i++)if(sha[i])a[i]=1000000,ans--;
		    sort(a+1,a+len+1);len=ans;
		    for(int i=1;i<len;i++){
		    	for(int j=i+1;j<=len;j++){
		    		p=ex_gcd(a[i],a[j]);
		    		if(p>a[1]){
		    			bool fl1=true,fl2=true;
		    			for(int k=1;k<=cnt1;k++)if(c[k]==i)fl1=false;
		    			if(fl1)c[++cnt1]=i;
		    			for(int k=1;k<=cnt1;k++)if(c[k]==j)fl2=false;
		    			if(fl2)c[++cnt1]=j;
		    			if(fl1&&fl2)ans--;
		    		}
		    	}
		    }
		}
		else ans=len;
		printf("%d\n",ans);
	}
	return 0;
}
