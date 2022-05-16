#include "repository_'liste'_ale_utilizatorului.h"

RepoForUser::RepoForUser()
{
	this->id_user = -1;
}

RepoForUser::RepoForUser(int id)
{
	this->id_user = id;
}

RepoForUser::RepoForUser(int id, TADMultimeOrdonata<int>& lista_prieteni_, map<int, vector<string>>& mesaje_primite_, map<int, vector<string>>& mesaje_trimise_)
{
	this->id_user = id;
	this->lista_prieteni = lista_prieteni_;
	this->mesaje_primite = mesaje_primite_;
	this->mesaje_trimise = mesaje_trimise_;
}

int RepoForUser::addFriend(int id)
{
	if (this->id_user == id)
		return 0;
	for (int i = 0; i < lista_prieteni.size(); i++)
		if (lista_prieteni[i] == id) return 0;
	lista_prieteni.add(id);
}

int RepoForUser::removeFriend(int id)
{
	return lista_prieteni.remove(id);
}

void RepoForUser::addReceivedMessage(int id_de_la_cine, string mesaj)
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

int RepoForUser::removeReceivedMessage(int id_de_la_cine, int poz)
{
	map<int, vector<string>>::iterator it;
	it = mesaje_primite.find(id_de_la_cine);
	if (it != mesaje_primite.end())
	{
		if (!(poz >= 0 && poz < it->second.size())) return 0;
		if (it->second.size() == 1) mesaje_primite.erase(it);
		else it->second.erase(it->second.begin() + poz);
		return 1;
	}
	return 0;
}

void RepoForUser::addSentMessage(int id_catre_cine, string mesaj)
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

int RepoForUser::removeSentMessaje(int id_catre_cine, int poz)
{
	map<int, vector<string>>::iterator it;
	it = mesaje_trimise.find(id_catre_cine);
	if (it != mesaje_trimise.end())
	{
		if (!(poz >= 0 && poz < it->second.size())) return 0;
		if (it->second.size() == 1) mesaje_trimise.erase(it);
		else it->second.erase(it->second.begin() + poz);
		return 1;
	}
	return 0;
}

int RepoForUser::getIdUtilizator()
{
	return this->id_user;
}

TADMultimeOrdonata<int> RepoForUser::getListaPrieteni()
{
	return this->lista_prieteni;
}

map<int, vector<string>> RepoForUser::getMesajePrimite()
{
	return this->mesaje_primite;
}

map<int, vector<string>> RepoForUser::getMesajeTrimise()
{
	return this->mesaje_trimise;
}

int RepoForUser::getNrPrieteni()
{
	return this->lista_prieteni.size();
}

int RepoForUser::getNrMsjPrm()
{
	int cate = 0;
	map<int, vector<string>>::iterator it;
	for (it = mesaje_primite.begin(); it != mesaje_primite.end(); it++)
		cate += it->second.size();
	return cate;
}

int RepoForUser::getNrMsjTrm()
{
	int cate = 0;
	map<int, vector<string>>::iterator it;
	for (it = mesaje_trimise.begin(); it != mesaje_trimise.end(); it++)
		cate += it->second.size();
	return cate;
}

RepoForUser& RepoForUser::operator=(RepoForUser& other)
{
	if (this != &other)
	{
		this->id_user = other.id_user;
		this->lista_prieteni = other.lista_prieteni;
		this->mesaje_primite = other.mesaje_primite;
		this->mesaje_trimise = other.mesaje_trimise;
	}
	return *this;
}

bool RepoForUser::operator==(RepoForUser& other)
{
	if (this->id_user != other.id_user) return false;
	if (!(this->lista_prieteni == other.lista_prieteni)) return false;
	if (this->getNrMsjPrm() != other.getNrMsjPrm()) return false;
	if (this->getNrMsjTrm() != other.getNrMsjTrm()) return false;
	return true;
}
