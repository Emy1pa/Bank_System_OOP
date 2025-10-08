#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

using namespace std;


int main()
{
	//clsMainScreen::ShowMainMenu();
	while (true) {
	clsLoginScreen::ShowLoginScreen();

	}

	
	system("pause>0");
	return 0;
}
