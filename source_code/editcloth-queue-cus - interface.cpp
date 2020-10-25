#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<sstream>
#include<ctime>

using namespace std;

class node{		
				public:
				
				string name,tel,date,weight,option,que,status;
				int data;
				node *link;
				node(){
					this->data = 0;
				}
			};
class nodequeue{
				
		public:
				
		string nameq,telq,dateq,weightq,optionq,queq,statusq;
		int dataq;
		nodequeue *linkq;
		nodequeue(){
			this->dataq = 0;
		}
};			
class customer{
	public:
		
		int count;	
		node *head;
		node *tail;
		node *temp;
		
		int countq;	
		nodequeue *headq;
		nodequeue *tailq;
		nodequeue *tempq;
		
		customer(void){		
			this->head = NULL;
			this->tail = NULL;
			this->count = 1;
			this->headq = NULL;
			this->tailq = NULL;
			this->countq = 1;
			
		}
		
		~customer(){
			
			for(int i = 1; i < this->count; i++){
				node * temp = this->head;
				this->head = this->head->link;
				delete temp;
				temp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
		}
		
		void add(string name,string tel,string date,string weight,string option,string que,string status){	
			node *temp = new node;
			temp->name = name;
			temp->tel = tel;
			temp->date = date;
			temp->weight = weight;
			temp->option = option;
			temp->que = que;
			temp->status = status;
			temp->link = NULL;			
		if(this->count == 1){			
				this->head = temp;
				this->tail = temp;		
			}else{			
				this->tail->link = temp;
				this->tail = this->tail->link;			
			}
			
		count++;
		
		}
		
		void addqueue(string name,string tel,string date,string weight,string option,string que,string status){	
			nodequeue *tempq = new nodequeue;
			tempq->nameq = name;
			tempq->telq = tel;
			tempq->dateq = date;
			tempq->weightq = weight;
			tempq->optionq = option;
			tempq->queq = que;
			tempq->statusq = status;
			tempq->linkq = NULL;			
		if(this->countq == 1){			
				this->headq = tempq;
				this->tailq = tempq;		
			}else{			
				this->tailq->linkq = tempq;
				this->tailq = this->tailq->linkq;			
			}
			
		countq++;
		
		}
		
		void set(string date,string weight,string option, int index,string name, string tel)
		{
			if (index < count)
			{
				node *ptemp = new node(); 
				int i;
				for (i = 1, ptemp = this->head; i <= index && ptemp != NULL; i++, ptemp = ptemp->link)
				{
					if (i == index)
					{
						ptemp->date = date;
						ptemp->weight = weight;
						ptemp->option = option;
					}
				}
			}
			else
			{
				cout << "no index" << endl;
			}
		}
		
		void remove(string value){
			nodequeue *ptemp = new nodequeue(); 
			nodequeue *temp = new nodequeue();
			if (this->headq->telq == value)
			{
				ptemp = this->headq;
				this->headq = this->headq->linkq;
				delete ptemp;
				this->countq--;
			}
			else
			{
				temp = this->headq;
				for (ptemp = this->headq->linkq; ptemp != NULL; ptemp = ptemp->linkq)
				{
					if (ptemp->telq == value)
					{
						break;
					}
					else
					{
						temp = ptemp;
					}
				}
				if (ptemp != NULL)
				{
					temp->linkq = ptemp->linkq;
					delete ptemp;
					this->countq--;
				}
			}
		}
		
		bool loaddata(){
			string name,tel,date,weight,option,que,status,line;
			ifstream myfile;
			myfile.open("customer.dat");
			
			while(getline(myfile,line)){
				
					name=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					tel=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					date=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					weight=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					option=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					que=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					status=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
				add(name,tel,date,weight,option,que,status);			
				
					
			}//while
		
		}//myfile
		
		void show(){
			node *temp = new node();
			temp = head;
			cout << "show cus\n";
			while(temp!=NULL){
				cout << temp->name <<temp->tel<< endl;
				
				temp=temp->link;
			}
			cout<<endl;
		}
		
		void showqueue(){
			nodequeue *tempq = new nodequeue();
			tempq = headq;
			int i = 0;
			cout << "show cus queue\n";
			while(tempq!=NULL){
				cout<< "Queue	"<<i+1
					<< "\nName	:	"<<tempq->nameq 
					<< "\nTel	:	"<<tempq->telq
					<< "\nStatus :	"<<tempq->statusq;
					if(tempq->optionq=="ww"||tempq->optionq=="WW"){
				cout<< "\nOption	:	Washing"<<endl<<endl;
					}else if(tempq->optionq=="wd"||tempq->optionq=="WD"){
				cout<< "\nOption	:	Washing And Drying"<<endl<<endl;		
					}else if(tempq->optionq=="dd"||tempq->optionq=="DD"){
				cout<< "\nOption	:	Drying"<<endl<<endl;
					}
					
			
				tempq=tempq->linkq;
				i++;
			}
			cout<<endl;
		}
		
		void writefileadd(string name,string tel,string weight,string option,string que,string status){
			
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
			
			ofstream myfile("customer.dat",ios::app);
			if(myfile.is_open()){
			
		
				myfile <<  name <<","<< tel <<","<< timee <<","<< weight <<","<< option <<","<< que << ","<< status <<endl;
		
		
			}//if
	
		}
		
		void writefileset(){
			ofstream myfile("customer.dat",ios::trunc);
			if(myfile.is_open()){
			
			node *temp;	
			temp = head;
			
			
			while(temp!=NULL){
				myfile <<  temp->name <<","<< temp->tel <<","<< temp->date <<","<< temp->weight <<","<< temp->option <<","<< temp->que << ","<< temp->status <<endl;
				temp = temp->link;	
				
			}
	
			myfile.close();
		
			}//if
	
		}
		
		void beforeadd(string name,string tel,string weight,string option,string q){	
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
			
			add(name,tel,timee,weight,option,"-","-");
			addqueue(name,tel,timee,weight,option,"-","waiting");
			
		}	
	
		void beforeset(string name,string tel,string weight,string option,string q){
		
			string Name,Tel,Add,Code,Year,Month,Day,Timeh,Timem,Times,Time,Tim,timee;
			stringstream ss;
		
			time_t now = time(0);
		 	tm *ltm = localtime(&now);
	
			ss << 1900 + ltm->tm_year;
	 		ss >> Year;
	   		ss.clear();
	   		ss << 1 + ltm->tm_mon;
	   		ss >> Month;
	   		
	   		if(Month=="1"||Month=="2"||Month=="3"||Month=="4"||Month=="5"||Month=="6"||Month=="7"||Month=="8"||Month=="9"){	
	   			Month = "0"+Month;
			}
	 		ss.clear();
	  		ss << ltm->tm_mday;
	   		ss >> Day;
	   		if(Day=="1"||Day=="2"||Day=="3"||Day=="4"||Day=="5"||Day=="6"||Day=="7"||Day=="8"||Day=="9"){	
	   			Day = "0"+Day;
			}
	   		ss.clear();
	   		ss << ltm->tm_hour;
	   		ss >> Timeh;
	   		if(Timeh=="1"||Timeh=="2"||Timeh=="3"||Timeh=="4"||Timeh=="5"||Timeh=="6"||Timeh=="7"||Timeh=="8"||Timeh=="9"){	
	   			Timeh = "0"+Timeh;
			}
	   		ss.clear();
	   		ss << 1+ltm->tm_min;
	   		ss >> Timem;
	   		if(Timem=="1"||Timem=="2"||Timem=="3"||Timem=="4"||Timem=="5"||Timem=="6"||Timem=="7"||Timem=="8"||Timem=="9"){	
	   			Timem = "0"+Timem;
			}
	   		ss.clear();
			ss << 1+ltm->tm_sec;
	   		ss >> Times;
	   		if(Times=="1"||Times=="2"||Times=="3"||Times=="4"||Times=="5"||Times=="6"||Times=="7"||Times=="8"||Times=="9"){	
	   			Times = "0"+Times;
			}
	   		ss.clear();
			
			Time = Timeh+":"+Timem+":"+Times;	
			Tim = Day+"-"+Month+"-"+Year;
			timee = Day+"-"+Month+"-"+Year+" "+Time;
			
			addqueue(name,tel,timee,weight,option,"-","waiting");
			
			string namet,telt,datet,weightt,optiont,quet,line;
			ifstream myfile;
			myfile.open("customer.dat");
			
			while(getline(myfile,line)){
				
					namet=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					telt=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					datet=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					weightt=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					optiont=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					quet=line.substr(0,line.find(','));
				
				node *temp = new node();
				temp = head;
				int count=1;
				while(temp!=NULL){
				
					if(temp->tel==tel){				
						set(timee,weight,option,count,name,tel);
							break;
					}
					temp=temp->link;
				count++;
				}					
			}//while
		}
		
		bool checkregistr(string username, string tel)
		{
			string line;
			string checkname,checktel;
			fstream myFile;
			myFile.open("customer.dat", std::ios::in | std::ios::out | std::ios::app);
				while(getline(myFile, line))
				{
					
					
					checkname=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					checktel=line.substr(0,line.find(','));
					
					if(checktel==tel)
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
		
		bool login(string username, string tel)
		{
			string line;
			string checkname,checktel;
			ifstream myFile;
			myFile.open("customer.dat", std::ios::in | std::ios::out | std::ios::app);
		
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
};
class Bookingqueue{
	//protected:
	public:	
	string *arr_queue;
		string turntel;
		string reserve;
		int max;
		int font;
		int rear;
			
		string *arr_queuereserve;
		int maxreserve;
		int fontreserve;
		int rearreserve;
		int countreserve;
		
		
		int count;
		Bookingqueue(){
			arr_queue = new string[5];
			max = 5;
			font = 0;	
			rear = 0;	
			count = 0;	
			
			arr_queuereserve = new string[100];
			maxreserve = 50;
			fontreserve = 0;	
			rearreserve = 0;	
			countreserve = 0;
			
		}
		
		Bookingqueue(int size){
			arr_queue = new string[size];
			max = size;
			font = 0;	
			rear = 0;	
			count = 0;	
			
			arr_queuereserve = new string[100];
			maxreserve = 50;
			fontreserve = 0;	
			rearreserve = 0;	
			countreserve = 0;
			
		}

		~Bookingqueue(){
			delete []arr_queue;
			delete []arr_queuereserve;
		}

		void enqueue(string tel){
			if(isFull()==1){	
				enqueuereserve(tel);
			}else{
				arr_queue[rear]=tel;
				rear++;
				count++;
			}//if-else
		}
			
		string dequeue(){
			if(isEmpty()==1){
				cout<<"Empty"<<endl;
			}else{
				string dereserve, a;
				turntel = arr_queue[0];
				reserve = turntel;
				for(int i=0;i<rear-1;i++){
					arr_queue[i]=arr_queue[i+1];
				}//for-loop		
				if(countreserve>0){					
					dereserve = dequeuereserve();
					for(int i=count-1;i<max;i++){										
						arr_queue[i]= " ";
						arr_queue[count-1] = dereserve;
					}
					turntel = reserve;
				}else{
					for(int i=count-1;i<max;i++){									
						arr_queue[i]= " ";
					}
					turntel = reserve;
					rear--;
					count--;				
				}
			}//if-else			
			return turntel;
		}
		
		void enqueuereserve(string tel){
			if(isFullreserve()==1){			
				cout<<"Reserve Full!"<<endl;
			}else{
				arr_queuereserve[rearreserve]=tel;
				rearreserve++;
				countreserve++;
			}//if-else
		}
			
		string dequeuereserve(){
			if(isEmptyreserve()==1){
				cout<<"Reserve Empty"<<endl;
			}else{						
				turntel = arr_queuereserve[0];
				for(int i=0;i<rearreserve-1;i++){
					arr_queuereserve[i]=arr_queuereserve[i+1];
				}//for-loop		
				
				for(int i=countreserve-1;i<maxreserve;i++){	
					arr_queuereserve[i]= " ";
				}
			}//if-else
			rearreserve--;
			countreserve--;
			return turntel;
		}
		
		bool isEmpty(){
			if(count==0){
				return true;
			}else{
				return false;
			}//if-else		
		}
			
		bool isFull(){
			if(count==max){
				return true;
			}else{
				return false;
			}//if-else
		}
		
		bool isEmptyreserve(){
			if(countreserve==0){
				return true;
			}else{
				return false;
			}//if-else
			
		}

		bool isFullreserve(){
			if(rearreserve==maxreserve){
				return true;
			}else{
				return false;
			}//if-else
		}

		void show(){
			for(int i=0;i<max;i++){
				cout<<"Queue = "<<arr_queue[i];
				cout<<endl;
			}//for-loop
		}
	
		void showreserve(){
			for(int i=0;i<countreserve;i++){
				cout<<"Queue reserve = "<<arr_queuereserve[i];
				cout<<endl;
			}//for-loop
		}		
		
			
};
class Clothesbasket{
	protected:
		string namein;
		string telin;
		string status;
	public:
		Bookingqueue *obj_edit_book;
		customer *obj_edit_cus;

		
		Clothesbasket(){
			
		}
		
		Clothesbasket(Bookingqueue *booking, customer *cus){
			obj_edit_book = booking;
			obj_edit_cus = cus;
			namein = " ";
			telin = " ";
		}
		void showq(){
			obj_edit_book->show();
		}
		
		void showlink(){
			for(int i=0;i<obj_edit_book->max;i++){
				cout << obj_edit_book->arr_queue[i]<<endl;
			}
			obj_edit_book->showreserve();	
		}
		
		void showdataqueue(){
			nodequeue *tmp = new nodequeue();
			tmp = obj_edit_cus->headq;
			int i=0;
			while(tmp!=NULL){
				if(i<5){
					cout<< "Name	:	"<<tmp->nameq
					<< "\nTel		:	"<<tmp->telq
					<< "\nQueue	:	"<<i<<endl;
					i++;
					tmp=tmp->linkq;
				}else{
					cout<< "Name	:	"<<tmp->nameq
					<< "\nTel		:	"<<tmp->telq
					<< "\nQueue	:	"<<i<<endl;
					i++;
					tmp=tmp->linkq;
				}
				
			}
		}
		
		string getstatus(){
			return status;
		}
		
		int correctcloth(string name, string tel,string statusin){
			int imain=0, ireserve = 0;
			
			nodequeue *tmp = new nodequeue();
			tmp = obj_edit_cus->headq;
			
			while(tmp!=NULL){	
				if(tel==tmp->telq){
					status = statusin;
					tmp->statusq = statusin;
					tmp=tmp->linkq;	
					imain++;
					return imain;
				}//if check
				else if(tel==tmp->telq){
					status = statusin;
					tmp->statusq = statusin;
					tmp=tmp->linkq;	
					imain++;
					return imain;
				}//if check
				else{
					tmp=tmp->linkq;	
				}//else			
			
			}//while loop correct
			
		}
		
		bool CheckStatusClothesBasket(string name, string tel){
			int imain=0, ireserve = 0;
			
			nodequeue *tmp = new nodequeue();
			tmp = obj_edit_cus->headq;
			
			while(tmp != NULL){
				
					if(name==tmp->nameq&&tel==tmp->telq){
				//	status = statusin;
				//	tmp->statusq = statusin;
				//	tmp=tmp->linkq;	
					imain++;
					return imain;	
		
				}
				else{
					tmp=tmp->linkq;	
				}//else
			
			}
	
		}
		
		int Showcheck(string name, string tel){
			nodequeue *tmp = new nodequeue();
			tmp = obj_edit_cus->headq;
			
			int q=CheckStatusClothesBasket(name, tel);
			
			int i=1;
			int j=0;
			while(tmp!=NULL){
				if(tmp->telq==tel&&tmp->nameq==name){
					cout<<"Username : "<<tmp->nameq<<endl;
					cout<<"Phone Number : "<<tmp->telq<<endl;
					cout<<"Queue : "<< i <<endl;
					cout<<"Booking time : "<<tmp->dateq<<endl;
					cout<<"Status : "<<tmp->statusq<<endl;
					j=1;
				}
				i++;
				tmp=tmp->linkq;
			}
			if(j==0){
						cout << "\nYou have not yet booked a queue." <<endl;
							
			}
			return j;
		}
		
		
};
class dryingmachine {
	
	public:
	string status[5];
	string q[5];
	int number;
	string Arraymac;
	Bookingqueue *obj_dry_book;
	customer *obj_dry_cus;	
	//washingmachine *obj_dry_wash;
	dryingmachine(){
	
	number = 0;
	
	}
	
	dryingmachine(Bookingqueue *book,customer *cus){
		obj_dry_book = book;
		obj_dry_cus = cus;
	//	obj_dry_wash = wash;
	}
	
	void setemptydry(){
		
		ofstream offile;
		offile.open("macdry.txt", std::ios::out | std::ios::trunc);
				
			offile << "Empty,Empty,Empty,Empty,Empty" ;
					
		offile.close();				
	}
	
	void setemptydryqueue(){
		
		ofstream offile;
		offile.open("macdryqueue.txt", std::ios::out | std::ios::trunc);
				
			offile << " , , , , " ;
			
		offile.close();
									
	}

	void correctstatusdry(){
		int h=1;
		int i,num;
		string statu;
		string set[5];
		
				string filein,m1,m2,m3,m4,m5;
				string filename,line;
				string checkname,checktel;
				ifstream infile;
				infile.open("macdry.txt", ios::in);
				
				while(getline(infile, filein)){
				
						m1=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m2=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
	
						m3=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
			
						m4=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m5=filein.substr(0,filein.find(','));
							
				}
				infile.close();
	
			status[0]= m1;
			status[1]= m2;
			status[2]= m3;
			status[3]= m4;
			status[4]= m5;
			
			string fileinq,q1,q2,q3,q4,q5;
				string filenameq,lineq;
				ifstream infileq;
				infileq.open("macdryqueue.txt", ios::in);
				
				while(getline(infileq, fileinq)){
				
						q1=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q2=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
	
						q3=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
			
						q4=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q5=fileinq.substr(0,fileinq.find(','));
							
				}
				infile.close();	
			q[0]= q1;
			q[1]= q2;
			q[2]= q3;
			q[3]= q4;
			q[4]= q5;
							
			
		menu:
		showdryingmachine();
		do{
		cout<<"Enter number Clothes dryer (1-5) : "<<endl;	
		cin>>num;
		}while(num<1||num>5);
		int ch;
		string tel;
		chstu:
		cout<<"Enter Tel	:	";
		cin>>tel;
		nodequeue *tmp = new nodequeue();
			tmp = obj_dry_cus->headq;
				while(tmp != NULL){
					if(tel==tmp->telq){	
						goto kip;
					}  
					else{
						tmp=tmp->linkq;	
					}//else
				
				}
				
				cout <<"No Account Data! Pls Login Again." << endl;
				goto chstu; 
				
		kip:	
		
		cout<<"Enter status Clothes dryer : "
			<<"\n1. Empty"
			<<"\n2. Full"
			<<"\n3. Broken\n";
		cin>>ch;	
		//cin>>statu;
		
		if(ch==1){
			statu = "Empty";
			status[num-1]=statu;
			q[num-1]=" ";
			obj_dry_book->dequeue();
			obj_dry_cus->remove(tel);
		}else if(ch==2){
			statu = "Full";
			status[num-1]=statu;
			q[num-1]=tel;
		}else if(ch==3){
			statu = "Broken";
			status[num-1]=statu;
			q[num-1]=" ";
		}else{
			goto chstu;
		}
		
	//	status[num-1]=statu;	
	
		
		cout << "================================= DryingMachine ==========================================" << endl; 	
		cout<<"------------		------------		------------   		------------		------------	"<<endl;
		cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
		cout<<"------------		------------		------------		------------		------------	"<<endl;
		cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
		cout<<"|"<<" "<<setw(6)<<status[0]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[1]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[2]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[3]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[4]<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
		cout<<"------------		------------		------------    	------------		------------	"<<endl;
		cout<<"|"<<" "<<setw(6)<<q[0]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[1]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[2]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[3]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[4]<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|----------|		|----------|		|----------|    	|----------|		|----------|	"<<endl;

		char jojo;
		cout << "input agian/finish(y/n) : ";
		cin >> jojo;
		if(jojo=='y'){
				ofstream offile;
				offile.open("macdry.txt", std::ios::out | std::ios::trunc);
				
					offile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] <<endl;
			
				offile.close();
				
				ofstream offileq;
				offileq.open("macdryqueue.txt", std::ios::out | std::ios::trunc);
				
					offileq << q[0] << ","<< q[1] << ","<< q[2] << ","<< q[3] << ","<< q[4] <<endl;
			
				offileq.close();
				goto menu;
			
		}
				ofstream offile;
				offile.open("macdry.txt", std::ios::out | std::ios::trunc);
				
					offile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] <<endl;
				offile.close();
				
				ofstream offileq;
				offileq.open("macdryqueue.txt", std::ios::out | std::ios::trunc);
				
					offileq << q[0] << ","<< q[1] << ","<< q[2] << ","<< q[3] << ","<< q[4] <<endl;
				
				offileq.close();
				cout << "SUCSESS!" <<endl;
		
	}
	
	
	void showdryingmachine(){
		
				string filein,m1,m2,m3,m4,m5;
				string filename,line;
				string checkname,checktel;
				ifstream infile;
				infile.open("macdry.txt", ios::in);
				
				while(getline(infile, filein)){
				
						m1=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m2=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
	
						m3=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
			
						m4=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m5=filein.substr(0,filein.find(','));
							
				}
				
				infile.close();
				
				string fileinq,q1,q2,q3,q4,q5;
				string filenameq,lineq;
				ifstream infileq;
				infileq.open("macdryqueue.txt", ios::in);
				
				while(getline(infileq, fileinq)){
				
						q1=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q2=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
	
						q3=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
			
						q4=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q5=fileinq.substr(0,fileinq.find(','));
							
				}
				infile.close();	
		
		cout << "================================= DryingMachine ==========================================" << endl; 	
		cout<<"------------		------------		------------   		------------		------------	"<<endl;
		cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
		cout<<"------------		------------		------------		------------		------------	"<<endl;
		cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
		cout<<"|"<<" "<<setw(6)<<m1<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m2<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m3<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m4<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m5<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
		cout<<"------------		------------		------------    	------------		------------	"<<endl;
		cout<<"|"<<" "<<setw(6)<<q1<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q2<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q3<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q4<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q5<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|----------|		|----------|		|----------|    	|----------|		|----------|	"<<endl;

	}
}; //drying	
class washingmachine {
	
	public:
	string status[5];
	string q[5];
	int number;
	string statu;
	string Arraymac;
	Bookingqueue *obj_wash_book ;
	customer *obj_wash_cus;	
	dryingmachine *obj_wash_dry;	
	washingmachine(){
	
		number=0;
	
	}

	washingmachine(Bookingqueue *book, customer *cus, dryingmachine *dry){
		obj_wash_book = book;
		obj_wash_cus = cus;
		obj_wash_dry = dry;
	}

	void setemptywash(){
		
		ofstream offile;
		offile.open("macwash.txt", std::ios::out | std::ios::trunc);
				
			offile << "Empty,Empty,Empty,Empty,Empty" ;
				
		offile.close();					
	}
	
	void setemptywashqueue(){
		
		ofstream offile;
		offile.open("macwashqueue.txt", std::ios::out | std::ios::trunc);
				
			offile << " , , , , " ;
				
		offile.close();		
									
	}
		
	
	int correctstatuswash(){
		
		int h=1,j=0;
		int i,num;
		string statu;
		string set[5];
		string q[5];
				string filein,m1,m2,m3,m4,m5;
				string filename,line;
				string checkname,checktel;
				ifstream infile;
				infile.open("macwash.txt", ios::in);
				
				while(getline(infile, filein)){
				
						m1=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m2=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
	
						m3=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
			
						m4=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m5=filein.substr(0,filein.find(','));
							
				}
				infile.close();
					
		 	
			status[0]= m1;
			status[1]= m2;
			status[2]= m3;
			status[3]= m4;
			status[4]= m5;
			
			
			string fileinq,q1,q2,q3,q4,q5;
				string filenameq,lineq;
				ifstream infileq;
				infileq.open("macwashqueue.txt", ios::in);
				
				while(getline(infileq, fileinq)){
				
						q1=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q2=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
	
						q3=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
			
						q4=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q5=fileinq.substr(0,fileinq.find(','));
							
				}
				infile.close();	
			q[0]= q1;
			q[1]= q2;
			q[2]= q3;
			q[3]= q4;
			q[4]= q5;
		
		menu:
		showwashingmachine();
		
		do{
		cout<<"Enter number Clothes wash (1-5) : "<<endl;	
		cin>>num;
		}while(num<1||num>5);
		int ch;
		string tel;
		string re="This Clothesbasket Can not dry clothes . . . ";
		chstu:
		cout<<"Enter Tel	:	";
		cin>>tel;
		
		nodequeue *tmp = new nodequeue();
			tmp = obj_wash_cus->headq;
			
				while(tmp != NULL){
					if(tel==tmp->telq&&tmp->optionq=="wd"||tmp->optionq=="WD"){	
						goto kip;
					}else if(tel==tmp->telq&&tmp->optionq=="wd"||tmp->optionq=="WD"){
						goto kip;
					}else if(tel==tmp->telq&&tmp->optionq=="dd"||tmp->optionq=="DD"){	
						cout << "This Clothesbasket Can not dry clothes . . . " <<endl;
						j=1;
						return j;
					}else{
						tmp=tmp->linkq;	
					}//else
					
					
					}
					
				cout <<"No Account Data! Pls Login Again." << endl;
				goto chstu; 
				
		kip:	
		
		cout<<"Enter status Clothes wash : "
			<<"\n1. Empty"
			<<"\n2. Full"
			<<"\n3. Broken\n";
		cin>>ch;	
		//cin>>statu;
		
		if(ch==1){
			statu = "Empty";
			status[num-1]=statu;
			q[num-1]=" ";
			
			nodequeue *tmp = new nodequeue();
			tmp = obj_wash_cus->headq;
				while(tmp != NULL){
					if(tel==tmp->telq){	
						if(tmp->optionq=="wd"||tmp->optionq=="WD"){
							obj_wash_dry->correctstatusdry();
							break;
						}else if(tmp->optionq=="ww"||tmp->optionq=="WW"){
							obj_wash_book->dequeue();
							obj_wash_cus->remove(tel);
							break;
						}else{
							
						}
						goto kip;
					}  
					else{
						tmp=tmp->linkq;	
					}//else
				
				}
			
			
		}else if(ch==2){	
			statu = "Full";
			status[num-1]=statu;
			q[num-1]=tel;
		}else if(ch==3){
			statu = "Broken";
			status[num-1]=statu;
			q[num-1]=" ";
		}else{
			goto chstu;
		}
		
	//	status[num-1]=statu;	
	
		
		
		cout << "================================= WashingMachine ==========================================" << endl; 	
		cout<<"------------		------------		------------   		------------		------------	"<<endl;
		cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
		cout<<"------------		------------		------------		------------		------------	"<<endl;
		cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
		cout<<"|"<<" "<<setw(6)<<status[0]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[1]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[2]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[3]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<status[4]<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
		cout<<"------------		------------		------------    	------------		------------	"<<endl;
		cout<<"|"<<" "<<setw(6)<<q[0]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[1]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[2]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[3]<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q[4]<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|----------|		|----------|		|----------|    	|----------|		|----------|	"<<endl;

		char jojo;
		cout << "input agian/finish(y/n) : ";
		cin >> jojo;
		if(jojo=='y'){
				
				ofstream offile;
				offile.open("macwash.txt", std::ios::out | std::ios::trunc);
				
					offile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] <<endl;
			
				offile.close();
				
				
				ofstream offileq;
				offileq.open("macwashqueue.txt", std::ios::out | std::ios::trunc);
				
					offileq << q[0] << ","<< q[1] << ","<< q[2] << ","<< q[3] << ","<< q[4] <<endl;
			
				offileq.close();
				goto menu;
				
		}
				
				ofstream offile;
				offile.open("macwash.txt", std::ios::out | std::ios::trunc);
				offile << status[0] << ","<< status[1] << ","<< status[2] << ","<< status[3] << ","<< status[4] <<endl;			
				offile.close();		
				
				ofstream offileq;
				offileq.open("macwashqueue.txt", std::ios::out | std::ios::trunc);
				
					offileq << q[0] << ","<< q[1] << ","<< q[2] << ","<< q[3] << ","<< q[4]<<endl ;
			
				offileq.close();	
				
				cout << "SUCSESS!" <<endl;;
		
	}
	void showwashingmachine(){
		
				string filein,m1,m2,m3,m4,m5;
				string filename,line;
				string checkname,checktel;
				ifstream infile;
				infile.open("macwash.txt", ios::in);
				
				while(getline(infile, filein)){
				
						m1=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m2=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
	
						m3=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
			
						m4=filein.substr(0,filein.find(','));
							 filein.erase(0,filein.find(',')+1);
						
						m5=filein.substr(0,filein.find(','));
							
				}
				infile.close();
				
				string fileinq,q1,q2,q3,q4,q5;
				string filenameq,lineq;
				ifstream infileq;
				infileq.open("macwashqueue.txt", ios::in);
				
				while(getline(infileq, fileinq)){
				
						q1=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q2=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
	
						q3=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
			
						q4=fileinq.substr(0,fileinq.find(','));
							 fileinq.erase(0,fileinq.find(',')+1);
						
						q5=fileinq.substr(0,fileinq.find(','));
							
				}
				infile.close();	
		
		
				
		cout << "================================= WashingMachine ==========================================" << endl; 	
		cout<<"------------		------------		------------   		------------		------------	"<<endl;
		cout<<"|    1     |		|    2 	   |		|    3     |   		|    4     |		|    5	   |	"<<endl;
		cout<<"------------		------------		------------		------------		------------	"<<endl;
		cout<<"|          |		|     	   |		|          |     	|          |		|    	   |	"<<endl;
		cout<<"|"<<" "<<setw(6)<<m1<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m2<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m3<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m4<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<m5<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|          |		|     	   |		|          |    	|          |		|    	   |	"<<endl;
		cout<<"------------		------------		------------    	------------		------------	"<<endl;
		cout<<"|"<<" "<<setw(6)<<q1<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q2<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q3<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q4<<setw(4)<<"|"<<setw(5)<<"		"<<"|"<<" "<<setw(6)<<q5<<setw(4)<<"|"<<setw(5)<<endl;
		cout<<"|----------|		|----------|		|----------|    	|----------|		|----------|	"<<endl;

	}
		
};// washing 
class Bill{
	private:
		int weight;
		int money;
		int cost;
		int received;
		string namel,tell,weightl,typel,datel;
		Bookingqueue *obj_pay_book ;
		customer *obj_pay_cus;	
		
		
	public:
		Bill(){
			weight = 0;
			cost = 0;
			received = 0;	
			typel = " ";
		}
		 
