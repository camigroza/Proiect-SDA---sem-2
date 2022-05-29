#include "utilizator.h"
#include "prietenie.h"
#include "mesaj.h"
#include "retea.h"
#include "tests.h"
#include "service.h"
#include "user_interface.h"
#include "mock_data.h"
#include <iostream>
using namespace std;

int main()
{
	test_all();

	Service s;

	add_input_data(s);

	UI ui(s);
	ui.runMenu();


	return 0;
}