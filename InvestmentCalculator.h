#ifndef AIRGEAD_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_INVESTMENT_CALCULATOR_H_

class InvestmentCalculator {
public:
	//Set the starting investment, annual rate, and investment period.
	InvestmentCalculator(double t_initialInvestment,
		double t_annualInterest,
		int t_numberOfYears);

	//Calculate and display yearly balances and earned interest.
	void displayReport(double t_monthlyDeposit) const;

private:
	//Keep the investment settings inside the calculator.
	double m_initialInvestment;
	double m_annualInterest;
	int m_numberOfYears;
};

#endif //AIRGEAD_INVESTMENT_CALCULATOR_H_
