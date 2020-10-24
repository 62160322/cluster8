#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>

using namespace std;

class NodeClothesBasket{
	public:
		string name,tel,queue,time,status;
		NodeClothesBasket *link;
		NodeClothesBasket(string n,string t,string q,string ti,string s){
			name = n;
			tel = t;
			queue = q;
			time = ti;
			status = s;
			link =NULL;
		}
};


class ClothesBasket{

	private: 
		
		NodeClothesBasket *head;
		NodeClothesBasket *tail;
		int count;
		string name_customer;
		string tel_Customer;
		
	public:
	
		ClothesBasket(){
			
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
			name_customer=" ";
			tel_Customer=" ";
			
		}
		
		~ClothesBasket(){
			
			for(int i=1;i<this->count;i++){
				NodeClothesBasket *temp = this->head;
				this->head = this->head->link;
				delete temp;
				temp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
			
		}
		
		
		void setDataCustomer(string name,string tal){
			
			name_customer=name;
			tel_Customer=tal;
			
		}
		
		void setClothesBasket(string n,string t,string q,string ti,string s){
			
			NodeClothesBasket *temp = new NodeClothesBasket(n,t,q,ti,s);
			if(count == 0){
				head = temp;
				tail = head;
				count++;
			}
			
			else{
				tail->link = temp;
				tail = temp;
				count++;
			}
			
		}
		
		void getDataCustomer(){
			
			string n,t,q,ti,s,filein;
			ifstream infile;
			infile.open("Customer.dat");
				while(getline(infile,filein)){
				n = filein.substr(0,filein.find(','));
			        filein.erase(0,filein.find(',')+1);
			    t = filein.substr(0,filein.find(','));
			        filein.erase(0,filein.find(',')+1);
				q = filein.substr(0,filein.find(','));
			        filein.erase(0,filein.find(',')+1);
			   ti = filein.substr(0,filein.find(','));
			        filein.erase(0,filein.find(',')+1);
				s = filein.substr(0,filein.find(','));
			        filein.erase(0,filein.find(',')+1);	
				setClothesBasket(n,t,q,ti,s);
			}
			count=0;
			infile.close();
			
		}
		
		bool CheckStatusClothesBasket(){
			
			NodeClothesBasket *temp = head;
			getDataCustomer();
			while(temp != NULL){
				
				if(name_customer==temp->name&&tel_Customer==temp->tel){
					
					return true;	
		
				}
				count=0;
				temp=temp->link;
				
			}
			
	
		}
		
		void Show(){
			
			int choice,num;
			string name,tel;
 			

			mainmenu:
		
			do{
				cout<<"==============================Customer=============================="<<endl;
				cout<<"1. Check clothing status"<<endl;
				cout<<"2. Exit"<<endl;
				cout<<"===================================================================="<<endl;
				cout<<"Enter :";
				cin>>choice;
				if(choice==1){
					
					system("CLS");
					cout<<"Enter Username : ";
					cin>>name;
					cout<<"Enter Phone Number : ";
					cin>>tel;
					setDataCustomer(name,tel);
					system("CLS");
					CheckStatusClothesBasket();
					if(CheckStatusClothesBasket()==1){
						NodeClothesBasket *temp = head;
						getDataCustomer();
						while(temp != NULL){
							if(name_customer==temp->name&&tel_Customer==temp->tel){
								cout<<"Username : "<<temp->name<<endl;
								cout<<"Phone Number : "<<temp->tel<<endl;
								cout<<"Queue : "<<temp->queue<<endl;
								cout<<"Booking time : "<<temp->time<<endl;
								cout<<"Status : "<<temp->status<<endl;
							}
						temp=temp->link;
						}
						cout<<endl;
						goto mainmenu;
						
					}
					else{
						
						cout<<"!!!!!Invalid Username or Phone Number!!!!"<<endl;
						cout<<endl;
						goto mainmenu;
						
					}
					
					
					
				}
				
				else if(choice==2){
					
					
					
				}
		
			}while(choice!=2);
			
		}
			
};


int main(){
	
	
	ClothesBasket *obj_ClothesBasket = new ClothesBasket();
	obj_ClothesBasket->Show();
	
	return 0;
}
