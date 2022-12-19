#pragma once
#pragma warning(disable:4996)

#include <cstring>
#include <iostream>
#include <fstream>

const int CODE_LENGTH = 6;

class Bank {
private:
    char code[CODE_LENGTH + 1];
    char *owner;
    double *withdrawn;
    size_t sizeWithdrawn;
    double *deposited;
    size_t sizeDeposited;

    bool isCorrect(const char *codeToValidate) {
        if (strlen(codeToValidate) != CODE_LENGTH) {
            return false;
        }

        if ((codeToValidate[0] < 'A' || codeToValidate[0] > 'Z') &&
            (codeToValidate[0] < 'a' || codeToValidate[0] > 'z')) {
            return false;
        }

        for (int i = 1; i < 6; i++) {
            if (codeToValidate[i] < '0' || codeToValidate[i] > '9') {
                return false;
            }
        }

        return true;
    }

public:
    void setCode(const char *newCode) {
        if (isCorrect(newCode)) {
            strcpy(this->code, newCode);
        } else {
            strcpy(this->code, "Wrong");
        }
    }

    void setOwner(const char *newOwner) {
        delete[] this->owner;

        this->owner = new char[strlen(newOwner) + 1];
        strcpy(this->owner, newOwner);
    }

    void setWithdrawn(const double *newWithdrawn, size_t size) {
        delete[] this->withdrawn;

        this->withdrawn = new double[size];

        for (size_t i = 0; i < size; i++) {
            this->withdrawn[i] = newWithdrawn[i];
        }

        sizeWithdrawn = size;
    }

    void setDeposited(const double *newDeposited, size_t size) {
        delete[] this->deposited;

        this->deposited = new double[size];

        for (size_t i = 0; i < size; i++) {
            this->deposited[i] = newDeposited[i];
        }

        sizeDeposited = size;
    }

    Bank() : owner(nullptr), withdrawn(nullptr), sizeWithdrawn(0), deposited(nullptr), sizeDeposited(0) {
        strcpy(code, "Wrong");
    }

    Bank(const char *code, const char *owner, const double *withdrawn, size_t sizeWithdrawn, const double *deposited,
         size_t sizeDeposited) {
        this->setCode(code);
        this->setOwner(owner);
        this->setWithdrawn(withdrawn, sizeWithdrawn);
        this->setDeposited(deposited, sizeDeposited);
    }

    const char *getCode() const {
        return code;
    }

    const char *getOwner() const {
        return owner;
    }

    const double *getWithdrawn() const {
        return withdrawn;
    }

    const double *getDeposited() const {
        return deposited;
    }

    size_t getWithdrawnSize() const {
        return sizeWithdrawn;
    }

    size_t getDepositedSize() const {
        return sizeDeposited;
    }

    double getDifference() const {
        double result = 0;

        for (unsigned i = 0; i < sizeDeposited; i++) {
            result += deposited[i];
        }

        for (unsigned i = 0; i < sizeWithdrawn; i++) {
            result -= withdrawn[i];
        }

        return result;
    }

    ~Bank() {
        delete[] owner;
        delete[] withdrawn;
        delete[] deposited;
    }

    friend std::ostream &operator<<(std::ostream &, const Bank &);

    friend void saveToFile(const Bank &bank, std::ofstream &file);

    friend void readFromFile(Bank &bank, std::ifstream &file);
};


std::ostream &operator<<(std::ostream &out, const Bank &bank) {
    out << "Bank code: " << bank.code << "\n" << "Bank Owner: " << bank.owner << "\n";

    out << "Bank withdrawals: ";

    if (bank.sizeWithdrawn == 0) {
        out << "None";
    }

    for (size_t i = 0; i < bank.sizeWithdrawn; i++) {
        out << bank.withdrawn[i] << " ";
    }

    out << "\n";

    out << "Bank deposits: ";

    if (bank.sizeDeposited == 0) {
        out << "None";
    }

    for (size_t i = 0; i < bank.sizeDeposited; i++) {
        out << bank.deposited[i] << " ";
    }

    out << "\n";

    return out;
}

void saveToFile(const Bank &bank, std::ofstream &file) {
    // write the 6 digits code
    file.write(bank.code, CODE_LENGTH * sizeof(char));

    // we get the length of owner
    size_t ownerNameLength = strlen(bank.owner);
    // next we write the length
    file.write((const char *) &ownerNameLength, sizeof(ownerNameLength));

    // then we write the owner. Exmaple: A123457Preslav
    file.write(bank.owner, ownerNameLength);

    // write the length
    file.write((const char *) &bank.sizeWithdrawn, sizeof(size_t));

    // next write this number of withdrawals
    for (unsigned i = 0; i < bank.sizeWithdrawn; i++) {
        file.write((const char *) &bank.withdrawn[i], sizeof(bank.withdrawn[i]));
    }

    // write the length
    file.write((const char *) &bank.sizeDeposited, sizeof(size_t));

    // next write this number of deposits
    for (unsigned i = 0; i < bank.sizeDeposited; i++) {
        file.write((const char *) &bank.deposited[i], sizeof(bank.deposited[i]));
    }
}

void readFromFile(Bank &bank, std::ifstream &file) {
    // read the 6 digits code
    file.read(bank.code, CODE_LENGTH * sizeof(char));

    bank.code[CODE_LENGTH] = '\0';

    size_t ownerNameLength;
    // read the length of the owner name
    file.read((char *) &ownerNameLength, sizeof(ownerNameLength));

    bank.owner = new char[ownerNameLength + 1];
    // read the Owner name
    file.read(bank.owner, ownerNameLength);

    bank.owner[ownerNameLength] = '\0';

    size_t withdrawalsCount;
    // read the amount of withdrawals to be read
    file.read((char *) &withdrawalsCount, sizeof(withdrawalsCount));

    bank.sizeWithdrawn = withdrawalsCount;
    bank.withdrawn = new double[withdrawalsCount];
    // read the withdrawals from the file
    for (unsigned i = 0; i < withdrawalsCount; i++)
    {
        file.read((char *) &bank.withdrawn[i], sizeof(bank.withdrawn[i]));
    }

    size_t depositsCount;
    // read the amount of deposits to be read in the file
    file.read((char *) &depositsCount, sizeof(depositsCount));
    bank.sizeDeposited = depositsCount;
    bank.deposited = new double[depositsCount];

    // read each deposit
    for (unsigned i = 0; i < depositsCount; i++)
    {
        file.read((char *) &bank.deposited[i], sizeof(bank.deposited[i]));
    }
}