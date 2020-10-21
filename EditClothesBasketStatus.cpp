#include<iostream>
#include<string>

using namespace std;

class EditClothesBsketStatus{
	protected:
		string statusClothes;
	public:
		EditClothesBsketStatus(){
			
		}
		EditClothesBsketStatus(string status){
			statusClothes = status;	
		}
		InformationCustomer(string username,string phone,string queuecode){
			
		}
		void show(){
			cout<<"Username:"<<endl;
			cout<<"Phone Number:"<<endl;
			cout<<"Queue:"<<endl;
			cout<<"Status:"<<statusClothes<<endl;
		}
};



