#pragma once

class Prietenie {
private:
	int id_utilizator_1;
	int id_utilizator_2;

public:
	Prietenie();
	Prietenie(int id1, int id2);
	Prietenie(const Prietenie& other);
	~Prietenie() = default;

	void setIdUtilizator1(int id1);
	void setIdUtilizator2(int id2);

	int getIdUtilizator1();
	int getIdUtilizator2();

	Prietenie& operator=(const Prietenie& other);
	bool operator==(const Prietenie& other);
};
