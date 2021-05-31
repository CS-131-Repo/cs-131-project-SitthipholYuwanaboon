#include <iostream>
#include <cmath>
using namespace std;

void setInput(int &time,double& rate,double &balance);
double computeRecursive(double Balance, double rate, double time) ;
double computeIterative(double Balance, double rate, double time);
int main()
{
    int choice = 0;
    int n=0;
    double rate=0.0;
    double balance=0.0;

    // cout << computeRecursive(100, 5, 5);

    do
    {
        cout << "Menu options\n"
            << "1) Compounding APY by Recursively function\n"
            << "2) Compounding APY by Loop and functions.\n"
            << "3) Quit the program.\n"
            << "Enter a valid input: ";
        cin >> choice;

        switch (choice)
        {
        
        case 1: setInput(n,rate, balance);
            cout << "Total net gain in APY compounding\n";
            cout << computeRecursive(balance,rate,n)  << "\n\n";
            break;
        case 2:  setInput(n,rate, balance);
             cout << "Total net gain in APY compounding\n";
             cout << computeIterative(balance,rate,n)  << "\n\n";
            break;
        case 3: cout << "\nQuitting program...\n\n";
            break;
        default: cout << "Enter a number listed on the menu.\n\n";
            cin.clear();
            cin.ignore(128, '\n');
        }
    } while (choice !=3);
    system("pause");
    return 0;
}


double computeRecursive(double Balance, double rate, double time) 
{ 
if ( time <= 0 ) 
{ 
  return Balance; 
} 

return computeRecursive(Balance*(1+rate/100), rate, time-1);
} 


double computeIterative(double Balance, double rate, double time)
{
    // The total balance is same as the initial balance if 
    // time is zero.
    float bal = Balance;
    for (int i = 0; i < time; i++)
    {
       // Compute the interest for this period
       float interest = bal*rate/100;

       // Add the interest to the balance so the interest
       // for the next period is a compound interest.
       bal += interest;
    }

    // The total balance after all the interests have
    // been compounded.
    return bal;
}





// Function checks for user input passed by reference with one paramater/

void setInput(int &time,double& rate,double &balance)
{
    
    cout << "\nEnter a whole number >= 1 for balance.\n"
         << "balance: ";
    cin >> balance;

    while (cin.fail() || balance < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for balance.\n"
             << "balance: ";
        cin >> balance;
    }

    cout << "\nEnter a whole number 1%-10% as 1 to 10 for rate of interest.\n"
         << "rate: ";
    cin >> rate;

    while (cin.fail() || rate < -1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for rate of interest.\n"
             << "rate of interest: ";
        cin >> rate;
    }

    cout << "\nEnter a whole number >= 1 for compounding time.\n"
         << "compounding: ";
    cin >> time;

    while (cin.fail() || time < 1)
    {
        cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter a whole number >= 1 for compounding time.\n"
             << "time: ";
        cin >> time;
    }
}


// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for balance.
// balance: 10

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 10

// Enter a whole number >= 1 for compounding time.
// compounding: 5
// Total net gain in APY compounding
// 16.1051

// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for balance.
// balance: 10

// Enter a whole number 1%-10% as 1 to 10 for rate of interest.
// rate: 10

// Enter a whole number >= 1 for compounding time.
// compounding: 10
// Total net gain in APY compounding
// 25.9374

// Menu options
// 1) Compounding APY by Recursively function
// 2) Compounding APY by Loop and functions.
// 3) Quit the program.
// Enter a valid input: 3

// Quitting program...

// sh: 1: pause: not found
