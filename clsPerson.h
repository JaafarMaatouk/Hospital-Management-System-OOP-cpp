#pragma once
# include <iostream>
using namespace std;

class clsPerson
{


private:

    string _FirstName;
    string _LastName;
    int _ID;
    int _Age;
   

public:


    clsPerson(string FirstName, string LastName, int ID, int Age)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _ID = ID;
        _Age = Age;
        
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set
    void SetID(int ID)
    {
        _ID = ID;
    }

    //Property Get
   int GetID()
    {
        return _ID;
    }
    __declspec(property(get = GetID, put = SetID)) int ID;



    //Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;


 


    //Property Set
    void SetAge(int Age)
    {
        _Age = Age;
    }

    //Property Get
    int GetAge()
    {
        return _Age;
    }
    __declspec(property(get = GetAge, put = SetAge)) int Age;

    
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

};

