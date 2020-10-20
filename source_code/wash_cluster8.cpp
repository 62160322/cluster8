#include "wash_cluster8.h"
#include<fstream>
employee::employee()
{
	nameEmployee = " ";
	telEmployee = " ";
}
void employee::getdataemployee(string username,string tel)
{

}
bool employee::login(string username, string tel)
{
	string line;
	ifstream myFile("namestaff.txt", ios::in);
	if(myFile.is_open())
	{
		while(getline(myFile, line))
		{
			string checkname,checktel;
			checkname=line.substr(0,line.find(','));
			line.erase(0, line.find(',')+1);
			checktel=line.substr(0,line.find(','));
			if(checkname==username&&checktel==tel)
			{
				  	return true;
				  	break;
			}
			else if(checkname!=username)
			{
				line.erase(0, line.find(',')+1);
				line.erase(0, line.find(',')+1);
				return false;
			}
			else if(checkname==username&&checktel!=tel)
			{
				return false;
			}
		}
		
	}
}
