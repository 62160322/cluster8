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
		string name,tel,day,weight,line,type;
	  	ifstream myfile;
	  
	  	myfile.open("Customer.dat");
	  	if(myfile.fail()){

	  	}else{
	   		while(getline(myfile,line)){
				name = line.substr(0,line.find(','));
   				     line.erase(0,line.find(',')+1);
	    		tel = line.substr(0,line.find(','));
  	    	    		line.erase(0,line.find(','));
	    		day = line.substr(0,line.find(','));
	        			line.erase(0,line.find(',')+1);
	   			weight = line.substr(0,line.find(','));
   		    			line.erase(0,line.find(',')+1);
				type = line.substr(0,line.find(' '));
				       line.erase(0,line.find(' ')+1);
				       addCustomer(name,tel,day,weight,type);
	    			//cout<<name<<" "<<tel<<endl;   
	   		}
	   		//cout<<name<<" "<<tel<<endl;
	      	 	myfile.close();
	   	}
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
	nodeCustomer *t;	
	t = headCustomer;
	readfile();
	cout<<"Username:"<<t->node_name<<endl;
	cout<<"Phone Number:"<<tel<<endl;
	cout<<"Queue:"<<endl;
	cout<<"Status:"<<statusClothes<<endl;
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
