#include<iostream>
#include<string>
#include<vector>
#include"personalinfo.h"

using namespace std;

class employee { 
	
	private:
		
		personalinfo pi;
		string career;
		string phoneNumber;
		string email;
		
	public:
		
		explicit employee(personalinfo _pi, string _phoneNumber, string _email, string _career); //pi part composition
		void setCareer(string _career);
		string getCareer();
		void setPhoneNumber(string _phoneNumber);
		string getPhoneNumber();
		void setEmail(string _email);
		string getEmail();
		void display();
		
		static void addEmployee();
    	static vector<employee> employees;
    	static void displayAllEmployees();
};



