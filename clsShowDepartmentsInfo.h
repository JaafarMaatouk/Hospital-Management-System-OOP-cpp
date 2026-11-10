#pragma once
# include <iostream>
# include "clsScreen.h"
# include "clsInternalDepartments.h"
# include <iomanip>

using namespace std;

class clsShowDepartmentsInfo:protected clsScreen
{
private:

    static void PrintDepartmentRecordLine(clsInternalDepartments Department)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << Department.DepartmentID;
        cout << "| " << setw(20) << left << Department.DepartmentName;
        cout << "| " << setw(20) << left << Department.NumberOfDepartmentRooms;
        cout << "| " << setw(20) << left << Department.NumberOfRoomBeds;
    

    }


public:
    static void ShowDepartmentsList()
    {

       
        vector <clsInternalDepartments> vDepartments = clsInternalDepartments::GetDepartmentsList();
        string Title = "\t  Departments List Screen";
        string SubTitle = "\t    (" + to_string(vDepartments.size()) + ") Departments(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Department ID";
        cout << "| " << left << setw(20) << "Department Name";
        cout << "| " << left << setw(20) << "Number Rooms";
        cout << "| " << left << setw(20) << "Number Beds";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vDepartments.size() == 0)
            cout << "\t\t\t\tNo Departments Available In the System!";
        else

            for (clsInternalDepartments& Department : vDepartments)
            {

                PrintDepartmentRecordLine(Department);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

