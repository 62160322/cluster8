#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
using namespace std;

class Editwashingmachine  {
	
	public:
	string status[5];
	int number;
	string Arraymac;
		
Editwashingmachine(int n){
	
	number = n;
}
void showwashingmachine(){
	
			string filein,m1,m2,m3,m4,m5;
			ifstream infile;
			infile.open("washingmachine.txt", ios::in);
			
			while(getline(infile, filein)){
			
					m1=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
					
					m2=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);

					m3=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
		
					m4=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
					
					m5=filein.substr(0,filein.find(','));
						
			}
			infile.close();
	
	cout<<"------------		------------		------------   		------------		------------	"<<endl;
	cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
	cout<<"------------		------------		------------		------------		------------	"<<endl;
	cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<m1<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m2<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m3<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m4<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m5<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
	cout<<"------------		------------		------------    	------------		------------	"<<endl;

}


string Editstatus(string st,int n){
	int h=1;
	int i;
	string set[5];
	
	
			string filein,m1,m2,m3,m4,m5;
			string filename,line;
			string checkname,checktel;
			ifstream infile;
			infile.open("washingmachine.txt", ios::in);
			
			while(getline(infile, filein)){
			
					m1=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
					
					m2=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);

					m3=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
		
					m4=filein.substr(0,filein.find(','));
						 filein.erase(0,filein.find(',')+1);
					
					m5=filein.substr(0,filein.find(','));
						
			}
			infile.close();
		
	
			
		status[0]= m1;
		status[1]= m2;
		status[2]= m3;
		status[3]= m4;
		status[4]= m5;
			
		
	menu:
	
	do{
	cout << endl;
	cout<<"Enter number clothes washing machine (1-5) : ";	
	cin>>n;
	}while(n<1||n>5);
	
	
	cout<<"Enter status clothes washing machine : ";
	cin>>st;
	cout << endl;
	
	status[n-1]=st;
	
	

	
	cout<<"------------		------------		------------   		------------		------------	"<<endl;
	cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
	cout<<"------------		------------		------------		------------		------------	"<<endl;
	cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<status[0]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[1]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[2]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[3]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[4]<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
	cout<<"------------		------------		------------    	------------		------------	"<<endl;

	
	char jojo;
	do{
	
	cout << endl;
	cout << "Do you want to edit more changes ? (y/n ) : ";
	cin >> jojo;
	if(jojo=='y'){
	
		goto menu;
			
	}else if(jojo=='n'){
	
			ofstream infile;
			infile.open("washingmachine.txt", std::ios::out | std::ios::trunc);
			
				infile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] ;
		
			infile.close();
		
	}
	}while(jojo!='y'&&jojo!='n');
}

	void printEditwashingmachine(){
 cout<<"  _____      _  _    _                         _     _                                    _     _             "<<endl;      
cout<<" |  ___|    | |(_)  | |                       | |   (_)                                  | |   (_)            "<<endl;
cout<<" | |__   ___| | _  _| |_    _     _  __ _ ____| |__  _ _ __   __ _   _ __ ___   __ _  ___| |__  _ _ __   ___  "<<endl;
cout<<" |  __| |  _  || ||__ __|  | | _ | |/ _` | ___| '_ `| | '_ ` / _` | | '_ ` _ ` / _` |/ __| '_ `| | '_ ` / _ ` "<<endl;
cout<<" | |___ | (_| || |  | |_   | || || | (_|  `__ ` | | | | | | | (_| | | | | | | | (_|   (__| | | | | | | |  __/ "<<endl;
cout<<" |_____||_____||_|  |___|  |_______|`__,_|____|_| |_|_| |_|_|`__, | |_| |_| |_|`__,_|`___|_| |_|_|_| |_|`___| "<<endl;
cout<<"                                                              __/ |                                           "<<endl;
cout<<"                                                             |___/                                            "<<endl;
	} 
};
int main(){
	int n;
	string st;
   	Editwashingmachine E(n);
	E.printEditwashingmachine();
	cout<<endl;
	cout<<endl;

	E.showwashingmachine();
	E. Editstatus( st,n);
}
