#include "PrintInvestments.h"
#include <iostream>
#include <iomanip>

using namespace std;


void PrintInvestments::printTableHeader() {
    cout << string(50, '-') << endl;
    cout << setw(7) << "Year" << setw(20) << "Annual Balance" << setw(20) << "Annual Interest" << endl;
    cout << string(50, '-') << endl;
}

/**
 * Prints the data from InvestmentDetails object in rows
 */
void PrintInvestments::printTable(InvestmentDetails& t_investmentDetails) {
    //local vars to avoid clutter
    vector<double> years = t_investmentDetails.getYears();
    vector<double> balances = t_investmentDetails.getYearEndBalances();
    vector<double> interest = t_investmentDetails.getEarnedInterest();

    printTableHeader();

    //loop through the InvestmentDetails object to print out the table
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(5) << fixed << setprecision(0) << years.at(i);
        cout << setw(20) << fixed << setprecision(2) << balances.at(i);
        cout << setw(18) << interest.at(i) << endl;
    }
    cout << string(50, '*') << endl;
}

/**
 * Print 2 reports one after another
 */
void PrintInvestments::printInvestments(InvestmentDetails& t_withoutDep, InvestmentDetails& t_withDep) {
    cout << "\n\n" << string(50, '*') << endl;
    cout << "*  Balance and Interest Without Monthly Deposits *" << endl;
    printTable(t_withoutDep);

    cout << "\n\n" << string(50, '*') << endl;
    cout << "*   Balance and Interest With Monthly Deposits   *" << endl;
    printTable(t_withDep);
}