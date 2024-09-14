#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <map>
int menu();
using namespace std;

struct СurrencyPair {
	string firstCurrency;
	string secondCurrency;
	double exchangeRate;
	void print() {
		cout << firstCurrency << " "<< secondCurrency <<" "<< exchangeRate << endl;
	}
};

class Terminal {
private:
	vector <СurrencyPair> currencyPairs;
	map <string, double> terminalMoney;
public:
	Terminal() {
		currencyPairs.push_back({ "RUB", "USD", 90 });
		currencyPairs.push_back({ "RUB", "EUR", 100 });
		currencyPairs.push_back({ "USD", "EUR", 1.1 });
		currencyPairs.push_back({ "USD", "USDT", 1 });
		currencyPairs.push_back({ "USD", "BTC", 58256 });
		terminalMoney["RUB"] = 10000;
		terminalMoney["USD"] = 1000;
		terminalMoney["EUR"] = 1000;
		terminalMoney["USDT"] = 1000;
		terminalMoney["BTC"] = 1.5;
	}
	void changeRate() {
		srand(time(0));
		double persent = (static_cast<double>(rand()) / RAND_MAX) * 0.1 - 0.05;
		for (int i = 0; i < currencyPairs.size(); i++) {
			currencyPairs[i].exchangeRate = currencyPairs[i].exchangeRate * (1 + persent);
			currencyPairs[i].exchangeRate = round(currencyPairs[i].exchangeRate * 100) / 100;
		}
	}
	double exchange(string firstCurrency, string secondCurrency, double firstAmount) {
		double purchase = -1;
		for (int i = 0; i < currencyPairs.size(); i++) {
			if (firstCurrency == currencyPairs[i].firstCurrency && secondCurrency == currencyPairs[i].secondCurrency) {
				purchase = firstAmount / currencyPairs[i].exchangeRate;
				purchase = round(purchase * 100) / 100;
				if (terminalMoney[secondCurrency] >= purchase) {
					terminalMoney[secondCurrency] = terminalMoney[secondCurrency] - purchase;
					terminalMoney[firstCurrency] = terminalMoney[firstCurrency] + firstAmount;
					changeRate();
				}
				else {
					throw 1; // не хватает средств
				}
			}
			if (firstCurrency == currencyPairs[i].secondCurrency && secondCurrency == currencyPairs[i].firstCurrency) {
				purchase = firstAmount * currencyPairs[i].exchangeRate;
				purchase = round(purchase * 100) / 100;
				if (terminalMoney[secondCurrency] >= purchase) {
					terminalMoney[secondCurrency] = terminalMoney[secondCurrency] - purchase;
					terminalMoney[firstCurrency] = terminalMoney[firstCurrency] + firstAmount;
					changeRate();
				}
				else {
					throw 1;// не хватает средств
				}

			}
		}
		if (purchase == -1) {
			throw exception("error"); // не правильные данные 
		}
		return purchase;
	}

	void printBalance() {
		cout << terminalMoney["RUB"] << " RUB" << endl <<
			terminalMoney["USD"] << " USD" << endl <<
			terminalMoney["EUR"] << " EUR" << endl <<
			terminalMoney["USDT"] << " USDT" << endl <<
			terminalMoney["BTC"] << " BTC" << endl;
	}
	void printRate() {
		for (int i = 0; i < 5; i++) {
			currencyPairs[i].print();
		}

	}
};
