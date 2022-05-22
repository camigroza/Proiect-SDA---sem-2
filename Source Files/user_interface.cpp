#include "user_interface.h"
#include <iostream>
using namespace std;

void UI::menuUsers()
{
	string optiune;
	cout << endl;

	while (true)
	{
		cout << " 1. Adauga utilizator\n";
		cout << " 2. Sterge utilizator\n";
		cout << " 3. Modifica utilizator\n";
		cout << " x. Iesire\n";

		cout << " Dati optiunea: ";
		cin >> optiune;

		if (optiune == "1")
			this->ui_adauga_utilizator();
		else if (optiune == "2")
			this->ui_sterge_utilizator();
		else if (optiune == "3")
			this->ui_modifica_utilizator();
		else if (optiune == "x")
			break;
		else cout << "\tOptiune gresita! Reincercati: \n";

		cout << endl;
	}

}

void UI::ui_adauga_utilizator()
{
	Utilizator u;
	cin >> u;
	this->service.addUser(u.getId(), u.getNume(), u.getVarsta(), u.getOras());
}

void UI::ui_sterge_utilizator()
{
	cout << " Dati id-ul utilizatorului de sters: ";
	int id;
	cin >> id;
	this->service.removeUser(id);
}

void UI::ui_modifica_utilizator()
{
	cout << " Dati id-ul utilizatorului de modificat: ";
	int id;
	cin >> id;
	cin.get();
	cout << " Dati noul nume al utilizatorului: ";
	string nume;
	getline(cin, nume);
	cout << " Dati noua varsta a utilizatorului: ";
	int varsta;
	cin >> varsta;
	cin.get();
	cout << " Dati noul oras al utilizatorului: ";
	string oras;
	getline(cin, oras);
	this->service.modifyUser(id, nume, varsta, oras);
}

void UI::menuFriendships()
{
	string optiune;
	cout << endl;

	while (true)
	{
		cout << " 1. Adauga prietenie\n";
		cout << " 2. Sterge prietenie\n";
		cout << " x. Iesire\n";

		cout << " Dati optiunea: ";
		cin >> optiune;

		if (optiune == "1")
			this->ui_adauga_prietenie();
		else if (optiune == "2")
			this->ui_sterge_prietenie();
		else if (optiune == "x")
			break;
		else cout << "\tOptiune gresita! Reincercati: \n";

		cout << endl;
	}
}

void UI::ui_adauga_prietenie()
{
	Prietenie p;
	cin >> p;
	this->service.addFriendship(p.getIdUtilizator1(), p.getIdUtilizator2());
}

void UI::ui_sterge_prietenie()
{
	Prietenie p;
	cin >> p;
	this->service.removeFriendship(p.getIdUtilizator1(), p.getIdUtilizator2());
}

void UI::menuMessages()
{
	string optiune;
	cout << endl;

	while (true)
	{
		cout << " 1. Adauga mesaj\n";
		cout << " 2. Sterge mesaj\n";
		cout << " x. Iesire\n";

		cout << " Dati optiunea: ";
		cin >> optiune;

		if (optiune == "1")
			this->ui_adauga_mesaj();
		else if (optiune == "2")
			this->ui_sterge_mesaj();
		else if (optiune == "x")
			break;
		else cout << "\tOptiune gresita! Reincercati: \n";

		cout << endl;
	}
}

void UI::ui_adauga_mesaj()
{
	cout << " Dati id-ul utilizatorului care trimite mesajul: ";
	int id_1;
	cin >> id_1;
	if (this->service.getPosRepoById(id_1) == -1)
		cout << "\tNu exista un utilizator cu id-ul dat!\n";
	else
	{
		cout << " Dati id-ul utilizatorului care primeste mesajul: ";
		int id_2;
		cin >> id_2;
		if (this->service.getPosRepoById(id_2) == -1)
			cout << "\tNu exista un utilizator cu id-ul dat!\n";
		else
		{
			cin.get();
			cout << " Dati mesajul: ";
			string mesaj;
			getline(cin, mesaj);
			Mesaj m(id_1, id_2, mesaj);
			this->service.addMessage(id_1, id_2, mesaj);
		}
	}
}

