#include <iostream>
#include <algorithm>
#include "flight.h"
#include "employee.h"
#include "personalinfo.h"
#include "dijkstra.h"
#include "customer.h"

using namespace std;

int main() {
    int choice;
    cargo myCargo;

    do {
        cout << "Menu:" << endl;
        cout << "1. Display all flights" << endl;
        cout << "2. Create a new flight" << endl;
        cout << "3. Display all employees" << endl;
        cout << "4. Add a new employee" << endl;
        cout << "5. Display all customers" << endl;
        cout << "6. Add a new customer" << endl;
        cout << "7. Calculate and Display Shortest Path for cargo" << endl;
        cout << "8. Sort flights by date" << endl; // sýralama algoritmasý
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                flightInfo::displayAllFlights();
                break;

            case 2:
                flightInfo::createFlight();
                break;

            case 3:
                employee::displayAllEmployees();
                break;

            case 4:
                employee::addEmployee();
                break;

            case 5:
                Customer::displayAllCustomers();
                break;

            case 6:
                Customer::addCustomer();
                break;

            case 7:
                myCargo.hesaplaVeYazdirMesafeSuresi();
                break;

            case 8:
                sort(flightInfo::flights.begin(), flightInfo::flights.end(), flightInfo::compareByDate);
                cout << "Flights sorted by date." << endl;
                flightInfo::displayAllFlights();
                break;

            case 9:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 9);

    return 0;
}



