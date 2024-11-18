
#include <iostream>
#include <fstream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

class User
{
private:
    char username[50];
    char password[50];
public:
    User() {};
    User(const char* uname, const char* pword)
    {
        strcpy(username, uname);
        strcpy(password, pword);
    }
    char* getUsername()
    {
        return username;
    }
    char* getPassword()
    {
        return password;
    }
    void show()
    {
        cout<<username<<"\t"<< password<<endl;
    }
} user;

class Registration: public User
{
private:
    char user_name[50];
    char pass_word[50];

public:
    Registration() {};
    Registration(const char* uname, const char* pword)
    {
        strcpy(user_name, uname);
        strcpy(pass_word, pword);
    }

    void signup()
    {
        cout << "\nEnter username: ";
        cin >> user_name;
        cout << "\nEnter password: ";
        cin >> pass_word;

        User user(user_name,pass_word);

        ofstream file("users.bin", ios::binary | ios::app);
        if (file.is_open())
        {
            file.write((char*)&user, sizeof(User));
            cout << "Account created successfully!" << endl;
            file.close();
        }
    }
    ~Registration()
    {

    }
};

class Login: public User, public Registration
{
private:
    char new_user[50];
    char Password[50];
public:
    Login() {};
    Login(const char* uname, const char* pword)
    {
        strcpy(new_user, uname);
        strcpy(Password, pword);
    }
    int login()
    {
        int n;

        cout << "\nEnter username: ";
        cin >> new_user;
        cout << "\nEnter password: ";
        cin >> Password;

        User user;

        ifstream file("users.bin", ios::binary);
        if (file.is_open())
        {
            while (file.read((char*)&user, sizeof(User)))
            {
                if (strcmp(user.getUsername(), "") != 0 && strcmp(user.getUsername(), new_user) == 0 && strcmp(user.getPassword(), Password) == 0)
                {
                    system("cls");
                    cout<<"\n\t\t\tHello "<<new_user <<"! \n\t\t\tYour login is successful!!\n";
                    //cout << "Login successful!" << endl;
                    n=1;
                    file.close();
                    return n;
                }
            }
            cout << "\n\n\tError!!!\n\tInvalid username or password!" << endl<<endl;
            n=0;
            return n;
            file.close();
        }
    }
    ~Login()
    {

    }
};

class Income
{
public:
    int Revenue;
public:
    Income(): Revenue(0)                                      ///Constructor///
    {

    }
    Income(int i): Revenue(i)
    {

    }
    ~Income()                                                 ///Destructor///
    {

    }
    void Entry_Data()
    {
        cout<<"Enter Revenue: ";
        cin>>Revenue;
    }
    void Showdata()
    {
        cout<<"The revenue is: "<<Revenue<<endl<<endl;
    }
};
class Expenses
{
protected:

    int Food;
    int Education;
    int Treatment;
    int Billing;
    int Shopping;
    int Communication;
    int Extra;

public:
    int Total_Cost;
    Expenses(): Food(0),Education(0),Treatment(0),Billing(0),Shopping(0),Communication(0),Extra(0)
    {

    }
    Expenses(int F, int E, int T, int B, int S, int C, int Ex ):Food(F),Education(E),Treatment(T),Billing(B),Shopping(S),Communication(C),Extra(Ex)
    {

    }

    void Entry_Data()
    {

        cout<<"Enter cost for Food: ";
        cin>>Food;
        cout<<"Enter cost for Education: ";
        cin>>Education;
        cout<<"Enter cost for Treatment: ";
        cin>>Treatment;

        cout<<"Enter cost for shopping: ";
        cin>>Shopping;
        cout<<"Enter cost for Communication: ";
        cin>>Communication;
        cout<<"Enter cost for Extra: ";
        cin>>Extra;
    }
    void Get_billing()
    {
        cout<<"Enter cost for billing: ";
        cin>>Billing;
    }
    void Get_Total_Cost()
    {

        Total_Cost=Food+Education+Treatment+Shopping+Communication+Extra;
        cout<<"\nYour Total Cost is: "<<Total_Cost;
        cout<<endl<<endl;
    }
    void Get_Final_cost()
    {

        Total_Cost=Food+Education+Treatment+Shopping+Communication+Extra+Billing;

    }
    void show_cost()
    {
        cout<<"\nYour Final cost is: "<<Total_Cost;

    }
    virtual void get_data()=0;
    virtual void get_billing()=0;
    virtual int get_Total_Cost()=0;
    virtual int get_Final_cost()=0;

