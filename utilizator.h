#pragma once
#include <vector>
#include <map>
#include <string>
#include "TAD_multime_ordonata---ABC.h"
using namespace std;

class Utilizator {
private:
	int id;
	string nume;
	int varsta;
	string oras;

public:
	//constructori si destructor
	Utilizator();
	Utilizator(int id_, string nume_, int varsta_, string oras_);
	Utilizator(const Utilizator& other);
	~Utilizator() = default;

	//setteri
	void setId(int id_);
	void setNume(string nume_);
	void setVarsta(int varsta_);
	void setOras(string oras_);

	//getteri
	int getId();
	string getNume();
	int getVarsta();
	string getOras();

	//overload la operatori
	Utilizator& operator=(const Utilizator& other);
	bool operator==(const Utilizator& other);
	bool operator>(const Utilizator& other);
	bool operator<(const Utilizator& other);
	friend ostream& operator<<(ostream& os, const Utilizator& u);
	friend istream& operator>>(istream& is, Utilizator& u);
};