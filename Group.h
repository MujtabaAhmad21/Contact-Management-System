#pragma once
#include "Address.h"
#include "Contact.h"
#include "ContactsBook.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
using namespace std;

class group : public ContactsBook
{
	Contact* Contact_arrptr;
	int size;
	int members_count;
	bool full();
	void resize_list();
public:
	group(int size = 0);
	void AddContact(const Contact& contact);
	void DisplayContacts();
	void LoadFile(string file_name);
	void SaveInFile(string file_name);
};
