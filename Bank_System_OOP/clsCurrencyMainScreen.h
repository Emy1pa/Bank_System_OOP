#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;


class clsCurrencyMainScreen : protected clsScreen {

private:
    enum enCurrenyExchangeMainMenu {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5] ? ";
        short Choice = clsInputValidate::ReadNumberBetween<int>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToMainMenu() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menue...\n";
        system("pause>0");
        ShowCurrencyMenu();
    }

    static void _ShowListCurrenicesScreen() {
        //cout << "\nCurrencies List Screen Will be here...\n";
        clsCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen() {
        //cout << "\nFind Currency Screen Will be here...\n";
        clsFindCurrency::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen() {
        //cout << "\nUpdate Rate Screen Will be here...\n";
        clsUpdateCurrency::ShowUpdateCurrencyScreen();

    }
    static void _ShowCurrenyCalculatorScreen() {
        //cout << "\nCurrency Calculator Screen Will be here...\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrecnyMenuOption(enCurrenyExchangeMainMenu CurrencyMenuOption) {
        switch (CurrencyMenuOption)
        {
        case enCurrenyExchangeMainMenu::eListCurrencies:
            system("cls");
            _ShowListCurrenicesScreen();
            _GoBackToMainMenu();
            break;
        case enCurrenyExchangeMainMenu::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToMainMenu();
            break;
        case enCurrenyExchangeMainMenu::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToMainMenu();
            break;
        case enCurrenyExchangeMainMenu::eCurrencyCalculator:
            system("cls");
            _ShowCurrenyCalculatorScreen();
            _GoBackToMainMenu();
            break;

        case enCurrenyExchangeMainMenu::eMainMenue:
        {

        }
        }

    }

public:
    static void ShowCurrencyMenu() {
        system("cls");
        _DrawScreenHeader("   Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrecnyMenuOption((enCurrenyExchangeMainMenu)_ReadCurrencyMenuOption());
    }

};

