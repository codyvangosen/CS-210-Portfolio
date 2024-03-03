// Cody VanGosen, CS 210, 02/10/2024
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <memory> // for std::make_unique
#include <limits> // for std::numeric_limits
#include <stdexcept> // for std::invalid_argument
#include <cctype> // for std::toupper

using namespace std;

class BankingApp {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int numberOfYears;

public:
    BankingApp(); // Constructor
    void displayUserInterface();
    void calculateAndDisplayReports();
    bool runAgain();
};

// Constructor initializes member variables to 0
BankingApp::BankingApp() : initialInvestment(0), monthlyDeposit(0), annualInterestRate(0), numberOfYears(0) {}

// Function to display user interface and accept input
void BankingApp::displayUserInterface() {
    cout << "Welcome to the Airgead Banking App.\n\n";

    bool validInput = false;
    do {
        try {
            // Prompt user for input and validate
            cout << "Initial Investment Amount: $";
            cin >> initialInvestment;

            if (cin.fail() || initialInvestment < 0) {
                throw invalid_argument("Invalid input. Please enter a non-negative numeric value.");
            }

            cout << "Monthly Deposit: $";
            cin >> monthlyDeposit;

            if (cin.fail() || monthlyDeposit < 0) {
                throw invalid_argument("Invalid input. Please enter a non-negative numeric value.");
            }

            cout << "Annual Interest (%): ";
            cin >> annualInterestRate;

            if (cin.fail() || annualInterestRate < 0) {
                throw invalid_argument("Invalid input. Please enter a non-negative numeric value.");
            }

            cout << "Number of Years: ";
            cin >> numberOfYears;

            if (cin.fail() || numberOfYears < 0) {
                throw invalid_argument("Invalid input. Please enter a non-negative integer value.");
            }

            validInput = true;
        }
        catch (const exception& e) {
            // Display error message for invalid input
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput); // Continue until valid input is provided
}

// Function to calculate and display reports
void BankingApp::calculateAndDisplayReports() {

    double monthlyInterestRate = annualInterestRate / 100 / 12;
    double maxBalance = initialInvestment;
    double maxInterest = 0;

    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarned = maxBalance * monthlyInterestRate * 12;
        maxBalance *= (1 + monthlyInterestRate * 12);
        maxInterest += interestEarned;
    }

    string maxBalanceStr = "$" + to_string(maxBalance);
    string maxInterestStr = "$" + to_string(maxInterest);

    // Calculate max width for formatting
    int maxWidth = max(maxBalanceStr.length(), maxInterestStr.length()) + 1;

    // Display report headers for without additional monthly deposits
    cout << "\n    Balance and Interest Without Additional Monthly Deposits\n";
    cout << "=============================================================\n";
    cout << setw(8) << right << "Year" << "\t" << setw(maxWidth) << right << "Year End Balance" << "\t" << setw(maxWidth) << right << "Year End Earned Interest\n";
    cout << "_____________________________________________________________\n";

    // Calculate and display report without monthly deposit
    double balanceWithoutMonthlyDeposit = initialInvestment;
    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarned = balanceWithoutMonthlyDeposit * monthlyInterestRate * 12;
        balanceWithoutMonthlyDeposit *= (1 + monthlyInterestRate * 12);
        cout << setw(8) << right << year << "\t" << setw(maxWidth) << right << fixed << setprecision(2) << "$" << balanceWithoutMonthlyDeposit << "\t" << setw(maxWidth) << right << fixed << setprecision(2) << "$" << interestEarned << "\n" << "\n";
    }

    // Display report headers for with additional monthly deposits
    cout << "\n       Balance and Interest With Additional Monthly Deposits\n";
    cout << "=============================================================\n";
    cout << setw(8) << right << "Year" << "\t" << setw(maxWidth) << right << "Year End Balance" << "\t" << setw(maxWidth) << right << "Year End Earned Interest\n";
    cout << "_____________________________________________________________\n";

    // Calculate and display report with monthly deposit
    double balanceWithMonthlyDeposit = initialInvestment;
    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarned = 0;
        for (int month = 0; month < 12; ++month) {
            double total = balanceWithMonthlyDeposit + monthlyDeposit;
            double monthlyInterest = total * monthlyInterestRate;
            balanceWithMonthlyDeposit = total + monthlyInterest;
            interestEarned += monthlyInterest;
        }
        cout << setw(8) << right << year << "\t" << setw(maxWidth) << right << fixed << setprecision(2) << "$" << balanceWithMonthlyDeposit << "\t" << setw(maxWidth) << right << fixed << setprecision(2) << "$" << interestEarned << "\n" << "\n";
    }
}

// Function to prompt user if they want to run the program again
bool BankingApp::runAgain() {
    char continueOption;
    do {
        cout << "Do you want to test with another set of values? (Y/N): ";
        cin >> continueOption;

        // Check for input errors
        if (cin.fail() || (toupper(continueOption) != 'Y' && toupper(continueOption) != 'N')) {
            cerr << "Invalid input. Please enter 'Y' or 'N'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return toupper(continueOption) == 'Y';
        }
    } while (true); // Loop until valid input is provided
}

int main() {
    // Main program loop
    do {
        try {
            BankingApp app;
            app.displayUserInterface();
            app.calculateAndDisplayReports();
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (BankingApp().runAgain()); // Continue running the program if user wants to test with another set of values

    return 0;
}