		Bill(Bookingqueue *book, customer *cus){
			obj_pay_book = book;
			obj_pay_cus = cus;
		
		}
		 
    	int getDataBill(string type2,int weight2,int money2){
    				money = money2;
    				weight = weight2;
    				typel = type2;
		}

		bool loaddata(string namein,string telin){
			string name,tel,date,weight,option,que,status,line;
			ifstream myfile;
			myfile.open("customer.dat");
			
			while(getline(myfile,line)){
				
					name=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					tel=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					date=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					weight=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					option=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					que=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
					status=line.substr(0,line.find(','));
						line.erase(0, line.find(',')+1);
				if(namein==name&&telin==tel){
					namel=name;
					tell=tel;
					datel=date;
					weightl = weight;
    				typel = option;
				}
					
			}//while
		
		}//myfile

    	int getAmountcost(){
    		
    		stringstream ss;
    		
    		ss << weightl ;
    		ss >> weight ;
    		ss.clear();
    		
    		if(typel=="ww"){
    			cost=weight*15;
    			
			}else if(typel=="dd"){
				cost=weight*20;
				
			}else{
				cost=(weight*15)+(weight*20);
				
			}
			return cost;
		}
		
		int getAmountReceived(int moneyin,int cost){
    	
				received=moneyin-cost;
			
			return received;
		}
		
