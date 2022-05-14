#include "eveniment.h"

Eveniment::Eveniment()
{
	this->id_utilizator = -1;
	this->data_nasterii = "";
}

Eveniment::Eveniment(int id, string data)
{
	this->id_utilizator = id;
	this->data_nasterii = data;
}

Eveniment::Eveniment(const Eveniment& other)
{
	this->id_utilizator = other.id_utilizator;
	this->data_nasterii = other.data_nasterii;
}

void Eveniment::setIdUtilizator(int id)
{
	this->id_utilizator = id;
}

void Eveniment::setDataNasterii(string data)
{
	this->data_nasterii = data;
}

int Eveniment::getIdUtilizator()
{
	return this->id_utilizator;
}

string Eveniment::getDataNasterii()
{
	return this->data_nasterii;
}

Eveniment& Eveniment::operator=(const Eveniment& other)
{
	if (this != &other)
	{
		this->id_utilizator = other.id_utilizator;
		this->data_nasterii = other.data_nasterii;
	}
	return *this;
}

bool Eveniment::operator==(const Eveniment& other)
{
	return this->id_utilizator == other.id_utilizator && this->data_nasterii == other.data_nasterii;
}
