#pragma once
#include "service.h"

class UI {
private:
	Service service;
	void menuUsers();
	void ui_adauga_utilizator();
	void ui_sterge_utilizator();
	void ui_modifica_utilizator();
	void menuFriendships();
	void ui_adauga_prietenie();
	void ui_sterge_prietenie();
	void menuMessages();
	void ui_adauga_mesaj();
	void ui_sterge_mesaj();
	void ui_afiseaza_toti_utilizatorii();
	void ui_afiseaza_toate_prieteniile();
	void ui_afiseaza_toate_mesajele();
	void ui_afiseaza_toti_prietenii_unui_utilizator();
	void ui_afiseaza_mesaje_trimise_de_un_utilizator();
	void ui_afiseaza_mesaje_primite_de_un_utilizator();
	void ui_afiseaza_conversatie();

public:
	//constructori si destructor
	UI();
	UI(Service& service_);
	~UI() = default;

	/// <summary>
	/// Afiseaza meniul
	/// </summary>
	void runMenu();
};