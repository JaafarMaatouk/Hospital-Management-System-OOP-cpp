#pragma once
# include <iostream>
# include "clsInternalDepartments.h"
# include "clsScreen.h"
# include "clsInputValidate.h"
using namespace std;

class clsUpdateDepartmentInfo:protected clsScreen
{
private:

    static void _PrintDepartment(clsInternalDepartments Department)
    {
        cout << "\nDepartment Card:";
        cout << "\n___________________";
        cout << "\nDepartment ID   : " << Department.DepartmentID;
        cout << "\nDepartment Name : " << Department.DepartmentName;
        cout << "\nNumber Rooms    : " << Department.NumberOfDepartmentRooms;
        cout << "\nNumber Beds     : " << Department.NumberOfRoomBeds;
        cout << "\n___________________\n";

    }

    static void ReadDepartmentInfo(clsInternalDepartments& Department)
    {
        cout << "\nEnter Department Name: ";
        Department.DepartmentName = clsInputValidate::ReadString();

        cout << "\nEnter Number of Rooms: ";
        Department.NumberOfDepartmentRooms = clsInputValidate::ReadIntNumber();

        cout << "\nEnter Number of Beds : ";
        Department.NumberOfRoomBeds = clsInputValidate::ReadIntNumber();

    }


public:


    static void ShowUpdateDepartmentScreen()
    {
       
        _DrawScreenHeader("\tUpdate Department Screen");

        int ID;

        cout << "\nPlease Enter Department ID Number: ";
        ID = clsInputValidate::ReadIntNumber();

        while (!clsInternalDepartments::IsDepartmentExist(ID))
        {
            cout << "\nID Number is not found, choose another one: ";
            ID = clsInputValidate::ReadIntNumber();
        }

        clsInternalDepartments Department1 = clsInternalDepartments::Find(ID);

        _PrintDepartment(Department1);

        cout << "\nAre you sure you want to update this Department y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Department Info:";
            cout << "\n____________________\n";


            ReadDepartmentInfo(Department1);

            clsInternalDepartments::enSaveResults SaveResult;

            SaveResult = Department1.Save();

            switch (SaveResult)
            {
            case  clsInternalDepartments::enSaveResults::svSucceeded:
            {
                cout << "\nDepartment Updated Successfully :-)\n";

                _PrintDepartment(Department1);
                break;
            }
            case clsInternalDepartments::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Department was not saved because it's Empty";
                break;

            }

            }

        }

    }


};

