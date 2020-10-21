#include <iostream>
#include <string>

using namespace std;

class Editdryingmachine{
	
	private:
		string status;
		int number;
	public:
 		Editdryingmachine();
 		void setdata();
 		string correctstatus(string st,int n);
 		void showBakingmachine();
	
};

