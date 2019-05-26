#include<cstdio>
using namespace std;
int n,m;
char s[5];
int p[100005],x,y,a,b,ans,f[100005][2];
int mymin(int x,int y){
	if (x>y) return y;else return x;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=1;i<=n;++i) scanf("%d",&p[i]);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
	}
	
	if (s[0]=='A'){
		for (int i=1;i<=m;++i){
		    scanf("%d%d%d%d",&a,&x,&b,&y);
		    ans=0;
		    if (b<a){
		    	int t;
		    	t=b;b=a;a=t;
		    	t=x;x=y;y=t;
		    }
		    if (b-a==1 && x==0 && y==0) ans=-1;
		    else{
		    	if (x==0){
		        	if (a>1){
		        		f[a-1][1]=p[a-1];f[a-1][0]=0x7FFFFFFF;
	    	        	for (int j=a-2;j>=1;--j){
		            		f[j][0]=f[j+1][1];
	    	        		f[j][1]=mymin(f[j+1][0],f[j+1][1])+p[j];
	   	            	}
	    	        	ans+=mymin(f[1][1],f[1][0]);
		        	}
		        	a++;x=1;
		        }
		        else if (a>=1){
		        		f[a][1]=p[a];f[a][0]=0x7FFFFFFF;
	    	        	for (int j=a-1;j>=1;--j){
		            		f[j][0]=f[j+1][1];
	    	        		f[j][1]=mymin(f[j+1][0],f[j+1][1])+p[j];
	   	            	}
	    	        	ans+=mymin(f[1][1],f[1][0]);ans-=p[a];
		        	}
		        if (y==0){
		        	if (b<n){
		        		f[b+1][1]=p[b+1];f[b+1][0]=0x7FFFFFFF;
		        		for (int j=b+2;j<=n;++j){
		        			f[j][0]=f[j-1][1];
		        			f[j][1]=mymin(f[j-1][0],f[j-1][1])+p[j];
		        		}
		        		ans+=mymin(f[n][1],f[n][0]);
		        	}
		        	b--;y=1;
		        }
		        else if (b<=n){
		        		f[b][1]=p[b];f[b][0]=0x7FFFFFFF;
		        		for (int j=b+1;j<=n;++j){
		        			f[j][0]=f[j-1][1];
		        			f[j][1]=mymin(f[j-1][0],f[j-1][1])+p[j];
		        		}
		        		ans+=mymin(f[n][1],f[n][0]);ans-=p[b];
		        	}
	    	    if (a<b){
	    	    	f[a][1]=p[a];f[a][0]=0x7FFFFFFF;
	    	      	for (int j=a+1;j<b;++j){
		            	f[j][0]=f[j-1][1];
		            	f[j][1]=mymin(f[j-1][0],f[j-1][1])+p[j];
		         	}
		         	int now=p[b]+mymin(f[b-1][0],f[b-1][1]);
		        	f[b][1]=p[b];f[b][0]=0x7FFFFFFF;
		        	for (int j=b-1;j>a;--j){
		            	f[j][0]=f[j+1][1];
		            	f[j][1]=mymin(f[j+1][0],f[j+1][1])+p[j];
		           	}
		         	int noww=p[a]+mymin(f[a+1][0],f[a+1][1]);
		        	ans+=mymin(now,noww);
		        }else ans+=p[a];
		    }
		    printf("%d\n",ans);
		    
	    }
	}
	return 0;
}