		int getAmountMoney(int moneyin){
			
    			money=moneyin;
			
			return money;
		}
		
		void showreceived(){
			cout << "Weight : "<< weightl << endl;
			cout << "Cost : "<< getAmountcost() << " Bath"<< endl;
			
		}
		
    	void printBill(){
    		string time,date;
    		date=datel.substr(0,datel.find(" "));
    		time=datel.erase(0,datel.find(" ")+1);
    		
    		stringstream ss;
    		
    		ss << weightl ;
    		ss >> weight ;
    		ss.clear();
    		
    		
    		if(typel=="ww"||typel=="WW"){
		    		cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                         CLUSTER 8 WASHING                                         |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Customer name : " << setw(20) << std::left << namel << setw(20) << std::right << "Tel : " <<  setw(10) << std::left << tell << setw(20)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Date  : " << setw(21) << std::left << date << setw(20) << std::right << "Time : " <<  setw(10) << std::left << time << setw(19)<< std::right << "|"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Item " << setw(20) << std::right << "|" << setw(25) << std::right << "Cost" << setw(25)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(28) << std::right << "Washing" << setw(10) << std::right << weightl+" KG" << setw(12) << std::right << "|" <<  setw(25) << std::right << weight*15 << setw(25)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Total " << setw(2) << std::right << "|" << setw(25) << std::right << getAmountcost() << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Cash " << setw(2) << std::right << "|" << setw(25) << std::right << money << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Change " << setw(2) << std::right << "|" << setw(25) << std::right << received << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                     At your disposal ,THANK YOU                                   |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;		
						
				}else if(typel=="wd"||typel=="WD"){		
					cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                         CLUSTER 8 WASHING                                         |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Customer name : " << setw(20) << std::left << namel << setw(20) << std::right << "Tel : " <<  setw(10) << std::left << tell << setw(20)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Date  : " << setw(21) << std::left << date << setw(20) << std::right << "Time : " <<  setw(10) << std::left << time << setw(19)<< std::right << "|"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Item " << setw(20) << std::right << "|" << setw(25) << std::right << "Cost" << setw(25)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(28) << std::right << "Washing" << setw(10) << std::right << weightl+" KG" << setw(12) << std::right << "|" <<  setw(25) << std::right << weight*15 << setw(25)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;	
					cout << setw(57) << std::right << "|" << setw(28) << std::right << "Drying" << setw(10) << std::right << weightl+" KG" << setw(12) << std::right << "|" <<  setw(25) << std::right << weight*20 << setw(25)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Total " << setw(2) << std::right << "|" << setw(25) << std::right << getAmountcost() << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Cash " << setw(2) << std::right << "|" << setw(25) << std::right << money << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Change " << setw(2) << std::right << "|" << setw(25) << std::right << received << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                     At your disposal ,THANK YOU                                   |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;		
						
				}else if(typel=="dd"||typel=="DD"){
					cout << " " << endl<< endl<< endl;
					cout << " 							 ___________________________________________________________________________________________________"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                         CLUSTER 8 WASHING                                         |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Customer name : " << setw(20) << std::left << namel << setw(20) << std::right << "Tel : " <<  setw(10) << std::left << tell << setw(20)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Date  : " << setw(21) << std::left << date << setw(20) << std::right << "Time : " <<  setw(10) << std::left << time << setw(19)<< std::right << "|"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(30) << std::right << "Item " << setw(20) << std::right << "|" << setw(25) << std::right << "Cost" << setw(25)<< std::right << "|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(28) << std::right << "Drying" << setw(10) << std::right << weightl+" KG" << setw(12) << std::right << "|" <<  setw(25) << std::right << weight*20 << setw(25)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Total " << setw(2) << std::right << "|" << setw(25) << std::right << getAmountcost() << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Cash " << setw(2) << std::right << "|" << setw(25) << std::right << money << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|                                                                                                   |"<< endl;
					cout << setw(57) << std::right << "|" << setw(48) << std::right << "Change " << setw(2) << std::right << "|" << setw(25) << std::right << received << setw(5) << std::right << " Bath" << setw(20)<< std::right << "|"<< endl;	
					cout << "							|___________________________________________________________________________________________________|"<< endl;
					cout << "							|                                                                                                   |"<< endl;
					cout << "							|                                     At your disposal ,THANK YOU                                   |"<< endl;
					cout << "							|___________________________________________________________________________________________________|"<< endl;		
						
			}
    	}
};
class employee{
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
class CheckRate{
	private:
		int weightWash;
		int weightDry;
		int rateWash;
		int rateDry;
		int price1;
		int price2;
		int total;
	public:
		CheckRate(){	
		//Washing
		weightWash = 0;
		rateWash = 15;	
		//Drying
		weightDry = 0;
		rateDry = 20;
		}//Constructor
		
/*		CheckRate(int w1,int w2,int r1,int r2){
			//Washing
			weightWash = w1;
			rateWash = r1;	
			//Drying
			weightDry = w2;
			rateDry = r2;
		}//Constructor
*/	
		void showRate(){
			//Rate-Washing
	 		cout << "===================Washing===================" << endl;
	 		cout << "=                    1 KG.                  =" << endl;
	 		cout << "=                   15 Bath                 =" << endl;
	 		cout << "=============================================" << endl;
	 		//Rate-Drying
	 		cout << "===================Drying====================" << endl;
	 		cout << "=                    1 KG.                  =" << endl;
	 		cout << "=                   20 Bath                 =" << endl;
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
/*		
		void printCost(){
			cout << "The Cost: " << total << endl;
		}//Function-printCost

*/
};
int main(){
	customer *tam = new customer();
	Bookingqueue *obj_queue = new Bookingqueue(5);
	//nodequeue *temp = new nodqueue();
	Clothesbasket *editcloth = new Clothesbasket(obj_queue,tam);
	Bill *pay = new Bill(obj_queue,tam);
	dryingmachine *dry = new dryingmachine(obj_queue,tam);
	washingmachine *wash = new washingmachine(obj_queue,tam,dry);
	CheckRate *rate = new CheckRate();
	employee *em = new employee();
	dry->setemptydry();
	wash->setemptywash();
	dry->setemptydryqueue();
	wash->setemptywashqueue();
	int n;
	string st;
	string choose,conf;
	
	
	tam->loaddata();
	
	string name,tel,weight,option,status;
	string yn;
	int num, mainmenu, choice;
	int c,numchoice;
	main:
	
	FILE *file;
	file = fopen("menu logo.txt", "r");
	if (file)
	{
		while ((c = getc(file)) != EOF)
		putchar(c);
	   	fclose(file);
	}
	cout<<"Input number : ";
	cin >> 	mainmenu;
	switch(mainmenu){
		
		case 1:{

	system ("CLS");
	
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
    			loginEm:
    			cout<<"Input staff username : ";
    			cin>>name;
    			cout<<"Input staff Tel : ";
    			cin>>tel;
    			if(em->login(name,tel)==true)
    			{
    				cout<<"login complete!!!"<<endl;
    			}
    			else if(em->login(name,tel)==false)
    			{
    				system ("CLS");
    				cout<<"login again"<<endl;
    				goto loginEm;
				}
			}
			else if(conf=="N"||conf=="n"||conf=="No"||conf=="NO"||conf=="no")
			{
				system ("CLS");
				goto main;
			}
			else
			{
				system ("CLS");
				goto sure;
			}
		
			
			choicemenu:
		
		                                                                                                                                               
			
			file = fopen("top.txt", "r");
			if (file)
			{
	 			while ((c = getc(file)) != EOF)
				putchar(c);
	   			fclose(file);
    		}
			
			
			file = fopen("menuem.txt", "r");
			if (file)
			{
	 			while ((c = getc(file)) != EOF)
				putchar(c);
	   			fclose(file);
    		}
			
			cout<< "\n1. Booking	:	\n"
				<< "2. Checkcloth	:	\n"
				<< "3. Checkmachine	:	\n"
				<< "4. Paymentsystem:	\n"
				<< "5. Exit		:   \n"
				<< "\n : ";
			cin >> 	choice;
			switch(choice){
				case 1:{
					menucustomer:
				FILE *file;
				file = fopen("booking.txt", "r");
				if (file){
					while ((c = getc(file)) != EOF)
						putchar(c);
				}//open file menu booking
				fclose(file);
		    cout << "1.Newcustomer" << endl;
		    cout << "2.Regurlarcustomer" << endl;
		    cout << " : ";
		    cin >> num;
		    
		    if(num==1){	
			    regis:	
			    cout << "=============== NewcustomerRegister ============" << endl;
			    cout << "Input Name: ";
			    cin >> name;	
			    cout << "Input tel: ";
			    cin >> tel;
			    
			    if(tam->checkregistr(name,tel)==true)
			   	{
			    	cout<<"Register Notcomplete!!!"<<endl;
			    	goto regis;
			   	}
			   	else if(tam->checkregistr(name,tel)==false)
			   	{   		
			    	cout<<"Register complete!"<<endl;
			    	goto booknew;		
				}
			    system("cls");
			    booknew:
			    cout << "=============== NewcustomerBooking ============" << endl;    
				cout << "Name: " << name << endl; 
			    cout << "Input weight: ";
			    cin >> weight;  
			    back:
			    cout << "Input option(WW,WD,DD): ";
			    cin >> option;
			    if(option=="WW"||option=="WD"||option=="DD"||option=="ww"||option=="wd"||option=="dd"){
			    	goto skip;
				}else{
					goto back;
				}
			    skip:    
			 //add newcus  	 
				tam->beforeadd(name,tel,weight,option,"-");
				tam->writefileadd(name,tel,weight,option,"-","-");
			    obj_queue->enqueue(tel);
				cout << "Booking SucSess!";	
				goto choicemenu;	    	
			}else if(num==2){
		  		login:
		  		cout << "=============== RegularCustomer ============" << endl;
		  		cout<<"Input your name : ";
		    	cin>>name;
		    	cout<<"Input your Tel : ";
		    	cin>>tel;
		    	if(tam->login(name,tel)==true)
		    	{
		    		cout<<"login complete!!!"<<endl;
		    	}
		    	else if(tam->login(name,tel)==false)
		    	{
		    		system ("CLS");
		    		cout<<"login again/exit(y/n) : "<<endl;
		    		cin >> yn;
					if(yn=="y"){
						goto menucustomer;
					}else{
						goto choicemenu;
					}
		    	
				}
		    	cout << "=============== RegularCustomerBooking ============" << endl;
		   		cout << "Name:" << name << endl;
			    cout << "Input weight: ";
			    cin >> weight;
			    
			    back2:
			    cout << "Input option(WW,WD,DD): ";
			    cin >> option;
			    if(option=="WW"||option=="WD"||option=="DD"||option=="ww"||option=="wd"||option=="dd"){
			    	goto skip2;
				}else{
					goto back2;
				}
			    skip2:
			// add regular   
				tam->beforeset(name,tel,weight,option," ");
				tam->writefileset();
				obj_queue->enqueue(tel);
				//editcloth->showq();
				goto choicemenu;
			}else{
				ex:	
				cout << "ExitProGram" << endl;
			}			
					break;
				}//case booking
				case 2:{
				int chcloth;
				cout<< "1. check cloth status\n"
					<< "2. correct cloth status\n"
					<< "Enter	:	";
				cin >> chcloth;
				switch(chcloth){
					case 1:{
						
						cout<< "\nEnter name	:	";
						cin >> name;
						cout<< "Enter tel	:	";
						cin >> tel;
						editcloth->Showcheck(name,tel);
						
						break;
					}
					case 2:{
						sq:
						tam->showqueue();
						cout<< "\nKeep For First Queue!";
						cout<< "\nEnter name	:	";
						cin >> name;
						cout<< "Enter tel	:	";
						cin >> tel;
						cout<< "Enter Status	:	";
						cin >>status;
						
						nodequeue *tmp = new nodequeue();
						tmp = tam->headq;
						while(tmp!=NULL){
							if(tmp->telq==tel&&tmp->nameq==name){
								if(tmp->optionq=="dd"||tmp->optionq=="DD"){
									editcloth->correctcloth(name,tel,status);
									goto dc;	
								}else if(tmp->optionq=="wd"||tmp->optionq=="WD"||tmp->optionq=="ww"||tmp->optionq=="WW"){
									editcloth->correctcloth(name,tel,status);
									goto wc;
								}else{
									
								}
												
							}else{
							
							
							}
						}
						
						cout << "No Data input again!(y/n)"<<endl;
						cout << " : ";
						cin >> yn;
						if(yn=="y"){
							goto sq;
						
						}
						goto choicemenu;
						
						cout<<"-----------";
						
						break;
					}
						
						
					}
					goto choicemenu;
					break;
				} //case check	
				case 3:{
					g:
			cout << "1. DyingMachine" << endl;
			cout << "2. WashingMachine" << endl;
			cout << "3. Back" << endl;
			cout << " : ";
			cin >> choose;
			if(choose=="1"){
				d:
				cout << "1. CheckDyingMachine" << endl;
				cout << "2. EditDyingMachine" << endl;
				cout << "3. Back"<< endl;
				cout << " : ";
				cin >> choose;		
				if(choose=="1"){
					dry->showdryingmachine();
					cout << "Back/End(y/n) : " ;
					cin >> choose;
					if(choose=="y"){
						goto d;
					}
				}else if(choose=="2"){
					dc:
					dry->correctstatusdry();
		
					cout << "go Back/Back to menu(y/n) : " ;
					cin >> choose;
					if(choose=="y"){
						goto d;
					}else{
						goto g;
					}
				}else{
					goto choicemenu;
				}
			}else if(choose=="2"){
				w:
				cout << "1. ChackWashingMachine" << endl;
				cout << "2. EditWashingMachine" << endl;
				cout << "3. Back" << endl;
				cout << " : ";
				cin >> choose;
				if(choose=="1"){
					wash->showwashingmachine();
					cout << "Back/End(y/n) : " ;
					cin >> choose;
					if(choose=="y"){
						goto w;
					}
				}else if(choose=="2"){
					wc:
					wash->correctstatuswash();
					
					cout << "go Back/Back to menu(y/n) : " ;
					cin >> choose;
					if(choose=="y"){
						goto w;
					}else{
						goto g;
					}
				}else{
					goto g;
				}
			}else{
				goto choicemenu;
			}		
					goto choicemenu;
					break;
				}
				case 4:{
					int money;
					
					loginPay:
			  		cout << "=============== PaymentSystem ============" << endl;
			  		cout<<"Input your name : ";
			    	cin>>name;
			    	cout<<"Input your Tel : ";
			    	cin>>tel;
			    	if(tam->login(name,tel)==true)
				    	{
				    		cout<<"login complete!!!"<<endl;
				    	}
				    	else if(tam->login(name,tel)==false)
				    	{
			    		cout<<"login False!!!"<<endl;
			    		cout<<"login again/exit(y/n) : "<<endl;
			    		cin >> yn;
						if(yn=="y"){
							goto loginPay;
						}else{
							goto choicemenu;
						}
			    	
					}
					getmoney:
					pay->loaddata(name,tel);
					pay->showreceived();
					cout << "disburse(BATH) : ";
					cin >>money;
					if(money<pay->getAmountcost()){
						goto getmoney;
					}else{
						goto tmoney;
					}
					tmoney:
						
					cout << "change	: " << pay->getAmountReceived(money,pay->getAmountcost()) <<endl;
					pay->getAmountMoney(money);
					pay->printBill();
					cout<<"Goto Payment again?/Exit to Menu(y/n) : "<<endl;
					cin >> yn;
					if(yn=="y"){
						goto loginPay;
					}else{
						goto choicemenu;
					}
					break;
				}
				case 5:{
					goto main;
					break;
				}
			break;
			}//switch case Employee
		
		}//case1
		case 2:{
			choicemenu2:
			
			cout<< "\n1. Checkcloth	:	\n"
				<< "2. CheckPayment	:	\n"
				<< "3. Chackrate	:	\n"
				<< "4. Exit		:   \n"
				<< "\n : ";
			cin >> 	choice;
			switch(choice){
				case 1:{
						cout<< "\nEnter name	:	";
						cin >> name;
						cout<< "Enter tel	:	";
						cin >> tel;
						editcloth->Showcheck(name,tel);
						goto choicemenu2 ;
						break;
					break;
				}
				case 2:{
					loginPayment:
			  		cout << "=============== CheckPayment ============" << endl;
			    		cout<< "\nEnter name	:	";
						cin >> name;
						cout<< "Enter tel	:	";
						cin >> tel;
						
			    	
					if(editcloth->Showcheck(name,tel)==1){
						pay->loaddata(name,tel);
						pay->showreceived();
						goto choicemenu2;
					}else{
					
						goto choicemenu2;
					}
					
					
					break;
				}
				case 3:{
					int weightWash;
					int weightDry;
					int price;
					rate->showRate();
					cout << "==========Check Rate==========" << endl;
					cout << "Weight Washing: " ;
					cin >> weightWash;
					cout << endl;
		
					cout << "Weight Drying: " ;
					cin >> weightDry;
					cout << endl;
					rate->setRate(weightWash,weightDry);
					cout << " The cost : " << rate->calculateRate();
					cout << endl;
					goto choicemenu2;
					break;
				}
				case 4:{
					goto main;
					break;
				}
					break;	
			}
			
			break;
		}//case1
		case 3:{
					int weightWash;
					int weightDry;
					int price;
					rated:
					rate->showRate();
					cout << "==========Check Rate==========" << endl;
					cout << "Weight Washing: " ;
					cin >> weightWash;
					cout << endl;
		
					cout << "Weight Drying: " ;
					cin >> weightDry;
					cout << endl;
					rate->setRate(weightWash,weightDry);
					cout << " The cost : " << rate->calculateRate();
					cout << endl;
					cout<<"Chack Payment again?/Exit to Menu(y/n) : "<<endl;
					cin >> yn;
					if(yn=="y"){
						goto rated;
					}else{
						goto main;
					}
					goto main;
					
					
					
					
					break;
			
			
		}
		
		break;
		   
	}//switch case mainmenu
    
    return 0;	

};
