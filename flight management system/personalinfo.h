#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include<iostream>
#include<string>

using namespace std;

class personalinfo{
	
	public:
		explicit personalinfo(string _name, string _surname, int id);
		void setName(string _name);
		string getName();
		void setSurname(string _surname);
		string getSurname();
		void setid(int _id);
		int getid();
		void printName();
		void printSurname();
		void printid();
		
	private:
		string name;
		string surname;
		int id;
};

#endif
