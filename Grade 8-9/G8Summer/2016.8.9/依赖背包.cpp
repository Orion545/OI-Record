#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
int n,m,v,in[1001][3],a[101][1001][3],tmp[101],num[101],f[100001],data[101][1001][2],fff[100001];
int main(){
	cin>>n>>v;
	int tt[1001];
	for(int i=1;i<=n;i++){
		cin>>in[i][0]>>in[i][1]>>in[i][2];
	}
	for(int i=1;i<=n;i++){
		if(in[i][2]==0){
			m++;num[m]++;tt[m]=i;
			a[m][1][0]=in[i][0];a[m][1][1]=in[i][1];a[m][1][2]=in[i][2];
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i][2]!=0){
			for(int j=1;i<=m;j++){
				if()
			}
		}
	}
	cout<<endl<<endl<<n<<" "<<m<<" "<<v<<endl<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			cout<<a[i][j][0]<<" "<<a[i][j][1]<<" "<<a[i][j][2]<<endl;
		}
		cout<<endl;
	} 
	for(int k=1;k<=m;k++){
		memset(f,0,sizeof(f));
		//cout<<"*******************************"<<endl<<endl;
		int flag;
		for(int i=1;i<=num[k];i++){
			if(a[k][i][2]==0) flag=i;
			if(a[k][i][2]!=0){
				for(int j=v;j>=0;j--){
					if(j-a[k][i][0]>=0) f[j]=max(f[j],f[j-a[k][i][0]]+a[k][i][1]);
				}
			}
		}
		/*
		for(int i=0;i<=v;i++){
			printf("%3d",i);
		} cout<<endl;
		for(int i=0;i<=v;i++){
			printf("%3d",f[i]);
		} cout<<endl<<endl;
		*/
		int t=-1000;
		for(int i=0;i<=v;i++){
			if(f[i]>t&&i+flag<=v){
				//cout<<"*check "<<i<<" ";
				t=f[i];
				data[k][tmp[k]][0]=i+a[k][flag][0];data[k][tmp[k]][1]=f[i]+a[k][flag][1];
				tmp[k]++;
			}
		}
		/*
		cout<<endl;
		for(int i=1;i<=tmp[k];i++){
			printf("%3d",i);
		}cout<<endl;
		for(int i=0;i<tmp[k];i++){
			printf("%3d",data[k][i][0]);
		}cout<<endl;
		for(int i=0;i<tmp[k];i++){
			printf("%3d",data[k][i][1]);
		}cout<<endl<<endl;
		cout<<"*******************************"<<endl;
		*/
	}
	/*
	cout<<endl<<endl;
	for(int i=1;i<=m;i++) cout<<tmp[i]<<" ";
	cout<<endl<<endl<<endl;
	*/
	for(int k=1;k<=m;k++){
		for(int j=v;j>=0;j--){
			for(int i=0;i<tmp[k];i++){
				if(j-data[k][i][0]>=0) fff[j]=max(fff[j],fff[j-data[k][i][0]]+data[k][i][1]);
			}
		}
		//for(int i=0;i<=v;i++) printf("%3d",fff[i]);
		//cout<<endl; 
	}
	//cout<<endl<<endl<<endl<<endl; 
	cout<<fff[v];
} 
