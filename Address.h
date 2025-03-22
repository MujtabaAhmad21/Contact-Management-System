#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Address
{
private:
	string house;
	string street;
	string city;
	string country;

public:
	bool equals(const Address& address);
	void Display_address();
	Address copyAddress();

	// Constructor
	Address(string house, string street, string city, string country);
	Address() {}

	// Getter and setter for house
	string G_House() const;
	void Set_House(const string& newHouse);

	// Getter and setter for street
	string G_Street() const;
	void Set_street(const string& newStreet);

	// Getter and setter for city
	string G_City() const;
	void Set_City(const string& newCity);

	// Getter and setter for country
	string G_Country() const;
	void Set_Country(const string& newCountry);

	bool operator==(const Address& other) const;
};
