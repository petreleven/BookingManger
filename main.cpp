#include<iomanip>
#include<iostream>
#include<ctime>
#include<string>
#include<chrono>
#include "password_MANAGE.h"




















int main()
{
   std::string empty(50,'-');
   char b='B',ex='E';
   char choice;
   do
   {
        std::cout<<empty<<"WELCOME"<<empty<<std::endl;
        std::cout<<"B ::MAKE BOOKING\nE ::EXIT\n";
        std::cin>>choice;
        choice=toupper(choice);
        switch (choice)
        {
        case 'B':
            getpassword();
            break;
        case 'E':
            std::cout<<"THANKS FOR NOTHING";
        
        default:
            break;
        }

} while (choice!=ex);
    
}
