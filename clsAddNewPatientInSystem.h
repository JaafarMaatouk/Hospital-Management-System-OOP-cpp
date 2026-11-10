#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"

using namespace std;


class clsAddNewPatientInSystem:protected clsScreen
{
     
private:

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
        Patient.PatientSituation= clsInputValidate::ReadString();


        cout << "Enter Analayses        : ";
        Patient.Analayses = clsInputValidate::ReadString();

        cout << "Enter Medicine         : ";
        Patient.Medicine = clsInputValidate::ReadString();


        cout << "Enter LastOperations   : ";
        Patient.LastOperations = clsInputValidate::ReadString();
    }


    static void _PrintPatient(clsPatient Patient)
    {
        cout << "\Patient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Patient.FirstName;
        cout << "\nLastName    : " << Patient.LastName;
        cout << "\nFull Name   : " << Patient.FullName();
        cout << "\nID          : " << Patient.ID;
        cout << "\nAge         : " << Patient.Age;
        cout << "\nBloodType   : " << Patient.BloodType;
        cout << "\nAnalayses   : " << Patient.Analayses;
        cout << "\nSituation   : " << Patient.PatientSituation;
        cout << "\nMedicine    : " << Patient.Medicine;
        cout << "\nLastOpe     : " << Patient.LastOperations;

        cout << "\n___________________\n";

    }



public : 


    static void ShowAddNewPatientScreen()
    {



        _DrawScreenHeader("\t  Add New Patient Screen");

        int ID;

        cout << "\nPlease Enter ID Number : ";
        ID=clsInputValidate::ReadIntNumber();
       while (clsPatient::IsPatientExist(ID))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            ID = clsInputValidate::ReadIntNumber();
       }

        clsPatient NewPatient = clsPatient::GetAddNewPatientObject(ID);


        _ReadPatientInfo(NewPatient);

        clsPatient::enSaveResults SaveResult;

            SaveResult = NewPatient.Save();

            switch (SaveResult)
            {
            case  clsPatient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Addeded Successfully :-)\n";
                _PrintPatient(NewPatient);
                break;
            }
            case clsPatient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsPatient::enSaveResults::svFaildIDNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;

            }
            
        }
    }
};

