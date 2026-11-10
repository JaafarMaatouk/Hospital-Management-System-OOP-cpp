#pragma once
# include <iostream>
# include <vector>
#include <string>
# include <fstream>
# include "clsString.h"

using namespace std;

class clsInternalDepartments
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	int _DepartmentID;
	string _DepartmentName;
	int _NumberOfDepartmentRooms;
	int _NumberOfRoomBeds;

	bool _MarkedForDelete = false;


	static clsInternalDepartments _ConvertLinetoDepartmentObject(string Line, string Seperator = "#//#")
	{
		vector<string> vDepartmentData;
		vDepartmentData = clsString::Split(Line, Seperator);

		return clsInternalDepartments(enMode::UpdateMode, stoi(vDepartmentData[0]), vDepartmentData[1]
			, stoi(vDepartmentData[2]), stoi(vDepartmentData[3]));

	}

	static string _ConverDepartmentObjectToLine(clsInternalDepartments Department, string Seperator = "#//#")
	{

		string stDepartmentRecord = "";
		stDepartmentRecord += to_string(Department.DepartmentID) + Seperator;
		stDepartmentRecord += Department.DepartmentName + Seperator;
		stDepartmentRecord += to_string(Department.NumberOfDepartmentRooms) + Seperator;
		stDepartmentRecord += to_string(Department.NumberOfRoomBeds);
		

		return stDepartmentRecord;

	}

	static clsInternalDepartments _GetEmptyDepartmentObject()
	{
		return clsInternalDepartments(enMode::EmptyMode, -1,"",-1,-1);
	}

	static  vector <clsInternalDepartments> _LoadDepartmentsDataFromFile()
	{

		vector <clsInternalDepartments> vDepartment;

		fstream MyFile;
		MyFile.open("Departments.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsInternalDepartments Department = _ConvertLinetoDepartmentObject(Line);

				vDepartment.push_back(Department);
			}

			MyFile.close();

		}

		return vDepartment;

	}

	static void _SaveDepartmentsDataToFile(vector <clsInternalDepartments> vDepartment)
	{

		fstream MyFile;
		MyFile.open("Departments.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsInternalDepartments& C : vDepartment)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverDepartmentObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsInternalDepartments> _vDepartment;
		_vDepartment = _LoadDepartmentsDataFromFile();

		for (clsInternalDepartments& C : _vDepartment)
		{
			if (C.DepartmentID == DepartmentID)
			{
				C = *this;
				break;
			}

		}

		_SaveDepartmentsDataToFile(_vDepartment);

	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Departments.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverDepartmentObjectToLine(*this));
	}

public:

	clsInternalDepartments(enMode Mode, int DepartmentID, string DepartmentName,
		int NumberOfDepartmentRooms, int NumberOfRoomBeds) {

		_Mode = Mode;

		_DepartmentID = DepartmentID;
		_DepartmentName = DepartmentName;
		_NumberOfDepartmentRooms = NumberOfDepartmentRooms;
		_NumberOfRoomBeds = NumberOfRoomBeds;
	}


	void setDepartmentID(int DepartmentID) {

		_DepartmentID = DepartmentID;
	}
	int GetDepartmentID() {
		return _DepartmentID;
	}
	__declspec(property(get = GetDepartmentID, put = SetDepartmentID))int DepartmentID;


	void SetDepartmentName(string DepartmentName) {

		_DepartmentName = DepartmentName;
	}
	string GetDepartmentName() {
		return _DepartmentName;
	}
	__declspec(property(get = GetDepartmentName, put = SetDepartmentName)) string DepartmentName;

	void SetNumberOfDepartmentRooms(int NumberOfDepartmentRooms) {

		_NumberOfDepartmentRooms = NumberOfDepartmentRooms;
	}
	int GetNumberOfDepartmentRooms() {
		return _NumberOfDepartmentRooms;
	}
	__declspec(property(get = GetNumberOfDepartmentRooms, put = SetNumberOfDepartmentRooms))int NumberOfDepartmentRooms;


	void SetNumberOfRoomBeds(int NumberOfRoomBeds) {

		_NumberOfRoomBeds = NumberOfRoomBeds;
	}
	int GetNumberOfRoomBeds() {
		return _NumberOfRoomBeds;
	}
	__declspec(property(get = GetNumberOfRoomBeds, put = SetNumberOfRoomBeds))int NumberOfRoomBeds;

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildIDNumberExists = 2 };
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsInternalDepartments::IsDepartmentExist(DepartmentID))
			{
				return enSaveResults::svFaildIDNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}



	}


	static clsInternalDepartments GetAddNewDepartmentObject(int ID)
	{
		return clsInternalDepartments(enMode::AddNewMode,ID,"",0,0);
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector <clsInternalDepartments> GetDepartmentsList()
	{
		return _LoadDepartmentsDataFromFile();
	}
	bool Delete()
	{
		vector <clsInternalDepartments> _vDepartments;
		_vDepartments = _LoadDepartmentsDataFromFile();

		for (clsInternalDepartments& C : _vDepartments)
		{
			if (C.DepartmentID == _DepartmentID)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveDepartmentsDataToFile(_vDepartments);

		*this = _GetEmptyDepartmentObject();

		return true;

	}

	static bool IsDepartmentExist(int ID)
	{

		clsInternalDepartments Department1 = Find(ID);
		return (!Department1.IsEmpty());
	}
	static clsInternalDepartments Find(int ID)
	{


		fstream MyFile;
		MyFile.open("Departments.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsInternalDepartments Department = _ConvertLinetoDepartmentObject(Line);
				if (Department.DepartmentID == ID)
				{
					MyFile.close();
					return Department;
				}

			}

			MyFile.close();

		}

		return _GetEmptyDepartmentObject();
	}

};

