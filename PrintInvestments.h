#ifndef AIRGEAD_PRINTINVESTMENTS_H
#define AIRGEAD_PRINTINVESTMENTS_H

#include "InvestmentDetails.h"
#include "Calculations.h"

class PrintInvestments {
public:
    static void printInvestments(InvestmentDetails& t_withoutDep, InvestmentDetails& t_withDep);
private:
    static void printTableHeader();
    static void printTable(InvestmentDetails& t_investmentDetails);

};


#endif //AIRGEAD_PRINTINVESTMENTS_H

