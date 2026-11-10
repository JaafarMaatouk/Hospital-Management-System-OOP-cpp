#pragma once
# include<iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsPatient.h"

using namespace std;

class clsUpdatePatientInfo:protected clsScreen
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

    static void _ReadPatientInfo(clsPatient& Patient)
    {
        cout << "Enter Patient FirstName: ";
        Patient.FirstName = clsInputValidate::ReadString();

        cout << "Enter patient LastName : ";
        Patient.LastName = clsInputValidate::ReadString();

        cout << "Enter Patient Age      : ";
        Patient.Age = clsInputValidate::ReadIntNumber();

        cout << " Enter BloodType       : ";
        Patient.BloodType = clsInputValidate::ReadString();

        cout << "Enter PatientSituation : ";
        Patient.PatientSituation = clsInputValidate::ReadString();


        cout << "Enter Analayses        : ";
        Patient.Analayses = clsInputValidate::ReadString();

        cout << "Enter Medicine         : ";
        Patient.Medicine = clsInputValidate::ReadString();


        cout << "Enter LastOperations   : ";
        Patient.LastOperations = clsInputValidate::ReadString();
    }


public:
    static void ShowUpdatePatientScreen()
    {
        

        _DrawScreenHeader("\tUpdate Patient Screen");

        int ID;

        cout << "\nPlease Enter Patient ID Number: ";
        ID = clsInputValidate::ReadIntNumber();

        while (!clsPatient::IsPatientExist(ID))
        {
            cout << "\nID number is not found, choose another one: ";
            ID = clsInputValidate::ReadIntNumber();
        }

        clsPatient Patient1 = clsPatient::Find(ID);

        _PrintAllPatientInformations(Patient1);

        cout << "\nAre you sure you want to update this Patient y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Patient Info:";
            cout << "\n____________________\n";


            _ReadPatientInfo(Patient1);

            clsPatient::enSaveResults SaveResult;

            SaveResult = Patient1.Save();

            switch (SaveResult)
            {
            case  clsPatient::enSaveResults::svSucceeded:
            {
                cout << "\nPatient Updated Successfully :-)\n";

                _PrintAllPatientInformations(Patient1);
                break;
            }
            case clsPatient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Patient was not saved because it's Empty";
                break;

            }

            }

        }

    }

};

