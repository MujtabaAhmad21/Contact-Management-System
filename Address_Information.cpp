#include "Address.h"
/*
*	Implement a constructor that initializes all the address parts
*
*/
Address::Address(string house, string street, string city, string country) : house(house), street(street), city(city), country(country)
{
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}
/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/
// Getter and setter definitions
string Address::G_House() const {
	return house;
}

void Address::Set_House(const string& newHouse) {
	house = newHouse;
}

string Address::G_Street() const {
	return street;
}

void Address::Set_street(const string& newStreet) {
	street = newStreet;
}

string Address::G_City() const {
	return city;
}

void Address::Set_City(const string& newCity) {
	city = newCity;
}

string Address::G_Country() const {
	return country;
}

void Address::Set_Country(const string& newCountry) {
	country = newCountry;
}

/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)
{
	return (house == address.house && street == address.street && city == address.city && country == address.country);
}

void Address::Display_address()
{
	cout << house << ", " << street << ", " << city << ", " << country << endl;
}

Address Address::copyAddress()
{
	return Address(house, street, city, country);
}
bool Address::operator==(const Address& other) const {
	return (house == other.house && street == other.street && city == other.city && country == other.country);
}

