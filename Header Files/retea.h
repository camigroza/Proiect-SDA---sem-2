#pragma once
#include "utilizator.h"
#include "prietenie.h"
#include "TAD_lista---array.h"

class Retea {
private:
	Lista<Utilizator> users;
	Lista<Prietenie> friendships;

public:
	//constructori si destructor
	Retea();
	Retea(Lista<Utilizator>& users_, Lista<Prietenie>& friendships_);
	Retea(const Retea& other);
	~Retea() = default;

	/// <summary>
	/// Adauga un utilizator
	/// </summary>
	/// <param name="u"> utilizatorul de adaugat </param>
	/// <returns>
	/// --> 0 daca exista deja utilizatorul dat in lista
	/// --> 1 altfel
	/// </returns>
	int addUser(const Utilizator& u);

	/// <summary>
	/// Sterge un utilizator
	/// </summary>
	/// <param name="u"> utilizatorul de sters </param>
	/// <returns>
	/// --> 0 daca nu exista in lista utilizatorul dat
	/// --> 1 altfel
	/// </returns>
	int removeUser(const Utilizator& u);

	/// <summary>
	/// Modifica un utilizator
	/// </summary>
	/// <param name="u_vechi"> utilizatorul de modificat </param>
	/// <param name="u_nou"> utilizatorul cu care se modifica </param>
	/// <returns>
	/// --> 0 daca nu exista utilizatorul vechi dat de modificat sau daca exista deja utilizatorul nou cu care se doreste sa se modifice
	/// --> 1 altfel
	/// </returns>
	int modifyUser(const Utilizator& u_vechi, const Utilizator& u_nou);

	/// <summary>
	/// Adauga o prietenie
	/// </summary>
	/// <param name="p"> prietenia de adaugat </param>
	/// <returns>
	/// --> 0 daca exista deja prietenia in lista sau daca nu exista cel putin unul dintre utlizatorii cu id-urile date
	/// --> 1 altfel
	/// </returns>
	int addFriendship(Prietenie& p);

	/// <summary>
	/// Sterge o prietenie
	/// </summary>
	/// <param name="p"> prietenia de sters </param>
	/// <returns>
	/// --> 0 daca nu exista prietenia in lista
	/// --> 1 altfel
	/// </returns>
	int removeFriendship(Prietenie& p);

	//getteri
	Lista<Utilizator> getUsers();
	Lista<Prietenie> getFriendships();

	/// <summary>
	/// Indica daca exista in lista un utilizator
	/// </summary>
	/// <param name="u"> utilizatorul dat </param>
	/// <returns> true daca exista, false in caz contrar </returns>
	bool existsUser(const Utilizator& u);

	/// <summary>
	/// Indica daca exista in lista o prietenie
	/// </summary>
	/// <param name="p"> prietenia data </param>
	/// <returns> true daca exista, false in caz contrar </returns>
	bool existsFriendship(const Prietenie& p);

	//overload la operatori
	Retea& operator=(Retea& other);
	bool operator==(const Retea& other);

	/// <summary>
	/// Indica pozitia in lista a utilizatorului cu id-ul dat
	/// </summary>
	/// <param name="id_"> id-ul utilizatorului </param>
	/// <returns> pozitia in lista daca acesta exista, -1 in caz contrar </returns>
	int findPosUserById(int id_);
};