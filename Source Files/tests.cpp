#include "tests.h"
#include "utilizator.h"
#include "prietenie.h"
#include "mesaj.h"
#include "retea.h"
#include "TAD_lista---array.h"
#include "TAD_multime_ordonata---ABC.h"
#include "repository_'liste'_ale_utilizatorului.h"
#include "service.h"
#include "ABCNode.h"
#include <assert.h>
#include <iostream>
using namespace std;

void test_utilizator()
{
	Utilizator u;
	assert(u.getId() == -1);
	assert(u.getNume() == "");
	assert(u.getVarsta() == 0);
	assert(u.getOras() == "");
	u.setId(1);
	u.setNume("Cami");
	u.setVarsta(19);
	u.setOras("Aiud");
	assert(u.getId() == 1);
	assert(u.getNume() == "Cami");
	assert(u.getVarsta() == 19);
	assert(u.getOras() == "Aiud");

	Utilizator u1(2, "Ferna", 19, "Aiud");
	assert(u1.getId() == 2);
	assert(u1.getNume() == "Ferna");
	assert(u1.getVarsta() == 19);
	assert(u1.getOras() == "Aiud");

	Utilizator u2(u1);
	assert(!(u2 == u));
	assert(u2 == u1);

	Utilizator u3 = u;
	assert(!(u3 == u1));
	assert(u3 == u);

	assert(u < u1);
	assert(!(u > u1));
}

void test_prietenie()
{
	Prietenie p;
	assert(p.getIdUtilizator1() == -1);
	assert(p.getIdUtilizator2() == -1);
	p.setIdUtilizator1(1);
	p.setIdUtilizator2(2);
	assert(p.getIdUtilizator1() == 1);
	assert(p.getIdUtilizator2() == 2);

	Prietenie p1(3, 4);
	assert(p1.getIdUtilizator1() == 3);
	assert(p1.getIdUtilizator2() == 4);

	Prietenie p2(p);
	assert(!(p2 == p1));
	assert(p2 == p);

	Prietenie p3 = p1;
	assert(!(p3 == p));
	assert(p3 == p1);

	Prietenie p4(4, 3);
	assert(p1 == p4);
}

void test_mesaj()
{
	Mesaj m1;
	assert(m1.getIdExpeditor() == -1);
	assert(m1.getIdDestinatar() == -1);
	assert(m1.getMesaj() == "");
	m1.setIdExpeditor(1);
	m1.setIdDestinatar(2);
	m1.setMesaj("aaa");
	assert(m1.getIdExpeditor() == 1);
	assert(m1.getIdDestinatar() == 2);
	assert(m1.getMesaj() == "aaa");

	Mesaj m2(11, 22, "aaa");
	assert(!(m2 == m1));
	assert(m2.getIdExpeditor() == 11);
	assert(m2.getIdDestinatar() == 22);
	assert(m2.getMesaj() == "aaa");

	Mesaj m3(m2);
	assert(m3 == m2);

	Mesaj m4 = m2;
	assert(m4 == m3);
}

void test_retea()
{
	Lista<Utilizator> lu;
	Lista<Prietenie> lp;
	Utilizator u1(1, "Cami", 19, "Aiud");
	Utilizator u2(2, "Ferna", 19, "Aiud");
	Prietenie p1(1, 2);
	Prietenie p2(3, 4);
	Retea r(lu, lp);

	assert(r.existsUser(u2) == false);
	assert(r.existsFriendship(p1) == false);
	r.addUser(u1);
	r.addUser(u2);
	r.addFriendship(p1);
	assert(r.findPosUserById(1) == 0);
	assert(r.findPosUserById(2) == 1);

	assert(r.existsUser(u2) == true);
	assert(r.existsFriendship(p1) == true);

	Retea r1(r);
	Retea r2;
	r2 = r1;
	assert(r2 == r);
	assert(r1 == r);

	assert(r.getUsers()[0] == u1);
	assert(r.getUsers()[1] == u2);
	assert(r.getFriendships()[0] == p1);

	r.removeUser(u1);
	assert(r.existsUser(u1) == false);
	r.removeFriendship(p1);
	assert(r.existsFriendship(p1) == false);
	assert(r.modifyUser(u1, u2) == 0);
	r.addFriendship(p1);
	r.modifyUser(u2, u1);
	assert(r.existsUser(u1) == true);
	assert(r.existsUser(u2) == false);
}

