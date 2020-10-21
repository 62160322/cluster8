#include <iostream>
#include "checkRate.h"
using namespace std;

int main(){
	checkRate myCheck1;
	myCheck1.showRate();
	
	int weightWash;
	int weightDry;
	int price;
	
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
}
