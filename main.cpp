#include <iostream>
#include "UserInput.h"
#include "PrintInvestments.h"
#include "Calculations.h"

void startAirgeadBankingApp() {
    UserInput userInput;
    InvestmentDetails withoutDeposits;
    InvestmentDetails withDeposits;
    bool flag;

    try {
        do {
            userInput.setBankingData();
            withoutDeposits = Calculations::calculateInvestment(userInput);
            withDeposits = Calculations::calculateInvestment(userInput, true);
            PrintInvestments::printInvestments(withoutDeposits, withDeposits);
            flag = userInput.checkForNewSession();
            cout << "\n\n" << endl;
        } while (flag);
    }
    catch (exception& e) {
        cout << "**** Something went wrong ****\n" << endl;
        cout << e.what() << endl;
    }
}

int main() {
    startAirgeadBankingApp();
    return 0;
}