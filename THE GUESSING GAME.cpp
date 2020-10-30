// GROUP WORK:
// Kidus Tefera
#include <iostream>
#include <cmath>
#include<string>
#include <time.h>
using namespace std;

int amount = 10;

// SINGLE SHOT GAME 
int SingleShot() {
	srand(time(NULL));

	int user;
	int r = rand() % 11 + 1;

	cout << "\nYOU HAVE PICKED SINGLE SHOT!" << endl;
	cout << "\nAVAILABLE BALANCE: $" << amount << endl;
	cout << "ENTER A NUMBER FROM 1 TO 11: ";
	cin >> user;

	// IF MATCHED USER WON
	if (user == r) {
		amount = amount + 2;
		cout << "\nWON $2 \nYOUR NUMBER: " << user << "\n: " << r << endl;
		cout << "YOUR NEW BALANCE: $" << amount << endl;
	}

	// LOSS $2
	else {
		amount = amount - 8;
		cout << "\nLOSS $1 \nYOUR NUMBER: " << user << "\nLUCKY NUMBER: " << r << endl;
		cout << "YOUR NEW BALANCE: $" << amount << endl;

	}

	return 0;
}

int DoubleDash() {

	if (amount < 4) {
		cout << "ADD MORE CASH TO PLAY DOUBLE DASH!" << endl;
		return 0;
	}

	else {
		srand(time(NULL));
		int RegularNumber1, RegularNumber2, SpecialNumber1, SpecialNumber2,
			Ureg1, Ureg2, Uspa1, Uspa2;

		RegularNumber1 = rand() % 11 + 1;
		RegularNumber2 = rand() % 11 + 1;
		SpecialNumber1 = rand() % 25 + 1;
		SpecialNumber2 = rand() % 25 + 1;


		if (SpecialNumber1 == 7 || SpecialNumber1 == 13 || SpecialNumber2 == 7 || SpecialNumber2 == 13) {
			SpecialNumber1 = rand() % 25 + 1;
			SpecialNumber2 = rand() % 25 + 1;
		}


		cout << "\nYOU HAVE PICKED DOUBLE DASH!" << endl;
		cout << "\nAVAILABLE BALANCE: $" << amount << endl;

		// USER INPUT FOR REGULAR NUMBERS
		cout << "ENTER FIRST REGULAR NUMBER FROM 1 to 11: ";
		cin >> Ureg1;
		cout << "ENTER SECOND REGULAR NUMBER FROM 1 to 11: ";
		cin >> Ureg2;

		// USER INPUT FOR SPECIAL NUMBERS
		cout << "\nENTER FIRST SPECIAL NUMBER FROM 1 TO 25 (EXCEPT 7 AND 13): ";
		cin >> Uspa1;
		cout << "ENTER SECOND SPECIAL  NUMBER FROM 1 TO 25 (EXCEPT 7 AND 13): ";
		cin >> Uspa2;



		// FOUR NUMBERS MATCH
		if (Ureg1 == RegularNumber1 && Ureg2 == RegularNumber2 && Uspa1 == SpecialNumber1 && Uspa2 == SpecialNumber2) {
			amount = amount + 100;
			cout << "\nWon $100" << endl;
			cout << "YOUR NEW BALANCE: $" << amount << endl;

		}

		// ONE REGULAR AND ONE SPECIAL NUMBER
		else if ((Ureg1 == RegularNumber1 || Ureg2 == RegularNumber2) && (Uspa1 == SpecialNumber1 || Uspa2 == SpecialNumber2)) {
			amount = amount + 50;
			cout << "\nWON $50" << endl;
			cout << "YOUR NEW BALANCE: $" << amount << endl;

		}

		// ONE SPECIAL NUMBER
		else if (Uspa1 == SpecialNumber1 || Uspa2 == SpecialNumber2) {
			amount = amount + 10;
			cout << "\nWON $10" << endl;
			cout << "YOUR NEW BALANCE: $" << amount << endl;
		}

		// ONE REGULAR NUMBER
		else if (Ureg1 == RegularNumber1 || Ureg2 == RegularNumber2) {
			amount = amount + 5;
			cout << "\nWON $5" << endl;
			cout << "YOUR NEW BALANCE: $" << amount << endl;

		}

		// USER LOSS $4
		else {
			amount = amount - 4;
			cout << "\nLOSS!" << endl;
			cout << "REGULAR RANDOM NUMBERS ARE: " << RegularNumber1 << "," << RegularNumber2 << endl;
			cout << "SPECIAL RANDOM NUMBERS ARE: " << SpecialNumber1 << "," << SpecialNumber2 << endl;
			cout << "YOUR NEW BALANCE: $" << amount << endl;

		}
	}

	return 0;
}



int  main() {

	cout << "YOUR BALANCE: $" << amount << endl;
	while (amount >= 0 && amount <= 100) {

		char user;
		cout << "ENTER (S) FOR SINGLE SHOT OR (D) FOR DOUBLE DASH: ";
		cin >> user;


		switch (user) {
		case 's': SingleShot();
			break;

		case 'd': DoubleDash();
			break;

		case 'S': SingleShot();
			break;

		case 'D': DoubleDash();
			break;

		default: cout << "NOT VAILD ENTRY! " << endl;

		}
	}

	if (amount <= 1) {
		cout << "YOU OUT OF CASH" << endl;
	}

	else {
		cout << "YOU WON THE MAXMIUM PRIZE! " << endl;

	}

	system("pause");
	return 0;

}	