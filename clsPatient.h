#pragma once
# include <iostream>
# include <vector>
# include <string>
# include <fstream>
# include "clsPerson.h"
# include "clsString.h"

using namespace std;

class clsPatient : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	
	string _BloodType;
	string _PatientSituation;
	string _Analayses;
	string _Medicine;
	string _LastOperations;

	bool _MarkedForDelete = false;

	static clsPatient _ConvertLinetoPatientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vPatientData;
		vPatientData = clsString::Split(Line, Seperator);

		return clsPatient(enMode::UpdateMode, vPatientData[0], vPatientData[1], stoi(vPatientData[2]),
			stoi(vPatientData[3]), vPatientData[4], vPatientData[5], vPatientData[6],
			vPatientData[7], vPatientData[8]);

	}

	static clsPatient _GetEmptyPatientObject()
	{
		return clsPatient(enMode::EmptyMode, "", "", -1, -1, "", "", "", "", "");
	}

	static  vector <clsPatient> _LoadPatientDataFromFile()
	{

		vector <clsPatient> vPatient;

		fstream MyFile;
		MyFile.open("Patients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsPatient Patient = _ConvertLinetoPatientObject(Line);

				vPatient.push_back(Patient);
			}

			MyFile.close();

		}

		return vPatient;

	}

	static string _ConverPatientObjectToLine(clsPatient Patient, string Seperator = "#//#")
	{

		string stPatientRecord = "";
		stPatientRecord += Patient.FirstName + Seperator;
		stPatientRecord += Patient.LastName + Seperator;
		stPatientRecord += to_string(Patient.ID ) + Seperator;
		stPatientRecord += to_string(Patient.Age) + Seperator;
		stPatientRecord += Patient.BloodType + Seperator;
		stPatientRecord += Patient.PatientSituation+Seperator;
		stPatientRecord += Patient.Analayses + Seperator;
		stPatientRecord += Patient.Medicine + Seperator;
		stPatientRecord += Patient.LastOperations;

		return stPatientRecord;

	}


	static void _SavePatientDataToFile(vector <clsPatient> vPatient)
	{

		fstream MyFile;
		MyFile.open("Patients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsPatient& C : vPatient)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverPatientObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Patients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}


	void _AddNew()
	{

		_AddDataLineToFile(_ConverPatientObjectToLine(*this));
	}

	void _Update()
	{
		vector <clsPatient> _vPatient;
		_vPatient = _LoadPatientDataFromFile();

		for (clsPatient& C : _vPatient)
		{
			if (C.ID == ID)
			{
				C = *this;
				break;
			}

		}

		_SavePatientDataToFile(_vPatient);

	}

public:

	clsPatient(enMode Mode, string FirstName, string LastName, int ID, int Age,
		string BloodType, string PatientSituation, string Analayses, string Medicine,
		string LastOperations) :clsPerson(FirstName, LastName, ID, Age)
	{
		_Mode = Mode;

		_BloodType = BloodType;
		_PatientSituation = PatientSituation;
		_Analayses = Analayses;
		_Medicine = Medicine;
		_LastOperations = LastOperations;

	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	void SetBloodType(string BloodType)
	{
		_BloodType = BloodType;
	}
	string GetBloodType()
	{
		return _BloodType;
	}
	__declspec(property(get = GetBloodType, put = SetBloodType)) string BloodType;

	void SetPatientSituation(string PatientSituation)
	{
		_PatientSituation = PatientSituation;
	}
	string GetPatientSituation()
	{
		return _PatientSituation;
	}
	__declspec(property(get = GetPatientSituation, put = SetPatientSituation)) string PatientSituation;

	void SetAnalayses(string Analayses)
	{
		_Analayses = Analayses;
	}
	string GetAnalayses()
	{
		return _Analayses;
	}
	__declspec(property(get = GetAnalayses, put = SetAnalayses)) string Analayses;

	void SetMedicine(string Medicine)
	{
		_Medicine = Medicine;
	}
	string GetMedicine()
	{
		return _Medicine;
	}
	__declspec(property(get = GetMedicine, put = SetMedicine)) string Medicine;

	void SetLastOperations(string LastOperations)
	{
		_LastOperations = LastOperations;
	}
	string GetLastOperations()
	{
		return _LastOperations;
	}
	__declspec(property(get = GetLastOperations, put = SetLastOperations)) string LastOperations;


	bool Delete()
	{
		vector <clsPatient> _vPatient;
		_vPatient = _LoadPatientDataFromFile();

		for (clsPatient& C : _vPatient)
		{
			if (C.ID == ID)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SavePatientDataToFile(_vPatient);

		*this = _GetEmptyPatientObject();

		return true;

	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
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
			if (clsPatient::IsPatientExist(ID))
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



	static bool IsPatientExist(int ID)
	{

		clsPatient Patient1 = Find(ID);
		return (!Patient1.IsEmpty());
	}
	static clsPatient GetAddNewPatientObject(int ID)
	{
		return clsPatient(enMode::AddNewMode, "", "", ID,0, "", "", "", "", "");
	}

	static clsPatient Find(int ID)
	{


		fstream MyFile;
		MyFile.open("Patients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsPatient Patient = _ConvertLinetoPatientObject(Line);
				if (Patient.GetID() == ID)
				{
					MyFile.close();
					return Patient;
				}

			}

			MyFile.close();

		}

		return _GetEmptyPatientObject();
	}

	 static vector <clsPatient> GetPatientsList()
	{
		return _LoadPatientDataFromFile();
	}

};

