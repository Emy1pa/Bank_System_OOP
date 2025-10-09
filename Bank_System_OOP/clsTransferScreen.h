#pragma once
#include <iostream>
#include <iomanip>
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

	static string _ReadAccountNumber() {
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient){
		float Amount;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance) {
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(SourceClient);


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);

		float Amount = ReadAmount(SourceClient);
		

		cout << "\nAre you sure you want to perform this operations ? Y/N ? ";
		char Answer = 'n';
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y') {
			
			
			if(SourceClient.Transfer(Amount, DestinationClient))
				cout << "\nTransfer done successfully\n";
			else 
				cout << "\nTransfer Faild \n";
		}
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

		}
};

