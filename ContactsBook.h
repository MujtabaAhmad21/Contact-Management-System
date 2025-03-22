#pragma once
#include "Address.h"
#include "Contact.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
using namespace std;

class ContactsBook
{
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
							// stored at this count plus 1 index

public:
	//Constructor

	ContactsBook(int size_of_list = 100);
	virtual ~ContactsBook();
	virtual void add_contact(const Contact& contact);
	int total_contacts();

	//New function added
	Contact* copy_contacts_list();

	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);


	void DisplayContactsSorted(string choice); // Only two choices first_name or last_name
	virtual void DisplayContacts();
	void RemoveDuplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if

							 /*
							 *  This function loads contacts from the given file (see details in ContactsBook.cpp)
							 */
	void Loadfile(string file_name);
	void saveinfile();

private:
	bool ISfull();
	void Editlist();
	void SortContacts(Contact* contacts_list, string choice);
};

