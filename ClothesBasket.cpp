#include<iostream>
#include<string>

using namespace std;

class ClothesBasket{
	public:
		double weightClothes;
		string typeJob;
		
		ClothesBasket(){
			
		}
		void setClothesBasket(double weight,string type){
			weightClothes = weight;
			typeJob = type;
		}
		double getWeight(){
			return weightClothes; 
		}
		string getType(){
			return typeJob;
		}
	
};

class EditClothesBsketStatus{
	protected:
		string statusClothes;
		ClothesBasket cb;
	public:
		EditClothesBsketStatus();
		EditClothesBsketStatus(string status);
		void show();
};

EditClothesBsketStatus::EditClothesBsketStatus()
{
	
}
EditClothesBsketStatus::EditClothesBsketStatus(string status)
{
	statusClothes = status;
}
void EditClothesBsketStatus::show()
{
	cout<<"Username:"<<endl;
	cout<<"Phone Number:"<<endl;
	cout<<"Queue:"<<endl;
	cout<<"Status:"<<statusClothes<<endl;
}



