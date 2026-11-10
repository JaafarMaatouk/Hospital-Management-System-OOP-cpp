#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
# include "clsInputValidate.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {

        string UserName, Password;

        short FaildLoginCount = 0;


        cout << "\nEnter Username? ";
         UserName=clsInputValidate::ReadString();

        cout << "Enter Password? ";
         Password = clsInputValidate::ReadString();

        while (UserName != ("Jaafar Maatouk") || Password != ("000911"))
        {
            cout << "\nInvlaid Username/Password!";
            FaildLoginCount++;
            cout << "\nYou have " << (3 - FaildLoginCount)
                << " Trial(s) to login.\n\n";

            if (FaildLoginCount == 3) {

                cout << "\nYour are Locked after 3 faild trails \n\n";
                return;
            }
            cout << "Enter Username? ";
            UserName = clsInputValidate::ReadString();

            cout << "Enter Password? ";
            Password = clsInputValidate::ReadString();

            

        }

        clsMainScreen::ShowMainMenue();



    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t    Login Screen");
        _Login();

    }

};