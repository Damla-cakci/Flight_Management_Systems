#include "customer.h"

vector<Customer> Customer::customers;

Passport::Passport(const string _passport_number){
	
	setPassport_number(_passport_number);
}
    
void Passport::setPassport_number(string _passport_number){
	
	passport_number = _passport_number;
}

string Passport::getPassport_number(){
	
	return passport_number;
}

Customer::Customer(string _first_name, string _last_name, int _customer_id, string _passport_number)
    : Passport(_passport_number), first_name(_first_name), last_name(_last_name), customer_id(_customer_id) {}

void Customer::setFirst_name(string _first_name){
	
	first_name = _first_name;
}

void Customer::setLast_name(string _last_name){
	
	last_name = _last_name;
}

void Customer::setCustomer_id(int _customer_id){
	
	customer_id = _customer_id;
}

string Customer::getFirst_name(){
	
	return first_name;
}


string Customer::getLast_name(){
	
	return last_name;
}

int Customer::getCustomer_id(){
	
	return customer_id;
}

void displayCustomerDetails(const Customer& customer) {
    cout << "Name: " << customer.first_name << endl;
    cout << "Last Name: " << customer.last_name << endl;
    cout << "ID: " << customer.customer_id << endl;
    cout << "Passport Number: " << customer.passport_number << endl;
}

void Customer::display() {
    displayCustomerDetails(*this);
}

void Customer::addCustomer() {
    string firstName, lastName, passportNumber;
    int customerId;

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter passport number: ";
    cin >> passportNumber;

    cout << "Enter customer ID: ";
    cin >> customerId;

    Customer customer(firstName, lastName, customerId, passportNumber);

    customers.push_back(customer);

    cout << "New Customer Created:" << endl;
    customer.display();
    cout << "-------------------------" << endl;
}

void Customer::displayAllCustomers() {
    cout << "All Customers:" << endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        customers[i].display();
        cout << "---------------------" << endl;
    }
}



