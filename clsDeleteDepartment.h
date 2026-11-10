#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInternalDepartments.h"
# include "clsInputValidate.h"


class clsDeleteDepartment:protected clsScreen
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


public:


    static void ShowDeleteDepartmentScreen()
    {

        _DrawScreenHeader("\tDelete Department Screen");

        int ID;

        cout << "\nPlease Enter ID Number: ";
        ID = clsInputValidate::ReadIntNumber();
        while (!clsInternalDepartments::IsDepartmentExist(ID))
        {
            cout << "\nID number is not found, choose another one: ";
            ID = clsInputValidate::ReadIntNumber();
        }

        clsInternalDepartments Department1 = clsInternalDepartments::Find(ID);
        _PrintDepartment(Department1);

        cout << "\nAre you sure you want to Delete this Department y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Department1.Delete())
            {
                cout << "\nDepartment Deleted Successfully :-)\n";
                _PrintDepartment(Department1);
            }
            else
            {
                cout << "\nError Department Was not Deleted\n";
            }
        }
    }


};