void test_TADLista()
{
	Lista<int> l;
	assert(l.size() == 0);
	l.add(1);
	l.add(2);

	Lista<int> l1(l);
	assert(l1 == l);

	assert(l.size() == 2);
	assert(l.exists(1) == true);
	assert(l.exists(2) == true);
	assert(l.exists(4) == false);
	assert(l[0] == 1);
	assert(l[1] == 2);
	assert(l[0] == 1);
	assert(l[1] == 2);
	assert(l.searchPos(1) == 0);
	assert(l.searchPos(2) == 1);
	l.remove(2);
	assert(l.size() == 1);
	assert(l.exists(1) == true);
	assert(l.exists(2) == false);
	l.remove(1);
	assert(l.size() == 0);
	assert(l.exists(1) == false);
	assert(l.exists(2) == false);

	Lista<Prietenie> lp;
	Prietenie p1(1, 2);
	Prietenie p2(3, 4);
	lp.add(p1);
	assert(lp.exists(p1) == true);
	assert(lp.exists(p2) == false);
	lp.add(p2);
	assert(lp.exists(p2) == true);

	Lista<Utilizator> lu;
	Utilizator u1(1, "Cami", 19, "Aiud");
	Utilizator u2(2, "Ferna", 19, "Aiud");
	lu.add(u1);
	lu.modify(u1, u2);
	assert(lu.exists(u1) == false);
	assert(lu.exists(u2) == true);
	assert(lu.modify(u1, u2) == 0);
	lu.add(u1);

	Lista<Mesaj> lm;
	Mesaj m1(1, 2, "aaa");
	Mesaj m2(3, 4, "bbb");
	lm.add(m1);
	lm.add(m2);
}

void test_TADMultimeOrdonata()
{
	Utilizator u1(1, "Cami1", 19, "Aiud1");
	Utilizator u2(2, "Cami2", 19, "Aiud2");
	Utilizator u3(3, "Cami3", 19, "Aiud3");

	ABCNode<Prietenie> nn;
	ABCNode<int> n(1);
	ABCNode<Utilizator> nu1(u1);
	ABCNode<Utilizator> nu2(u2);
	ABCNode<Utilizator> nu3(u3, &nu1, &nu2);
	ABCNode<Utilizator> aux(u2);
	aux = nu3;
	assert(aux == nu3);

	MultimeOrdonata<Utilizator> mm;
	mm.add(u1);
	mm.add(u2);

	MultimeOrdonata<Utilizator> mmm;
	mmm = mm;
	assert(mmm == mm);

	assert(mm[0] == u1);
	assert(mm[1] == u2);
	mm.modify(u1, u3);
	assert(mm.exists(u1) == false);
	assert(mm.exists(u2) == true);
	assert(mm.exists(u3) == true);
	assert(mm[0] == u2);
	assert(mm[1] == u3);
	assert(mm.modify(u1, u2) == 0);
	assert(mm.modify(u2, u3) == 0);

	MultimeOrdonata<Utilizator> mu;
	assert(mu.size() == 0);
	mu.add(u1);
	assert(mu.size() == 1);
	mu.add(u2);
	assert(mu.size() == 2);
	mu.add(u3);
	assert(mu.size() == 3);
	assert(mu[0] == u1);
	assert(mu[1] == u2);
	assert(mu[2] == u3);

	assert(mu[0] == u1);
	assert(mu[1] == u2);
	assert(mu[2] == u3);

	mu.remove(u1);
	assert(mu.size() == 2);
	assert(mu[0] == u2);
	assert(mu[1] == u3);
	mu.remove(u3);
	assert(mu.size() == 1);
	assert(mu[0] == u2);
	mu.remove(u2);
	assert(mu.size() == 0);

	MultimeOrdonata<int> m1;
	m1.add(1);
	m1.add(2);
	m1.add(3);

	MultimeOrdonata<int> m;
	m.add(2);
	m.add(3);
	m.add(1);
	m.add(1);

	assert(m1 == m);
	MultimeOrdonata<int> m2;
	m2 = m;
	assert(m2 == m1);

	assert(m.size() == 3);
	assert(m[0] == 1);
	assert(m[1] == 2);
	assert(m[2] == 3);

	assert(m.searchPos(1) == 0);
	assert(m.searchPos(2) == 1);
	assert(m.searchPos(3) == 2);
	
	assert(m.exists(2) == true);
	assert(m.exists(5) == false);

	m.remove(3);
	m.remove(1);
	m.remove(2);
	m.remove(2);
}

