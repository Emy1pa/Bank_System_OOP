#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen {

private:
	static void _PrintClientCard(clsBankClient Client) {
		cout << "\nClient Card: \n\n";
		cout << "------------------------\n";
		cout << "FullName: " << Client.FullName() << "\n";
		cout << "Acc.Number: " << Client.AccountNumber() << "\n";
		cout << "Balance: " << Client.AccountBalance << "\n";
		cout << "------------------------\n\n";
	}

public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\tTransfer Screen");

		string AccountNumber;
		cout << "Please Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);

		string AccountNumber2;
		cout << "Please Enter Account Number to Transfer To: ";
		AccountNumber2 = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber2))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber2 = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		_PrintClientCard(Client2);

		float TransferAmount;
		cout << "Please Enter The Transfer Amount ? ";
		TransferAmount = clsInputValidate::ReadFloatNumber();

		while (TransferAmount > Client.AccountBalance) {
			cout << "\nAmount exceeds the available balance, enter another amount ? ";
			TransferAmount = clsInputValidate::ReadFloatNumber();
		}
		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operations ? Y/N ? ";
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y') {
			Client.AccountBalance -= TransferAmount;
			Client2.AccountBalance += TransferAmount;

			clsBankClient::enSaveResults SaveResult, SaveResult2;
			SaveResult = Client.Save();
			SaveResult2 = Client2.Save();

			switch (SaveResult)
			{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nTransfer Done Successfully \n";
				_PrintClientCard(Client);
				break;
			}
			case clsBankClient::enSaveResults::svFailedEmptyObject:
			{
				cout << "\nError Operation was not saved because it's Empty";
				break;
			}
			}

			switch (SaveResult2)
			{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				_PrintClientCard(Client2);
				break;
			}
			case clsBankClient::enSaveResults::svFailedEmptyObject:
			{
				cout << "\nError Operation was not saved because it's Empty";
				break;
			}
			}

		}
	
		}
};

