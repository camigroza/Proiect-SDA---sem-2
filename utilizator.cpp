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

int Utilizator::addFriend(int id)
{
	if (this->id == id)
		return 0;
	for (int i = 0; i < lista_prieteni.size(); i++)
		if (lista_prieteni[i] == id) return 0;
	lista_prieteni.push_back(id);
}

int Utilizator::removeFriend(int id)
{
	vector<int>::iterator it = std::find(lista_prieteni.begin(), lista_prieteni.end(), id);
	if (it != lista_prieteni.end())
	{
		lista_prieteni.erase(it);
		return 1;
	}
	return 0;
}

void Utilizator::addReceivedMessage(int id_de_la_cine, string mesaj)
{
	map<int, vector<string>>::iterator it;
	it = mesaje_primite.find(id_de_la_cine);
	if (it != mesaje_primite.end())
		it->second.push_back(mesaj);
	else
	{
		vector<string> m;
		m.push_back(mesaj);
		mesaje_primite.insert(pair<int, vector<string>>(id_de_la_cine, m));
	}
}

void Utilizator::addSentMessage(int id_catre_cine, string mesaj)
{
	map<int, vector<string>>::iterator it;
	it = mesaje_trimise.find(id_catre_cine);
	if (it != mesaje_trimise.end())
		it->second.push_back(mesaj);
	else
	{
		vector<string> m;
		m.push_back(mesaj);
		mesaje_trimise.insert(pair<int, vector<string>>(id_catre_cine, m));
	}
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

map<int, vector<string>> Utilizator::getMesajePrimite()
{
	return this->mesaje_primite;
}

map<int, vector<string>> Utilizator::getMesajeTrimise()
{
	return this->mesaje_trimise;
}

int Utilizator::getNrPrieteni()
{
	return this->lista_prieteni.size();
}

int Utilizator::getNrMsjPrm()
{
	int cate = 0;
	map<int, vector<string>>::iterator it;
	for (it = mesaje_primite.begin(); it != mesaje_primite.end(); it++)
		cate += it->second.size();
	return cate;
}

int Utilizator::getNrMsjTrm()
{
	int cate = 0;
	map<int, vector<string>>::iterator it;
	for (it = mesaje_trimise.begin(); it != mesaje_trimise.end(); it++)
		cate += it->second.size();
	return cate;
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
