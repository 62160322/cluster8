#include <iostream>
#include <string>

using namespace std;
class Bookingqueue{
	private :
		int * arr_queue;
		int max;
		int count;
		int font; //First
		int rear; //last
		Newcustomer obj_newcus;
		Repeatcustomer obj_repeatcus;
	public :
		QueueArray( int size );		
		~QueueArray( );
		enqueue( string value );
		int dequeue( );
};
