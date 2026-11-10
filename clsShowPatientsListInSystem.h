#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsPatient.h"
# include <iomanip>

class clsShowPatientsListInSystem:protected clsScreen
{
private:

        static void PrintPatientRecordLine(clsPatient Patient)
        {

            cout << setw(2) << left << "" << "| " << setw(5) << left << Patient.ID;
            cout << "| " << setw(20) << left << Patient.FullName();
            cout << "| " << setw(4) << left << Patient.Age;
            cout << "| " << setw(6) << left << Patient.BloodType;
            cout << "| " << setw(40) << left << Patient.Analayses;
            cout << "| " << setw(20) << left << Patient.Medicine;
            cout << "| " << setw(25) << left << Patient.LastOperations;


        }


    public:
        static void ShowDepartmentsList()
        {


            vector <clsPatient> vPatients = clsPatient::GetPatientsList();
            string Title = "\t  Patients List Screen";
            string SubTitle = "\t    (" + to_string(vPatients.size()) + ") Patient(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << setw(2) << left << "" << "\n   _______________________________________________________";
            cout << "_________________________________________________________________________\n" << endl;

            cout << setw(2) << left << "" << "| " << left << setw(5) << "ID";
            cout << "| " << left << setw(20) << "Patient FullName";
            cout << "| " << left << setw(4) << "Age";
            cout << "| " << left << setw(6) << "Blood";
            cout << "| " << left << setw(40) << "            Analayses";
            cout << "| " << left << setw(20) << "Medicine";
            cout << "| " << left << setw(25) << "LastOperations";

            cout << setw(2) << left << "" << "\n  _______________________________________________________";
            cout << "_______________________________________________________________________\n" << endl;

            if (vPatients.size() == 0)
                cout << "\t\t\t\tNo Patients Available In the System!";
            else

                for (clsPatient& Patient : vPatients)
                {

                    PrintPatientRecordLine(Patient);
                    cout << endl;
                }

            cout << setw(2) << left << "" << "\n  _______________________________________________________";
            cout << "_______________________________________________________________________\n" << endl;

        }


    };

