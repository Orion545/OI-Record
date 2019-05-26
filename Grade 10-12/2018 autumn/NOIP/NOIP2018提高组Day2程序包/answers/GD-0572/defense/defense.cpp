#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<cmath>
#define cin fin
#define cout fout
using namespace std;
ofstream fout("defense.out.txt");
ifstream fin("defense.in.txt");
int n,m,t;
string ss;
int s[300000],sl[300000];
int a,b,x,y;
bool bb[300000];
int val[300000];
long long sum,jj;
int main()
{   int i,j,k;
	cin>>n>>m>>ss;
	t=n;
	for(i=1;i<=n;++i){
		cin>>val[i];
		s[i]=i;
	}
	for(i=1;i<n;++i){
		cin>>j>>k;
		s[++t]=j;
		sl[t]=sl[k];
		sl[k]=t;
		s[++t]=k;
		sl[t]=sl[j];
		sl[j]=t;
	}
	
	if(ss[0]=='A'){
		for(i=1;i<=m;++i){
			sum=0;
			memset(bb,0,sizeof bb);
			cin>>a>>x>>b>>y;
			if(abs(a-b)==1&x==0&&y==0){
				cout<<-1<<endl;continue;
			} 
			if(x==1) sum+=val[a];
			bb[a]=x;
			if(y==1) sum+=val[b];
			bb[b]=y;
			j=a;
			if(!bb[j]){
			    	//	cout<<j-1<<" "<<val[j-1]<<endl;
			    		if(!bb[j-1]&&j-1>=1){
			    			bb[j-1]=1;
			    			sum+=val[j-1];
			    		}
			    	//	cout<<j+1<<" "<<val[j+1]<<endl;
			          if(!bb[j+1]&&j+1<=n){
			    			bb[j+1]=1;
			    			sum+=val[j+1];
			    		}
			}
			j=b;
			if(!bb[j]){
			    	//	cout<<j-1<<" "<<val[j-1]<<endl;
			    		if(!bb[j-1]&&j-1>=1){
			    			bb[j-1]=1;
			    			sum+=val[j-1];
			    		}
			    	//	cout<<j+1<<" "<<val[j+1]<<endl;
			          if(!bb[j+1]&&j+1<=n){
			    			bb[j+1]=1;
			    			sum+=val[j+1];
			    		}
			}
			for(j=1;j<=n;j++){
			//	cout<<sum<<endl;
				jj=0;
			    
			    	
			    
				if(!bb[j]&&j!=a&&j!=b){
					if(j>1&&!bb[j-1]){
						jj+=val[j-1];
					}
					if(j<n&&!bb[j+1]){
						jj+=val[j+1];
					}
					if(jj>val[j]){
						sum+=val[j];
						bb[j]=1;
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	fin.close();
    fout.close();
	return 0;
}
