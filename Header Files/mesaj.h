#pragma once
#include <string>
using namespace std;

class Mesaj {
private:
	int id_expeditor;
	int id_destinatar;
	string mesaj;

public:
	//constructori si destructor
	Mesaj();
	Mesaj(int id_exp, int id_dest, string mesaj_);
	Mesaj(const Mesaj& other);
	~Mesaj() = default;

	//setteri
	void setIdExpeditor(int id);
	void setIdDestinatar(int id);
	void setMesaj(string mesaj_);

	//getteri
	int getIdExpeditor();
	int getIdDestinatar();
	string getMesaj();

	//overload la operatori
	Mesaj& operator=(const Mesaj& other);
	bool operator==(const Mesaj& other);
	friend ostream& operator<<(ostream& os, const Mesaj& m);
};