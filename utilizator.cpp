#include "utilizator.h"

Utilizator::Utilizator()
{
	this->id = -1;
	this->nume = "";
	this->varsta = 0;
	this->oras = "";
}

Utilizator::Utilizator(int id_, string nume_, int varsta_, string oras_)
{
	this->id = id_;
	this->nume = nume_;
	this->varsta = varsta_;
	this->oras = oras_;
}

Utilizator::Utilizator(const Utilizator& other)
{
	this->id = other.id;
	this->nume = other.nume;
	this->varsta = other.varsta;
	this->oras = other.oras;
	this->lista_prieteni = other.lista_prieteni;
	this->mesaje_primite = other.mesaje_primite;
	this->mesaje_trimise = other.mesaje_trimise;
}

void Utilizator::setId(int id_)
{
	this->id = id_;
}

void Utilizator::setNume(string nume_)
{
	this->nume = nume_;
}

void Utilizator::setVarsta(int varsta_)
{
	this->varsta = varsta_;
}

void Utilizator::setOras(string oras_)
{
	this->oras = oras_;
}

int Utilizator::addFriend(int id_)
{
	return 0;
}

int Utilizator::removeFriend(int id_)
{
	return 0;
}

int Utilizator::getId()
{
	return this->id;
}

string Utilizator::getNume()
{
	return this->nume;
}

int Utilizator::getVarsta()
{
	return this->varsta;
}

string Utilizator::getOras()
{
	return this->oras;
}

vector<int> Utilizator::getListaPrieteni()
{
	return this->lista_prieteni;
}

map<int, string> Utilizator::getMesajePrimite()
{
	return this->mesaje_primite;
}

map<int, string> Utilizator::getMesajeTrimise()
{
	return this->mesaje_trimise;
}

int Utilizator::getNrPrieteni()
{
	return this->lista_prieteni.size();
}

int Utilizator::getNrMsjPrm()
{
	return this->mesaje_primite.size();
}

int Utilizator::getNrMsjTrm()
{
	return this->mesaje_trimise.size();
}

Utilizator& Utilizator::operator=(const Utilizator& other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->nume = other.nume;
		this->varsta = other.varsta;
		this->oras = other.oras;
		this->lista_prieteni = other.lista_prieteni;
		this->mesaje_primite = other.mesaje_primite;
		this->mesaje_trimise = other.mesaje_trimise;
	}
	return *this;
}

bool Utilizator::operator==(const Utilizator& other)
{
	return this->id == other.id && this->nume == other.nume 
		&& this->varsta == other.varsta && this->oras == other.oras;
}

bool Utilizator::operator>(const Utilizator& other)
{
	return this->nume > other.nume;
}

bool Utilizator::operator<(const Utilizator& other)
{
	return this->nume < other.nume;
}
