#ifndef AIRGEAD_USERINPUT_H
#define AIRGEAD_USERINPUT_H

#include <vector>
#include <string>

using namespace std;

class UserInput {
public:
    UserInput();
    vector<string> getPrompts() const { return m_prompts; };

    double getInitInvestmentAmount() const { return m_initInvestmentAmount; };
    void setInitInvestmentAmount(double t_initInvestmentAmount) {
        m_initInvestmentAmount = t_initInvestmentAmount;
    };

    double getMonthlyDeposit() const { return m_monthlyDeposit; };
    void setMonthlyDeposit(double t_monthlyDeposit) {
        m_monthlyDeposit = t_monthlyDeposit;
    };

    double getAnnualInterest() const { return m_annualInterest; };
    void setManualInterest(double t_annualInterest) {
        m_annualInterest = t_annualInterest;
    };

    double getNumYears() const { return m_numYears; };
    void setNumYears(double t_numYears) {
        m_numYears = t_numYears;
    };

    vector<double> getUserData();
    void setBankingData();

    bool checkForNewSession();
private:
    vector<string> m_prompts;
    double m_initInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    double m_numYears;

    void printHeader();
};


#endif //AIRGEAD_USERINPUT_H
