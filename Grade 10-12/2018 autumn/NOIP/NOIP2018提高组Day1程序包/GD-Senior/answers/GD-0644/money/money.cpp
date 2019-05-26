#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
int t,n,a[6],b[6],nub;
long long gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
bool fl;
int main(){
	fin>>t;
	while(t--){
		fin>>n;nub=0;fl=0;
		for(int i=1;i<=n;i++){
			fin>>a[i];
			if(a[i]==1) fl=1;
		}
		if(fl){
			cout<<1<<endl;
			continue;
		}
		sort(a+1,a+1+n);
		nub=1;b[0]=a[1];
		for(int i=2;i<=n;i++){
			if(nub==1){
				if(gcd(b[0],a[i])!=1) continue;
				else{
					nub++;b[1]=a[i];continue;
				}
			}bool fl1=0;
			for(int i1=0;i1<nub;i1++){
				if(gcd(b[i1],a[i])!=1) fl1=1;
			}
			if(fl1) continue;
			else{
				if(nub==2){
					for(int i1=0;i1<=100;i1++){
						if(fl1) break;
						for(int i2=0;i2<=100;i2++){
							if(b[0]*i1+b[1]*i2==a[i]){
								fl1=1;break;
							}
							if(b[0]*i1+b[1]*i2>a[i]) break;
						}
					}
					if(!fl1) b[nub]=a[i],nub++;
					continue;
				}
				if(nub==3){
					for(int i1=0;i1<=100;i1++){
						if(fl1) break;
						for(int i2=0;i2<=100;i2++){
							if(fl1) break;
							for(int i3=0;i3<=100;i3++){
								if(b[0]*i1+b[1]*i2+b[2]*i3==a[i]){
									fl1=1;break;
								}
								if(b[0]*i1+b[1]*i2+b[2]*i3>a[i]) break;
							}
						}
					}
					if(!fl1) b[nub]=a[i],nub++;
					continue;
				}
				if(nub==4){
					for(int i1=0;i1<=100;i1++){
						if(fl1) break;
						for(int i2=0;i2<=100;i2++){
							if(fl1) break;
							for(int i3=0;i3<=100;i3++){
								if(fl1) break;
								for(int i4=0;i4<=100;i4++){
								if(b[0]*i1+b[1]*i2+b[2]*i3+b[3]*i4==a[i]){
									fl1=1;break;
								}
								if(b[0]*i1+b[1]*i2+b[2]*i3+b[3]*i4>a[i]) break;
								}
							}
						}
					}
					if(!fl1) b[nub]=a[i],nub++;
					continue;
				}
			}
		}
		fout<<nub<<endl;
		
	}return 0;
}
