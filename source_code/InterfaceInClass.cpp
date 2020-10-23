#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include <stdlib.h>
using namespace std;

class Show{
	public:
		int c;
		
		void TOP(){	                                                                                                                                               
			FILE *file;
			file = fopen("top.txt", "r");
			if (file){
				while ((c = getc(file)) != EOF)
					putchar(c);
	   				fclose(file);
			}
		}
		
		void Employee(){
			string name,tel,pick,date,option;
			int menu,weight,received;
			booking:
			FILE *file;
			file = fopen("menuem.txt", "r");
			if (file){
				while ((c = getc(file)) != EOF)
					putchar(c);
	   				fclose(file);
			}//open menu
			cout << " " << endl<< endl<< endl;
			cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
			cout << setw(100) << std::right << "Enter Menu : ";
			cin  >> menu;
			cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
			if(menu==1){
				no:				
				FILE *file;
				file = fopen("booking.txt", "r");
				if (file){
					while ((c = getc(file)) != EOF)
						putchar(c);
	   					fclose(file);
					}//open file menu booking
				cout << " " << endl<< endl<< endl;
				cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
				cout << setw(100) << std::right << "Enter Menu : ";
				cin  >> menu;
				cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
				
				if(menu==1){
					cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
					cout << setw(126) << std::right << "Are you sure enter in new customer (y/n) : ";
					cin  >> pick;
					cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						if(pick=="y"){
							goto yes;
						}else{
							goto no;
						}//check sure
						
					yes:
					cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                           NEW  CUSTOMER                                           |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(55) << std::right << "Enter Name Customer : ";
					cin  >> name;
					cout << setw(57) << std::right << "|" << setw(56) << std::right << " Enter Phone Number : ";
					cin  >> tel;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					
					FILE *file;
					file = fopen("submit.txt", "r");
						if (file){
							while ((c = getc(file)) != EOF)
								putchar(c);
	   							fclose(file);
						}//open file submit
					cout << " " << endl<< endl<< endl;	
					cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
					cout << setw(115) << std::right << "Are you sure for submit (y/n) : ";
					cin  >> pick;
					cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;	
					if(pick=="y"){
						yes2:
						cout << " " << endl<< endl<< endl;
						cout << " 							 ___________________________________________________________________________________________________"<< endl;
						cout << "							|                                                                                                   |"<< endl;
						cout << "							|                                           NEW  CUSTOMER                                           |"<< endl;
						cout << "							|___________________________________________________________________________________________________|"<< endl;
						cout << "							|                                                                                                   |"<< endl;
						cout << setw(57) << std::right << "|" << setw(45) << std::right << "Username : " << setw(10) << std::right << "10,000,000" << setw(5) << std::right << "Bath"<< setw(40) << std::right << "|" << endl;	
						cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Date : ";
						cin  >> date;
						cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Weight : ";
						cin  >> weight;
						cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Option : ";
						cin  >> option;
						cout << "							|___________________________________________________________________________________________________|"<< endl;
						FILE *file;
						file = fopen("submit.txt", "r");
						if (file){
							while ((c = getc(file)) != EOF)
								putchar(c);
	   							fclose(file);
						}//open file submit
						cout << " " << endl<< endl<< endl;	
						cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						cout << setw(115) << std::right << "Are you sure for submit (y/n) : ";
						cin  >> pick;
						cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						if(pick=="y"){
							cout<<"wait!";
						}else{
							goto yes2;
						}
					}else{
						goto yes;
					}//check sure		
					
				}else if(menu==2){
					cout << " " << endl<< endl<< endl;
					cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
					cout << setw(126) << std::right << "Are you sure enter in new customer (y/n) : ";
					cin  >> pick;
					cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						if(pick=="y"){
							goto yes3;
						}else{
							goto no;
						}//check sure
					yes3:
					cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                         REPEAT  CUSTOMER                                          |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(55) << std::right << "Enter Name Customer : ";
					cin  >> name;
					cout << setw(57) << std::right << "|" << setw(56) << std::right << " Enter Phone Number : ";
					cin  >> tel;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Date : ";
					cin  >> date;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Weight : ";
					cin  >> weight;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "Enter Option : ";
					cin  >> option;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					FILE *file;
						file = fopen("submit.txt", "r");
						if (file){
							while ((c = getc(file)) != EOF)
								putchar(c);
	   							fclose(file);
						}//open file submit
						cout << " " << endl<< endl<< endl;	
						cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						cout << setw(115) << std::right << "Are you sure for submit (y/n) : ";
						cin  >> pick;
						cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
						if(pick=="y"){
							cout<<"wait!";
						}else{
							goto yes3;
						}
				}else{
					goto booking;
				}
						
			}else if(menu==2){
				cout << setw(130) << std::right << "________________________________________________"<< endl<< endl;
				cout << setw(126) << std::right << "Are you sure enter in payment (y/n) : ";
				cin  >> pick;
				cout << endl << setw(130) << std::right << "________________________________________________"<< endl<< endl;
				if(pick=="y"){
					cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                              Payment                                              |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(55) << std::right << "Enter Name Customer : ";
					cin  >> name;
					cout << setw(57) << std::right << "|" << setw(56) << std::right << " Enter Phone Number : ";
					cin  >> tel;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "Clothing Weight : "<< setw(10) << std::right << "10,000,000"  << setw(45) << std::right << "|" << endl;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "The Cost : " << setw(10) << std::right << "10,000,000" << setw(45) << std::right << "|" << endl;
					cout << setw(57) << std::right << "|" << setw(55) << std::right << "Enter Amount Received  : ";
					cin  >> received;
					cout << setw(57) << std::right << "|" << setw(45) << std::right << "Amount Of Change : " << setw(10) << std::right << "10,000,000" << setw(45) << std::right << "|" << endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					
					
				}else{
					goto booking;
				}//check sure
			}else if(menu==3){
				
			}else if(menu==4){
				
			}else{
				
			}//menu Employee
			
		}
		
		
		
		
		
		
		void MenuBooking(){
			FILE *file;
			file = fopen("booking.txt", "r");
			if (file){
				while ((c = getc(file)) != EOF)
					putchar(c);
	   				fclose(file);
			}
		}
		
