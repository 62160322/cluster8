#include <iostream>
#include <string>

using namespace std;
class employee
{
	private:
		string nameEmployee;
		string telEmployee;
		string status;
		string number;
		
		
		
	public:
		employee();
		void getdataemployee(string username,string tel);
	protected:
};
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

