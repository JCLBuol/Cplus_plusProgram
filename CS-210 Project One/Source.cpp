
# include <iostream>
# include <string>
# include <iomanip>

using namespace std;


int AddOneHour24(int& hours24, int& hours12, string& amPm) {    // adds one hour to the clock and changes AM PM
	int tempHours;

	if (hours24 > 24) {
		hours24 = hours24 + 1;
	}
	else {							//  if the 24 hour clock hits 24 resets the time to hour 1
		tempHours = hours24 + 1;
		hours24 = tempHours % 24;
	}


	if (hours24 > 12) {

		hours12 = hours24 - 12;

	}

	else {
		hours12 = hours24;
	}

	if (hours12 == 0) {		// to set the 12 hour clock to 12 AM
		hours12 = 12;
	}

	if (hours24 >= 12) {	// the switch from AM to PM
		amPm = "P M";
	}

	else {
		amPm = "A M";
	}
	return amPm, hours12, hours24;
}



int AddOneMinute(int& minutes) {		//  adds one minute to both clocks
	int tempMinutes;

	if (minutes > 60) {
		minutes = minutes + 1;
	}
	
	else {							//  if the minutes hits 60 it resets it to 00
		tempMinutes = minutes + 1;
		minutes = tempMinutes % 60;
	}

	return minutes;
}

int AddOneSecond(int& seconds) {		//  adds one second to both clocks
	int tempSeconds;

	if (seconds > 60) {
		seconds = seconds + 1;
	}

	else {								// if the seconds hit 60 it resets to 00
		tempSeconds = seconds + 1;
		seconds = tempSeconds % 60;
	}

	return seconds;
}


int main() {

	int hours12 = 3;
	int hours24 = 15;
	int minutes = 22;	
	int seconds = 01;
	string amPm = "P M";
	char menu;

	do {
		cout << "**************************      **************************" << endl;
		cout << "*     12-Hour Clock      *      *     24-Hour Clock      *" << endl;
		cout << "*      " << setw(2) << setfill('0') << hours12 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << amPm <<								// to set the 12 and 24 hour clock time display, keeping all sections to 2 digits with a 0 as fill
			"      *      *       " << setw(2) << setfill('0') << hours24 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << "         *" << endl;
		cout << "**************************      **************************" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                **************************" << endl;
		cout << "                * 1 - Add One Hour       *" << endl;
		cout << "                * 2 - Add One Minute     *" << endl;
		cout << "                * 3 - Add One Second     *" << endl;
		cout << "                * 4 - Exit Program       *" << endl;
		cout << "                **************************" << endl;

		cin >> menu;


		if (menu == '1') {										// menu loop
			AddOneHour24(hours24, hours12, amPm);
			cout << "Added one hour" << endl;
			cout << endl;
			cout << endl;
		}

		else if (menu == '2') {
			AddOneMinute(minutes);
			cout << "Added one Minute" << endl;
			cout << endl;
			cout << endl;
		}

		else if (menu == '3') {
			AddOneSecond(seconds);
			cout << "Added one second" << endl;
			cout << endl;
			cout << endl;
		}

		else if (menu == '4') {
			cout << "Exit program" << endl;
			cout << endl;
			cout << endl;
		}

		else {
			cout << "Invalid entry.  Please enter a selection from the menue" << endl;
			cout << endl;
			cout << endl;
		}

		system("cls");		// to clear the screen after menue selection
	}

	while (menu != '4');
	cout << "Goodbye" << endl;

}

