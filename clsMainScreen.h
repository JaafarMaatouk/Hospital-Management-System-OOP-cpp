#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsShowAllPatientInfo.h"
# include "clsShowPatientAnalayses.h"
# include "clsAddNewPatientInSystem.h"
# include "clsUpdatePatientInfo.h"
# include "clsDeletePatient.h"
# include "clsShowDailingWithInternalHospiatlDepartmentsScreen.h"
# include "clsDepartmentLeaderTour.h"
# include "clsBloodBankScreen.h"
# include "clsShowPatientsListInSystem.h"
# include <iomanip>

class clsMainScreen :protected clsScreen
{

private:

    enum enMainMenueOptions {
        eInternalHospitalDepartments = 1 , eShowAllPatientsInSystem = 2, eAddPatient = 3,
        eUpdatePatientInfo = 4, eShowAllPatientInfo = 5, eFindPatientAndShowhisAnalises = 6,
        eDepartmentLeaderTour = 7, ePatientdischarge = 8, eBloodBank = 9,
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllPatientInfo() {

        clsShowAllPatientInfo::ShowFindPatientScreen();

    }

    static void _ShowAddNewpatientInSystemScreen() {

        clsAddNewPatientInSystem::ShowAddNewPatientScreen();
    }

    static void _ShowFindPatientAndPrintHisAnalaysesScreen() {

        clsShowAllPatientAnalayses::ShowPatientAnalaysesScreen();
    }

    static void _ShowUpdatePatientInfoMenue() {

        clsUpdatePatientInfo::ShowUpdatePatientScreen();
    }

    static void _ShowDeletePatientFromSystem() {

        clsDeletePatient::ShowDeleteClientScreen();
    }

    static void _ShowDailingWithInternalHospitalDepartmentsScreen() {

        clsShowDailingWithInternalHospiatlDepartmentsScreen::ShowDealingWithInternalDepartmentsMenue();
        
    }

    static void _ShowDepartmentLeaderTourScreen() {

        clsDepartmentLeaderTour::ShowDepartmentLeaderTourScreen();
    }

    static void _ShowBloodBankScreen() {

        clsBloodBankScreen::ShowBloodBankOptions();
    }

    static void _ShowAllPatientInSystemScreen() {

        clsShowPatientsListInSystem::ShowDepartmentsList();
    }
   
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        
        case enMainMenueOptions::eInternalHospitalDepartments:
        {
            system("cls");
            _ShowDailingWithInternalHospitalDepartmentsScreen();
            _GoBackToMainMenue();
            break;
        }
        
        case enMainMenueOptions::eShowAllPatientsInSystem:
        {
            system("cls");
            _ShowAllPatientInSystemScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddPatient:
        {
            system("cls");
            _ShowAddNewpatientInSystemScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eFindPatientAndShowhisAnalises:
        {
            system("cls");
            _ShowFindPatientAndPrintHisAnalaysesScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eShowAllPatientInfo:
        {
            system("cls");
            _ShowAllPatientInfo();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eUpdatePatientInfo:
        {
            system("cls");
            _ShowUpdatePatientInfoMenue();
            _GoBackToMainMenue();
            break;
        }
     
        case enMainMenueOptions::eDepartmentLeaderTour:
        {
            system("cls");
            _ShowDepartmentLeaderTourScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::ePatientdischarge:
        {
            system("cls");
            _ShowDeletePatientFromSystem();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eBloodBank:
        {
            system("cls");
            _ShowBloodBankScreen();
            _GoBackToMainMenue();
            break;
        }
       


        }


    }

public:

    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t    ( HOSPIAL SYSTEM )");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t [1] Internal Hospital Departments.\n";
        cout << setw(37) << left << "" << "\t [2] Show All Patients IN System.\n";
        cout << setw(37) << left << "" << "\t [3] Add Patient On System.\n";
        cout << setw(37) << left << "" << "\t [4] Update Patient Info.\n";
        cout << setw(37) << left << "" << "\t [5] Show All Patient Info.\n";
        cout << setw(37) << left << "" << "\t [6] Find Patient And Show his Analises.\n";
        cout << setw(37) << left << "" << "\t [7] Department Leader Tour.\n";
        cout << setw(37) << left << "" << "\t [8] Patient discharge from hospital.\n";
        cout << setw(37) << left << "" << "\t [9] Blood Bank.\n";  
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};

