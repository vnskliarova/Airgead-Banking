#include "Calculations.h"

/**
 * Take user input for calculations and construct InvestmentDetails object
 * @param input - user data
 * @param t_isMonthlyDeposit - false by default
 * @return - InvestmentDetails object with years, balances, and interest data
 */
InvestmentDetails Calculations::calculateInvestment(UserInput& input, bool t_isMonthlyDeposit) {
    double initAmount = input.getInitInvestmentAmount();
    double monthlyDep = input.getMonthlyDeposit();
    double interest = input.getAnnualInterest();
    double numYears = input.getNumYears();

    InvestmentDetails investmentDetails;
    vector<double> years;
    vector<vector<double>> endOfYearBalancesAndInterests;

    //store years data
    for (int i = 1; i <= numYears; ++i) {
        years.push_back(i);
    }

    try {
        if (t_isMonthlyDeposit) { //calculate with monthly deposit
            endOfYearBalancesAndInterests = getBalanceAndInterestLists(initAmount, monthlyDep, interest, numYears);
        }
        else { //calculate without monthly deposit
            endOfYearBalancesAndInterests = getBalanceAndInterestLists(initAmount, 0, interest, numYears);
        }

        //populate InvestmentDetails object
        investmentDetails.setYears(years);
        investmentDetails.setYearEndBalances(endOfYearBalancesAndInterests.at(0));
        investmentDetails.setEarnedInterest(endOfYearBalancesAndInterests.at(1));
    }
    catch (out_of_range& e) {
        cout << "**** Something went wrong ****\n" << endl;
        cout << e.what() << endl;
    }
    return investmentDetails;
}

/**
 * Calculate annual balances and earned interest
 */
vector<vector<double>> Calculations::getBalanceAndInterestLists(double t_initAmount, double t_monthlyDeposit, int t_interestRate, int t_years) {
    vector<vector<double>> balancesAndInterests;
    vector<double> annualInterests;
    vector<double> annualBalances;
    double endOfMonthInterest;
    double endOfYearInterest = 0;
    double endOfYearBalance;
    double startBalance = t_initAmount + t_monthlyDeposit;

    //loop through each month in a given years period to calculate annual balance and interest
    for (int i = 1; i <= (t_years * 12); ++i) {
        //calculate monthly interest
        endOfMonthInterest = startBalance * ((t_interestRate / 100.00 / 12.00));
        //add it to the yearly accumulated interest
        endOfYearInterest += endOfMonthInterest;
        //calculate annual total balance (every 12 iterations), used to get a starting balance for next iteration
        endOfYearBalance = startBalance + endOfMonthInterest;
        //balance for calculating monthly interest in the next iteration
        startBalance = endOfYearBalance + t_monthlyDeposit;
        if (i % 12 == 0) { //store only annual data to the vectors
            annualInterests.push_back(endOfYearInterest);
            annualBalances.push_back(endOfYearBalance);
        }
    }

    //sanity check for a very large amount
    if (endOfYearBalance > LONG_MAX) {
        throw out_of_range("***** Unable to complete calculation *****"
            "\nYou will end up with a lot of money, I can't even handle it!");
    }

    //storing balances and interest into vector to be returned
    balancesAndInterests.push_back(annualBalances);
    balancesAndInterests.push_back(annualInterests);

    return balancesAndInterests;
}