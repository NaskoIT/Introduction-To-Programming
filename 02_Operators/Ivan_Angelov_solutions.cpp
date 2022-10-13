#include <iostream>
using namespace std;
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
int main()
{
	return 0;
}
 
void f1()
{
	double mxn;
	double mxnToBgn = 0.11;
	double bgn;
	cout << "Enter MXN:";
	cin >> mxn;
	bgn = mxnToBgn * mxn;
	cout << bgn << " BGN";
}
 
void f2()
{
	double a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
}
 
void f3()
{
	int years;
	cout << "Enter years: ";
	cin >> years;
	long minutes = years * 365 * 24 * 60;
	long seconds = minutes * 60;
	cout << years << " years have:" << endl;
	cout << minutes << " minutes" << endl;
	cout << seconds << " seconds" << endl;
}
 
void f4()
{
	double huansMoney;
	double jarWithLutenicaPrice = 4.70;
	double patePrice = 3.20;
	double breadPrice = 1.70;
	int jarWithLutenicaCount, pateCount, breadCount;
	cout << "Enter Huan's money: ";
	cin >> huansMoney;
	cout << "Enter jar with lutenica count: ";
	cin >> jarWithLutenicaCount;
	cout << "Enter pate count: ";
	cin >> pateCount;
	cout << "Enter bread count: ";
	cin >> breadCount;
	double moneyLeft = huansMoney -
		(jarWithLutenicaCount * jarWithLutenicaPrice +
			pateCount * patePrice + breadCount * breadPrice);
	cout << "Huan's money left: " << moneyLeft << endl;
}
 
void f5() 
{
	double nylonPrice = 1.50;
	double paintPrice = 14.50;
	double thinnerPrice = 5.00;
	double bagsPrice = 0.40;
	double nylonArea, paintLitres, thinnerLitres, workingHours, workPrice;
	double totalExpenses;
	cout << "Enter nylon area in square meters: ";
	cin >> nylonArea;
	cout << "Enter paint litres: ";
	cin >> paintLitres;
	cout << "Enter thinner litres: ";
	cin >> thinnerLitres;
	cout << "Enter working hours: ";
	cin >> workingHours;
	totalExpenses = (nylonArea + 2) * nylonPrice + paintLitres * 1.1 * paintPrice + thinnerLitres * thinnerPrice;
	workPrice = 0.3 * totalExpenses + 0.40;
	totalExpenses += workPrice;
 
	cout << "Total expenses are : " << totalExpenses;
}
 
void f6()
{
	int number;
	cin >> number;
	cout << number % 10;
	number /= 10;
	cout << number % 10;
	number /= 10;
	cout << number % 10;
	number /= 10;
	cout << number;
	//while (number > 10)
	//{
	//	int n = number % 10;
	//	cout << n;
	//	number /= 10;
	//}
	//cout << number;
}