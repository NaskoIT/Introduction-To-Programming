#include "BankAccount.h"
#include <iostream>
#include <fstream>

using namespace std;

void saveBankAccountsToFile(Bank *banks, size_t count, const char *fileName) {
    std::ofstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        cout << "ERROR";
        return;
    }

    // write the number of Banks in the file
    file.write((const char *) &count, sizeof(count));

    for (unsigned i = 0; i < count; i++) {
        saveToFile(banks[i], file);
    }

    file.close();
}

void readBankAccountsFromFile(Bank *&banks, size_t &count, const char *fileName) {
    ifstream file(fileName, ios::binary);

    if (!file.is_open()) {
        cout << "ERROR";
        return;
    }

    // Read the number of Banks in the file
    file.read((char *) &count, sizeof(count));

    banks = new Bank[count];
    for (unsigned i = 0; i < count; i++) {
        readFromFile(banks[i], file);
    }

    file.close();
}

void swap(Bank &a, Bank &b) {
    Bank temp = a;
    a = b;
    b = temp;
}

int partition(Bank *banks, int left, int right) {
    Bank pivot = banks[right];
    int changeIndex = left;

    for (int i = left; i < right; i++) {
        if (strcmp(banks[i].getOwner(), banks[right].getOwner()) > 1) {
            swap(banks[i], banks[changeIndex]);
            changeIndex++;
        }
    }

    swap(banks[changeIndex], banks[right]);

    return changeIndex;
}

void sortByName(Bank *banks, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = partition(banks, left, right);
    sortByName(banks, left, pivot - 1);
    sortByName(banks, pivot + 1, right);
}

void showBankAccountZeroDifferences(const Bank *banks, size_t count) {
    for (unsigned i = 0; i < count; i++) {
        if (banks[i].getDifference() == 0) {
            cout << banks[i] << "\n";
        }
    }
}

void saveZeroDiff(const Bank *banks, size_t banksCount) {
    size_t count = 0;

    for (unsigned i = 0; i < banksCount; i++) {
        if (banks[i].getDifference() == 0) {
            count++;
        }
    }

    Bank *banksToSave = new Bank[count];
    size_t iter = 0;

    for (unsigned i = 0; i < count; i++) {
        if (banks[i].getDifference() == 0) {
            banksToSave[iter++] = banks[i];
        }
    }

    saveBankAccountsToFile(banksToSave, count, "BANKS.bin");
}

int main() {
    Bank banks[2];

    double withdraw1[4] = {1.5, 3, 4 , 5};
    double deposit1[3] = {10.1, 20, 2};
    banks[0].setCode("A12345");
    banks[0].setOwner("Lubo");
    banks[0].setWithdrawn(withdraw1, 4);
    banks[0].setDeposited(deposit1, 3);

    double withdraw2[3] = {1.5, 3, 4};
    double deposit2[2] = {6.5, 2 };
    banks[1].setCode("A34567");
    banks[1].setOwner("Atanas");
    banks[1].setWithdrawn(withdraw2, 3);
    banks[1].setDeposited(deposit2, 2);


    cout << "Created bank accounts: " << endl;
	for (unsigned i = 0; i < 2; i++)
	{
		std::cout << banks[i] << endl;
	}

    cout << "Start saving the banks to file: bankAccounts.bin" << endl;
    saveBankAccountsToFile(banks, 2, "bankAccounts.bin");
    cout << "Saved bank accounts to file: bankAccounts.bin" << endl;

    Bank *newBanks;
    size_t sizeBanks;
    readBankAccountsFromFile(newBanks, sizeBanks, "bankAccounts.bin");
    cout << "Read the bank accounts from the file: bankAccounts.bin" << endl;

    for (unsigned i = 0; i < sizeBanks; i++) {
        std::cout << newBanks[i] << "\n";
    }

    cout << "Show bank account with zero difference:" << endl;
    showBankAccountZeroDifferences(newBanks, sizeBanks);

    delete[] newBanks;

    return 0;
}