#include"Bookingqueue.h"
Bookingqueue::QueueArray( int size ){
			arr_queue = new int[ size ];
			max = size;
			count = 0;
			font = 0;
			rear = 0;
		}
Bookingqueue::~QueueArray( ){
			delete [] arr_queue;
		}
		
Bookingqueue::enqueue( string value ){
			if(rear==0){
				arr_queue[rear] = value;
				rear++;
				count++;
			}else{
				if(isFull( )==1){
					arr_queue[rear] = value;
					rear++;
					count++;
				}else{
					cout << "Queue Value Full = "<< value;
					cout << "	Size is "<< max<<endl;
				}	
			}
		}
int Bookingqueue::dequeue( ){
				arr_queue[font] = 0;			
				font++;	
				count--;
		
		}
