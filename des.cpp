#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class QueueArray{
	
	private : 
		
		int *arr_queue;
		int max;
		int count;
		int font;
		int rear;  
		
	public : 	
		
		QueueArray(int size){
			arr_queue = new int[size];
			max=size;
			count=0;
			font=0;
			rear=0;
		}
		
		~QueueArray(){
			
			
		}
		
		void enqueue(int value){
			
		
				if(isEmpty()){
					arr_queue[rear]=value;
					count++;
					rear++;	
				
				
				
			}
		}
		
		int dequeue(){
			
				
					arr_queue[font]=NULL;
					count--;
					font++;	
				
				if(font==rear){
					
					rear=0;
					font=0;
					
				}
				
				
				
			
		}
		
		void show(){
			
			cout << "count : " << count <<endl;
			cout << "rear : " << rear <<endl;
			cout << "font : " << font <<endl;
			
			for(int i=0;i<max;i++){
				
				cout <<	arr_queue[i] << endl;
					
			
			}
			
		}
		
		bool isFull(){
			if(count==max){
				
				return true;
				
			}
			
		}
		
		bool isEmpty(){
			
		
			if(count==0){
					
				return true;
				
			}	
		}
	
};


int main(){
	
	QueueArray *obj_queueArr=new QueueArray(5);
	obj_queueArr->enqueue(5);
	obj_queueArr->enqueue(10);
	obj_queueArr->enqueue(6);
	obj_queueArr->enqueue(11);
	obj_queueArr->enqueue(12);
	obj_queueArr->enqueue(16);
	obj_queueArr->show();
	
	
	cout<<endl;
	obj_queueArr->dequeue();
	obj_queueArr->dequeue();
	obj_queueArr->show();
/*	QueueArray obj_queueArr(5);
	obj_queueArr.enqueue(5);
	obj_queueArr.enqueue(10);
	obj_queueArr.enqueue(6);
	obj_queueArr.show();
*/

}
