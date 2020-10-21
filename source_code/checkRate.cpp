#include <iostream>
#include "checkRate.h"
using namespace std;

	checkRate::checkRate(){	
		//Washing
		weightWash = 0;
		rateWash = 15;	
		//Drying
		weightDry = 0;
		rateDry = 15;
	}//Constructor
	
	checkRate::checkRate(int w1,int w2,int r1,int r2){
		//Washing
		weightWash = w1;
		rateWash = r1;	
		//Drying
		weightDry = w2;
		rateDry = r2;
	}//Constructor

	void checkRate::showRate(){
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
	
	void checkRate::setRate(int w1,int w2){
		//Washing
		weightWash = w1;
		//Drying
		weightDry = w2;
	}//Function-setRate
	
	int checkRate::getWash(){
		return weightWash;
	}//Function-getWash
	
	int checkRate::getDry(){
		return weightDry;
	}//Function-getDry

	int checkRate::calculateRate(){
		price1 = weightWash*rateWash;
		price2 = weightDry*rateDry;
		total = price1 + price2;
	return total;
	}//Fuction-calculateRate
	
	void checkRate::printCost(){
		cout << "The Cost: " << total << endl;
	}//Function-printCost



