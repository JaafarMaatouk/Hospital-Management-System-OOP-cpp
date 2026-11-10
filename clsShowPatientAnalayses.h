#pragma once
# include<iostream>
# include "clsScreen.h"
# include "clsPatient.h"
# include "clsInputValidate.h"


using namespace std;
class clsShowAllPatientAnalayses :protected clsScreen
{

private:
    static void _PrintAllPatientAnalayses(clsPatient Patient1)
    {
        cout << "\nPatient Card:";
        cout << "\n___________________";
        cout << "\nID          : " << Patient1.GetID();
        cout << "\nFullName    : " << Patient1.FullName();
        cout << "\nAnalayses   : " << Patient1.Analayses;
        cout << "\n___________________\n";

    }

public:

    static void ShowPatientAnalaysesScreen()
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

        _PrintAllPatientAnalayses(Patient1);

    }

};



