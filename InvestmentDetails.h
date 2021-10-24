#ifndef AIRGEAD_INVESTMENTDETAILS_H
#define AIRGEAD_INVESTMENTDETAILS_H

#include <vector>

using namespace std;

class InvestmentDetails {
public:
    vector<double> getYears() const { return m_years; };
    void setYears(vector<double> t_years) { m_years = t_years; };

    vector<double> getYearEndBalances() const { return m_yearEndBalances; };
    void setYearEndBalances(vector<double> t_yearEndBalances) { m_yearEndBalances = t_yearEndBalances; };

    vector<double> getEarnedInterest() const { return m_earnedInterest; };
    void setEarnedInterest(vector<double> t_earnedInterest) { m_earnedInterest = t_earnedInterest; };
private:
    vector<double> m_years;
    vector<double> m_yearEndBalances;
    vector<double> m_earnedInterest;
};


#endif //AIRGEAD_INVESTMENTDETAILS_H