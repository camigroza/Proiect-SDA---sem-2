#include "mesaj.h"
#include <iostream>
using namespace std;

Mesaj::Mesaj()
{
	this->id_expeditor = -1;
	this->id_destinatar = -1;
	this->mesaj = "";
}

Mesaj::Mesaj(int id_exp, int id_dest, string mesaj_)
{
	this->id_expeditor = id_exp;
	this->id_destinatar = id_dest;
	this->mesaj = mesaj_;
}

Mesaj::Mesaj(const Mesaj& other)
{
	this->id_expeditor = other.id_expeditor;
	this->id_destinatar = other.id_destinatar;
	this->mesaj = other.mesaj;
}

void Mesaj::setIdExpeditor(int id)
{
	this->id_expeditor = id;
}

void Mesaj::setIdDestinatar(int id)
{
	this->id_destinatar = id;
}

void Mesaj::setMesaj(string mesaj_)
{
	this->mesaj = mesaj_;
}

int Mesaj::getIdExpeditor()
{
	return this->id_expeditor;
}

int Mesaj::getIdDestinatar()
{
	return this->id_destinatar;
}

string Mesaj::getMesaj()
{
	return this->mesaj;
}

Mesaj& Mesaj::operator=(const Mesaj& other)
{
	if (this != &other)
	{
		this->id_expeditor = other.id_expeditor;
		this->id_destinatar = other.id_destinatar;
		this->mesaj = other.mesaj;
	}
	return *this;
}

bool Mesaj::operator==(const Mesaj& other)
{
	return this->id_expeditor == other.id_expeditor && 
		this->id_destinatar == other.id_destinatar && this->mesaj == other.mesaj;
}

ostream& operator<<(ostream& os, const Mesaj& m)
{
	os << m.id_expeditor << " - " << m.id_destinatar << ": " << m.mesaj;
	return os;
}
