#include "InvestmentCalculator.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <sstream>

using namespace std;

//Store the values provided when the calculator is created.
InvestmentCalculator::InvestmentCalculator(
	double t_initialInvestment,
	double t_annualInterest,
	int t_numberOfYears)
	: m_initialInvestment(t_initialInvestment),
	m_annualInterest(t_annualInterest),
	m_numberOfYears(t_numberOfYears) {

}

//Calculate and display one row for each year.
void InvestmentCalculator::displayReport(
	double t_monthlyDeposit) const {

	const int MONTHS_PER_YEAR = 12;

	//Start each report with the original investment amount.
	double balance = m_initialInvestment;
	double monthlyRate = (m_annualInterest / 100.0) / MONTHS_PER_YEAR;

	//Display a title for the selected deposit scenario.
	if (t_monthlyDeposit == 0.0) {
		cout << "\nBalance and Interest Without Monthly Deposits\n";
	}
	else {
		cout << "\nBalance and Interest With Monthly Deposits\n";
	}

	cout << string(65, '~') << '\n';
	cout << left << setw(8) << "Year"
		<< right << setw(25) << "Year End Balance"
		<< setw(30) << "Year End Earned Interest" << '\n';
	cout << string(65, '*') << '\n';

	//Format monetary results to show two decimal places.
	cout << fixed << setprecision(2);

	for (int year = 0; year < m_numberOfYears; ++year) {
		double yearlyInterest = 0.0;

		//Calculate twelve months of growth for the current year.
		for (int month = 0; month < MONTHS_PER_YEAR; ++month) {
			//Each deposit earns interest during the month it is added.
			double monthlyInterest =
				(balance + t_monthlyDeposit) * monthlyRate;

			balance += t_monthlyDeposit + monthlyInterest;
			yearlyInterest += monthlyInterest;

			//Stop if the calculated amounts get too large.
			if (!isfinite(balance) || !isfinite(yearlyInterest)) {
				throw overflow_error("Calculated amount is too large.");
			}
		}

		//Format each dollar sign and amount together.
		ostringstream balanceText;
		ostringstream interestText;

		balanceText << "$" << fixed << setprecision(2) << balance;
		interestText << "$" << fixed << setprecision(2) << yearlyInterest;

		//Align the complete dollar amounts beneath the headings.
		cout << left << setw(8) << (year + 1)
			<< right << setw(25) << balanceText.str()
			<< setw(30) << interestText.str() << '\n';
	}
}