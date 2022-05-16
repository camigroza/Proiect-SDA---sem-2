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
	Utilizator();
	Utilizator(int id_, string nume_, int varsta_, string oras_);
	Utilizator(const Utilizator& other);
	~Utilizator() = default;

	void setId(int id_);
	void setNume(string nume_);
	void setVarsta(int varsta_);
	void setOras(string oras_);

	int getId();
	string getNume();
	int getVarsta();
	string getOras();

	Utilizator& operator=(const Utilizator& other);
	bool operator==(const Utilizator& other);
	bool operator>(const Utilizator& other);
	bool operator<(const Utilizator& other);
};