void UI::ui_sterge_mesaj()
{
	cout << " Dati id-ul utilizatorului care a trimis mesajul: ";
	int id_1;
	cin >> id_1;
	if (this->service.getPosRepoById(id_1) == -1)
		cout << "\tNu exista un utilizator cu id-ul dat!\n";
	else
	{
		cout << " Dati id-ul utilizatorului catre care a fost trimis mesajul: ";
		int id_2;
		cin >> id_2;
		if (this->service.getPosRepoById(id_2) == -1)
			cout << "\tNu exista un utilizator cu id-ul dat!\n";
		else
		{
			cout << " Dati pozitia pe care se afla mesajul pe care doriti sa il stergeti: ";
			int poz;
			cin >> poz;
			vector<string> sm = this->service.getAllSentMessages(id_1)[id_2];
			if (!(poz >= 0 && poz < sm.size()))
				cout << "\tPozitia nu este valida!\n";
			else
				this->service.removeMessage(id_1, id_2, poz);
		}
	}
}

void UI::ui_afiseaza_toti_utilizatorii()
{
	Lista<Utilizator> all = this->service.getAllUsers();
	if (all.size() == 0)
		cout << "\tNu exista utilizatori!\n";
	else
		for (int i = 0; i < all.size(); i++) 
			cout << "\t" << all[i] << endl;
}

void UI::ui_afiseaza_toate_prieteniile()
{
	Lista<Prietenie> all = this->service.getAllFriendships();
	if (all.size() == 0)
		cout << "\tNu exista prietenii!\n";
	else
		for (int i = 0; i < all.size(); i++) 
			cout << "\t" << all[i] << endl;
}

void UI::ui_afiseaza_toate_mesajele()
{
	Lista<Mesaj> all = this->service.getAllMessages();
	if (all.size() == 0)
		cout << "\tNu exista mesaje!\n";
	else
		for (int i = 0; i < all.size(); i++)
			cout << "\t" << all[i] << endl;
}

void UI::ui_afiseaza_toti_prietenii_unui_utilizator()
{
	cout << " Dati id-ul utilizatorului caruia doriti sa ii afisati prietenii: ";
	int id;
	cin >> id;
	if (this->service.getPosRepoById(id) == -1)
		cout << "\tNu exista utilizatorul cu id-ul '" << id << "'!";
	else
	{
		Lista<Utilizator> all = this->service.getAllFriends(id);
		if (all.size() == 0)
			cout << "\tUtilizatorul cu id-ul '" << id << "' nu are prieteni!\n";
		else
		{
			cout << "\tPrietenii ultilizatorului cu id-ul '" << id << "' sunt:\n";
			for (int i = 0; i < all.size(); i++)
				cout << "\t" << all[i] << endl;
		}
	}
}

void UI::ui_afiseaza_mesaje_trimise_de_un_utilizator()
{
	cout << " Dati id-ul utilizatorului: ";
	int id;
	cin >> id;
	if (this->service.getPosRepoById(id) == -1)
		cout << "\tNu exista un utilizator cu id-ul dat!\n";
	else
	{
		map<int, vector<string>> all = this->service.getAllSentMessages(id);
		if (all.size() == 0)
			cout << "\tUtilizatorul cu id-ul '" << id << "' nu a trimis nici un mesaj!\n";
		else
		{
			cout << "\tMesajele trimise de utilizatorul cu id-ul '" << id << "' sunt:\n";
			map<int, vector<string>>::iterator it;
			for (it = all.begin(); it != all.end(); it++)
			{
				cout << "\t" << it->first << ": \n";
				for (int i = 0; i < it->second.size(); i++)
					cout << "\t   " << it->second[i] << endl;
			}
		}
	}
}

