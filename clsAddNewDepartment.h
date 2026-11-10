#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInputValidate.h"
# include "clsInternalDepartments.h"

using namespace std;

class clsAddNewDepartment:protected clsScreen
{
private:

    static void _ReadDepartmentInfo(clsInternalDepartments & Department)
    {
        cout << "\nEnter Department Name                : ";
        Department.DepartmentName= clsInputValidate::ReadString();

        cout << "\nEnter Number Rooms in This Department: ";
        Department.NumberOfDepartmentRooms = clsInputValidate::ReadIntNumber();

        cout << "\nEnter Number Beds In Each Room       : ";
        Department.NumberOfRoomBeds = clsInputValidate::ReadIntNumber();

      
    }

    static void _PrintDepartment(clsInternalDepartments Department)
    {
        cout << "\Department Card:";
        cout << "\n___________________";
        cout << "\nDepartment ID  : " << Department.DepartmentID;
        cout << "\nDepartment Name: " << Department.DepartmentName;
        cout << "\nNumber Rooms   : " << Department.NumberOfDepartmentRooms;
        cout << "\nNumber Beds    : " << Department.NumberOfRoomBeds;
        cout << "\n___________________\n";

    }


public:

    static void ShowAddNewDepartmentScreen()
    {



        _DrawScreenHeader("\t  Add New Department Screen");

        int ID;

        cout << "\nPlease Enter ID Number : ";
         ID=clsInputValidate::ReadIntNumber();
        while (clsInternalDepartments::IsDepartmentExist(ID))
        {
            cout << "\ID Number Is Already Used, Choose another one: ";
            cin >> ID;
        }

        clsInternalDepartments NewDepartment = clsInternalDepartments::GetAddNewDepartmentObject(ID);


        _ReadDepartmentInfo(NewDepartment);

        clsInternalDepartments::enSaveResults SaveResult;

        SaveResult = NewDepartment.Save();

        switch (SaveResult)
        {
        case  clsInternalDepartments::enSaveResults::svSucceeded:
        {
            cout << "\nID Addeded Successfully :-)\n";
            _PrintDepartment(NewDepartment);
            break;
        }
        case clsInternalDepartments::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError ID was not saved because it's Empty";
            break;

        }
        case clsInternalDepartments::enSaveResults::svFaildIDNumberExists:
        {
            cout << "\nError ID was not saved because ID number is used!\n";
            break;

        }

        }
    }



};

