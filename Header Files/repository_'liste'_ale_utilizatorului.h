#pragma once
#include <map>
#include <string>
#include "TAD_multime_ordonata---ABC.h"

class RepoForUser {
private:
	int id_user;
	MultimeOrdonata<int> lista_prieteni;
	map<int, vector<string>> mesaje_primite;
	map<int, vector<string>> mesaje_trimise;

public:
	//constructori si destructor
	RepoForUser();
	RepoForUser(int id);
	RepoForUser(int id, MultimeOrdonata<int>& lista_prieteni_, 
		map<int, vector<string>>& mesaje_primite_, 
		map<int, vector<string>>& mesaje_trimise_);
	~RepoForUser() = default;

	/// <summary>
	/// Adauga id-ul unui prieten in lista de prieteni
	/// </summary>
	/// <param name="id"> id-ul prietenului </param>
	/// <returns>
	/// --> 0 daca id-ul este identic cu al utilizatorului sau daca id-ul prietenului se afla deja in lista
	/// --> 1 altfel
	/// </returns>
	int addFriend(int id);

	/// <summary>
	/// Sterge id-ul unui prieten din lista de prieteni
	/// </summary>
	/// <param name="id"> id-ul prietenului </param>
	/// <returns>
	/// --> 0 daca nu exista in lista id-ul dat
	/// --> 1 altfel
	/// </returns>
	int removeFriend(int id);

	/// <summary>
	/// Adauga in lista mesajelor primite mesajul si id-ul prietenului care l-a trimis
	/// </summary>
	/// <param name="id_de_la_cine"> id-ul prietenului care a trimis mesajul </param>
	/// <param name="mesaj"> mesajul </param>
	void addReceivedMessage(int id_de_la_cine, string mesaj);

	/// <summary>
	/// Sterge din lista mesajelor primite mesajul si id-ul prietenului care l-a trimis
	/// </summary>
	/// <param name="id_de_la_cine"> id-ul prietenului care a trimis mesajul </param>
	/// <param name="poz"> pozitia pe care se afla mesajul de sters in lista </param>
	/// <returns>
	/// --> 0 daca pozitia e invalida sau daca nu exista in lista un mesaj primit de la utilizatorul cu id-ul dat
	/// --> 1 altfel
	/// </returns>
	int removeReceivedMessage(int id_de_la_cine, int poz);

	/// <summary>
	/// Adauga in lista mesajelor trimise mesajul si id-ul prietenului catre care este trimis 
	/// </summary>
	/// <param name="id_catre_cine"> id-ul prietenului catre care se trimite mesajul </param>
	/// <param name="mesaj"> mesajul </param>
	void addSentMessage(int id_catre_cine, string mesaj);

	/// <summary>
	/// Sterge din lista mesajelor trimise mesajul si id-ul prietenului catre care a fost trimis 
	/// </summary>
	/// <param name="id_catre_cine"> id-ul prietenului catre care a fost trimis mesajul </param>
	/// <param name="poz"> pozitia pe care se afla mesajul de sters in lista </param>
	/// <returns> 
	/// --> 0 daca pozitia e invalida sau daca nu exista in lista un mesaj trimis catre utilizatorul cu id-ul dat
	/// --> 1 altfel
	/// </returns>
	int removeSentMessaje(int id_catre_cine, int poz);

	//getteri
	int getIdUtilizator();
	MultimeOrdonata<int> getListaPrieteni();
	map<int, vector<string>> getMesajePrimite();
	map<int, vector<string>> getMesajeTrimise();
	int getNrPrieteni();
	int getNrMsjPrm();
	int getNrMsjTrm();

	//overload la operatori
	RepoForUser& operator=(RepoForUser& other);
	bool operator==(RepoForUser& other);
};