    ~Expenses()
    {

    }

};


class village :public Expenses
{
public:
    int COST_V;
public:
    village()
    {
        COST_V=0;
    }
    ~village()
    {

    }
    void get_data()
    {
        Expenses::Entry_Data();
    }
    void get_billing()
    {
        Expenses::Get_billing();
    }
    int get_Total_Cost()
    {
        Expenses::Get_Total_Cost();
        COST_V=Expenses::Total_Cost;
        return COST_V;

    }
    int get_Final_cost()
    {
        Expenses::Get_Final_cost();
        COST_V=Expenses::Total_Cost;
        cout<<"\nYour Cost is :"<<COST_V<<endl;
        return COST_V;
    }
    village operator + (village);
};
village village :: operator + (village v1)
{
    village v2;
    v2.COST_V=COST_V + v1.COST_V;
    return v2;
}

class town :public Expenses
{
protected :
    int rent;
    int COST_T;
public:
    town(): rent(0),COST_T(0)
    {

    }
    void get_data()
    {
        Expenses::Entry_Data();
    }
    void get_billing()
    {
        cout<<"Enter cost for rent: ";
        cin>>rent;
        Expenses::Get_billing();
    }
    int get_Total_Cost()
    {
        Expenses::Get_Total_Cost();
        COST_T=Expenses::Total_Cost;
        return COST_T;
    }
    int get_Final_cost()
    {
        Expenses::Get_Final_cost();

        COST_T=Expenses::Total_Cost;
        cout<<"\nYour Cost is :"<<COST_T+rent<<endl;
        return COST_T+rent;
    }
    ~town()
    {

    }
    town operator + (town);

};

town town :: operator + (town t1)
{
    town t2;
    t2.COST_T=COST_T+t1.COST_T;
    return t2;
}
class Savings: public Income
{
public:
    int savings;
public:
    Savings(): savings(0)
    {

    }
    Savings(int sv): savings(sv)
    {

    }
    void calculate_savings(Income p1,int cost)
    {

        savings=p1.Revenue-cost;
        if(savings<0)
        {
            savings=0;
        }

    }
    void Show_savings()
    {
        cout<<"\nYour savings is: "<<savings<<endl;
    }
    ~Savings()
    {

    }

};

