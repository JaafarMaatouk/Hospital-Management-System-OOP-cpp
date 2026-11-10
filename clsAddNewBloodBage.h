#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsBloodBagesObject.h"
using namespace std;

class clsAddNewBloodBage:protected clsScreen
{

    private:

        static void _ReadBloodBageInfo(clsBloodBagesObject& BloodBage)
        {
            cout << "\nEnter blood Type   : ";
            BloodBage.BloodType = clsInputValidate::ReadString();

            cout << "\nEnter Donation Date: ";
            BloodBage.BloodDonationDate = clsInputValidate::ReadString();

           

        }

        static void _PrintBloodBage(clsBloodBagesObject BloodBage)
        {
            cout << "\Blood Bage Card:";
            cout << "\n___________________";
            cout << "\nBlood Bage ID  : " << BloodBage.BloodBageID;
            cout << "\nBlood Type     : " << BloodBage.BloodType;
            cout << "\nDonation Date  : " << BloodBage.BloodDonationDate;
            cout << "\n___________________\n";

        }


    public:

        static void ShowAddNewBloodBageScreen()
        {



            _DrawScreenHeader("\t  Add New Blood Bage Screen");

            int ID;

            cout << "\nPlease Enter Blood Bage ID Number : ";
             ID=clsInputValidate::ReadIntNumber();
            while (clsBloodBagesObject::IsBloodBageExist(ID))
            {
                cout << "\ID Number Is Already Used, Choose another one: ";
                ID = clsInputValidate::ReadIntNumber();
            }

            clsBloodBagesObject NewBloodBage = clsBloodBagesObject::GetAddNewBloodBageObject(ID);


            _ReadBloodBageInfo(NewBloodBage);

            clsBloodBagesObject::enSaveResults SaveResult;

            SaveResult = NewBloodBage.Save();

            switch (SaveResult)
            {
            case  clsBloodBagesObject::enSaveResults::svSucceeded:
            {
                cout << "\nBlood Bage ID Addeded Successfully :-)\n";
                _PrintBloodBage(NewBloodBage);
                break;
            }
            case clsBloodBagesObject::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Blood Bage ID was not saved because it's Empty";
                break;

            }
            case clsBloodBagesObject::enSaveResults::svFaildIDNumberExists:
            {
                cout << "\nError Blood Bage ID was not saved because ID number is used!\n";
                break;

            }

            }
        }



    };