void test_RepoForUser()
{
	RepoForUser r;
	assert(r.getIdUtilizator() == -1);
	assert(r.getNrPrieteni() == 0);
	assert(r.getNrMsjPrm() == 0);
	assert(r.getNrMsjTrm() == 0);

	RepoForUser r1(1);
	assert(r1.getIdUtilizator() == 1);
	assert(r1.getNrPrieteni() == 0);
	assert(r1.getNrMsjPrm() == 0);
	assert(r1.getNrMsjTrm() == 0);

	r1.addFriend(1);
	r1.addFriend(2);
	r1.addFriend(3);
	assert(r1.getNrPrieteni() == 2);
	assert(r1.getListaPrieteni()[0] == 2);
	assert(r1.getListaPrieteni()[1] == 3);

	assert(r1.removeFriend(4) == 0);
	assert(r1.removeFriend(1) == 0);
	r1.removeFriend(2);
	assert(r1.getNrPrieteni() == 1);
	assert(r1.getListaPrieteni()[0] == 3);

	r1.addReceivedMessage(2, "super");
	r1.addReceivedMessage(2, "super x 2");
	r1.addReceivedMessage(3, "tare");
	assert(r1.getNrMsjPrm() == 3);
	assert(r1.getMesajePrimite()[2][0] == "super");
	assert(r1.getMesajePrimite()[2][1] == "super x 2");
	assert(r1.getMesajePrimite()[3][0] == "tare");

	r1.removeReceivedMessage(2, 0);
	assert(r1.removeReceivedMessage(5, 0) == 0);
	assert(r1.removeReceivedMessage(2, 5) == 0);
	assert(r1.getNrMsjPrm() == 2);
	assert(r1.getMesajePrimite()[2][0] == "super x 2");
	assert(r1.removeReceivedMessage(2, 1) == 0);
	r1.removeReceivedMessage(2, 0);
	assert(r1.getNrMsjPrm() == 1);
	r1.removeReceivedMessage(3, 0);
	assert(r1.getNrMsjPrm() == 0);

	r1.addSentMessage(3, "wow");
	r1.addSentMessage(3, "wow x 2");
	r1.addSentMessage(4, "miau");
	assert(r1.getNrMsjTrm() == 3);
	assert(r1.getMesajeTrimise()[3][0] == "wow");
	assert(r1.getMesajeTrimise()[3][1] == "wow x 2");
	assert(r1.getMesajeTrimise()[4][0] == "miau");

	assert(r1.removeSentMessaje(1, 3) == 0);
	assert(r1.removeSentMessaje(3, 3) == 0);
	r1.removeSentMessaje(3, 1);
	assert(r1.getNrMsjTrm() == 2);
	assert(r1.getMesajeTrimise()[3][0] == "wow");
	assert(r1.removeSentMessaje(3, 1) == 0);
	r1.removeSentMessaje(3, 0);
	assert(r1.getNrMsjTrm() == 1);
	r1.removeSentMessaje(4, 0);
	assert(r1.getNrMsjTrm() == 0);

	RepoForUser r3(r1);
	RepoForUser r4;
	r4 = r1;
	assert(r3 == r4);

	MultimeOrdonata<int> m;
	m.add(1);
	vector<string> v1;
	v1.push_back("aaa");
	vector<string> v11;
	v11.push_back("AAA");
	vector<string> v2;
	v2.push_back("bbb");
	vector<string> v22;
	v22.push_back("BBB");
	vector<string> v222;
	v222.push_back("bBb");
	map<int, vector<string>> mp;
	mp.insert(pair<int, vector<string>>(1, v1));
	mp.insert(pair<int, vector<string>>(11, v11));
	map<int, vector<string>> mt;
	mt.insert(pair<int, vector<string>>(2, v2));
	mt.insert(pair<int, vector<string>>(22, v22));
	mt.insert(pair<int, vector<string>>(222, v222));
	RepoForUser r2(2, m, mp, mt);
	assert(r2.getIdUtilizator() == 2);
	assert(r2.getListaPrieteni() == m);
	assert(r2.getMesajePrimite() == mp);
	assert(r2.getMesajeTrimise() == mt);
	assert(r2.getNrPrieteni() == 1);
	assert(r2.getNrMsjPrm() == 2);
	assert(r2.getNrMsjTrm() == 3);
}

void test_service()
{
	Service ssss;
	
	RepoForUser r(1);
	r.addFriend(2);
	r.addReceivedMessage(2, "hei");
	r.addSentMessage(2, "hei back");
	RepoForUser r1(3);
	r1.addFriend(2);
	r1.addReceivedMessage(2, "hei");
	r1.addSentMessage(2, "hei back");
	vector<RepoForUser> v;
	v.push_back(r);
	v.push_back(r1);
	Retea rr;
	rr.addUser(Utilizator(1, "Cami", 19, "Aiud"));
	rr.addUser(Utilizator(2, "Camii", 19, "Aiud"));
	Prietenie p(1, 2);
	rr.addFriendship(p);
	Lista<Mesaj> lm;
	lm.add(Mesaj(1, 2, "hei"));
	lm.add(Mesaj(2, 1, "hei back"));
	Service ss(rr, v, lm);

	Service sss;
	sss = ss;

	assert(ss.getPosRepoById(1) == 0);
	assert(ss.getPosRepoById(2) == -1);
	assert(ss.getPosRepoById(3) == 1);
	ss.addUser(2, "Ariana", 19, "Aiud");
	assert(ss.getPosRepoById(2) == 2);
	ss.removeUser(1);
	assert(ss.getPosRepoById(1) == -1);
	assert(ss.getPosRepoById(3) == 0);
	assert(ss.getPosRepoById(2) == 1);
	ss.modifyUser(2, "Iulia", 19, "Cluj");
}

void test_all()
{
	test_utilizator();
	test_prietenie();
	test_mesaj();
	test_retea();
	test_TADLista();
	test_TADMultimeOrdonata();
	test_RepoForUser();
	test_service();
	cout << " Toate testele au trecut cu succes!\n\n";
}