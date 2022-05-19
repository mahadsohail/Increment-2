#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;
void changeofemployeespassword()
{
	ifstream input("EmployeesData.txt");
	string username, password;
	const int size = 50;
	string Usernames[size] = {};
	string Passwords[size] = {};
	int loop = 0;
	while (!input.eof())
	{
			getline(input, username, ',');
			getline(input, password);
			Usernames[loop] = username;
			Passwords[loop] = password;
			loop++;
	}
	input.close();
	string usertochngpass, newpassword,prevpassword;
	ofstream output("EmployeesData.txt");
	cout << "Enter the username" << endl;
	cin >> usertochngpass;
	cout << "Enter the password" << endl;
	cin >> prevpassword;
	for (int i = 0; i < loop-1; i++)
	{
		if (Usernames[i]==usertochngpass&&Passwords[i]==prevpassword)
		{
			cout << "Enter the new password" << endl;
			cin >> newpassword;
			if (Passwords[i] != newpassword)
			{
				Passwords[i] = newpassword;
				cout << "Password Updated" << endl;
			}
		}
		output << Usernames[i] << "," << Passwords[i] << endl;
	}
	output.close();
}
void CustomerInfo()
{
	string customerid, CNICnumber, CustomerName, Address, PhoneNumber, CustomerType, MeterType, ConnectionDate;
	int RegularUnitsUsed=0, PeakHoursUnitsUsed=0;
	ofstream output("CustomerInfo.txt");
	string usernameOfCustm, PassOfCustm;
	usernameOfCustm = customerid;
	PassOfCustm = CNICnumber;
	string check;
	float bill = 0;
	if (check == "n")
	{
		RegularUnitsUsed = 0;
	}
	bool threephase = true;
	if (!threephase)
	{
		RegularUnitsUsed = RegularUnitsUsed;
		PeakHoursUnitsUsed = 0;
	}
	else
	{
		RegularUnitsUsed = RegularUnitsUsed;
		PeakHoursUnitsUsed = PeakHoursUnitsUsed;
	}
	output << customerid << "," << CNICnumber << "," << Address << "," << PhoneNumber << "," << CustomerType << "," << MeterType << "," <<
		ConnectionDate << "," << RegularUnitsUsed << "," << PeakHoursUnitsUsed << endl;
	output.close();
}
class billingmonth
{
	int month;
	int day;
	int year;
public:
	billingmonth()
	{
		month = 01;
		day = 01;
		year = 01;
	}
	billingmonth(int d,int m,int y )
	{
		day = d;
		month = m;
		year = y;
	}
	friend void BillingInfo();
	friend void ViewExpirydate();
};
void BillingInfo()
{
	ifstream inputbill("CustomerInfo.txt");
	string customerid, dueDate, CustomerType, MeterType;
	int RegularMeter=0, PeakMeter=0,TotalBillingamount=0, Costofelectricity=0, SalesTaxAmount=0, FixedCharges=0;
	int RegularUnitsUsed = 0, PeakHoursUnitsUsed = 0, RegularUnitPrice = 0, PeakUnitPrice = 0;
	while (!inputbill.eof())
	{
		getline(inputbill, customerid, ',');
		cout << customerid << endl;
		break;
	}
	billingmonth issuedate;
	billingmonth duedate;
	billingmonth datenow;
	cout << "Enter the issue date of bill in the Format DD/MM/YY" << endl;
	cin >> issuedate.day;
	cin >> issuedate.month;
	cin >> issuedate.year;
	cout << "Enter the due date of the bill in the Format DD/MM/YY" << endl;
	cin >> duedate.day;
	cin >> duedate.month;
	cin >> duedate.year;
	cout << "Enter the date today in the Format DD/MM/YY" << endl;
	cin >> datenow.day;
	cin >> datenow.month;
	cin >> datenow.year;
	bool BillStatus = true;
	if (!BillStatus)
	{
		BillStatus = false;
		cout << "NotPaid" << endl;
	}
	else
	{
		BillStatus = true;
		cout << "Paid" << endl;
	}
	cout << "Enter the customer type" << endl;
	cin >> CustomerType;
	cout << "Enter the meter type" << endl;
	cin >> MeterType;
	if (CustomerType == "Commercial" && MeterType=="SinglePhase")
	{
		Costofelectricity = 15;
		RegularUnitsUsed = RegularMeter - RegularUnitsUsed;
		PeakHoursUnitsUsed = 0;
		TotalBillingamount = (RegularUnitsUsed * Costofelectricity);
	}
	else if (CustomerType == "Domestic" && MeterType == "SinglePhase")
	{
		Costofelectricity = 5;
		RegularUnitsUsed = RegularMeter - RegularUnitsUsed;
		PeakHoursUnitsUsed = 0;
		TotalBillingamount = (RegularUnitsUsed * Costofelectricity);
	}
	else if (CustomerType == "Domestic" && MeterType == "ThreePhase")
	{
		RegularUnitPrice = 8;
		PeakUnitPrice = 12;
		RegularUnitsUsed = RegularMeter - RegularUnitsUsed;
		PeakHoursUnitsUsed = PeakMeter - PeakHoursUnitsUsed;
		TotalBillingamount = PeakHoursUnitsUsed * PeakUnitPrice;
		TotalBillingamount = TotalBillingamount + (RegularUnitsUsed * RegularUnitPrice);
	}
	else if (CustomerType == "Commercial" && MeterType == "ThreePhase")
	{
		RegularUnitPrice = 18;
		PeakUnitPrice = 25;
		RegularUnitsUsed = RegularMeter - RegularUnitsUsed;
		PeakHoursUnitsUsed = PeakMeter - PeakHoursUnitsUsed;
		TotalBillingamount = PeakHoursUnitsUsed * PeakUnitPrice;
		TotalBillingamount = TotalBillingamount + (RegularUnitsUsed * RegularUnitPrice);
	}
	cout << TotalBillingamount << endl;
}
//part 4
void taxinfo()
{
	string MeterType,CustomerType;
	int salestax = 0, fixedcharges = 0, tarriftax=0;
	int RegularUnitPrice = 0, PeakUnitPrice = 0;
	cout << "Enter the unit price for regular time" << endl;
	cin >> RegularUnitPrice;
	cout << "Enter the unit price at peak time" << endl;
	cin >> PeakUnitPrice;
	cout << "Enter the metertype" << endl;
	cin >> MeterType;
	ofstream output("Tarrif.txt");
	if (MeterType == "1Phase"&&CustomerType=="Domestic")
	{
		output << MeterType << "," << RegularUnitPrice << "," <<""<< "," << tarriftax << "," << fixedcharges << endl;
	}
	else if (MeterType == "3Phase" && CustomerType == "Domestic")
	{
		output << MeterType << "," << RegularUnitPrice << "," << PeakUnitPrice << "," << tarriftax << "," << fixedcharges << endl;
	}
	else if (MeterType == "1Phase" && CustomerType == "Commercial")
	{
		output << MeterType << "," << RegularUnitPrice << "," << "" << "," << tarriftax << "," << fixedcharges << endl;
	}
	else
	{
		output << MeterType << "," << RegularUnitPrice << "," << PeakUnitPrice << "," << tarriftax << "," << fixedcharges << endl;
	}
	output.close();
}
//part6
void BillingInfoChk()
{
	ofstream output;
	output.open("Billinginfo.txt");
	output << "";
	output.close();
	cout << "Updated successfully";
}
//part7
void TarrifFile()
{
	ofstream output;
	output.open("Tariff.txt");
	output << "   ";
	output.close();
	cout << "updated successfully ";
}
//part 8
void viewbill()
{
	char username;
	cout << "Enter username " << endl;
	cin >> username;
	int password;
	cout << "Enter valid password" << endl;
	cin >> password;
	int id;
	cout << "Enter 4 digit customer id" << endl;
	cin >> id;
	if (id <= 4)
	{
		ifstream input("BillingInfo.txt");
		input.close();
	}
	else
	{
		cout << "Invalid id" << endl;
	}
}
//part 9
void view()
{
	int digit;
	cout << "Enter 4 digit ID " << endl;
	cin >> digit;
	if (digit >= 4)
	{
		double cnic;
		cout << "Enter CNIC " << endl;
		cin >> cnic;
		int metertype;
		cout << "Enter meter type (1 for 1-phase and 2 for 3-phase)" << endl;
		cin >> metertype;
		if (metertype == 1)
		{
			cout << "Your meter is 1 phase" << endl;
		}
		else
		{
			cout << "Your meter is 3 phase" << endl;
		}
		double reading;
		cout << "Enter current meter reading" << endl;
		cin >> reading;
		//cost of electricity
		// tax
		//fixed charges
	}
	else
	{
		cout << "ID must be 4 digits" << endl;
	}
}
//part 10
void viewingPaidandUnpaidBills()
{
	string BillStatus;
	int countP = 0;
	int countUp = 0;
	ifstream input("CustomerInfo.txt");
	while (!input.eof())
	{
		getline(input,BillStatus);
		if (BillStatus == "1")
		{
			countP++;
		}
		else
		{
			countUp++;
		}
	}
	input.close();
	cout << "The number of paid bills are" << endl;
	cout << countP << endl;
	cout << "The number of unpaid bills are" << endl;
	cout << countUp << endl;
}
//part 11
void ViewExpirydate()
{
	string Expiryday;
	string Expiryyear;
	string Expirymonth;
	string datetoday;
	string month;
	string year;
	string customername;
	string CNIC;
	cout << "Enter the date today (Day)" << endl;
	cin >> datetoday;
	cout << "Enter the date today (Day)" << endl;
	cin >> month; 
	cout << "Enter the date today (Day)" << endl;
	cin >> year;
	ifstream input("NADRADB.txt");
	while (!input.eof())
	{
		getline(input, Expiryday, '/');
		getline(input, Expirymonth, '/');
		getline(input, Expiryyear, '/');
	}
	input.close();
	input.open("CustomerInfo.txt");
	if (Expiryday < datetoday + "30")
	{
		getline(input, customername, ',');
		getline(input, CNIC, ',');
		cout << customername << endl;
		cout << CNIC << endl;
	}
	input.close();
}
//part 12
void updateofexpirydate()
{
	ifstream input("NADRADB.txt");
	string customerid;
	string CNIC;
	string expiryday;
	string expirymonth;
	string expiryyear;
	string cnic;
	string customername;
	string updatedDay;
	string updatedmonth;
	string updatedyear;
	cout << "Enter the username" << endl;
	cin >> customerid;
	cout << "Enter the cinic number" << endl;
	cin >> CNIC;
	while (!input.eof())
	{
		getline(input, customername, ',');
		getline(input, cnic, ',');
		getline(input, expiryday, '/');
		getline(input, expirymonth, '/');
		getline(input, expiryyear);
	}
	input.close();
	ofstream output("NADRA.txt");
	if (customerid == customername && cnic == CNIC)
	{
		cout << "Enter the updated expiry day" << endl;
		cin >> updatedDay;
		cout<< "Enter the updated expiry day" << endl;
		cin >> updatedmonth;
		cout << "Enter the updated expiry day" << endl;
		cin >> updatedyear;
		output << customerid << "," << cnic << "," << updatedDay << "/" << updatedmonth << "/" << updatedyear << endl;
	}
	output.close();
}
void displayEmployee()
{
	changeofemployeespassword();
	CustomerInfo();
	TarrifFile();
	viewbill();
	BillingInfoChk();
	ViewExpirydate();
	taxinfo();
	viewingPaidandUnpaidBills();
}
void displayCustomer()
{
	view();
	updateofexpirydate();
}
int main()
{	
	int number = 0;
	cout << "Enter 1 if you are employee and 2 if customer" << endl;
	cin >> number;
	if (number == 1)
	{
		displayEmployee();
	}
	else if (number == 0)
	{
		displayCustomer();
	}
	else
	{
		cout << "Incorrect entry.Program Terminated" << endl;
	}
	return 0;
}