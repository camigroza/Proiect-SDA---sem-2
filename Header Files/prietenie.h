#pragma once
#include <iostream>
using namespace std;

class Prietenie {
private:
	int id_utilizator_1;
	int id_utilizator_2;

public:
	//constructori si destructor
	Prietenie();
	Prietenie(int id1, int id2);
	Prietenie(const Prietenie& other);
	~Prietenie() = default;

	//setteri
	void setIdUtilizator1(int id1);
	void setIdUtilizator2(int id2);

	//getteri
	int getIdUtilizator1();
	int getIdUtilizator2();

	//overload la operatori
	Prietenie& operator=(const Prietenie& other);
	bool operator==(const Prietenie& other);
	friend ostream& operator<<(ostream& os, const Prietenie& p);
	friend istream& operator>>(istream& is, Prietenie& p);
};
