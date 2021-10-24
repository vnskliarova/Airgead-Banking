#ifndef AIRGEAD_CALCULATIONS_H
#define AIRGEAD_CALCULATIONS_H

#include <vector>
#include <iostream>
#include "UserInput.h"
#include "InvestmentDetails.h"

class Calculations {
public:
    static InvestmentDetails calculateInvestment(UserInput& input, bool t_isMonthlyDeposit = false);
private:
    static vector<vector<double>> getBalanceAndInterestLists(double t_initAmount, double t_monthlyDeposit, int t_interestRate, int t_years);
};

#endif //AIRGEAD_CALCULATIONS_H