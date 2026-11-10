#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsBloodBagesObject.h"
# include "clsInputValidate.h"

class clsDeleteBloodBageScreen:protected clsScreen
{ 

    private:

        static void _PrintBloodBage(clsBloodBagesObject BloodBage)
        {
            cout << "\nBlood Bage Card:";
            cout << "\n___________________";
            cout << "\nBlood Bage ID      : " << BloodBage.BloodBageID;
            cout << "\nBlood Bage Type    : " << BloodBage.BloodType;
            cout << "\nBlood Donation Date: " << BloodBage.BloodDonationDate;
            cout << "\n___________________\n";

        }


    public:


        static void ShowDeleteBloodTypeScreen()
        {

            _DrawScreenHeader("\tDelete Blood Bage Screen");

            int ID;

            cout << "\nPlease Enter Blood Bage ID Number: ";
            ID = clsInputValidate::ReadIntNumber();
            while (!clsBloodBagesObject::IsBloodBageExist(ID))
            {
                cout << "\nBlood Bage ID number is not found, choose another one: ";
                ID = clsInputValidate::ReadIntNumber();
            }

            clsBloodBagesObject BloodBage1 = clsBloodBagesObject::Find(ID);
            _PrintBloodBage(BloodBage1);

            cout << "\nAre you sure you want to Delete this Blood Bage y/n? ";

            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {


                if (BloodBage1.Delete())
                {
                    cout << "\nBlood Bage Deleted Successfully :-)\n";
                    _PrintBloodBage(BloodBage1);
                }
                else
                {
                    cout << "\nError Blood Bage Was not Deleted\n";
                }
            }
        }


    };




