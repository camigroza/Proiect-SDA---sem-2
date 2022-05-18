#pragma once
#include "repository_'liste'_ale_utilizatorului.h"
#include "retea.h"
#include "mesaj.h"

class Service {
private:
	Retea retea;
	vector<RepoForUser> repos_for_users;
	Lista<Mesaj> mesaje;

public:
	//constructori si destructor
	Service();
	Service(Retea& retea_, vector<RepoForUser>& repos_for_users_, Lista<Mesaj>& mesaje_);
	~Service() = default;

	//CRUD utilizator
	void addUser(int id, string nume, int varsta, string oras);
	void removeUser(int id);
	void modifyUser(int id, string nume_nou, int varsta_noua, string oras_nou);

	//CRUD prietenie
	void addFriendship(int id_1, int id_2);
	void removeFriendship(int id_1, int id_2);

	//CRUD mesaj
	void addMessage(int id_exp, int id_dest, string mesaj);
	void removeMessage(int id_exp, int id_dest, int poz_mesaj);

	/// <summary>
	/// Indica pozitia in lista a repository-ului specific unui utilizator cu un id anume
	/// </summary>
	/// <param name="id"> id-ul utilizatorului </param>
	/// <returns> pozitia repository-ului cautat </returns>
	int getPosRepoById(int id);

	/// <summary>
	/// Indica toti utilizatorii
	/// </summary>
	/// <returns> o lista cu toti utilizatorii </returns>
	Lista<Utilizator> getAllUsers();

	/// <summary>
	/// Indica toate prieteniile
	/// </summary>
	/// <returns> o lista cu toate prieteniile </returns>
	Lista<Prietenie> getAllFriendships();

	/// <summary>
	/// Indica toate mesajele
	/// </summary>
	/// <returns> o lista cu toate mesajele </returns>
	Lista<Mesaj> getAllMessages();

	/// <summary>
	/// Indica toate mesajele primite de un utilizator cu un anumit id
	/// </summary>
	/// <param name="id"> id-ul utilizatorului </param>
	/// <returns> un dictionar
	///			  {
	///				key: id-ul utilizatorului care a trimis mesajele
	///				value: vector cu toate mesajele
	///			  } 
	///  </returns>
	map<int, vector<string>> getAllReceivedMessages(int id);

	/// <summary>
	/// Indica toate mesajele trimise de un utilizator cu un anumit id
	/// </summary>
	/// <param name="id"> id-ul utilizatorului </param>
	/// <returns> un dictionar
	/// 		  {
	///				key: id-ul utilizatorului catre care au fost trimise mesajele
	///				value: vector cu toate mesajele
	///			  } 
	/// </returns>
	map<int, vector<string>> getAllSentMessages(int id);

	/// <summary>
	/// Indica toti prietenii unui utilizator cu un anumit id
	/// </summary>
	/// <param name="id"> id-ul utilizatorului </param>
	/// <returns> o lista cu toti prietenii </returns>
	Lista<Utilizator> getAllFriends(int id);

	/// <summary>
	/// Indica conversatia dintre doi utilizatori cu anumite id-uri
	/// </summary>
	/// <param name="id_1"> id-ul primului utilizator </param>
	/// <param name="id_2"> id-ul celui de-al doilea utilizator </param>
	/// <returns> o lista cu toate mesajele trimise unul altuia </returns>
	Lista<Mesaj> getChatBetweenTwoUsers(int id_1, int id_2);

	//overload la operator
	Service& operator=(Service& other);
};