#include "Terminal.h"
#include <iostream>
int menu() {
	Terminal terminal;
	int choice = 1;
	cout << "Terminal can change:" << endl
		<< "RUB / USD" << endl
		<< "RUB / EUR" << endl
		<< "USD / EUR" << endl
		<< "USD / USDT" << endl
		<< "USD / BTC" << endl;
	while (1) {
		while (true) {
			cout << "Make an exchange - 1; Show current rate- 2; Exit - 3" << endl;
			cin >> choice;
			if (cin.fail()) {
				cout << "Incorrect input" << std::endl;
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			}
			else {
				break;
			}
		}
		if (choice == 1 || choice == 2 || choice == 3) {
			switch (choice) {
			case 1: {
				try {
					string firstcurr, secondcurr;
					int fc, sc;
					double fa;
					while (true) {
						cout << "Select the currency to sell : 1 - RUB, 2 - USD, 3 - EUR, 4 - USDT, 5 - BTC" << endl;
						cin >> fc;
						if (cin.fail()) {
							cout << "Incorrect input" << std::endl;
							std::cin.clear();
							std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						else {
							break;
						}
					}
					if (fc == 1) firstcurr = "RUB";
					else if (fc == 2) firstcurr = "USD";
					else if (fc == 3) firstcurr = "EUR";
					else if (fc == 4) firstcurr = "USDT";
					else if (fc == 5) firstcurr = "BTC";
					else {
						cout << "Incorrect input" << endl;
						break;
					}
					while (true) {
						cout << "Select the currency to purchase: 1 - RUB, 2 - USD, 3 - EUR, 4 - USDT, 5 - BTC" << endl;
						cin >> sc;
						if (cin.fail()) {
							cout << "Incorrect input" << std::endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
						}
						else {
							break;
						}
					}
					if (sc == 1) secondcurr = "RUB";
					else if (sc == 2) secondcurr = "USD";
					else if (sc == 3) secondcurr = "EUR";
					else if (sc == 4) secondcurr = "USDT";
					else if (sc == 5) secondcurr = "BTC";
					else {
						cout << "Incorrect input" << endl;
						break;
					}
					while (true){
						cout << "Deposit amount" << endl;
						cin >> fa;
						if (cin.fail()) {
							cout << "Incorrect input" << std::endl;
							std::cin.clear(); // —брос флага ошибки
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else {
							break;
						}
					}
					cout << terminal.exchange(firstcurr, secondcurr, fa) << " " << secondcurr << endl;
				}
				catch (const exception& e) {
					cout << "Incorrect input" << endl;
				}
				catch (const int& e) {
					cout << "There are not enough funds in the terminal for exchange" << endl;
				}
				break;
			}

			case 2: {
				terminal.printRate();
				break;
			}
			case 3:
				return 0;
			}
		}
		else {
			cout << "Incorrect input" << endl;
		}

	}
}