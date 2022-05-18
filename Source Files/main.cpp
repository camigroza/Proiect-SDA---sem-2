#include "utilizator.h"
#include "prietenie.h"
#include "mesaj.h"
#include "retea.h"
#include "tests.h"
#include "service.h"
#include "user_interface.h"
#include <iostream>
using namespace std;

int main()
{
	test_all();

	Service s;

	s.addUser(1, "Cami", 19, "Aiud");
	s.addUser(2, "Ariana", 20, "Cluj-Napoca");
	s.addUser(3, "Iulia", 19, "Aiud");
	s.addUser(4, "Ferna", 19, "Alba");
	s.addFriendship(1, 2);
	s.addFriendship(1, 3);
	s.addFriendship(1, 4);
	s.addFriendship(2, 4);
	s.addFriendship(4, 3);
	s.addMessage(1, 2, "hei");
	s.addMessage(1, 3, "mi-e foame");
	s.addMessage(1, 3, "vreau mancare");
	s.addMessage(2, 1, "hei back");
	s.addMessage(1, 2, "imi e pofta de pizza");
	s.addMessage(3, 1, "heii");
	s.addMessage(3, 1, "spune-mi ce vrei si iti aduc");
	s.addMessage(2, 3, "hello");
	s.addMessage(2, 3, "la Cami ii e foame");
	s.addMessage(1, 3, "vreau paste");
	s.addMessage(3, 1, "bine, iti aduc");
	s.addMessage(3, 2, "stiu");
	s.addMessage(3, 2, "mi-a zis si mie :)");
	s.addMessage(1, 3, "multumeeesc <3");
	s.addMessage(3, 1, "<3");

	UI ui(s);
	ui.runMenu();


	return 0;
}