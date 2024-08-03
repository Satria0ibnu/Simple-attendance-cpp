#include <iostream>
#include <ctime>
#include <cstring>
#include <cctype>
using namespace std;
int main() 
{

	string fullAttend[] = {"satria", "leo", "marcellino", "daus"}; 
	string idAttend[] = {"00001", "00002", "00003", "00004"};		
	
	int x;
	string id;
	time_t curr_time;
	string name;
	
	int hourLimit = 7;
	int minLimit =  30;
	int timelimit = hourLimit * 60 + minLimit;
	
	while (true)
	{
		cout << "Please Input Your Name" << endl;
		cin >> name;

		cout << "Please Input Your Student ID" << endl;
		cin >> id;
		x=0;	
		
		while ((x < sizeof(fullAttend) / sizeof(string))&&(x < sizeof(idAttend) / sizeof(string)))	
		{																					
			if ((name == fullAttend[x])&&(id == idAttend[x]))
			{
				curr_time = time(0);
				tm *tm_local = localtime(&curr_time);
				
				if (tm_local->tm_hour < hourLimit) 
				{	
					cout << "" << endl;
					cout << "=================================================================" <<endl;
					cout << "Name : " << name <<endl;
					cout << "Student ID : " << id << endl;
					cout << "You Are Attend On Time" << endl;
					cout << "Welcome To The Class"<< endl;
					cout << "=================================================================" <<endl;
					cout << "" << endl;
					abort();
				}
				else if((tm_local->tm_hour == hourLimit)&&(tm_local->tm_min <= minLimit))
				{
					cout << "" << endl;
					cout << "=================================================================" <<endl;
					cout << "Name : " << name <<endl;
					cout << "Student ID : " << id << endl;
					cout << "You Are Attend On Time" << endl;
					cout << "Welcome To The Class"<< endl;
					cout << "=================================================================" <<endl;
					cout << "" << endl;
					abort();
				}
				else
				{
					int	currenttime = tm_local->tm_hour *60 + tm_local->tm_min;
					int sisa = currenttime - timelimit;
					
					cout << "" << endl;
					cout << "=================================================================" <<endl;
					cout << "Name : " << name <<endl;
					cout << "Student ID : " << id << endl;
					cout << "You Are Late " << sisa << " Minute" << endl;
					cout << "Welcome To The Class"<< endl;
					cout << "=================================================================" <<endl;
					cout << "" << endl;
					abort();
				}										
				break;																		
			}										
			else
			{
				x++;
			}
		}
	}
	return 0;
}
