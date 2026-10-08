#ifndef AIRGEAD_BANKING_APP_H_
#define AIRGEAD_BANKING_APP_H_

#include <string>

class BankingApp {
public:
	void run();

private:
	//Read a valid number, allowing zero only when requested.
	double readNumber(const std::string& t_prompt, bool t_allowZero);
	//Require a positive whole number for the investment period.
	int readYears();
};

#endif //AIRGEAD_BANKING_APP_H_
