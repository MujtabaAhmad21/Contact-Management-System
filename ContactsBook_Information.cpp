#include "ContactsBook.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <filesystem>
#include<iostream>
using namespace std;

Contact::Contact() {
	
}
// Constructor
ContactsBook::ContactsBook(int size_of_list) {
	contacts_list = new Contact[size_of_list];
	size_of_contacts = size_of_list;
	contacts_count = 0;
}
// Destructor
ContactsBook::~ContactsBook() {
	delete[] contacts_list;
}
// Add a contact to the contacts list
void ContactsBook::add_contact(const Contact& contact) {
	if (ISfull()) {
		Editlist();
	}
	contacts_list[contacts_count++] = contact;
}
// Return the total number of contacts
int ContactsBook::total_contacts() {
	return contacts_count;
}
// Check if the contacts list is full
bool ContactsBook::ISfull() {
	return contacts_count == size_of_contacts;
}
// Resize the contacts list
void ContactsBook::Editlist() {
	int new_size = size_of_contacts * 2;
	Contact* new_list = new Contact[new_size];

	for (int i = 0; i < size_of_contacts; ++i) {
		new_list[i] = contacts_list[i];
	}

	delete[] contacts_list;
	contacts_list = new_list;
	size_of_contacts = new_size;
}
// Search for a contact by first name and last name
Contact* ContactsBook::search_contact(std::string first_name, std::string last_name) {
	for (int i = 0; i < contacts_count; ++i) {
		if (contacts_list[i].First_Name() == first_name && contacts_list[i].LastName() == last_name) {
			return new Contact(contacts_list[i]);
		}
	}
	return nullptr;
}
// Search for a contact by phone number
Contact* ContactsBook::search_contact(std::string phone) {
	for (int i = 0; i < contacts_count; ++i) {
		if (contacts_list[i].Mobile_Number() == phone) {
			return new Contact(contacts_list[i]);
		}
	}
	return nullptr;
}
// Search for a contact by address
Contact* ContactsBook::search_contact(const Address& address) {
	for (int i = 0; i < contacts_count; ++i) {
		if (*(contacts_list[i].G_Address()) == address) {
			return new Contact(contacts_list[i]);
		}
	}
	return nullptr;
}
// Create a copy of the contacts list
Contact* ContactsBook::copy_contacts_list() {
	Contact* copied_contacts = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i) {
		copied_contacts[i] = contacts_list[i];
	}
	return copied_contacts;
}
// Print contacts sorted by either first name or last name
void ContactsBook::DisplayContactsSorted(std::string choice) {
	Contact* sorted_contacts = copy_contacts_list();
	SortContacts(sorted_contacts, choice);
	for (int i = 0; i < contacts_count; ++i) {
		sorted_contacts[i].Display_contact();
		std::cout << std::endl;
	}
	delete[] sorted_contacts;
}
// Sort contacts list by either first name or last name
void ContactsBook::SortContacts(Contact* contacts_list, std::string choice) {
	if (choice == "first_name") {
		std::sort(contacts_list, contacts_list + contacts_count, [](const Contact& c1, const Contact& c2) {
			return c1.First_Name() < c2.First_Name();
		});
	}
	else if (choice == "last_name") {
		std::sort(contacts_list, contacts_list + contacts_count, [](const Contact& c1, const Contact& c2) {
			return c1.LastName() < c2.LastName();
		});
	}
}
// Merge duplicate contacts
void ContactsBook::RemoveDuplicates() {
	int merged_count = 0;
	for (int i = 0; i < contacts_count - 1; ++i) {
		for (int j = i + 1; j < contacts_count; ++j) {
			if (contacts_list[i].equals(contacts_list[j])) {
				for (int k = j; k < contacts_count - 1; ++k) {
					contacts_list[k] = contacts_list[k + 1];
				}
				contacts_count--;
				merged_count++;
				j--;
			}
		}
	}
	std::cout << "Merged " << merged_count << " duplicates." << std::endl;
}
// Load contacts from a file
void ContactsBook::Loadfile(std::string file_name) {
	std::ifstream input_file(file_name);
	if (!input_file.is_open()) {
		std::cerr << "Error: Unable to open file " << file_name << std::endl;
		return;
	}
	int contacts_count;
	input_file >> contacts_count;

	for (int i = 0; i < contacts_count; ++i) {
		std::string first_name, last_name, mobile_number, email_address;
		std::string house, street, city, country;

		input_file >> first_name >> last_name >> mobile_number >> email_address >> house >> street >> city >> country;
		Address address(house, street, city, country);
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		add_contact(contact);
	}
	input_file.close();
}
// Save contacts to a file

void ContactsBook::saveinfile() {
		std::ofstream output_file("kkk.txt");

		if (!output_file.is_open()) {
			throw std::runtime_error("Error: Unable to open or create file kkk.txt");
		}

		output_file << contacts_count << std::endl;
		
			output_file << contacts_list[0].First_Name() << " "
				<< contacts_list[0].LastName() << " "
				<< contacts_list[0].Mobile_Number() << " "
				<< contacts_list[0].Email_Address() << std::endl;

			if (contacts_list[0].G_Address() != nullptr) {
				output_file << contacts_list[0].G_Address()->G_House() << " "
					<< contacts_list[0].G_Address()->G_Street() << " "
					<< contacts_list[0].G_Address()->G_City() << " "
					<< contacts_list[0].G_Address()->G_Country() << std::endl;
			}
			else {
				output_file << "No Address" << std::endl;
			}
		

		// Close the output file after writing
		output_file.close();
	}
	
// Print all contacts
void ContactsBook::DisplayContacts() {
	if (contacts_count == 0) {
		std::cout << "No contacts to display." << std::endl;
		return;
	}

	std::cout << "Contacts:" << std::endl;
	for (int i = 0; i < contacts_count; ++i) {
		std::cout << "Contact " << i + 1 << ":" << std::endl;
		contacts_list[i].Display_contact();
		std::cout << std::endl;
	}
}
