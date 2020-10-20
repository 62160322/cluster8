#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class node{
	public :
		string node_id,node_name,node_tel,node_fac;
		node *link;
};

class linklist{
	public :
		node *head;
		node *tail;
		node *temp;
	

		linklist(){
		this->head = NULL;
		this->tail = NULL;
		this->temp = NULL;
		}

		void add(string id,string name,string tel,string fac){
			if(head==NULL){
				head = new node;
				head->node_id = id;
				head->node_name = name;
				head->node_tel = tel;
				head->node_fac = fac;
				tail = head;
				tail->link = NULL;
			}else{
				temp = new node;
				temp->node_id = id;
				temp->node_name = name;
				temp->node_tel = tel;
				temp->node_fac = fac;
				tail->link = temp;
				tail = temp;
				tail->link = NULL;
			}//if-else	
		}//add

		bool loaddata(){
		string id,name,tel,fac,line;
		ifstream myfile;
		myfile.open("student.dat");
			if(myfile.fail()){
				return false;
			}else{
				while(getline(myfile,line)){
				id = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				name = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				tel = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				fac = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				add(id,name,tel,fac);
				}//while
			return true;
			}//if-else
			
		}//loaddata
		void show(){
			if(head == NULL){
			cout <<" Empty "<<endl;	
			}
			else{
				cout<<setw(30)<<left<<"================"<<setw(30)<<left<<"=================="<<setw(30)<<left<<"================="<<setw(30)<<left<<"==============="<<endl;
				cout<<setw(30)<<left<<"||  Nisit ID  ||"<<setw(30)<<left<<"||  Nisit Name  ||"<<setw(30)<<left<<"||  Nisit tel  ||"<<setw(30)<<left<<"||  Faculty  ||"<<endl;
				cout<<setw(30)<<left<<"================"<<setw(30)<<left<<"=================="<<setw(30)<<left<<"================="<<setw(30)<<left<<"==============="<<endl;
			}
			temp = head;
			while(temp!=NULL){
			cout<<setw(30)<<left<<temp->node_id<<setw(30)<<left<<temp->node_name<<setw(30)<<left<<temp->node_tel<<setw(30)<<left<<temp->node_fac<<endl;
			temp = temp->link;
			}	
		}
};

int main(){
	linklist L;
	L.loaddata();
	L.show();
}
