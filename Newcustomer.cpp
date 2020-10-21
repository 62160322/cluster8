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
    	

 		void aadCustomer(string name,string tel,string date,string weight,string option){
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




int main(){
    string n;
    string t;
    string d;
    string w;
    string o;

    Newcustomer N;
    

    cout << "=============== Newcustomer ============" << endl;
    cout << "Input Name: ";
    cin >> n;

    cout << "Input tel: ";
    cin >> t;
    
    cout << "Input date: ";
    cin >> d;
    
    cout << "Input weight: ";
    cin >> w;
    
    cout << "Input option: ";
    cin >> o;
    
	N.aadCustomer(n,t,d,w,o);
    N.writefile();
     
     /*if(N.writefile() == false){
     	cout << "save file Error!!!" << endl;
	 }else{
	 	cout << "save Suscess" << endl;
	 }*/
    	

};
