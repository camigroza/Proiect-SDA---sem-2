#include "tests.h"
#include "utilizator.h"
#include "prietenie.h"
#include "mesaj.h"
#include "eveniment.h"
#include "retea.h"
#include "TAD_lista---array.h"
#include "TAD_multime_ordonata---ABC.h"
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
	assert(u.getNrPrieteni() == 0);
	assert(u.getNrMsjPrm() == 0);
	assert(u.getNrMsjTrm() == 0);

	Utilizator u1(2, "Ferna", 19, "Aiud");
	assert(u1.getId() == 2);
	assert(u1.getNume() == "Ferna");
	assert(u1.getVarsta() == 19);
	assert(u1.getOras() == "Aiud");
	assert(u1.getNrPrieteni() == 0);
	assert(u1.getNrMsjPrm() == 0);
	assert(u1.getNrMsjTrm() == 0);
	u1.addFriend(1);
	assert(u1.getNrPrieteni() == 1);
	u1.addFriend(2);
	assert(u1.getNrPrieteni() == 1);
	u1.addFriend(3);
	assert(u1.getNrPrieteni() == 2);
	assert(u1.getListaPrieteni()[0] == 1);
	assert(u1.getListaPrieteni()[1] == 3);
	assert(u1.removeFriend(2) == 0);
	u1.removeFriend(1);
	assert(u1.getNrPrieteni() == 1);
	assert(u1.getListaPrieteni()[0] == 3);
	u1.removeFriend(3);
	assert(u1.getNrPrieteni() == 0);

	assert(u1.getNrMsjPrm() == 0);
	u1.addReceivedMessage(1, "super");
	assert(u1.getNrMsjPrm() == 1);
	u1.addReceivedMessage(1, "super x 2");
	assert(u1.getNrMsjPrm() == 2);
	assert(u1.getMesajePrimite()[1][0] == "super");
	assert(u1.getMesajePrimite()[1][1] == "super x 2");
	u1.addReceivedMessage(2, "superr");
	assert(u1.getNrMsjPrm() == 3);
	assert(u1.getMesajePrimite()[2][0] == "superr");

	assert(u1.getNrMsjTrm() == 0);
	u1.addSentMessage(2, "foarte super");
	assert(u1.getNrMsjTrm() == 1);
	u1.addSentMessage(2, "foarte super x 2");
	assert(u1.getNrMsjTrm() == 2);
	assert(u1.getMesajeTrimise()[2][0] == "foarte super");
	assert(u1.getMesajeTrimise()[2][1] == "foarte super x 2");
	u1.addSentMessage(3, "foarte superr");
	assert(u1.getNrMsjTrm() == 3);
	assert(u1.getMesajeTrimise()[3][0] == "foarte superr");

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

void test_eveniment()
{
	Eveniment e1;
	assert(e1.getIdUtilizator() == -1);
	assert(e1.getDataNasterii() == "");
	e1.setIdUtilizator(1);
	e1.setDataNasterii("16.06.2002");
	assert(e1.getIdUtilizator() == 1);
	assert(e1.getDataNasterii() == "16.06.2002");

	Eveniment e2(2, "12.07.1967");
	assert(e2.getIdUtilizator() == 2);
	assert(e2.getDataNasterii() == "12.07.1967");

	Eveniment e3(e2);
	assert(!(e3 == e1));
	assert(e3 == e2);

	Eveniment e4 = e1;
	assert(e1 == e4);
}

void test_retea()
{
	TADLista<Utilizator> lu;
	TADLista<Prietenie> lp;
	Utilizator u1(1, "Cami", 19, "Aiud");
	Utilizator u2(2, "Ferna", 19, "Aiud");
	Prietenie p1(1, 2);
	Retea r(lu, lp);

	r.addUser(u1);
	r.addFriendship(p1);
	r.addUser(u2);

	assert(r.getUsers()[0] == u1);
	assert(r.getUsers()[1] == u2);
	assert(r.getFriendships()[0] == p1);
}

void test_TADLista()
{
	TADLista<int> l;
	assert(l.size() == 0);
	l.add(1);
	l.add(2);

	TADLista<int> l1(l);
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

	TADLista<Prietenie> lp;
	Prietenie p1(1, 2);
	Prietenie p2(3, 4);
	lp.add(p1);
	assert(lp.exists(p1) == true);
	assert(lp.exists(p2) == false);
	lp.add(p2);
	assert(lp.exists(p2) == true);

	TADLista<Utilizator> lu;
	Utilizator u1(1, "Cami", 19, "Aiud");
	Utilizator u2(2, "Ferna", 19, "Aiud");
	lu.add(u1);
	lu.add(u2);
	lu.modify(u1, u2);
	assert(lu.exists(u1) == false);
	assert(lu.exists(u2) == true);
	assert(lu.modify(u1, u2) == 0);

	TADLista<Eveniment> le;
	Eveniment e1(1, "16.06.2002");
	Eveniment e2(2, "04.11.2002");
	le.add(e1);
	le.add(e2);
	assert(le[0] == e1);
	assert(le[1] == e2);
	le.modify(e1, e2);
	assert(le[0] == e2);
	assert(le[1] == e2);
	assert(le.exists(e1) == false);
	assert(le.modify(e1, e2) == 0);

	TADLista<Mesaj> lm;
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

	TADMultimeOrdonata<Utilizator> mm;
	mm.add(u1);
	mm.add(u2);

	TADMultimeOrdonata<Utilizator> mmm;
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

	TADMultimeOrdonata<Utilizator> mu;
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

	TADMultimeOrdonata<int> m1;
	m1.add(1);
	m1.add(2);
	m1.add(3);

	TADMultimeOrdonata<int> m;
	m.add(2);
	m.add(3);
	m.add(1);
	m.add(1);

	assert(m1 == m);
	TADMultimeOrdonata<int> m2;
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

void test_all()
{
	test_utilizator();
	test_prietenie();
	test_mesaj();
	test_eveniment();
	test_retea();
	test_TADLista();
	test_TADMultimeOrdonata();
	cout << "Toate testele au trecut cu succes!\n";
}