		void ShowCheckRate(){
			int wash,dry;
			FILE *file;
			file = fopen("checkrate.txt", "r");
			if (file){
				while ((c = getc(file)) != EOF)
					putchar(c);
	   				fclose(file);
			}
			cout << " " << endl<< endl<< endl;
			cout << " 							 ___________________________________________________________________________________________________"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << "							|                                             THE  COST                                             |"<< endl;
			cout << "							|___________________________________________________________________________________________________|"<< endl;
			cout << "							|                                                                                                   |"<< endl;
			cout << setw(57) << std::right << "|" << setw(55) << std::right << "Enter Weight Washing : ";
			cin  >> wash;
			cout << setw(57) << std::right << "|" << setw(56) << std::right << " Enter Weight Drying   : ";
			cin  >> dry;
			cout << "							|___________________________________________________________________________________________________|"<< endl;	
			cout << "							|                                                                                                   |"<< endl;	
			cout << setw(57) << std::right << "|" << setw(45) << std::right << "The Cost : " << setw(10) << std::right << "10,000,000" << setw(5) << std::right << "Bath"<< setw(40) << std::right << "|" << endl;	
			cout << "							|___________________________________________________________________________________________________|"<< endl;		
		}	
		
		
		
		
		
		
		
		
		
		void ShowBill(){
			cout << "Customer name : " << " pong" << setw(20) << std::right << "Tel : " << "0123456789" << endl;
			cout << "Date : " << "21/10/2020" << setw(20) << std::right << "Time : " << "20.20" << endl;
			cout << setw(20) << std::right << "Item" << setw(5) << std::right << "|" << setw(10) << std::right << "Cost" << endl;
			cout << " " << endl;
			cout << " _______________________________________________" << endl;
			cout << setw(20) << std::right << "Total" << setw(5) << std::right << "|" << setw(20) << std::right << "Bath" << endl;
		}
		
		void ShowCheckPayment(){
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
};

int main(){
	Show s;
	s.TOP();
	//s.MenuBooking();
	s.Employee();
	//s.ShowCheckRate();
	//s.ShowBill();
	//s.ShowCheckRate();
}
