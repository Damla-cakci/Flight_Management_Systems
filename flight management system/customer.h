#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passport {
	
public:
    Passport(string passport_number);
    void setPassport_number(string _passport_number);
    string getPassport_number();

protected:
    string passport_number;
};

class Customer : public Passport {
	
public:
	
    Customer(string _first_name, string _last_name, int _customer_id, string _passport_number);
    void setFirst_name(string _first_name);
    void setLast_name(string _last_name);
    void setCustomer_id(int _customer_id);
    string getFirst_name();
    string getLast_name();
    int getCustomer_id();
    void display();
    
    static vector<Customer> customers;
    static void addCustomer();
    static void displayAllCustomers();
    
    friend void displayCustomerDetails(const Customer& customer);

private:
	
    string first_name;
    string last_name;
    int customer_id;
    
};

#endif
