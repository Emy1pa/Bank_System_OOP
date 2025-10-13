#pragma once
#include <ios>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsFindCurrency : protected clsScreen {
    
private:

    static short _ReadCurrencyOption() {
        cout << "Find By: [1] Code or [2] Country ? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter Number between 1 & 2? ");
        return Choice;
    }

    static string ReadCurrencyCode() {
        string CurrencyCode;
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();
        return CurrencyCode;
    }

    static string ReadCountryName() {
        string CountryName;
        cout << "\nPlease Enter Country Name: ";
        CountryName = clsInputValidate::ReadString();
        return CountryName;
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


public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t Find Currency Screen");

        short FindChoice = _ReadCurrencyOption();
       
        if (FindChoice == 1) {
            string CurrencyCode = ReadCurrencyCode();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else if (FindChoice == 2) {
            string CountryName = ReadCountryName();
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResults(Currency);
        }
    }
};

