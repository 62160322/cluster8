#include "wash_cluster8.h"

editclothesbasketstatus::editclothesbasketstatus()
{
	
}
editclothesbasketstatus::editclothesbasketstatus(string day,string time,string status)
{
	finishDay = day;
	finishTime = time;
	statusClothes = status;
}
void editclothesbasketstatus::show()
{
	cout<<"Username:"<<endl;
	cout<<"Phone Number:"<<endl;
	cout<<"Queue:"<<endl;
	cout<<"Status:"<<finishDay<<" "<<finishTime<<" "<<status<<endl;
}
