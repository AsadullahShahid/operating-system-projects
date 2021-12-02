/* ---program3.cpp------------------------------------------------------------------
   A driver file for the Queue class 
   Operations are:
	
   Written by: Tyler Frye			Tennessee Technological University
   Written for: CSC 2110			Written on: March 05, 2010
   ---------------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;
#include "Queue.h"
struct Teller_s {
	bool active;
	int time_At;
};
int main() {
	char runAgain;
	while (runAgain != 'N') {
		int sim_Time, trans_Time, num_Serv, arriv_Time;
		int i = 0, c_Time = 0; //Counters
		int customers = 0, left, wait_Time = 0;
		Queue bankQ;
		
		cout << "\n------------------------------------------"
			 << "\n- Welcome to the Bank Simulation Program -"
			 << "\n------------------------------------------";
		
		//Menu information
		cout << "\n\nPlease input the following data(Time in minutes):\n";
		cout << "\nLength of the Simulation: ";
		cin >> sim_Time;
		cout << "Average Transaction Time: ";
		cin >> trans_Time;
		cout << "Average Number of Servers: ";
		cin >> num_Serv;
		cout << "Average Time Between Arrivals: ";
		cin >> arriv_Time;
		
		Teller_s tellArray[num_Serv];
		
		//Set all tellers to empty
		for (i = 0; i < num_Serv; i++) {
			tellArray[i].active = false;
			tellArray[i].time_At = 0;
		}
		
		while (c_Time < sim_Time) {
		
			if (c_Time % arriv_Time == 0) {
				bankQ.enqueue();
				customers++;
			}
			if (bankQ.front() != NULL) {
				for (i = 0; i < num_Serv; i++) {
					if (tellArray[i].active == false) {
						bankQ.dequeue();
						tellArray[i].active = true;
						tellArray[i].time_At = trans_Time;						
					}
				}
			}
			
			
			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == true) {
					tellArray[i].time_At--;
				}
				if (tellArray[i].time_At == 0 && tellArray[i].active == true) {
					tellArray[i].active = false;
				}
			}
			
			left = bankQ.getSize();
			cout << endl << left;
			wait_Time  += left;
			c_Time++;
		}
		
		cout << "\n---------------"
			 << "\n- Data Output -"
			 << "\n---------------\n";
			 
		cout << "Simulation Time: ";
		cout << sim_Time << endl;
		
		cout << "Average Transaction Time: ";
		cout << trans_Time << endl;
		
		cout << "Average Number of Servers: ";
		cout << num_Serv << endl;
		
		cout << "Average Time Between Arrivals: ";
		cout << arriv_Time << endl << endl;
		
		cout << "Average Total Wait Time: ";
		cout << fixed << setprecision(2) << (float)wait_Time/customers;
		cout << endl << wait_Time << endl;
		
		cout << "\n\nRun the program again? (y/n): ";
		cin >> runAgain;
		runAgain = (char)toupper(runAgain);
		while (runAgain != 'Y' && runAgain != 'N') {
			cout << "Invalid Entry, please re-enter: ";
			cin >> runAgain;
			runAgain = (char)toupper(runAgain);
		}
	}	
	return 0;
}
