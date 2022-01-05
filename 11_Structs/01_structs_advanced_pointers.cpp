#include<iostream>
#include <string>

using namespace std;

struct Company {
    string name;
};

struct Employee {
    string name;
    double salary;
    Employee* boss;
    Company company;
};

void setName(Employee& employee) {
    employee.name = "some_name";
}

int main() {
    Employee* boss = new Employee();
    boss->name = "Boss";
    boss->salary = 10000;
    boss->boss = nullptr;

    Company company = { "Microsoft" };
    Employee worker = { "Worker", 2000, boss, company };

    cout << worker.name + " has chief: " << worker.boss->name;
    cout << " and working in: " << worker.company.name << endl;

    Employee otherWorker = worker;

    cout << otherWorker.name << " " << otherWorker.salary << endl;
    otherWorker.name = "Other worker";
    cout << worker.name << " " << otherWorker.name << endl;

    setName(worker);
    cout << worker.name << endl;

    worker.boss->name = "New boss";
    cout << "Worker boss: " << worker.boss->name << ", Other worker boss: " << otherWorker.boss->name << endl;

    worker.company.name = "new company";
    cout << "Worker company: " << worker.company.name << ", Other worker company: " << otherWorker.company.name << endl;
}