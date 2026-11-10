#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsBloodBagesObject.h"
# include <iomanip>

using namespace std;


class clsBloodBagesList:protected clsScreen
    {


    private:

        static void _PrintBloodBageRecordLine(clsBloodBagesObject BloodBage)
        {

            cout << setw(8) << left << "" << "| " << setw(25) << left << BloodBage.BloodBageID;
            cout << "| " << setw(25) << left << BloodBage.BloodType;
            cout << "| " << setw(25) << left << BloodBage.BloodDonationDate;


        }


    public:
        static void ShowDepartmentsList()
        {


            vector <clsBloodBagesObject> VBloodBages = clsBloodBagesObject::GetBloodBagesList();
            string Title = "\t  Blood Bages List Screen";
            string SubTitle = "\t    (" + to_string(VBloodBages.size()) + ") Blood Bage(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(25) << "Blood Bage ID";
            cout << "| " << left << setw(25) << "Blood Bage Type";
            cout << "| " << left << setw(25) << "Blood Donatoin Date";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (VBloodBages.size() == 0)
                cout << "\t\t\t\tNo Blood Bage Available In the System!";
            else

                for (clsBloodBagesObject& BloodBage : VBloodBages)
                {

                    _PrintBloodBageRecordLine(BloodBage);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

        }


    };




