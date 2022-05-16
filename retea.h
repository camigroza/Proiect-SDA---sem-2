#pragma once
#include "utilizator.h"
#include "prietenie.h"
#include "TAD_lista---array.h"

class Retea {
private:
	TADLista<Utilizator> users;
	TADLista<Prietenie> friendships;

public:
	Retea();
	Retea(TADLista<Utilizator>& users_, TADLista<Prietenie>& friendships_);
	Retea(const Retea& other);
	~Retea() = default;

	int addUser(const Utilizator& u);
	int removeUser(const Utilizator& u);
	int modifyUser(const Utilizator& u_vechi, const Utilizator& u_nou);

	int addFriendship(Prietenie& p);
	int removeFriendship(Prietenie& p);

	TADLista<Utilizator> getUsers();
	TADLista<Prietenie> getFriendships();

	bool existsUser(const Utilizator& u);
	bool existsFriendship(const Prietenie& p);

	Retea& operator=(Retea& other);
	bool operator==(const Retea& other);

	int findPosUserById(int id_);
};