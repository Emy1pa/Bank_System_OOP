#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrency : protected clsScreen {

private:

    static float _ReadNewCurrencyRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

    static string _ReadCurrencyCode() {
        string CurrencyCode;
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();
        return CurrencyCode;
    }

    static void _ShowResults(clsCurrency Currency) {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

public:
    static void ShowUpdateCurrencyScreen(){
        _DrawScreenHeader("\t Update Currency Screen");

        string CurrencyCode = _ReadCurrencyCode();
        
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        cout << "\nAre you sure you want to update this rate of this currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            float NewRate = _ReadNewCurrencyRate();
            Currency.UpdateRate(NewRate);

            cout << "\nCurrency Rate Updated Successfully :-) \n";
            _PrintCurrencyCard(Currency);
        }
    }
};

