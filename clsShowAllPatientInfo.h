#pragma once
# include<iostream>
# include "clsScreen.h"
# include "clsPatient.h"
# include "clsInputValidate.h"


using namespace std;
class clsShowAllPatientInfo :protected clsScreen
{

private:
    static void _PrintAllPatientInformations(clsPatient Patient1)
    {
        cout << "\nPatient Card:";
        cout << "\n___________________";
        cout << "\nID          : " << Patient1.GetID();
        cout << "\nFullName    : " << Patient1.FullName();
        cout << "\nAge         : " << Patient1.Age;
        cout << "\nBlood Type  : " << Patient1.BloodType;
        cout << "\nSituation   : " << Patient1.PatientSituation;
        cout << "\nAnalayses   : " << Patient1.Analayses;
        cout << "\nMedicine    : " << Patient1.Medicine;
        cout << "\nOperations  : " << Patient1.LastOperations;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindPatientScreen()
    {


        _DrawScreenHeader("\tShow All Patient info");

        int ID;
        cout << "\nPlease Enter ID : ";
         ID=clsInputValidate::ReadIntNumber();
        while (!clsPatient::IsPatientExist(ID))
        {
            cout << "\nThis ID is not found, choose another one: ";
            ID = clsInputValidate::ReadIntNumber();
        }

        clsPatient Patient1 = clsPatient::Find(ID);

        if (!Patient1.IsEmpty())
        {
            cout << "\nPatient Found :-)\n";
        }
        else
        {
            cout << "\nPatient Was not Found :-(\n";
        }

        _PrintAllPatientInformations(Patient1);

    }

};



