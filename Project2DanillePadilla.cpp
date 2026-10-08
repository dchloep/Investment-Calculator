#include "BankingApp.h"
#include <exception>
#include <iostream>

using namespace std;

int main() {
	try {
		//Create the application and start user interaction.
		BankingApp app;
		app.run();
	}

	catch (const exception& t_error) {
		//Explain unexpected errors and end the program gracefully.
		cerr << "Application ended: " << t_error.what() << '\n';
		return 1;
	}
	

	return 0;
}