/*
*   Include all the needed headers here to run the scenarios
*/
#include <iostream>
#include <string>
#include "ContactsBook.h"
#include"SearchHistory.h"
#include"Group.h"
#include <cstdlib> 
#include"windows.h"
using namespace std;
Address* createAddressFromInput()
{
	string house, street, city, country;
	cout << "Enter Your House :\n";
	cin >> house;
	cout << "Enter Your Street :\n";
	cin >> street;
	cout << "Enter City :\n ";
	cin >> city;
	cout << "Enter Country :\n ";
	cin >> country;
	return new Address(house, street, city, country);
}

int main()
{
	//HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	
	//SetConsoleTextAttribute(h,3);
	cout << "\t..........EXTENDED PROJECT............\n";
	//SetConsoleTextAttribute(h, 8);
	string inpStr = "The input stream is fail!";
	ContactsBook contactsBook(5);
	group contactGroup(10); // Create a group instance

	int choice;
	do
	{
		try //exception handling
		{
			cout << "\nMenu:\n" << "1. Add New Contact\n" << "2. Remove Duplicates\n" << "3. Store In File\n" << "4. Load From File\n" << "5. Display Contacts Sorted\n" << "6. Display Contacts\n"
				<< "7. Search Contacts\n" << "8. Search History\n" << "9. Add Contact In Group\n" << "10. Display Contacts IN Group\n" << "11. Save Group To File\n" << "12. Load Group From File\n"
				<< "13. Exit Program \n" << "Enter your choice: ";
			cin >> choice;
			if (choice < 0) {
				
				throw string("Negative INVALID Input!!!");
			}
			else if (!cin)
			{
				
				throw inpStr;
			}
		}
		catch (string s)
		{
			
			cout << "Exception: " << s << endl;
			
			exit(0);
		}
		switch (choice)
		{
		case 1:
		{
			try //exception handling
			{
				// Add New Contact
				string first_name, last_name, email_address;
				int mobile_number;
				//SetConsoleTextAttribute(h, 25);
				cout << "Enter Your Good First Name: ";
				cin >> first_name;
				//SetConsoleTextAttribute(h, 12);
				cout << "Enter Your Good Last Name: ";
				cin >> last_name;
				//SetConsoleTextAttribute(h, 14);
				cout << "Enter Your Mobile Number: ";
				cin >> mobile_number;
				if (!cin)
				{
					throw inpStr;
				}
				cout << "Enter Your Email Address: ";
				cin >> email_address;
				Address* address = createAddressFromInput();
				Contact contact(first_name, last_name, to_string(mobile_number), email_address, address);
				contactsBook.add_contact(contact);
				break;
			}
			catch (string s)
			{
				cout << "Exception: " << s << endl;
				exit(0);
			}
		}
		case 2:
			// Merge Duplicates
			contactsBook.RemoveDuplicates();
			break;
		case 3: {
			
			contactsBook.saveinfile();
			break;
		}
		case 4: {
			// Load From File
			string file_name;
			cout << "Enter file name: ";
			cin >> file_name;
			contactsBook.Loadfile(file_name);
			break;
		}
		case 5: {
			// Print Contacts Sorted
			string choice;
			cout << "You Want First Name OR Last Name Please Enter in this Format (first_name or last_name): ";
			cin >> choice;
			contactsBook.DisplayContactsSorted(choice);
			break;
		}
		case 6:
			// Print Contacts
			contactsBook.DisplayContacts();
			break;
		case 7: {
			// Search Contacts
			string search_choice;
			cout << "You want First Name OR Last Name OR Mobile Number Please Enter in this format (first_name, last_name, or phone): ";
			cin >> search_choice;
			if (search_choice == "first_name" || search_choice == "last_name") {
				string name;
				cout << "Enter name: ";
				cin >> name;
				Contact* result = contactsBook.search_contact(name, search_choice);
				if (result != nullptr) {
					cout << "Contact found:" << endl;
					result->Display_contact();
				}
				else {
					cout << "Contact not found." << endl;
				}
			}
			else if (search_choice == "phone") {
				string phone;
				cout << "Enter phone number: ";
				cin >> phone;
				Contact* result = contactsBook.search_contact(phone);
				if (result != nullptr) {
					cout << "Contact found:" << endl;
					result->Display_contact();
				}
				else {
					cout << "Contact not found." << endl;
				}
			}
			else {
				cout << "Invalid search choice." << endl;
			}
			break;
		}
		case 8:
		{
			SearchHistory searchHistory;
			int choice;
			do {

				cout << "\nMenu:\n"
					<< "1. Search Contacts\n"
					<< "2. Display Search History\n"
					<< "3. Display Top 5 Searched Contacts\n"
					<< "4. Exit Program\n"
					<< "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					// Search Contacts
					string searchStr;
					cout << "Enter search string: ";
					cin >> searchStr;
					// Perform contact search here
					// For now, just add the search to history
					searchHistory.search(searchStr);
					break;
				}
				case 2:
					// View Search History
					searchHistory.Display_History();
					break;
				case 3:
					// View Top 5 Frequently Searched Contacts
					searchHistory.Display_Top5_Contacts();
					break;
				case 4:
					cout << "Exiting program." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
				}
			} while (choice != 4);
			break;
		}
		case 9: {
			// Add Contact to Group
			string groupName;
			cout << "Enter group name: ";
			cin >> groupName;
			Contact* contact = contactsBook.copy_contacts_list(); // Copy contacts list
			cout << "Select a contact to add to group:" << endl;
			for (int i = 0; i < contactsBook.total_contacts(); ++i) {
				cout << i + 1 << ". ";
				contact[i].Display_contact();
			}
			int contactIndex;
			cout << "Enter the index of the contact to add to group: ";
			cin >> contactIndex;
			contactGroup.add_contact(contact[contactIndex - 1]);
			break;
		}
		case 10:
			// Print Contacts in Group
			contactGroup.DisplayContacts();
			break;
		case 11: {
			contactGroup.saveinfile();
			break;
		}
		case 12: {
			// Load Group From File
			string file_name;
			cout << "Enter file name: ";
			cin >> file_name;
			contactGroup.Loadfile(file_name);
			break;
		}
		case 13:
			// Exit
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 13);
}



