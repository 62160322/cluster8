#include "wash_cluster8.h"
employee::employee()
{
	nameEmployee = " ";
	telEmployee = " ";
}
void employee::getdataemployee(string username,string tel)
{

}
Editdryingmachine::Editdryingmachine(){
	status = " ";
	number = " ";
}
void Editdryingmachine::setdata(){
	status = st;
	number = n;
}
string Editdryingmachine::correctstatus(string st,string n){
	do{
	cout<<"Enter number baking machine(1-5) : "<<endl;	
	cin>>n;
	}while(n<1||n>5);
	cout<<"Enter status baking machine : "<<endl;
	cin>>st;
	if(n==1){
	cout<<"------------	"<<endl;
	cout<<"|    1"<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	cout<<"|          |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<st<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|     "<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	}
	if(n==2){
	cout<<"------------	"<<endl;
	cout<<"|    2"<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	cout<<"|          |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<st<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|     "<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	}
	if(n==3){
	cout<<"------------	"<<endl;
	cout<<"|    3"<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	cout<<"|          |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<st<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|     "<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	}
	if(n==4){
	cout<<"------------	"<<endl;
	cout<<"|    4"<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	cout<<"|          |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<st<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|     "<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	}
	if(n==5){
	cout<<"------------	"<<endl;
	cout<<"|    5"<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	cout<<"|          |	"<<endl;
	cout<<"|"<<" "<<setw(6)<<st<<setw(4)<<"|"<<setw(5)<<endl;
	cout<<"|     "<<setw(6)<<"|"<<endl;
	cout<<"------------	"<<endl;
	}				
}
void Editdryingmachine::showBakingmachine(){
	cout<<"------------		------------		------------        ------------		------------	"<<endl;
	cout<<"|    1     |		|    2 	   |		|    3     |        |    4     |		|    5	   |	"<<endl;
	cout<<"------------		------------		------------	    ------------		------------	"<<endl;
	cout<<"|          |		|     	   |		|          |        |          |		|    	   |	"<<endl;
	cout<<"|          |		|     	   |		|          |        |          |		|    	   |	"<<endl;
	cout<<"|          |		|     	   |		|          |        |          |		|    	   |	"<<endl;
	cout<<"------------		------------		------------        ------------		------------	"<<endl;

}
