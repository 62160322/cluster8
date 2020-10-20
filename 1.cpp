#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct data{
	string id;
	string name;
	string num;
	string institute;
	data *link;
};
class student{
	private:
		data *head;
		data *tail;
		data *temp;
	public:
	
		int AddData(string id,string n,string num,string ins){
			if(head==NULL){
				head = new data;
				head->id = id;
				head->name = n;
				head->num = num;
				head->institute = ins;
				tail = head;
				tail->link = NULL;
			}else{
				temp = new data;
				temp->id = id;
                temp->name = n;
                temp->num = num;
                temp->institute = ins;
                tail->link = temp;
                tail = temp;
				tail->link = NULL;
			}
		}
		bool file(){
			string id,name,num,institute,filein;
			ifstream data;
			data.open("student.dat",ios::in);
			if(data.fail()){
				return false;
			}else{
				while(getline(data,filein)){
					id = filein.substr(0,filein.find(','));
				         filein.erase(0,filein.find(',')+1);
					name = filein.substr(0,filein.find(',')+1);
						filein.erase(0,filein.find(',')+1);
					num = filein.substr(0,filein.find(','));
					     filein.erase(0,filein.find(',')+1);
					institute = filein.substr(11,filein.find(','));
					     filein.erase(0,filein.find(',')+1);	
					AddData(id,name+'.',num,institute);
				}
			}
		}
		void print(){
			int i=1;
			if(head == NULL){
		        	cout<< "the list is empty" << endl;
			}else{
				cout << "================================ BUUCHANA ==================================="<< endl;
				cout << setw(6) << left  <<" NO"<< setw(15) <<"Student ID"<< setw(21) <<"Student Name"<< setw(16)<< "Tel." << setw(15)<< left << "Department" << endl;
		        temp = head;
				while(temp != NULL){
				cout << right << setw(3)<< i <<setw(5)<< left<<"." <<setw(15)<< temp->id << setw(10) << temp->name.substr(0,temp->name.find(" "));
				temp->name.erase(0,temp->name.find(" ")+1);
				cout << setw(5) << temp->name.substr(0,1)+'.'<< setw(15) << temp->num<< setw(20) << temp->institute << endl;
	            temp=temp->link;
				i++;	
				}
			}	
		}
};
int main(){
	student *data = new student();
	data->file();
	int menu;
	cout << "====================== BUUCHANA ============================="<<endl;
	cout << "1.Student Registration "<<endl;
	cout << "2.Exit"<<endl;
	cout << "============================================================="<<endl;
	cout << "Enter : ";
	cin >> menu;
	switch(menu){
		case 1:
			data->print();
			break;

		case 2:
			break;

	}
	return 0;
}