class Advice: public Savings
{
private:
    char Month[15];
    int Target;
public:
    Advice()
    {
        Target=0;

    }
    Advice(int tgt): Target(tgt)
    {

    }
    ~Advice()
    {

    }
    void Get_Data()
    {
        cout<<"\nEnter The Month: ";
        cin>>Month;
        cout<<"\nEnter Your Target: ";
        cin>>Target;
    }
    void Show_Data()
    {
        cout<<"\n\nIn "<<Month<<": \n\n";
        cout<<"\nYour Target was: "<<Target<<endl;
    }
    void Advise( Savings s1)
    {
        if((s1.savings)>=Target)
        {
            cout<<"\nTarget is Fulfilled :) \n";
        }
        else
        {
            cout<<"\nTarget is not fulfilled\nYou have to be Frugal\n";
        }
    }
};
class Account
{
    //data can't be variable length,otherwise any type of data
    char username[50];
    char password[50];
    char records[10000];
public:
    Account()
    {
        strcpy(username,"na");
        strcpy(password,"na");
        strcpy(records,"");
    };
    void make_account()
    {
        cout<<"Enter username : ";
        cin>>username;
        cout<<"Enter password : ";
        cin>>password;
    }
    void show()
    {
        cout<<"Your username : "<<username<<endl;
        cout<<"Records : Month            Saving\n";
        cout<<records<<endl;
    }
    void do_records(char *mon,int savings1)
    {
        char str[100];
        sprintf(str,"%15s      %10d \n",mon,savings1);
        strcat(records,str);
    }
    bool log(char *u,char *p)
    {
        if(strcmp(username,u)==0 && strcmp(password,p)==0)
        {
            return true;
        }
        return false;
    }

};
class AccountFile: public Account
{
    vector<Account> vec;
public:
    AccountFile() {}
    void load()
    {
        //file name will be the name of the file that'll be stored in hard-drive
        vec.clear();
        string filename = "Account.bin";
        ifstream ifile(filename,ios::binary);
        Account tmp;
        while(ifile.read(reinterpret_cast<char*>(&tmp),sizeof(Account)))
        {
            vec.push_back(tmp);
        }
        ifile.close();
    }
    void update()
    {
        //file name will be the name of the file that'll be stored in hard-drive
        string filename = "Account.bin";
        ofstream ofile(filename,ios::binary);
        for(auto tmp:vec)
        {
            ofile.write(reinterpret_cast<char*>(&tmp),sizeof(Account));
        }
        ofile.close();
    }
    void add_account()
    {
        Account tmp;
        tmp.make_account();
        vec.push_back(tmp);
        update();

    }
    void login()
    {
        cout<<"\n\t\tUSERNAME: ";
        char usr[50];
        cin>>usr;
        cout<<"\n\t\tPASSWORD: ";
        char pas[50];
        cin>>pas;
        cout<<endl;
        for(auto &p:vec)
        {
            if(p.log(usr,pas))
            {
                system("cls");
                cout<<"\n\n\tSuccessfully Logged in!!!\n\n";
                cout<<"\t\t\tUsers Record\n";
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
                while(true)
                {
                    cout<<"\n\tPress 1: To Add new record\n";
                    cout<<"\tPress 2: To see previous record\n";
                    cout<<"\tPress 0: To Exit\n";
                    cout<<"\t\tEnter Your choice -> ";
                    int button;
                    cin>>button;
                    cout<<endl<<endl;
                    if(button ==1)
                    {
                        //menu;
                        char mon[15];
                        cout<<"\tEnter the Month: ";
                        cin>>mon;
                        int save3;
                        cout<<"\n\tEnter Savings: ";
                        cin>>save3;
                        cout<<endl<<endl;
                        p.do_records(mon,save3);
                        system("pause");
                    }
                    if(button == 2)
                    {
                        p.show();
                        system("pause");
                    }
                    if(button ==0)
                    {
                        system("cls");
                        break;
                    }
                }

                return ;
            }

        }
        cout<<"\n\t\tLogin Failed. Try Again!! \n\n";
    }
    void show()
    {
        for(auto &a:vec)
        {
            a.show();
        }
        cout<<endl;
    }

};
int main()
{
    cout<<"      \n\t\t\t\t--------------------------------";
    cout<<"   \n\t\t\t\t| Personal Expenses and savings |";
    cout<<"      \n\t\t\t\t--------------------------------";
    cout<<"      \n\n\n\t\t\t\t\t   Submitted by: \n\n";
    cout<<"      \t\t\t\tNahida Akther Reshmi  Roll-365\n\t\t\t\tUmme Anom             Roll-368\n\n\n";
    cout<<"      \n\n\t\t\t\t\t   Submitted to : \n\n";;
    cout<<"      \t\t\t\t\tDr. Md. Ezharul Islam\n";
    cout<<"        \t\t\t\t\tProfessor\n";
    cout<<"  \t\t\t\tDepartment of Computer Science and Engineering\n";
    cout<<"             \t\t\t\tJahangirnagar University\n\n\n";

    cout<<"       \t\t\t\t";
    system("pause");
    system("cls");
    Login log1;
    Registration log2;
    int choice,fun;
    int N=1;
    cout<<"\n\t\t\t\tSince you're Here, You're Wise :)\n";
    while(N==1)
    {
        cout<<"\n\tEnter 1: SignIn/LogIn"<<endl;
        cout<<"\tEnter 2: SignUp/Register"<<endl;
        cout<<"\t\tEnter your choice -> ";
        cin>>choice;
        if(choice==1)
        {
            fun=log1.login();

            if(fun==1)
            {
                N=2;
            }
            else
            {
                N=1;
            }

        }
        else if(choice==2)
        {
            log2.signup();

            N=1;
        }
    }
    cout<<endl;

    if(N==2)
    {
        Expenses *person[6];
        int n=0;

        char c;
        cout<<"Do you live in Village or Town ?(v/t)"<<endl<<endl;
        cout<<"Enter your Answer-> ";
        cin>>c;
        system("cls");
        if(c=='v')
        {


            Advice F1;
            F1.Get_Data();
            cout<<endl;
            Income rev1;
            rev1.Entry_Data();
            cout<<endl;
            person[0]=new village;
            cout<<"\n\t\tFor First 10 Days...\n";
            cout<<" --------------------------------------------\n\n";
            person[0]->get_data();
            int a=person[0]->get_Total_Cost();
            if(a>((rev1.Revenue)/3))
            {
                cout<<"\nWarning!!!\n\nYou have crossed your limit....\nSpend money more wisely\n\n";
            }
            system("pause");
            system("cls");

            cout<<"\n\t\tFor Second 10 Days...\n";
            cout<<" --------------------------------------------\n\n";

            person[1]=new village;
            person[1]->get_data();
            int b=person[1]->get_Total_Cost();

            if(b>((rev1.Revenue)/3))
            {
                cout<<"\nWarning!!!\n\nYou have crossed your limit....\nSpend money more wisely\n\n";
            }
            int i;
            system("pause");

            system("cls");

            cout<<"\n\t\tFor Last 10 Days...\n";
            cout<<" --------------------------------------------\n\n";

            person[2]=new village;
            person[2]->get_data();
            person[2]->get_billing();
            int c=person[2]->get_Final_cost();


            system("pause");
            system("cls");

            cout<<"\n\t\tFinal Calculation";
            cout<<"\n------------------------------------------------\n\n";

            int cost2=a+b+c;


            F1.Show_Data();
            cout<<"Your Final Cost is: "<<cost2<<endl;

            Savings save2;

            save2.calculate_savings(rev1, cost2);
            save2.Show_savings();
            F1.Advise(save2);


            system("pause");
            system("cls");

        }

        else if(c='t')
        {
            Advice F2;
            F2.Get_Data();
            cout<<endl;
            Income rev2;
            rev2.Entry_Data();
            cout<<endl;
            person[0]=new town;
            cout<<"\n\t\tFor First 10 Days...\n";
            cout<<" --------------------------------------------\n\n";
            person[0]->get_data();
            int a=person[0]->get_Total_Cost();

            if(a>((rev2.Revenue)/3))
            {
                cout<<"\nWarning!!!\n\nYou have crossed your limit....\nSpend money more wisely\n\n";
            }
            int i;
            system("pause");
            system("cls");

            cout<<"\n\t\tFor Second 10 Days...\n";
            cout<<" --------------------------------------------\n\n";

            person[1]=new town;
            person[1]->get_data();
            int b=person[1]->get_Total_Cost();

            if(b>((rev2.Revenue)/3))
            {
                cout<<"\nWarning!!!\n\nYou have crossed your limit....\nSpend money more wisely\n\n";
            }

            system("pause");
            system("cls");

            cout<<"\n\t\tFor Last 10 Days...\n";
            cout<<" --------------------------------------------\n\n";

            person[2]=new town;
            person[2]->get_data();
            person[2]->get_billing();
            int c=person[2]->get_Final_cost();

            system("pause");
            system("cls");

            cout<<"\n\t\tFinal Calculation";
            cout<<"\n------------------------------------------------\n\n";

            int cost1=a+b+c;
            F2.Show_Data();
            cout<<"Your Final Cost for this month is: "<<cost1<<endl;

            Savings save1;
            save1.calculate_savings( rev2, cost1);
            save1.Show_savings();

            F2.Advise(save1);


            system("pause");
            system("cls");
        }


    }
        cout<<"\n\t\t\tRecord of Savings...\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    s:
        int button;

        AccountFile c1;
        c1.load();

        cout<<"\n\tEnter 1: Create Account"<<endl;
        cout<<"\tEnter 2: Login"<<endl;
        cout<<"\tEnter 3: Show Full Record"<<endl;
        cout<<"\tEnter 0: Exit"<<endl;

        cout<<"\t\tEnter your choice -> ";
        cin>>button;
        if(button==1)
        {
            c1.add_account();
        }
        else if(button==2)
        {
            c1.login();

        }
        else if(button ==3)
        {
            c1.show();
        }
        else if(button==0)
        {
            exit(0);
        }
        c1.update();
        goto s;
}
