#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class nodeCustomer{
    public:
        string node_name,node_tel,node_date,node_weight,node_option;
        nodeCustomer *linkCustomer;
};

          

class Newcustomer{
    public:
    	nodeCustomer *headCustomer;
    	nodeCustomer *tailCustomer;
    	nodeCustomer *tempCustomer;
    	
        string name;
        string tel;
        string date;
        string weight;
        string option;
        int count;
        
    	Newcustomer(){
    		this->headCustomer = NULL;
    		this->tailCustomer = NULL;
    		this->tempCustomer = NULL;
		}

             
    	void setdataCustomer(){
        	name = " ";
        	tel = " ";
        	date = " ";
        	weight = " ";
        	option = " ";
    	}


		string getdata(string n,string t,string d,string w,string o){
        	name = n;
        	tel = t;
        	date = d;
        	weight = w;
        	option = o;
    	}
    	

 		void addCustomer(string name,string tel,string date,string weight,string option){
            if(headCustomer==NULL){
            //head
                headCustomer = new nodeCustomer;
                headCustomer->node_name = name;
                headCustomer->node_tel = tel;
                headCustomer->node_date = date;
                headCustomer->node_weight = weight;
                headCustomer->node_option = option;
            //tail
                tempCustomer = headCustomer;
                tempCustomer->linkCustomer;
            }else{
                nodeCustomer *tempCustomer = new nodeCustomer;
                tempCustomer->node_name = name;
                tempCustomer->node_tel = tel;
                tempCustomer->node_date = date;
                tempCustomer->node_weight = weight;
                tempCustomer->node_option = option;
                
            //tail
                tailCustomer->linkCustomer = tempCustomer;
                tailCustomer = tempCustomer;
                tailCustomer->linkCustomer = NULL;
            }//if-else
    	}//addCustomer
        



		void writefile(){
			ofstream myfile("Customer.dat",ios::app);
			if(myfile.is_open()){
			
			nodeCustomer *tempCustomer;	
			tempCustomer = headCustomer;
			
			
			while(tempCustomer!=NULL){
				myfile <<  tempCustomer->node_name <<","<< tempCustomer->node_tel <<","<< tempCustomer->node_date <<","<< tempCustomer->node_weight <<","<< tempCustomer->node_option << endl;
				tempCustomer = tempCustomer->linkCustomer;	
				
			}
	
			myfile.close();
			//return true;
			}//if
		//return false;
		}
		
		void readfile(){
		string line;
		ifstream myfile;
		myfile.open("Customer.dat");
		
		while(getline(myfile,line)){
			cout << line << endl;
		}//while
		
		}//myfile
};//class Newcustomer


class editclothesbasketstatus:public Newcustomer{
	protected:
		//string finishDay;
		//string finishTime;
		string statusClothes;
		//ClothesBasket c; 
		//Newcustomer n;
		//queuewashing qw;
		//queuedrying qd;
	public:
		editclothesbasketstatus();
		editclothesbasketstatus(string status);
		void show();
};

editclothesbasketstatus::editclothesbasketstatus(){
	
}
editclothesbasketstatus::editclothesbasketstatus(string status)
{
	//finishDay = day;
	//finishTime = time;
	statusClothes = status;
}
void editclothesbasketstatus::show()
{

	char a;
	string user,pass;
	//do{
	menu:
	cout<<"Correct clothing status"<<endl;
	cout<<"Username:";
	cin>>user;
	cout<<"Phone Number:";
	cin>>pass;
	//if(){
		cout<<"Username:"<<user<<endl;
		cout<<"Phone Number:"<<pass<<endl;
		cout<<"Queue:"<<endl;
	//}
	cout<<"Status:";
	cin>>statusClothes;
	cout<<"Do you want to edt again? (y/n):";
	cin>>a;
	if(a=='y'){
		goto menu;
	}
	//}while(a!='y');
}

int main(){
	editclothesbasketstatus e;
	Newcustomer n;
	
	//n.readfile();
//	n.show();
	//cout<<tempCustomer->
	e.show();
    return 0;	

};
