#include <iosteam>
using namespace std;

class Bill{
    private:
		int weight;
        int cost;
        int change;
        int choise;
        int received;
    public:
    Bill();
    int getDataBill(weight);
    int getAmountReceived(received);
    int getBill(choise);
    void print();
};