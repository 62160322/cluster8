#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class editclothesbasketstatus{
	protected:
		//string finishDay;
		//string finishTime;
		string statusClothes;
		//ClothesBasket c; 
		//Newcustomer n;
		//queuewashing qw;
		//queuedrying qd;
	public:
		editclothesbasketstatus(){
			//statusClothes = " ";
		}
		editclothesbasketstatus(string status){
			statusClothes = status;
		}
		int check(string u,string p){
			string line,user,pass;
			ifstream myfile;
			myfile.open(" ");
			
			if(myfile.fail()){
				
			}else{
		   		while(getline(myfile,line)){
	    			user = line.substr(0,line.find(','));
     		    	    	line.erase(0,line.find(','+1));    		    		
					pass = line.substr(0,line.find(' '));
				       line.erase(0,line.find(' ')+1);
	    			
					if(user==u&&pass==p){
						return 1;
					}    
	   			}
				myfile.close();
			}
		}
		void show(){					
			string user,pass;
				menu:
					cout<<"Correct clothing status"<<endl;
					cout<<"=========================="<<endl;
					cout<<"Username:";
					cin>>user;
					cout<<"Phone Number:";
					cin>>pass;
					system("cls");
					
					if(check(user,pass)==1){
						cout<<"Correct clothing status"<<endl;
						cout<<"=========================="<<endl;
						cout<<"Username:"<<user<<endl;
						cout<<"Phone Number:"<<pass<<endl;
						cout<<"Queue:"<<endl;
					}else{
						goto menu;
					}
					cout<<"Status:";
					cin>>statusClothes;
				yn:			
					char a;
					cout<<"Do you want to edt again? (y/n or Y/N):";
					cin>>a;
					if(a=='y'||a=='Y'){
						goto menu;
					}else if(a=='n'||a=='N'){
						
					}else{
						goto yn;
					}						
		
		}
};

int main(){
	editclothesbasketstatus e;
	//Newcustomer n;
	
	//n.readfile();
 	//n.show();
	//cout<<tempCustomer->
	e.show();
    return 0;	

};
