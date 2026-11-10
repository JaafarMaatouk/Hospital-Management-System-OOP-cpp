#pragma once

#include<iostream>
# include<iomanip>
# include "clsScreen.h"
# include "clsAddNewDepartment.h"
# include "clsShowDepartmentsInfo.h"
# include "clsUpdateDepartmentInfo.h"
# include "clsDeleteDepartment.h"

using namespace std;

class clsShowDailingWithInternalHospiatlDepartmentsScreen:protected clsScreen
{
private:

    enum enDealingWithInternalDepartmentsMenueOptions {
        eShowAllDepartments = 1, eAddNewDepartment = 2,
        eUpdateDepartment = 3, eDeleteDepartment = 4,
        eShowMainMenue = 5

    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;

    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowDealingWithInternalDepartmentsMenue();

    }

    static void _ShowAllDepartmentsInfo() {

        clsShowDepartmentsInfo::ShowDepartmentsList();
    }


    static void _ShowAddDepartmentScreen() {

        clsAddNewDepartment::ShowAddNewDepartmentScreen();
    }

    static void _ShowUpdateDepartmentInfoScreen() {

        clsUpdateDepartmentInfo::ShowUpdateDepartmentScreen();
    }

    static void _ShowDeleteDepartmentScreen() {

        clsDeleteDepartment::ShowDeleteDepartmentScreen();
    }


    static void _PerformTransactionsMenueOption(enDealingWithInternalDepartmentsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enDealingWithInternalDepartmentsMenueOptions::eShowAllDepartments:
        {
            system("cls");
            _ShowAllDepartmentsInfo();
            _GoBackToTransactionsMenue();
            break;
        }

        case enDealingWithInternalDepartmentsMenueOptions::eAddNewDepartment:
        {
            system("cls");
            _ShowAddDepartmentScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enDealingWithInternalDepartmentsMenueOptions::eUpdateDepartment:
        {
            system("cls");
           _ShowUpdateDepartmentInfoScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enDealingWithInternalDepartmentsMenueOptions::eDeleteDepartment:
        {
            system("cls");
            _ShowDeleteDepartmentScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enDealingWithInternalDepartmentsMenueOptions::eShowMainMenue:
        {

            //do nothing here the main screen will handle it :-) ;

        }
        }


    }


public:


    static void ShowDealingWithInternalDepartmentsMenue()
    {


        system("cls");
        _DrawScreenHeader("\tInternal Departments Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t       Options Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show All Departments.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Department.\n";
        cout << setw(37) << left << "" << "\t[3] Update Department.\n";
        cout << setw(37) << left << "" << "\t[4] Delete Department.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enDealingWithInternalDepartmentsMenueOptions)ReadTransactionsMenueOption());
    }

};

