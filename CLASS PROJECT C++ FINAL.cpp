#include <iostream>
#include <ctime> 
#include <cstring> 
#include <vector>
using namespace std;

int main() {
	int a, loopfree, ketIn, detail;
	
	string fullAttend[] = {"SATRIA", "LEO", "MARCELLINO", "DAUS", "JOSEPH", "RIGEL", "RIFAI"};
	string idAttend[] = {"00001", "00002", "00003", "00004", "00005", "00006", "00007"};
 	vector<string> attend;
 	vector<string> sick;
 	vector<string> absence;

	string name;
	string id;
	time_t curr_time;

	// set this to when the class start
	int hourLimit = 7;
	int minLimit =  30;
	int timelimit = hourLimit * 60 + minLimit;
	
	cout << "WHO ARE YOU : " << endl;
	cout << "1. \tLECTURER" << endl;
	cout << "2. \tSTUDENT" << endl;
	cout << "ELSE. \tQUIT" << endl;
	cin >> a;
	
	while (true) {
		if (a == 1) 
		{
			for (int i =0; i < sizeof(fullAttend) / sizeof(string); i++)
			{
				cout << "NUMBER  	: "<< i+1 << endl;
				cout << "NAME		: " << fullAttend[i] << endl;
				cout << "STUDENT ID	: " << idAttend[i] <<endl; 
					
				cout << "\t1. ATTEND" << endl << "\t2. SICK" << endl << "\t3. ABSENCE" << endl;
				
				while (true)
				{	
				cout << "DESCRIPTION : " ;
				cin >> ketIn;
					
				loopfree=0;
					switch (ketIn)
					{
						case 1:
							cout << fullAttend[i] << " CONSIDERED ATTEND" << endl << endl;				
							attend.push_back(fullAttend[i]);
							loopfree = 1;
							break;
							
						case 2:
							cout << fullAttend[i] << " CONSIDERED ABSENCE (SICK)" << endl << endl;
							sick.push_back(fullAttend[i]);
							loopfree = 1;
							break;
							
						case 3:
							cout << fullAttend[i] << " CONSIDERED ABSENCE " << endl << endl;
							absence.push_back(fullAttend[i]);
							loopfree = 1;
							break;	
								
						default:
							cout << "INVALID INPUT. INPUT AGAIN CORRECTLY" << endl;
							cout << endl;
							break;
					}
					if (loopfree == 1)
					break;
				}
			}

			while (true)
			{
			cout << "\n\nREPORT:" << endl;
			cout << "\t1. ATTENDANCE LIST" << endl << "\t2. ATTEND REPORT" << endl << "\t3. SICK REPORT" << endl << "\t4. ABSENCE REPORT" << endl << "\t5. EXIT" << endl;
			
			cout << "INPUT : ";
			cin >> detail;
			cout << endl;
			
				switch (detail)
				{
					case 1: 
						cout << "FULL STUDENT AT THIS CLASS: " <<sizeof(fullAttend) / sizeof(string) << endl;
						for (int j=0; j < sizeof(fullAttend) / sizeof(string); j++)
						{
							cout << j+1 << ". " << fullAttend[j] << endl;
						}
						break;
					
					case 2:
						cout << "STUDENT IN THE CLASS: " << attend.size() << endl;	
						for (const string& k : attend) 
						{
						cout << k << endl;
		  				}			
						break;
						
					case 3: 
						cout << "TOTAL OF SICK STUDENT: "<< sick.size() << endl;	
						for (const string& l : sick) 
						{
						cout << l << endl;
		  				}					
						break;
					
					case 4:
						cout << "TOTAL OF ABSENCE STUDENT: " << absence.size() << endl;	
								
						for (const string& m : absence) 
						{
						cout << m << endl;
		  				}					
						break;
						
					case 5: 
						abort();
						break;
						
					default:
						break;               
				}
			}					
		}
		else if (a == 2) 
		{
			while (true)
			{
				cout << "PLEASE INPUT YOUR NAME (CAPITAL LETTERS)" << endl;
				cin >> name;
				cout << endl;				
				
				int x=0;
				while (x < sizeof(fullAttend) / sizeof(string))
				{
					if (name == fullAttend[x])
					{
						cout << "PLEASE INPUT YOUR STUDENT ID"<< endl;
						cin >> id;
						cout << endl;
					
						if (id == idAttend[x])
						{	
							curr_time = time(0);
							tm *tm_local = localtime(&curr_time);
						
							if (tm_local->tm_hour < hourLimit) 
							{	
								cout << endl;
								cout << "=================================================================" <<endl;
								cout << "NAME \t\t:" << name <<endl;
								cout << "STUDENT ID \t:" << id << endl;
								cout << "YOU ARE ATTEND ON TIME" << endl;
								cout << "WELCOME TO THE CLASS"<< endl;
								cout << "=================================================================" <<endl;
								cout << endl;
								abort();
							}
							else if((tm_local->tm_hour == hourLimit)&&(tm_local->tm_min <= minLimit))
							{
								cout << endl;
								cout << "=================================================================" <<endl;
								cout << "NAME \t\t:" << name <<endl;
								cout << "STUDENT ID \t:" << id << endl;
								cout << "YOU ARE ATTEND ON TIME" << endl;
								cout << "WELCOME TO THE CLASS"<< endl;
								cout << "=================================================================" <<endl;
								cout << endl;
								abort();
							}
							else
							{
								int	currenttime = tm_local->tm_hour *60 + tm_local->tm_min;
								int sisa = currenttime - timelimit;
								
								cout << endl;
								cout << "=================================================================" <<endl;
								cout << "NAME \t\t:" << name <<endl;
								cout << "STUDENT ID \t:" << id << endl;
								cout << "YOU ARE LATE " << sisa << " MINUTE" << endl;
								cout << "WELCOME TO THE CLASS"<< endl;
								cout << "=================================================================" <<endl;
								cout << endl;
								abort();
							}
						}
					}
					else
					{
					x++;
					}
				}	
			}
		}
		else 
		{
			cout << "THANK YOU!" << endl;
			break;
		}
	}
	return 0;
}
