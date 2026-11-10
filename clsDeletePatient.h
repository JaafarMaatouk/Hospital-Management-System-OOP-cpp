
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsPatient.h"
#include "clsInputValidate.h"

    class clsDeletePatient :protected clsScreen
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
        static void ShowDeleteClientScreen()
        {
           

            _DrawScreenHeader("\tDelete Patient Screen");

            int ID;

            cout << "\nPlease Enter ID Number: ";
            ID = clsInputValidate::ReadIntNumber();
            while (!clsPatient::IsPatientExist(ID))
            {
                cout << "\nID number is not found, choose another one: ";
                ID = clsInputValidate::ReadIntNumber();
            }

            clsPatient Patient1 = clsPatient::Find(ID);
            _PrintAllPatientInformations(Patient1);

            cout << "\nAre you sure you want to delete this Patient y/n? ";

            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {


                if (Patient1.Delete())
                {
                    cout << "\nPatient Deleted Successfully :-)\n";
                    _PrintAllPatientInformations(Patient1);
                }
                else
                {
                    cout << "\nError Patient Was not Deleted\n";
                }
            }
        }

    };



