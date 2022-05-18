#include "retea.h"

Retea::Retea()
{
}

Retea::Retea(Lista<Utilizator>& users_, Lista<Prietenie>& friendships_)
{
	this->users = users_;
	this->friendships = friendships_;
}

Retea::Retea(const Retea& other)
{
	this->users = other.users;
	this->friendships = other.friendships;
}

int Retea::addUser(const Utilizator& u)
{
	if (this->existsUser(u)) return 0;
	this->users.add(u);
	return 1;
}

int Retea::removeUser(const Utilizator& u)
{
	return this->users.remove(u);
}

int Retea::modifyUser(const Utilizator& u_vechi, const Utilizator& u_nou)
{
	if (this->users.exists(u_nou))
		return 0;
	return this->users.modify(u_vechi, u_nou);
}
int Retea::addFriendship(Prietenie& p)
{
	if (p.getIdUtilizator1() == p.getIdUtilizator2()) return 0;
	if (this->existsFriendship(p)) return 0;
	int poz_1 = this->findPosUserById(p.getIdUtilizator1());
	int poz_2 = this->findPosUserById(p.getIdUtilizator2());
	if (poz_1 == -1 || poz_2 == -1) return 0;
	this->friendships.add(p);
	return 1;
}

int Retea::removeFriendship(Prietenie& p)
{
	return this->friendships.remove(p);
}

Lista<Utilizator> Retea::getUsers()
{
	return this->users;
}

Lista<Prietenie> Retea::getFriendships()
{
	return this->friendships;
}

bool Retea::existsUser(const Utilizator& u)
{
	return this->users.exists(u);
}

bool Retea::existsFriendship(const Prietenie& p)
{
	return this->friendships.exists(p);
}

Retea& Retea::operator=(Retea& other)
{
	if (this != &other)
	{
		this->users = other.users;
		this->friendships = other.friendships;
	}
	return *this;
}

bool Retea::operator==(const Retea& other)
{
	return this->users == other.users && this->friendships == other.friendships;
}

int Retea::findPosUserById(int id_)
{
	for (int i = 0; i < users.size(); i++)
		if (users[i].getId() == id_) return i;
	return -1;
}

