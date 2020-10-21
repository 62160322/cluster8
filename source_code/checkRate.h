#include <iostream>
#include <string>
using namespace std;

class checkRate{
	private:
		int weightWash;
		int weightDry;
		int rateWash;
		int rateDry;
		int price1;
		int price2;
		int total;
	public:
		checkRate();
		checkRate(int w1,int w2,int r1,int r2);
		void showRate();
		void setRate(int w1,int w2);
		int getWash();
		int getDry();
		int calculateRate();
		void printCost();
};
