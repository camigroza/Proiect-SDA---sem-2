#include "prietenie.h"

Prietenie::Prietenie()
{
	this->id_utilizator_1 = -1;
	this->id_utilizator_2 = -1;
}

Prietenie::Prietenie(int id1, int id2)
{
	this->id_utilizator_1 = id1;
	this->id_utilizator_2 = id2;
}

Prietenie::Prietenie(const Prietenie& other)
{
	this->id_utilizator_1 = other.id_utilizator_1;
	this->id_utilizator_2 = other.id_utilizator_2;
}

void Prietenie::setIdUtilizator1(int id1)
{
	this->id_utilizator_1 = id1;
}

void Prietenie::setIdUtilizator2(int id2)
{
	this->id_utilizator_2 = id2;
}

int Prietenie::getIdUtilizator1()
{
	return this->id_utilizator_1;
}

int Prietenie::getIdUtilizator2()
{
	return this->id_utilizator_2;
}

Prietenie& Prietenie::operator=(const Prietenie& other)
{
	if (this != &other)
	{
		this->id_utilizator_1 = other.id_utilizator_1;
		this->id_utilizator_2 = other.id_utilizator_2;
	}
	return *this;
}

bool Prietenie::operator==(const Prietenie& other)
{
	return (this->id_utilizator_1 == other.id_utilizator_1 && this->id_utilizator_2 == other.id_utilizator_2) ||
		(this->id_utilizator_1 == other.id_utilizator_2 && this->id_utilizator_2 == other.id_utilizator_1);
}

ostream& operator<<(ostream& os, const Prietenie& p)
{
	os << "Prietenie intre utilizatorul cu id-ul '" << p.id_utilizator_1 << "' si utilizatorul cu id-ul '" << p.id_utilizator_2 << "'";
	return os;
}

istream& operator>>(istream& is, Prietenie& p)
{
	cout << " Dati id-ul primului prieten: ";
	int id_1;
	is >> id_1;
	cout << " Dati id-ul celui de-al doilea prieten: ";
	int id_2;
	is >> id_2;
	p.setIdUtilizator1(id_1);
	p.setIdUtilizator2(id_2);
	return is;
}
