#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
using namespace std;

class Editdryingmachine {
	
	public:
	string status[5];
	int number;
	string Arraymac;
		
Editdryingmachine(int n){
	
	number = n;
}
void showdryingmachine(){
	
			string filein,m1,m2,m3,m4,m5;
			ifstream infile;
			infile.open("dryingmachine.txt", ios::in);
			
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
			ifstream infile;
			infile.open("dryingmachine.txt", ios::in);
			
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
	cout<<"Enter number clothes drying machine (1-5) : ";	
	cin>>n;
	}while(n<1||n>5);
	
	
	cout<<"Enter status clothes drying machine : ";
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
			infile.open("dryingmachine.txt", std::ios::out | std::ios::trunc);
			
				infile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] ;
		
			infile.close();
		
	}
	}while(jojo!='y'&&jojo!='n');
}

	void printEditdryingmachine(){
 cout<<" ______    _ _ _         _            _                                    _      _"<<endl;             
 cout<<"|  ____|  | (_) |       | |          (_)                                  | |    (_)"<<endl;            
 cout<<"| |__   __| |_| |_    __| |_ __ _   _ _ _ ___ _____   _ __ ____  __ _  ___| |___  _ _ ___  ___ "<<endl; 
 cout<<"|  __| | _` | | __|  | _` | '__| | | | | '_  || _  | | '_ ` _  |/ _` || __| '_  || | '_  || = ''"<<endl;
 cout<<"| |___|| (_|| | |_   | (_|| |  | |_| | | | | ||(_| | | | | | | ||(_| ||(__| | | || | | | || __/"<<endl; 
 cout<<"|______)__,_|_||__|  |__,_|_|  |___, |_|_| |_||__, | |_| |_| |_||__,_||___|_| |_||_|_| |_||___| "<<endl;
 cout<<"                                 __| |         __| |                                           "<<endl;
 cout<<"                                |____|        |____|             "<<endl;
	} 
};
int main(){
	int n;
	string st;
   	Editdryingmachine E(n);
	E.printEditdryingmachine();
	cout<<endl;
	cout<<endl;

	E.showdryingmachine();
	E. Editstatus( st,n);
}
