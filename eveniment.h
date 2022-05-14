#pragma once
#include <string>
using namespace std;

class Eveniment {
private:
	int id_utilizator;
	string data_nasterii;

public:
	Eveniment();
	Eveniment(int id, string data);
	Eveniment(const Eveniment& other);
	~Eveniment() = default;

	void setIdUtilizator(int id);
	void setDataNasterii(string data);

	int getIdUtilizator();
	string getDataNasterii();

	Eveniment& operator=(const Eveniment& other);
	bool operator==(const Eveniment& other);
};