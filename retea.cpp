#include "retea.h"

Retea::Retea()
{
}

Retea::Retea(TADLista<Utilizator>& users_, TADLista<Prietenie>& friendships_)
{
	this->users = users_;
	this->friendships = friendships_;
}

void Retea::addUser(const Utilizator& u)
{
	this->users.add(u);
}

int Retea::removeUser(const Utilizator& u)
{
	return this->users.remove(u);
}

int Retea::modifyUser(const Utilizator& u_vechi, const Utilizator& u_nou)
{
	return this->users.modify(u_vechi, u_nou);
}

void Retea::addFriendship(const Prietenie& p)
{
	this->friendships.add(p);
}

int Retea::removeFriendship(const Prietenie& p)
{
	return this->friendships.remove(p);
}

int Retea::modifyFriendship(const Prietenie& p_veche, const Prietenie& p_noua)
{
	return this->friendships.modify(p_veche, p_noua);
}

TADLista<Utilizator> Retea::getUsers()
{
	return this->users;
}

TADLista<Prietenie> Retea::getFriendships()
{
	return this->friendships;
}

Retea& Retea::operator=(Retea& other)
{
	if (this != &other)
	{
		for (int i = 0; i < other.users.size(); i++)
			this->users.add(other.users[i]);
		for (int i = 0; i < other.friendships.size(); i++)
			this->friendships.add(other.friendships[i]);
	}
	return *this;
}
