#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include <stdlib.h>
using namespace std;

class Bill{
	private:
		int weight;
		int money;
		int cost;
		int received;
		string type;
	public:
		 Bill(){
		 	weight = 0;
			cost = 0;
			received = 0;	
			type = " ";
		 }
		 
    	int getDataBill(string type2,int weight2,int money2){
    				money = money2;
    				weight = weight2;
    				type = type2;
		}

    	int getAmountReceived(){
    		if(type=="ww"){
    			cost=weight*15;
    			received=money-cost;
			}else if(type=="dd"){
				cost=weight*20;
				received=money-cost;
			}else{
				cost=(weight*15)+(weight*20);
				received=money-cost;
			}
			return received;
		}
		
    	void printBill(){
    		cout << " " << endl<< endl<< endl;
			cout << " 							 ___________________________________________________________________________________________________"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << "							|                                         CLUSTER 8 WASHING                                         |"<< endl;
			cout << "							|___________________________________________________________________________________________________|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(30) << std::right << "Customer name : " << setw(20) << std::left << " gam" << setw(20) << std::right << "Tel : " <<  setw(10) << std::left << "0000000000" << setw(20)<< std::right << "|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(30) << std::right << "Date  : " << setw(21) << std::left << "21/10/2020" << setw(20) << std::right << "Time : " <<  setw(10) << std::left << "20.20" << setw(19)<< std::right << "|"<< endl;
			cout << "							|___________________________________________________________________________________________________|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(30) << std::right << "Item " << setw(20) << std::right << "|" << setw(25) << std::right << "Cost" << setw(25)<< std::right << "|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(28) << std::right << "Washing" << setw(10) << std::right << "15KG" << setw(12) << std::right << "|" <<  setw(25) << std::right << "2000" << setw(25)<< std::right << "|"<< endl;	
			cout << "							|___________________________________________________________________________________________________|"<< endl;	
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(48) << std::right << "Total " << setw(2) << std::right << "|" << setw(25) << std::right << "10,000" << setw(5) << std::right << "Bath" << setw(20)<< std::right << "|"<< endl;	
			cout << "							|                                                                                                   |"<< endl;
			cout << "							|___________________________________________________________________________________________________|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << "							|                                     At your disposal ,THANK YOU                                   |"<< endl;
			cout << "							|___________________________________________________________________________________________________|"<< endl;		
		}			
};


int main(){
	Bill objB;
	int money,weight;	
	string type;
	
	cout << "input option : ";
	cin  >> type;
	
	
	cout<<"Weight : ";
	cin>>weight;

	
	cout<<"Money : ";
	cin>>money;	
	
	objB.getDataBill(type,weight,money);
	cout<<"Received : ";
	
	cout<< objB.getAmountReceived();
	objB.printBill();
}
