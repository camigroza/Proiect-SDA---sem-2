#pragma once
#include <map>
#include <string>
#include "TAD_multime_ordonata---ABC.h"

class RepoForUser {
private:
	int id_user;
	TADMultimeOrdonata<int> lista_prieteni;
	map<int, vector<string>> mesaje_primite;
	map<int, vector<string>> mesaje_trimise;

public:
	RepoForUser();
	RepoForUser(int id);
	RepoForUser(int id, TADMultimeOrdonata<int>& lista_prieteni_, 
		map<int, vector<string>>& mesaje_primite_, 
		map<int, vector<string>>& mesaje_trimise_);
	~RepoForUser() = default;

	int addFriend(int id);
	int removeFriend(int id);

	void addReceivedMessage(int id_de_la_cine, string mesaj);
	int removeReceivedMessage(int id_de_la_cine, int poz);
	void addSentMessage(int id_catre_cine, string mesaj);
	int removeSentMessaje(int id_catre_cine, int poz);

	int getIdUtilizator();
	TADMultimeOrdonata<int> getListaPrieteni();
	map<int, vector<string>> getMesajePrimite();
	map<int, vector<string>> getMesajeTrimise();

	int getNrPrieteni();
	int getNrMsjPrm();
	int getNrMsjTrm();

	RepoForUser& operator=(RepoForUser& other);
	bool operator==(RepoForUser& other);
};