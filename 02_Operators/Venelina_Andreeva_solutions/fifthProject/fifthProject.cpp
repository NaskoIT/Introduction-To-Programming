// fifthProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double neededNylon, neededPaint, neededThinner;
    int hoursOfWorking;
    std::cin >> neededNylon >> neededPaint >> neededThinner >> hoursOfWorking;

    double moneyForPaint = 0.1 * (neededPaint * 14.50) + (neededPaint * 14.50);
    double moneyForNylon = neededNylon * 1.50 + 2 * 1.50;
    double moneyForThinner = neededThinner * 5.00;

    double moneyForMaterials = moneyForPaint + moneyForNylon + moneyForThinner;

    double moneyForWork = 0.3 * moneyForMaterials * hoursOfWorking;

    double moneyToSpend = moneyForMaterials + moneyForWork + 0.40;
    std::cout << moneyToSpend;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
