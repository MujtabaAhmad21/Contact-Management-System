#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
int Contact::id = 0;

Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address)
	:first_name(first_name), last_name(last_name), mobile_number(mobile_number), email_address(email_address)
{
	id++;
	try //exception handling
	{
		this->address = new Address();
		// Set address using setter method to ensure correct input  
		this->address->Set_House(address->G_House());
		this->address->Set_street(address->G_Street());
		this->address->Set_City(address->G_City());
		this->address->Set_Country(address->G_Country());
	}
	catch (bad_alloc be)
	{
		cout << "In the bad_alloc exception"
			<< "Block: " << be.what() << endl;
	}
}


Contact::~Contact()
{
	delete address;
	id--;
}

int Contact::getId()
{
	return id;
}
/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/
// Getter and setter definitions
string Contact::First_Name() const
{
	return first_name;
}

void Contact::Set_First_Name(const string& newFirstName)
{
	if (!newFirstName.empty()) {
		first_name = newFirstName;
	}
}

string Contact::LastName() const {
	return last_name;
}

void Contact::Set_Last_Name(const string& newLastName) {
	if (!newLastName.empty()) {
		last_name = newLastName;
	}
}

string Contact::Mobile_Number() const {
	return mobile_number;
}

void Contact::Set_Mobile_Number(const string& newMobileNumber)
{
	if (newMobileNumber.size() == 11)
	{
		mobile_number = newMobileNumber;
	}
	else
		cout << "\nPLease Enter Mobile Number of 11 digit!!\n";
}

string Contact::Email_Address() const {
	return email_address;
}

void Contact::Set_Email_Address(const string& newEmailAddress) {
	email_address = newEmailAddress;
}

Address* Contact::G_Address() const {
	return address;
}

void Contact::Set_Address(Address* newAddress) {
	if (newAddress == nullptr) { return; }
	address = new Address;
	if (newAddress != nullptr) {
		address->Set_House(newAddress->G_House());
		address->Set_street(newAddress->G_Street());
		address->Set_City(newAddress->G_City());
		address->Set_Country(newAddress->G_Country());
	}
}


/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(const Contact& contact)
{
	// Compare all attributes
	return (first_name == contact.first_name &&
		last_name == contact.last_name &&
		mobile_number == contact.mobile_number &&
		email_address == contact.email_address &&
		(address != nullptr && contact.address != nullptr ? address->equals(*(contact.address)) : false));
}

Contact* Contact::copy_contact()
{
	// Create a new Contact object with copied attributes
	Contact* copiedContact = new Contact(first_name, last_name, mobile_number, email_address, nullptr);
	// If address exists, create a new Address object with copied values
	if (address != nullptr) {
		Address* copiedAddress = new Address(address->G_House(), address->G_Street(), address->G_City(), address->G_Country());
		copiedContact->Set_Address(copiedAddress);
	}
	return copiedContact;
}
void Contact::Display_contact()
{
	cout << "Contact ID: " << getId() << endl;
	cout << "First Name: " << first_name << endl;
	cout << "Last Name: " << last_name << endl;
	cout << "Mobile Number: " << mobile_number << endl;
	cout << "Email Address: " << email_address << endl;
	cout << "Address:" << endl;
	address->Display_address();
}
void Contact::update_contact_information()
{
	int choice;
	string update_val;
	cout << "1.First Name " << endl;
	cout << "2.Last Name " << endl;
	cout << "3.Mobile Number " << endl;
	cout << "4.Email Address " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter First Name : ";
		getline(cin, update_val);
		Set_First_Name(update_val);
		break;
	case 2:
		cout << "Enter Last Name : ";
		getline(cin, update_val);
		Set_Last_Name(update_val);
		break;
	case 3:
		cout << "Enter Mobile Number : ";
		getline(cin, update_val);
		Set_Mobile_Number(update_val);
		break;
	case 4:
		cout << "Enter Email Address : ";
		getline(cin, update_val);
		Set_Email_Address(update_val);
		break;
	default:
		cout << "Invalid Input!!!" << endl;
		break;
	}
}