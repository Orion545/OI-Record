#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstdlib>
#define MAXN 20
void space(){
	std::cout<<"\n		";
}
void myst(){
	std::cout<<"Troll!\n";
	myst();
}
int random(int low, int up){
	return low+(long)((up-low+1)*(double)rand()/(RAND_MAX+1));
}
void warranty(){std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<"			This is a Private System."<<std::endl;
	std::cout<<"			CopyRight (C) LLHSC++.Inc Limited"<<std::endl;
	std::cout<<"			This App is distributed in the hope that it will be useful,but WITHOUT ANY \nWARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details."<<std::endl;
	std::cout<<"			You Are Warned."<<std::endl<<std::endl<<std::endl<<std::endl;
}
struct USER{
	std::string set;
	std::string hide;
	std::string hint;
	std::string name;
	std::string Q1;
	std::string A1;
	std::string Q2;
	std::string A2;
	};
USER command[MAXN];
int main(){
	std::string secretcommand,secretcommand1="secretcommandsecretcommandsecretcommandsecretcommand";
	std::string secretcommand2="iamapig",secretcommand3="whatapigami",nameagain,code;
	bool bocheck[MAXN]={0},w=false;
	std::ofstream SaveFile("Password.LHSC++");
	long userin,userinin,userininin,times=3,time=60,useer=0,j,i,num,s_s,user=0,n=3,milk,aa;
	std::string in,checkagain;
	system("color 8F");
	space();
	std::cout<<"-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*"<<std::endl;
	space();
	std::cout<<"Welcome To C++ Private System,Developed By LHSC++.INC."<<std::endl;
	space();
	std::cout<<"-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*(*-*)-*-*"<<std::endl;
	goback:
	space();
	std::cout<<"Enter The Number To Go To Destination"<<std::endl;
	std::cout<<std::endl<<"		1.Lock a Secret"<<std::endl<<"		2.See The Secrets"<<std::endl<<"		3.Warranty"<<std::endl<<"		4.Get A secret Message"<<std::endl<<"		5.See The secret Message"<<std::endl<<"		6.Clear Screen"<<std::endl<<"		";
	std::cin>>userin;
	if(userin==1){
		getchar();
		std::cout<<"Developed By LHSC++.INC."<<std::endl;
		std::cout<<"Your Name Please? ";
		getline(std::cin,command[user].name);
		std::cout<<"Now Input 2 Questions That You Use During 'Lost Password'.";
		std::cout<<"First Question:\n";
		getline(std::cin,command[user].Q1);
		std::cout<<"First Answer:\n";
		getline(std::cin,command[user].A1);
		std::cout<<"Second Question:\n";
		getline(std::cin,command[user].Q2);
		std::cout<<"Second Answer:\n";
		getline(std::cin,command[user].A2);
		std::cout<<"Now Name What You Want To Hide:"<<std::endl;
		std::cout<<"-------SECRET-INFORMATION-------"<<std::endl;
		std::cout<<"********************************"<<std::endl;
		getline(std::cin,command[user].hide);
		std::cout<<"********************************"<<std::endl;
		std::cout<<"-----SECRET-INFORMATION-END-----"<<std::endl;
		first:
		std::cout<<"Enter Passcode ******************************\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		getline(std::cin,command[user].set);
		std::cout<<"Again ******************************\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		getline(std::cin,checkagain);
		int check=0;
		if(checkagain!=command[user].set){
			++check;
			std::cout<<"Two Unequal Password!Do It Again\n";
			goto first;
		}
		std::cout<<"Two Correct Password!"<<std::endl;
		std::cout<<"Now Enter A Hint To Remind You The Password.\nHint : ______________________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		getline(std::cin,command[user].hint);
		std::cout<<"All Righty~~~~~~~~"<<std::endl;
		++user;
		goto goback;
	}
	if(userin==2){
		getchar();
		if(user==0){
			std::cout<<"No One Created A Secret Before!";
			getchar();
			goto goback;
		}
		password:
		std::cout<<"Developed By LHSC++.INC."<<std::endl;
		std::cout<<"Want A Hint? Just Input 'IWANTAHINT' In The Password Box And We Can Help You.\n";
		std::cout<<"Enter The Passcode : ******************************\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		getline(std::cin,in);
		if(in=="IWANTAHINT"){
			memset(bocheck,false,sizeof(bocheck));
			std::cout<<"Describe Your Name.";
			getline(std::cin,nameagain);
			for(i=0;i<=user;++i){
			j=i;
			if(nameagain!=command[i].name){
				bocheck[i]=true;
			}
			if(nameagain==command[i].name){
				bocheck[i]=false;
			}
			for(i=0;i<=user;++i){
				if(bocheck[i]==false){
					goto xx;
				}
				std::cout<<"Your Name Is Not In The Program.";
				getchar();
				goto goback;
			}
			xx:
			std::cout<<"First Question:"<<std::endl<<command[j].Q1<<'\n'<<"Answer:";
			getline(std::cin,nameagain);
			if(nameagain==command[j].A1){
				std::cout<<"Second Question:"<<std::endl<<command[j].Q2<<'\n'<<"Answer:";
				getline(std::cin,nameagain);
				if(nameagain==command[j].A2){
					std::cout<<"Confirmed That You Are "<<command[j].name<<" .";
					goto a;
				}
				else{
					std::cout<<"Wrong Answer!";
					getchar();
					goto goback;
				}
			}
			else{
					std::cout<<"Wrong Answer!";
					getchar();
					goto goback;
				}
			{		a:
					std::cout<<"Ok,"<<command[j].name<<",Your Hint Is This:\n";
					std::cout<<"--------------------------\n";
					std::cout<<command[j].hint<<std::endl;
					std::cout<<"--------------------------\n";
					getchar();
					goto password;
				}	
			}
		}
		memset(bocheck,false,sizeof(bocheck));
		for(i=0;i<=user;++i){
			j=i;
			if(in!=command[i].set){
				bocheck[i]=true;
			}
			if(in==command[i].set){
				bocheck[i]=false;
			}
			for(int x=0;x<MAXN;++x){
				if(bocheck[x]==0) goto hide;
				else goto fault;
			}
		}
		{
			hide:
			std::cout<<"Here is The Things You Want To See:<Enter To Continue>"<<std::endl;
			std::cout<<"-*-*-*-TOP SECRET*-*-*-*-TOP SECRET*-*-*-*"<<std::endl;
			std::cout<<command[j].hide<<"           		| | | |"<<std::endl;
			std::cout<<"-*-*-*-TOP SECRET*-*-*-*-TOP SECRET*-*-*-*"<<std::endl;
			getchar();
			goto goback;
		}
			fault:
			j=0;
			--times;
			if(times!=0) {
				if(time!=1) std::cout<<"No!Input Password Correctly!"<<"<You Still Have "<<times<<" times!>"<<std::endl;
				else std::cout<<"No!Input Password Correctly!"<<"You Still Have Only 1 Time Left!"<<std::endl;
				goto password;
			}
			else{
				std::cout<<"'System-Imposter' Detected!You Are Now Arrested!(Closing Computer In 3 Minute And Lock The Computer)"<<std::endl;
				times=4;
				system("@echo off");
				system("shutdown -s -t 180");
				std::cout<<"If You Now Entered The secret COMMAND,YOU STILL CAN GET RELASED!(Repeat secretcommand 4 times)"<<std::endl;
				/*while(n!=0){
					system("@start calc");
					system("@start cmd");
					system("@start write");
					system("@start mspaint");
					system("@start notepad");
					system("@start osk");
					system("@start taskmgr");
					system("@start eventvwr");
					system("@start explorer");
					system("@start magnify");
					system("@start dvdplay");
					system("@start services.msc");
					system("@start narrator");
					--n;
				}*/
				getline(std::cin,secretcommand);
				getchar();
				if(secretcommand==secretcommand1){
				system("shutdown -a");
				std::cout<<"Now Relased!"<<std::endl;
				getchar();
				goto goback;
				}
				else{
					while(time!=0){
					system("tree");
					--time;
					std::cout<<time<<" seconds left"<<std::endl;
					Sleep(100);
					if(time<=10){
					std::cout<<"Good Computer By The Way."<<std::endl;
					}
				}
			}
		}
	}
	if(userin==3){
		warranty();
		getchar();
		goto goback;
	}
	if(userin==4){
		getchar();
		std::cout<<"Input A Sentense You Want To Hide.\n";
		getline(std::cin,code);
		int l=code.length();
		int ran=random(10000,20000);
		int ran1=random(1457,4285);
		int ran2=random(5718,7142);
		SaveFile<<l<<" "<<ran<<" "<<ran1<<" "<<ran2<<" ";
		for(aa=0;aa<l;++aa){
			SaveFile<<(int)(code[aa])+ran-ran1+ran2<<" ";
		}
		//int ran=random(1,1000);
		/*for(aa=0;aa<l;++aa){
			code[aa]+=ran;
		}
		SaveFile<<ran<<" ";
		ran=random(20,30);
		for(aa=0;aa<l;++aa){
			code[aa]+=ran;
		}
		SaveFile<<ran<<" ";*/
		std::cout<<"Complete.";
		SaveFile.close();
		goto goback;
	}
	if(userin!=1&&userin!=2&&userin!=3&&userin!=0&&userin!=233&&userin!=2333&&userin!=4&&userin!=5&&userin!=6){
		getchar();
		std::cout<<"You Made A Wrong Number!"<<std::endl;
		std::cout<<"Developed By LHSC++.INC.<Press Enter To Get Out>"<<std::endl;
		getchar();
		goto goback;
	}
	if(userin==5){
		std::cout<<"Copy The Numbers Into The Screen.\n";
		int l1,random,random1,random2;
		std::cin>>l1>>random>>random1>>random2;
		int a[l1];
		for(aa=0;aa<l1;++aa){
			std::cin>>a[aa];
		}
		std::cout<<"Secret Sentense:\n";
		for(aa=0;aa<l1;++aa){
			std::cout<<(char)(a[aa]-random+random1-random2);
		}
		std::cout<<"\nDone!";
		goto goback;
	}
	if(userin==6){
		for(int i=0;i<500;++i){
			std::cout<<'\n';
		}
		goto goback;
	}
	if(userin==233||userin==2333){
		std::cout<<"You Entered The Private PRIVATE system of this!"<<std::endl;
		std::cout<<"1.Change The Three Commands"<<std::endl<<"2.HIGH SECURTY!(NO ENTRY)"<<std::endl<<"3.Say Troll!"<<std::endl;
		std::cin>>userininin;
		if(userininin==1){
			std::cout<<"The First Is For Release."<<std::endl<<"Now It is:";
			getline(std::cin,secretcommand1);
			std::cout<<"The Second Is For Entering All The Secrets."<<std::endl<<"Now It is:";
			getline(std::cin,secretcommand2);
			std::cout<<"The Third Command Is Also For Entering All The Secrets."<<std::endl<<"Now It is:";
			getline(std::cin,secretcommand3);
			goto goback;
		}
		if(userininin==2){
			std::cout<<"Error:No Permission From LHSC++.INC(C).Input Ten Times 2 Will Help.";
			for(int shx=0;shx<10;++shx){
				std::cin>>userininin;
				if(userininin!=2){
					std::cout<<"Hahahaha!You Just Cannot Get In!"<<std::endl;
					getchar();getchar();
					goto goback;
				}
			}
			std::cout<<"??????????????????????????????"<<std::endl;
			std::cout<<"(Count ?) Command Error."<<std::endl;
			std::cin>>num;
			if(num==30){
				std::cout<<"???????";
				std::cout<<"Command Error."<<std::endl;
				std::cin>>num;
				if(num==7){
					std::cout<<"??????????????????????????"<<std::endl;
					for(int ms=0;ms<10;++ms){
						milk=random(122,468238);
						s_s=random(100,200);
						std::cout<<"Error Command 0x"<<milk<<"xtg5d2"<<s_s<<std::endl;
						std::cin>>num;
						if(num!=s_s){
							std::cout<<"No!You Just Can't Get In,Don't You?"<<std::endl;
							getchar();
							goto goback;
						}
					}
					std::cout<<"Misson Denied:0xedj46xcje92s4"<<std::endl;
					std::cin>>num;
					if(num==46924){
						if(user==0){
							std::cout<<"No Passcode.";
							getchar();
							goto goback;
						}
						std::cout<<"All The Passcode Is Here"<<std::endl;
						for(int mi=0;mi<user;++mi){
							std::cout<<command[mi].set<<std::endl;
							std::cout<<"||||||||||||||||\n";
						}
						getchar();
						goto goback;
					}
				}
			}
		}
		if(userininin==3){
			myst();
		}
	}
	if(userin==0){
		std::cout<<"Welcome To The Settings."<<std::endl;
		std::cout<<"Developed By LHSC++.INC."<<std::endl;
		std::cout<<"1.Change How Many Times You Want To Troll"<<std::endl<<"2.See All Secrets(need secretcommand TWO)"<<std::endl;
		std::cin>>userinin;
		if(userinin==1){
			std::cout<<"(Original is 3)Now Troll Time=";
			std::cin>>n;
			std::cout<<std::endl<<"Complete.";
			getchar();
			goto goback;
		}
		if(userinin==2){
			if(user!=0){
			std::cout<<"Enter Secret Command TWO!"<<std::endl;
			getline(std::cin,secretcommand);
			getchar();
			if(secretcommand==secretcommand2){//I am a pig
				std::cout<<"Thanks For Telling The Truth."<<std::endl;
				std::cout<<"Now INPUT the secretcommand THREE!";
				getline(std::cin,secretcommand);
			}
			else{
				std::cout<<"Haha....You Thief Cannot Get Into Here...Stupid!"<<std::endl;
				getchar();
				goto goback;
				}
				if(secretcommand==secretcommand3){//what a pig am I
				std::cout<<"All The Secrets are Here....."<<std::endl;
				for(int s=0;s<user;++s){
					std::cout<<"--------------------------"<<std::endl;
					std::cout<<command[s].hide<<"      | |"<<std::endl;
					std::cout<<"--------------------------"<<std::endl;
				}
				std::cout<<"Done!"<<std::endl;
			}
			else{std::cout<<"Haha....You Thief Cannot Get Into Here...Stupid!"<<std::endl;}
			}
			else{
				std::cout<<"No one had Make a Secret Before!(Create Some!)"<<std::endl;
			}
			getchar();
			goto goback;
		}
	}
	return 0;
}
