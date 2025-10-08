#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

class clsLoginScreen : protected clsScreen {

private:
	static bool _Login() {

		bool LoginFailed = false;
		short FailedCounter = 0;

		string UserName, Password;
		
		do
		{
			if (LoginFailed) {
				FailedCounter++;
				cout << "\nInvlaid Username/Password!\n";
				cout << "You have " << (3-FailedCounter)<< " trial(s) left to login.\n\n";
			}

			if (FailedCounter == 3) {
				cout << "\nYou are locked after 3 failed trials.\n";
				return false;
			}
			
			cout << "Enter Username? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();
		return true;
	}

	



public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

