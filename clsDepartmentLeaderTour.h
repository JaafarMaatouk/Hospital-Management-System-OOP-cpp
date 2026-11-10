#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsPatient.h"
# include "clsInputValidate.h"
# include "clsUpdatePatientInfo.h";

class clsDepartmentLeaderTour:protected clsScreen
{
private:

	enum eDepartmentNameOption { eHeartDep=1,eEyesDep=2,eNoiseDep=3,eTeethDep=4,
	     eBoonsDep=5,eSurgonDep=6,eMainMenue=7};

    static  void _GoBackToDepartmentsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Departments Menue...\n";

        system("pause>0");
        ShowDepartmentLeaderTourScreen();
    }

    static short _ReadMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
        return Choice;
    }

    static void _PerfromMenueOption(eDepartmentNameOption eMainOption)
    {
        switch (eMainOption)
        {
        case eDepartmentNameOption::eHeartDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;
        }
        case eDepartmentNameOption::eEyesDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;
        }
        case eDepartmentNameOption::eNoiseDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;
        }
        case eDepartmentNameOption::eTeethDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;
        }
        case eDepartmentNameOption::eBoonsDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;
        }
        case eDepartmentNameOption::eSurgonDep:
        {
            system("cls");
            clsUpdatePatientInfo::ShowUpdatePatientScreen();
            _GoBackToDepartmentsMenue();
            break;

        }
        case eDepartmentNameOption::eMainMenue:
        {
           // Nothing :)
        }

        }
    }
public:

    static void ShowDepartmentLeaderTourScreen()
    {

        system("cls");
        _DrawScreenHeader("\tDepartment Leader Tour");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t      Departments Names\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t [1] Heart Department.\n";
        cout << setw(37) << left << "" << "\t [2] Eyes Department.\n";
        cout << setw(37) << left << "" << "\t [3] Noise Department.\n";
        cout << setw(37) << left << "" << "\t [4] Teeth Department.\n";
        cout << setw(37) << left << "" << "\t [5] Bones Department.\n";
        cout << setw(37) << left << "" << "\t [6] Internal Surgon Department.\n";
        cout << setw(37) << left << "" << "\t [7] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMenueOption((eDepartmentNameOption)_ReadMenueOption());
    }



};

