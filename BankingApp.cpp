#include "BankingApp.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

//Collect the information needed to calculate investment growth.
void BankingApp::run() {

	//Repeat the application until the user chooses to exit.
	while (true) {

		//Use doubles because dollar amounts and interest rates can have decimals.
		double initialInvestment = 0.0;
		double monthlyDeposit = 0.0;
		double annualInterest = 0.0;
		//Use an integer because the investment period is measured in whole years.
		int numberOfYears = 0;

		//Display the application heading.
		cout << "********************************\n";
		cout << "        AIRGEAD BANKING\n";
		cout << "********************************\n";

		//Require a positive starting investment.
		initialInvestment = readNumber(
			"Initial Investment Amount : $", false);

		//Require a positive monthly contribution.
		monthlyDeposit = readNumber(
			"Monthly Deposit: $", false);

		//Allow a zero interest rate to explore growth from deposits alone.
		annualInterest = readNumber(
			"Annual Interest (%): ", true);

		//Validate the investment period before calculating growth.
		numberOfYears = readYears();

		//Display money and percentages with two decimal places.
		cout << fixed << setprecision(2);

		//Let the user review the values before viewing the reports.
		cout << "\n********************************\n";
		cout << "           DATA INPUT\n";
		cout << "********************************\n";
		cout << "Initial Investment Amount: $"
			<< initialInvestment << '\n';
		cout << "Monthly Deposit: $"
			<< monthlyDeposit << '\n';
		cout << "Annual Interest: "
			<< annualInterest << "%\n";
		cout << "Number of Years: "
			<< numberOfYears << '\n';


		//Wait for Enter before proceeding to the investment reports.
		cout << "\nPress Enter to continue...";
		string input;

		if (!getline(cin, input)) {
			throw runtime_error("Input is no longer available.");
		}

		//Create the calculator using the validated investment settings.
		InvestmentCalculator calculator(
			initialInvestment, annualInterest, numberOfYears);

		//Display growth without additional monthly deposits.
		calculator.displayReport(0.0);

		//Display growth with the user's monthly deposit.
		calculator.displayReport(monthlyDeposit);

		//Ask whether the user wants to test another investment.
		string choice;

		while (true) {
			cout << "\nTry another investment? (Y/N): ";

			if (!getline(cin, choice)) {
				throw runtime_error("Input is no longer available.");
			}

			//Accept either uppercase or lowercase response.
			if (choice == "Y" || choice == "y" ||
				choice == "N" || choice == "n") {
				break;
			}

			cout << "Please enter Y or N.\n";
		}

		//Leave the application loop when the user chooses no.
		if (choice == "N" || choice == "n") {
			break;
		}
	}

	cout << "\nThank you for using Airgead Banking!\n";
}

double BankingApp::readNumber(const string& t_prompt, bool t_allowZero) {
	string input;
	double value = 0.0;

	//Keep asking until the user enters an acceptable number.
	while (true) {
		cout << t_prompt;

		//Stop gracefully if input is no longer available.
		if (!getline(cin, input)) {
			throw runtime_error("Input is no longer available.");
		}

		//Read from the whole line so extra characters can be rejected.
		istringstream inputStream(input);
		char extraCharacter = '\0';

		if ((inputStream >> value) && !(inputStream >> extraCharacter) && isfinite(value)) {
			//Investment amounts must be positive; the rate may be zero.
			if (value > 0.0 || (t_allowZero && value == 0.0)) {
				return value;
			}
		}

		//Explain which values are accepted before asking again.
		if (t_allowZero) {
			cout << "Please enter a number greater than or equal to zero.\n";
		}
		else {
			cout << "Please enter a number greater than zero.\n";
		}
	}
}

int BankingApp::readYears() {
	string input;
	int years = 0;

	//Repeat the prompt until a positive whole number is entered.
	while (true) {
		cout << "Number of years: ";

		if (!getline(cin, input)) {
			throw runtime_error("Input is no longer available.");
		}
		istringstream inputStream(input);
		char extraCharacter = '\0';

		//Reject extra characters, including a decimal point.
		if ((inputStream >> years) && !(inputStream >> extraCharacter) && years > 0) {
			return years;
		}

		cout << "Please enter a whole number greater than zero.\n";
	}
}