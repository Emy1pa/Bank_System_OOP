#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferLogScreen : clsScreen {

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogScreen TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {
        /*if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
            return;*/

        vector <clsBankClient::stTransferLogScreen> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(10) << "D.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "UserName";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";
        else

            for (clsBankClient::stTransferLogScreen Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "___________________________________________________\n" << endl;

    }
};

