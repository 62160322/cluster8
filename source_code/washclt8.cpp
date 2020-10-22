#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Bookingqueue{
	
	private :
	
		int * arr_queue;
		int max;
		int count;
		int font; //First
		int rear; //last
		//Newcustomer obj_newcus;
		//Repeatcustomer obj_repeatcus;
	
	public :
	
		QueueArray( int size )
		{
			arr_queue = new int[ size ];
			max = size;
			count = 0;
			font = 0;
			rear = 0;
		}	
	
		enqueue( string value )
		{
			if(rear==0){
				//arr_queue[rear] = value;
				rear++;
				count++;
			}else{
			/*	if(isFull( )==1){
					arr_queue[rear] = value;
					rear++;
					count++;
				}else{
					cout << "Queue Value Full = "<< value;
					cout << "	Size is "<< max<<endl;
				}	*/
			}
		}
		
		
		int dequeue( ){
				arr_queue[font] = 0;			
				font++;	
				count--;
		
		}
};

class checkRate{
	
	private:
	
		int weightWash;
		int weightDry;
		int rateWash;
		int rateDry;
		int price1;
		int price2;
		int total;
	
	public:
	
		checkRate(){	
		//Washing
		weightWash = 0;
		rateWash = 15;	
		//Drying
		weightDry = 0;
		rateDry = 15;
		}//Constructor
		
		checkRate(int w1,int w2,int r1,int r2){
			//Washing
			weightWash = w1;
			rateWash = r1;	
			//Drying
			weightDry = w2;
			rateDry = r2;
		}//Constructor
	
		void showRate(){
			//Rate-Washing
	 		cout << "===================Washing===================" << endl;
	 		cout << "=                    1 KG.                  =" << endl;
	 		cout << "=                   15 Bath                 =" << endl;
	 		cout << "=============================================" << endl;
	 		//Rate-Drying
	 		cout << "===================Drying====================" << endl;
	 		cout << "=                    1 KG.                  =" << endl;
	 		cout << "=                   15 Bath                 =" << endl;
	 		cout << "=============================================" << endl;
		}//Function-checkRate
		
		void setRate(int w1,int w2){
			//Washing
			weightWash = w1;
			//Drying
			weightDry = w2;
		}//Function-setRate
		
		int getWash(){
			return weightWash;
		}//Function-getWash
		
		int getDry(){
			return weightDry;
		}//Function-getDry
	
		int calculateRate(){
			price1 = weightWash*rateWash;
			price2 = weightDry*rateDry;
			total = price1 + price2;
		return total;
		}//Fuction-calculateRate
		
		void printCost(){
			cout << "The Cost: " << total << endl;
		}//Function-printCost


};

class employee
{
	private:
		string nameEmployee;
		string telEmployee;
		
	public:
		employee()
				{
			nameEmployee = " ";
			telEmployee = " ";
		}
		
		void getdataemployee(string username,string tel)
		{

		}
		
		bool login(string username, string tel)
		{
			string line;
			string checkname,checktel;
			ifstream myFile("namestaff.txt", ios::in);
			if(myFile.is_open())
			{
				while(getline(myFile, line))
				{
					
					
					checkname=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					checktel=line.substr(0,line.find(','));
					
					if(checkname==username&&checktel==tel)
					{
						  	return true;
						  	break;
					}
					else 
					{
						
					}
					
					
				}
				return false;
			}
		}
		

};



class Newcustomer
{
	private:
		string Namecustomer;
		string telcustomer;
	
	public:
		Newcustomer()
		{
			Namecustomer = "";
			telcustomer = "";
		}
		void getdatacustomer(string name,string tel)
		{
			
		}
		
};

int main(int argc, char** argv)
{
	employee getEmployee;
	int c,numchoice;
	string conf,name,tel;
	checkRate myCheck1;
	
	
	int weightWash;
	int weightDry;
	int price;
	
	menu:
	FILE *file;
	file = fopen("menu logo.txt", "r");
	if (file)
	{
		while ((c = getc(file)) != EOF)
		putchar(c);
	   	fclose(file);
	}
	cout<<"Input number : ";
	cin>>numchoice;
	system ("CLS");
		if(numchoice==1)
		{
			
		FILE *file;
		file = fopen("logologin.txt", "r");
			if (file)
			{
	 			while ((c = getc(file)) != EOF)
				putchar(c);
	   			fclose(file);
    		}
    		cout<<endl<<endl;
    		sure:
    		cout<<"Are you sure ? (Y/N) : ";
    		cin>>conf;
    		
    		if(conf=="Y"||conf=="y"||conf=="Yes"||conf=="yes"||conf=="YES")
    		{
    			login:
    			cout<<"Input your username : ";
    			cin>>name;
    			cout<<"Input your Tel : ";
    			cin>>tel;
    			if(getEmployee.login(name,tel)==true)
    			{
    				cout<<"login complete!!!"<<endl;
    			}
    			else if(getEmployee.login(name,tel)==false)
    			{
    				system ("CLS");
    				cout<<"login again"<<endl;
    				goto login;
				}
			}
			else if(conf=="N"||conf=="n"||conf=="No"||conf=="NO"||conf=="no")
			{
				system ("CLS");
				goto menu;
			}
			else
			{
				system ("CLS");
				goto sure;
			}
		}
		else if(numchoice==2)
		{
		
		}
		else if(numchoice==3)
		{
			myCheck1.showRate();
			cout << "==========Check Rate==========" << endl;
			cout << "Weight Washing: " ;
			cin >> weightWash;
			cout << endl;
			myCheck1.getWash();
			
			cout << "Weight Drying: " ;
			cin >> weightDry;
			cout << endl;
			myCheck1.getDry();
			
			myCheck1.setRate(weightWash,weightDry);
			
			myCheck1.calculateRate();
			myCheck1.printCost();
			cout << endl;
			cout << "==============================" << endl;
			cout<<"Are you sure ? (Y/N) : ";
    		cin>>conf;
    		system ("cls");
    		
			if(conf=="Y"||conf=="y"||conf=="Yes"||conf=="yes"||conf=="YES")
    		{
    			goto menu;
			}
			else
			{
			/*	FILE *file;
				file = fopen("pen.txt", "r");
				if (file)
				{
	 			while ((c = getc(file)) != EOF)
				putchar(c);
	   			fclose(file);*/
    		
			}
			
		}
		else if(numchoice==4)
		{
			return 0;
		}
	
	return 0;
}
