#include<iostream>
#include"employee.h"
#include"personalinfo.h"

using namespace std;

vector<employee> employee::employees;

employee::employee(personalinfo _pi, string _phoneNumber, string _email, string _career) : pi(_pi) {
    setPhoneNumber(_phoneNumber);
    setEmail(_email);
    setCareer(_career);
}


void employee::setPhoneNumber(string _phoneNumber){
	
	phoneNumber = _phoneNumber;
}

string employee::getPhoneNumber(){
	
	return phoneNumber;
}

void employee::setEmail(string _email){
	
	email = _email;
}

string employee::getEmail(){
	
	return email;
}

void employee::setCareer(string _career){
	
	career = _career;
}

string employee::getCareer(){
	
	return career;
}

void employee::display(){
		
	cout << "Name: ";
	pi.printName();
	cout << "Surname: ";
	pi.printSurname();
	cout << "ID: ";
	pi.printid();
	cout << "Phone Number: " << phoneNumber << endl;
	cout << "Email: " << email << endl;
	cout << "Career: " << career << endl;

}

void employee::addEmployee() {
    string name, surname, phoneNumber, email, career;
    int id;

    cout << "Enter employee name: ";
    cin >> name;

    cout << "Enter employee surname: ";
    cin >> surname;

    cout << "Enter employee ID: ";
    cin >> id; 

    cout << "Enter employee phone number: ";
    cin >> phoneNumber;
    
    cout << "Enter employee email: ";
    cin >> email;

    cout << "Enter employee career: ";
    cin >> career;

    personalinfo pi(name, surname, id);

    employee emp(pi, phoneNumber, email, career);

    employees.push_back(emp);

    cout << "New Employee Added:" << endl;
    emp.display();
    cout << "-------------------------" << endl;
}

void employee::displayAllEmployees() {
    cout << "All Employees:" << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i].display();
        cout << "---------------------" << endl;
    }
}
