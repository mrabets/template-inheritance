#pragma once
#include "Stationary.h"
class Monoblock : public Stationary
{
public:
	Monoblock();
	Monoblock(string standColour, int powerSupply, string model);
	Monoblock(const Monoblock& object);
	~Monoblock();

	string getStandColour() const;
	void setStandColour(string standColour);

	friend bool operator<(const Monoblock& first, const Monoblock& second);
	friend bool operator==(const Monoblock& first, const Monoblock& second);

	friend istream& operator >> (istream& in, Monoblock& obj);
	friend ostream& operator << (ostream& os, const Monoblock& obj);

	friend fstream& operator<<(fstream& out, Monoblock& obj);
	friend fstream& operator>>(fstream& in, Monoblock& obj);

	friend ofstream& operator<<(ofstream& out, Monoblock& obj);
	friend ifstream& operator>>(ifstream& in, Monoblock& obj);
private:
	string standColour;
};
