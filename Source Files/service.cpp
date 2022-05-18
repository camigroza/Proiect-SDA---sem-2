#include "service.h"

Service::Service()
{
}

Service::Service(Retea& retea_, vector<RepoForUser>& repos_for_users_, Lista<Mesaj>& mesaje_)
{
	this->retea = retea_;
	for (int i = 0; i < repos_for_users_.size(); i++)
		this->repos_for_users.push_back(repos_for_users_[i]);
	this->mesaje = mesaje_;
}

void Service::addUser(int id, string nume, int varsta, string oras)
{
	Utilizator u(id, nume, varsta, oras);
	if (this->retea.addUser(u) == 1)
	{
		if (getPosRepoById(id) == -1)
			this->repos_for_users.push_back(RepoForUser(id));
	}
}

void Service::removeUser(int id)
{
	int poz = this->retea.findPosUserById(id);
	if (poz != -1)
	{
		Utilizator u = this->retea.getUsers()[poz];
		this->retea.removeUser(u);
		int poz_repo = getPosRepoById(id);
		for (int i = poz_repo; i < repos_for_users.size() - 1; i++)
			repos_for_users[i] = repos_for_users[i + 1];
		repos_for_users.pop_back();
	}
}

void Service::modifyUser(int id, string nume_nou, int varsta_noua, string oras_nou)
{
	int poz = this->retea.findPosUserById(id);
	if (poz != -1)
	{
		Utilizator u_vechi = this->retea.getUsers()[poz];
		Utilizator u_nou(id, nume_nou, varsta_noua, oras_nou);
		this->retea.modifyUser(u_vechi, u_nou);
	}
}

void Service::addFriendship(int id_1, int id_2)
{
	Prietenie p(id_1, id_2);
	if (this->retea.addFriendship(p) == 1)
	{
		int poz_repo_1 = getPosRepoById(id_1);
		int poz_repo_2 = getPosRepoById(id_2);
		repos_for_users[poz_repo_1].addFriend(id_2);
		repos_for_users[poz_repo_2].addFriend(id_1);
	}
}

void Service::removeFriendship(int id_1, int id_2)
{
	Prietenie p(id_1, id_2);
	if (this->retea.removeFriendship(p) == 1)
	{
		int poz_repo_1 = getPosRepoById(id_1);
		int poz_repo_2 = getPosRepoById(id_2);
		repos_for_users[poz_repo_1].removeFriend(id_2);
		repos_for_users[poz_repo_2].removeFriend(id_1);
	}
}

void Service::addMessage(int id_exp, int id_dest, string mesaj)
{
	Mesaj m(id_exp, id_dest, mesaj);
	this->mesaje.add(m);
	int poz_repo_exp = this->getPosRepoById(id_exp);
	int poz_repo_dest = this->getPosRepoById(id_dest);
	repos_for_users[poz_repo_exp].addSentMessage(id_dest, mesaj);
	repos_for_users[poz_repo_dest].addReceivedMessage(id_exp, mesaj);
}

void Service::removeMessage(int id_exp, int id_dest, int poz_mesaj)
{
	
}

int Service::getPosRepoById(int id)
{
	for (int i = 0; i < repos_for_users.size(); i++)
		if (id == repos_for_users[i].getIdUtilizator()) return i;
	return -1;
}

Lista<Utilizator> Service::getAllUsers()
{
	return this->retea.getUsers();
}

Lista<Prietenie> Service::getAllFriendships()
{
	return this->retea.getFriendships();
}

Lista<Mesaj> Service::getAllMessages()
{
	return this->mesaje;
}

map<int, vector<string>> Service::getAllReceivedMessages(int id)
{
	int poz = this->getPosRepoById(id);
	return repos_for_users[poz].getMesajePrimite();
}

map<int, vector<string>> Service::getAllSentMessages(int id)
{
	int poz = this->getPosRepoById(id);
	return repos_for_users[poz].getMesajeTrimise();
}

Lista<Utilizator> Service::getAllFriends(int id)
{
	Lista<Utilizator> all;
	int poz_repo = this->getPosRepoById(id);
	RepoForUser r = this->repos_for_users[poz_repo];
	MultimeOrdonata<int> p = r.getListaPrieteni();
	for (int i = 0; i < p.size(); i++)
	{
		int poz_user = this->retea.findPosUserById(p[i]);
		Utilizator u = this->retea.getUsers()[poz_user];
		all.add(u);
	}
	return all;
}

Lista<Mesaj> Service::getChatBetweenTwoUsers(int id_1, int id_2)
{
	Lista<Mesaj> rez;
	for (int i = 0; i < this->mesaje.size(); i++)
	{
		Mesaj m = this->mesaje[i];
		if ((m.getIdDestinatar() == id_1 && m.getIdExpeditor() == id_2) ||
			(m.getIdDestinatar() == id_2 && m.getIdExpeditor() == id_1)) rez.add(m);
	}
	return rez;
}

Service& Service::operator=(Service& other)
{
	if (this != &other)
	{
		this->retea = other.retea;
		for (int i = 0; i < other.repos_for_users.size(); i++)
			this->repos_for_users.push_back(other.repos_for_users[i]);
		this->mesaje = other.mesaje;
	}
	return *this;
}