void UI::ui_afiseaza_mesaje_primite_de_un_utilizator()
{
	cout << " Dati id-ul utilizatorului: ";
	int id;
	cin >> id;
	if (this->service.getPosRepoById(id) == -1)
		cout << "\tNu exista un utilizator cu id-ul dat!\n";
	else
	{
		map<int, vector<string>> all = this->service.getAllReceivedMessages(id);
		if (all.size() == 0)
			cout << "\tUtilizatorul cu id-ul '" << id << "' nu a primit nici un mesaj!\n";
		else
		{
			cout << "\tMesajele primite de utilizatorul cu id-ul '" << id << "' sunt:\n";
			map<int, vector<string>>::iterator it;
			for (it = all.begin(); it != all.end(); it++)
			{
				cout << "\t" << it->first << ": \n";
				for (int i = 0; i < it->second.size(); i++)
					cout << "\t   " << it->second[i] << endl;
			}
		}
	}
}

void UI::ui_afiseaza_conversatie()
{
	cout << " Dati id-ul primului utilizator al conversatiei: ";
	int id_1;
	cin >> id_1;
	if (this->service.getPosRepoById(id_1) == -1)
		cout << "\tNu exista un utilizator cu id-ul dat!\n";
	else
	{
		cout << " Dati id-ul celui de-al doilea utilizator al conversatiei: ";
		int id_2;
		cin >> id_2;
		if (this->service.getPosRepoById(id_2) == -1)
			cout << "\tNu exista un utilizator cu id-ul dat!\n";
		else
		{
			Lista<Mesaj> all = this->service.getChatBetweenTwoUsers(id_1, id_2);
			if (all.size() == 0)
				cout << "\tUtilizatorul cu id-ul '" << id_1 << "' si cel cu id-ul '" << id_2 << "' nu si-au trimis inca mesaje!\n";
			else
			{
				for (int i = 0; i < all.size(); i++)
					if (all[i].getIdExpeditor() == id_1)
						cout << "\t" << id_1 << ": " << all[i].getMesaj() << endl;
					else cout<< "\t" << id_2 << ": " << all[i].getMesaj() << endl;
			}
		}
	}
}

UI::UI()
{
}

UI::UI(Service& service_)
{
	this->service = service_;
}

void UI::runMenu()
{
	string optiune;
	while (true)
	{
		cout << " 1. Gestiune (CRUD) utilizatori\n";
		cout << " 2. Gestiune (CRUD) prietenii\n";
		cout << " 3. Gestiune (CRUD) mesaje\n";
		cout << " 4. Afiseaza toti prietenii unui utilizator\n";
		cout << " 5. Afiseaza toate mesajele trimise de un utilizator\n";
		cout << " 6. Afiseaza toate mesajele primite de un utilizator\n";
		cout << " 7. Afiseaza o conversatie intre doi utilizatori\n";
		cout << " au. Afiseaza toti utilizatorii\n";
		cout << " ap. Afiseaza toate prieteniile\n";
		cout << " am. Afiseaza toate mesajele\n";

		cout << " x. Iesire\n";

		cout << " Dati optiunea: ";
		cin >> optiune;

		if (optiune == "1")
			this->menuUsers();
		else if (optiune == "2")
			this->menuFriendships();
		else if (optiune == "3")
			this->menuMessages();
		else if (optiune == "4")
			this->ui_afiseaza_toti_prietenii_unui_utilizator();
		else if (optiune == "5")
			this->ui_afiseaza_mesaje_trimise_de_un_utilizator();
		else if (optiune == "6")
			this->ui_afiseaza_mesaje_primite_de_un_utilizator();
		else if (optiune == "7")
			this->ui_afiseaza_conversatie();
		else if (optiune == "au")
			this->ui_afiseaza_toti_utilizatorii();
		else if (optiune == "ap")
			this->ui_afiseaza_toate_prieteniile();
		else if (optiune == "am")
			this->ui_afiseaza_toate_mesajele();

		else if (optiune == "x")
			break;
		else cout << "\tOptiune gresita! Reincercati: \n";

		cout << endl;
	}
}
