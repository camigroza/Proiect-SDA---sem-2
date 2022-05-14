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
	~Retea() = default;

	void addUser(const Utilizator& u);
	int removeUser(const Utilizator& u);
	int modifyUser(const Utilizator& u_vechi, const Utilizator& u_nou);

	void addFriendship(const Prietenie& p);
	int removeFriendship(const Prietenie& p);
	int modifyFriendship(const Prietenie& p_veche, const Prietenie& p_noua);

	TADLista<Utilizator> getUsers();
	TADLista<Prietenie> getFriendships();

	Retea& operator=(Retea& other);
};