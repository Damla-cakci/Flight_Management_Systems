#include<iostream>
#include"personalinfo.h"

using namespace std;

personalinfo::personalinfo(string _name, string _surname, int _id){
	
	setName(_name);
	setSurname(_surname);
	setid(_id);
}

void personalinfo::setName(string _name){
	
	name = _name;
}

string personalinfo::getName(){
			
	return name;
}

void personalinfo::setSurname(string _surname){
	
	surname = _surname;
}

string personalinfo::getSurname(){
	
	return surname;
}

void personalinfo::setid(int _id){
	
	id = _id;
}

int personalinfo::getid(){
	
	return id;
}

void personalinfo::printName(){
	
	cout << name << endl;
}

void personalinfo::printSurname(){
	
	cout << surname << endl;
}

void personalinfo::printid(){
	
	cout << id << endl;
}
