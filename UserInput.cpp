
#include "UserInput.h"
#include <iostream>

//default constructor
UserInput::UserInput() {
    m_prompts = {
            "  * Initial Investment Amount: $",
            "  * Monthly Deposit: $",
            "  * Annual Interest: %",
            "  * Number of Years: "
    };
}

void UserInput::printHeader() {
    cout << string(40, '*') << endl;
    cout << "*" << string(14, ' ') << "Data Input" << string(14, ' ') << "*" << endl;
    cout << string(40, '*') << endl;
}

/**
 * Loop through the vector with prompts to get input for each prompt
 * @return vector of user's input values
 */
vector<double> UserInput::getUserData() {
    vector<string> userPrompts = getPrompts();
    vector<double> userdata;

    for (int i = 0; i < userPrompts.size(); ++i) {
        double input;
        cout << userPrompts.at(i);
        cin >> input;

        //handling any invalid arguments
        if (cin.fail()) {
            throw invalid_argument("Only numerical values are allowed, e.g. \"1000\" or \"2.3\"\n"
                "Please try again");
        }
        else if (input < 0) {
            throw out_of_range("Negative values are not allowed\n"
                "Please try again");
        }
        else { //adding input value to the vector
            userdata.push_back(input);
        }
    }
    cout << string(40, '*') << endl;
    getchar(); //to flush the ENTER key after the last input and give the user a moment to read their data
    return userdata;
}

/**
 * Storing user's data into class members
 */
void UserInput::setBankingData() {
    vector<double> bankingData;
    bool flag = true;

    while (flag) {
        try {
            bankingData.clear(); //empty the vector to start fresh in case an exception is thrown
            printHeader();
            bankingData = getUserData();
            //handle the exceptions
        }
        catch (invalid_argument& invArgException) {
            cin.clear(); //clear error flags to start fresh in a new loop iteration
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << invArgException.what() << endl;
        }
        catch (out_of_range& rangeException) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << rangeException.what() << endl;
        }

        //check that we have 4 values for each private class member
        if (bankingData.size() == 4) {
            //assign class members
            setInitInvestmentAmount(bankingData.at(0));
            setMonthlyDeposit(bankingData.at(1));
            setManualInterest(bankingData.at(2));
            setNumYears(bankingData.at(3));
            flag = false; //break out of the loop
        }
    }

    cout << "Press ENTER to continue..." << endl;
    if (getchar()) {
        return;
    }
}

/**
 * Prompt user to input new values or to quit the program
 * @return true = input new values
 *         false = quit
 */
bool UserInput::checkForNewSession() {
    string userInput;
    cout << "Press ENTER to continue or Q to quit...";
    getline(cin, userInput);

    //loop to handle invalid input
    while (true) {
        if (!userInput.empty()) {
            if (userInput.find('q') == 0 || userInput.find('Q') == 0) {
                return false;
            }
            else {
                cout << "Press ENTER to continue or Q to quit...";
                getline(cin, userInput);
            }
        }
        else {
            return true;
        }
    }
}
