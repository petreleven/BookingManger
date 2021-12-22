#include<iomanip>
#include<iostream>
#include<ctime>
#include<string>
#include<chrono>

#include "password_MANAGE.h"


using namespace std;
static string password="GATHEE";
string line(50,'-');
string prompt="ENTER PASSWORD";
time_t max_time=60;
double MAXtrial=3;



void timeChecker()
{
    long long sec=0;
    time( &sec);
    string converted_time=ctime(&sec);
    cout<<converted_time<<endl;
}


void first_log_errors(int count,double Maxtrial ,long timeleft)
{
 
    if(count>MAXtrial)
    {
        cout<<"Too many attempts\n";
    }

    if  (timeleft<=0)
    {
        cout<<"TIME OUT";
    }
}



void change_password()
{
    string newPassword;
    string confirm_pass;
    do
    {
        cout<<line<<endl<<"ENTER NEW PASSWORD :";
        cin>>newPassword;
        bool confirmation=true;

        if(newPassword.size()>=confirmation)
        {
            cout<<endl<<"CONFIRM PASSWORD :";
            cin>>confirm_pass;
            if(confirm_pass!=newPassword)
                {
                    cout<<endl<<"PASSWORDS DONT MATCH"<<endl;
                }
        }
    } while(confirm_pass!=newPassword);


    cout<<endl<<"SUCCSSEFULY CHANGED PASSWORD"<<endl<<line<<endl;
    password==newPassword;

}

    

void getpassword()
{
    cout<<line<<endl<<"TIME OF ACCESS :";
    timeChecker();
    int count=0;
    
    time_t start,end,timeTaken;
    long timeleft=max_time;
    start=time(0);
    
    while(count<=MAXtrial  && timeleft>0)
    {
        ++count;
        string temp_pass;
        cout<<"ENTER PASSWORD :";
        cin>>temp_pass;
        end=time(0);
        timeTaken=end-start;
        timeleft=timeleft-timeTaken;
        if (temp_pass==password &&timeleft>0)
        {
            cout<<"SUCCESS\n";
            change_password();
            break;
        } 
        else
        {
            cout<<"Trials left :"<<MAXtrial-count<<endl;
            cout<<"Seconds left:"<<timeleft<<endl<<line<<endl;
        }

    }

    first_log_errors(count,MAXtrial,timeleft);
    
    
}