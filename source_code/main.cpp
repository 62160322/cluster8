#include <iostream>
#include<fstream>
#include<stdlib.h>
#include "wash_cluster8.h"
#include"Bookingqueue.h"
using namespace std;
int main(int argc, char** argv)
{
	employee versus;
	int c,numchoice;
	string conf,username,tel;
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
		if(numchoice==1)
		{
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
    			login:
    			cout<<"Input your username : ";
    			cin>>username;
    			cout<<"Input your Tel : ";
    			cin>>tel;
    			if(versus.login(username,tel)==true)
    			{
    				cout<<"login complete!!!"<<endl;
    			}
    			else if(versus.login(username,tel)==false)
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

		}
		else if(numchoice==4)
		{
			return 0;
		}
	
	return 0;
}
