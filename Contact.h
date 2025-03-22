#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"
using namespace std;

class Contact
{
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address* address;
	static int id;
public:

	bool equals(const Contact& contact);
	Contact* copy_contact();

	// Getter and setter for first_name
	string First_Name() const;
	void Set_First_Name(const string& newFirstName);

	// Getter and setter for last_name
	string LastName() const;
	void Set_Last_Name(const string& newLastName);

	// Getter and setter for mobile_number
	string Mobile_Number() const;
	void Set_Mobile_Number(const string& newMobileNumber);

	// Getter and setter for email_address
	string Email_Address() const;
	void Set_Email_Address(const string& newEmailAddress);

	// Getter and setter for address
	Address* G_Address() const;
	void Set_Address(Address* newAddress);

	static int getId();

	// Constructor
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address);
	Contact();
	void Display_contact();

	void update_contact_information();
	// Destructor
	~Contact();
};

