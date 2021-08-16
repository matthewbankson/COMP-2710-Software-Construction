//Matthew Bankson (mlb0126)
//project1_mlb0126.cpp
//How to compile: g++ project1_mlb0126.cpp

#include <iostream>
using namespace std;

int main() {
//Variable Initialization
   double loan = 0.0;
   double interestRate = 0.0;
   double monthlyPaid = 0.0;
   double interestRateC = 0.0;
   double interestPaid = 0.0;
   double totalInterest = 0.0;
   int currentMonth = 0;
   
   //Currency Formatting
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   do {
      cout << "\nLoan Amount: ";
      cin >> loan;
   }
   while (loan <= 0);
   
   do {
      cout << "Interest Rate (% per year): ";
      cin >> interestRate;
   }
   while (interestRate <= 0);
   
   //Get proper interest rate for calculations
   interestRate /= 12;
   interestRateC = interestRate / 100;
   
   do {
      cout << "Monthly Payments: ";
      cin >> monthlyPaid;
   }
   while (((loan * interestRateC) > monthlyPaid) || ((monthlyPaid - (loan * interestRateC)) < 0.000001));
   cout << endl;
   
   //Amortization table
   cout << "*****************************************************************\n"
      << "\tAmortization Table\n"
      << "*****************************************************************\n"
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
      
      //Loop to fill table
   while (loan > 0) {
      if (currentMonth == 0) {
         cout << currentMonth++ << "\t$" << loan;
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
      }
      else {
         interestPaid = loan * interestRateC;
         totalInterest += interestPaid;
         if (loan * (1 + interestRateC) >= monthlyPaid) {
            loan = loan - monthlyPaid + (loan * interestRateC);
            cout << currentMonth++ << "\t$" << loan;
            if (loan < 1000) {
               cout << "\t";
            }
            cout << "\t$" << monthlyPaid << "\t" << interestRate
                  << "\t$" << interestPaid << "\t\t$"
                  << monthlyPaid - interestPaid << "\n";
            
         }
         else {
            cout << currentMonth++ << "\t$0.00\t\t$" << loan * (1 + interestRateC)
               << "\t" << interestRate << "\t$" << interestPaid
               << "\t\t$" << (loan * (1 + interestRateC)) - interestPaid << "\n";
            loan = 0;
         }
      }
   }
   
   cout << "*****************************************************************\n";
   cout << "\nIt takes " << --currentMonth << " months to pay off " 
      << "the loan.\n"
      << "Total interest paid is: $" << totalInterest;
   cout << endl << endl;
   return 0;
}
