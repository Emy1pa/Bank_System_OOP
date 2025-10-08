#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen {

private:
	static void _Login() {
		bool LoginFailed = false;
		short FailedCounter = 3;

		string UserName, Password;
		
		do
		{
			if (LoginFailed) {
				cout << "\nInvlaid Username/Password!\n";

			}
			
			

			cout << "Enter Username? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		if (FailedCounter == 0) {
			cout << "You are Locked after 3 failed trails \n";

		} 
		clsMainScreen::ShowMainMenu();
	}

public:
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

