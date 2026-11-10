#pragma once
#include <iostream>
#include "clsScreen.h"
# include "clsBloodBagesList.h"
# include "clsAddNewBloodBage.h"
# include "clsDeleteBloodBageScreen.h"

class clsBloodBankScreen:protected clsScreen
{
private:
    enum eBloodBagesOptions{ eBloodBagesList=1,eAddNewBloodBage=2,eDeleteBloodBages=3
                                , eShowMainMenue=4};

    static short ReadbloodBankMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;

    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowBloodBankOptions();

    }

    static void _ShowAllBloodBagessInfo() {

        clsBloodBagesList::ShowDepartmentsList();
    }

    static void _ShowAddBloodBageScreen() {

        clsAddNewBloodBage::ShowAddNewBloodBageScreen();
    }

    static void _ShowDeleteBloodBageScreen() {

        clsDeleteBloodBageScreen::ShowDeleteBloodTypeScreen();
    }

    static void _PerformBloodBagesMenueOption(eBloodBagesOptions BloodBagesOptions)
    {
        switch (BloodBagesOptions)
        {
        case eBloodBagesOptions::eBloodBagesList:
        {
            system("cls");
            _ShowAllBloodBagessInfo();
            _GoBackToTransactionsMenue();
            break;
        }

        case eBloodBagesOptions::eAddNewBloodBage:
        {
            system("cls");
            _ShowAddBloodBageScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case eBloodBagesOptions::eDeleteBloodBages:
        {
            system("cls");
            _ShowDeleteBloodBageScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case eBloodBagesOptions::eShowMainMenue:
        {

            //do nothing -) ;

        }
        }


    }


public:

    static void ShowBloodBankOptions()
    {


        system("cls");
        _DrawScreenHeader("\           Blood Bank Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t       Options Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show All Blood Bages.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Blood Bage.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Blood Bage.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformBloodBagesMenueOption((eBloodBagesOptions)ReadbloodBankMenueOption());
    }


};

