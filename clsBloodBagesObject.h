#pragma once
# include <iostream>
# include <vector>
#include <string>
# include <fstream>
# include "clsString.h"

using namespace std;
class clsBloodBagesObject

{
private:
	enum enMode { EmptyMode = 0, ExistsMode = 1, AddNewMode = 2 };
	enMode _Mode;

	int _BloodBageID;
	string _BloodType;
	string _BloodDonationDate;
	

	bool _MarkedForDelete = false;


	static clsBloodBagesObject _ConvertLinetoBloodBageObject(string Line, string Seperator = "#//#")
	{
		vector<string> vBloodBagesInfo;
		vBloodBagesInfo = clsString::Split(Line, Seperator);

		return clsBloodBagesObject(enMode::ExistsMode, stoi(vBloodBagesInfo[0]), vBloodBagesInfo[1]
			, vBloodBagesInfo[2]);

	}

	static string _ConverBloodBageObjectToLine(clsBloodBagesObject BloodBage, string Seperator = "#//#")
	{

		string stBloodBageRecord = "";
		stBloodBageRecord += to_string(BloodBage.BloodBageID) + Seperator;
		stBloodBageRecord += BloodBage.BloodType+ Seperator;
		stBloodBageRecord += BloodBage.BloodDonationDate;



		return stBloodBageRecord;

	}

	static clsBloodBagesObject _GetEmptyBloodBageObject()
	{
		return clsBloodBagesObject(enMode::EmptyMode, -1, "", "");
	}

	static  vector <clsBloodBagesObject> _LoadBloodBagesDataFromFile()
	{

		vector <clsBloodBagesObject> vBloodBage;

		fstream MyFile;
		MyFile.open("BloodBank.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBloodBagesObject BloodBage = _ConvertLinetoBloodBageObject(Line);

				vBloodBage.push_back(BloodBage);
			}

			MyFile.close();

		}

		return vBloodBage;

	}



	static void _SaveBloodBagesDataToFile(vector <clsBloodBagesObject> vBloodBage)
	{

		fstream MyFile;
		MyFile.open("BloodBank.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBloodBagesObject& C : vBloodBage)
			{
				if (C.MarkedForDeleted() == false)
				{
					DataLine = _ConverBloodBageObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("BloodBank.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}


	void _AddNew()
	{

		_AddDataLineToFile(_ConverBloodBageObjectToLine(*this));
	}

public:

	clsBloodBagesObject(enMode Mode, int BloodBageID, string BloodType,
		string BloodDonationDate) {

		_Mode = Mode;

		_BloodBageID = BloodBageID;
		_BloodType = BloodType;
		_BloodDonationDate = BloodDonationDate;
	}


	void SetBloodBageID(int BloodBageID) {

		_BloodBageID = BloodBageID;
	}
	int GetBloodBageID() {
		return _BloodBageID;
	}
	__declspec(property(get = GetBloodBageID, put = SetBloodBageID))int BloodBageID;


	void SetBloodType(string BloodType) {

		_BloodType = BloodType;
	}
	string GetBloodType() {
		return _BloodType;
	}
	__declspec(property(get = GetBloodType, put = SetBloodType)) string BloodType;

	void SetBloodDonationDate(string BloodDonationDate) {

		_BloodDonationDate = BloodDonationDate;
	}
	string GetBloodDonationDate() {
		return _BloodDonationDate;
	}
	__declspec(property(get = GetBloodDonationDate, put = SetBloodDonationDate))string BloodDonationDate;


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

		

		case enMode::AddNewMode:
		{
			if (clsBloodBagesObject::IsBloodBageExist(BloodBageID))
			{
				return enSaveResults::svFaildIDNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::ExistsMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}



	}


	static clsBloodBagesObject GetAddNewBloodBageObject(int BloodBageID)
	{
		return clsBloodBagesObject(enMode::AddNewMode, BloodBageID, "","");
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector <clsBloodBagesObject> GetBloodBagesList()
	{
		return _LoadBloodBagesDataFromFile();
	}
	bool Delete()
	{
		vector <clsBloodBagesObject> _vBloodBages;
		_vBloodBages = _LoadBloodBagesDataFromFile();

		for (clsBloodBagesObject& C : _vBloodBages)
		{
			if (C.BloodBageID == _BloodBageID)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveBloodBagesDataToFile(_vBloodBages);

		*this = _GetEmptyBloodBageObject();

		return true;

	}

	static bool IsBloodBageExist(int ID)
	{

		clsBloodBagesObject BloodBage1 = Find(ID);
		return (!BloodBage1.IsEmpty());
	}
	static clsBloodBagesObject Find(int ID)
	{


		fstream MyFile;
		MyFile.open("BloodBank.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBloodBagesObject BloodBage = _ConvertLinetoBloodBageObject(Line);
				if (BloodBage.BloodBageID == ID)
				{
					MyFile.close();
					return BloodBage;
				}

			}

			MyFile.close();

		}

		return _GetEmptyBloodBageObject();
	}

};



