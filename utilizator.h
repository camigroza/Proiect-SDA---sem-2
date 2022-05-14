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
	vector<int> lista_prieteni;
	map<int, vector<string>> mesaje_primite;
	map<int, vector<string>> mesaje_trimise;

public:
	Utilizator();
	Utilizator(int id_, string nume_, int varsta_, string oras_);
	Utilizator(const Utilizator& other);
	~Utilizator() = default;

	void setId(int id_);
	void setNume(string nume_);
	void setVarsta(int varsta_);
	void setOras(string oras_);

	int addFriend(int id);
	int removeFriend(int id);

	void addReceivedMessage(int id_de_la_cine, string mesaj);
	void addSentMessage(int id_catre_cine, string mesaj);

	int getId();
	string getNume();
	int getVarsta();
	string getOras();
	vector<int> getListaPrieteni();
	map<int, vector<string>> getMesajePrimite();
	map<int, vector<string>> getMesajeTrimise();

	int getNrPrieteni();
	int getNrMsjPrm();
	int getNrMsjTrm();

	Utilizator& operator=(const Utilizator& other);
	bool operator==(const Utilizator& other);
	bool operator>(const Utilizator& other);
	bool operator<(const Utilizator& other);

	/*TO DO 
		-> metoda care adauga un prieten
		-> metoda care adauga mesajele primite/trimise in dictionar*/
};