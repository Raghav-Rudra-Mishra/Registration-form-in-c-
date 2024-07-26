#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Login{
    private:
    string userID;
    string password;
    public:
    Login(){

    }

    void setId(string id){
        userID = id;
    }

    void setPassword(string password){
        this->password = password;
    }

    string getId(){
        return userID;
    }

    string getPassword(){
        return password;
    }
};

void register_User(Login user){
    system("cls");

    string id,password;

    cout<<"\tEnter Username : ";
    cin>>id;
    user.setId(id);

    start:
    cout<<"\tEnter Password : ";
    cin>>password;
    if(password.length()>=8){
        user.setPassword(password);
    }else{
        cout<<"\tPassword must have atleast 8 characters"<<endl;
        goto start;
    }

    ofstream outfile("C:/Users/ragha/OneDrive/Desktop/Login.txt", ios::app);     //usable after including fstream header file. ofstream helps in writing data to the file and ifstream is used to get data from the file.
    if(!outfile){
        cout<<"\tError! File cannot be opened";
    }else{
        outfile<<"\t"<<user.getId()<<" : "<<user.getPassword()<<endl;
        cout<<"\tUser Registered Successfully!"<<endl;
    }
    outfile.close();
    Sleep(3000);
}


void login_user(){
    system("cls");
    string id,password;
    cout<<"\tEnter Username : "<<endl;
    cin>>id;

    cout<<"\tEnter Password : "<<endl;
    cin>>password;

    ifstream infile("C:/Users/ragha/OneDrive/Desktop/Login.txt");
    if(!infile){
        cout<<"\tSome Error Occured"<<endl;
    }else{
        string query;
        bool found = false;
        while(getline(infile,query)){
            stringstream ss;
            ss<<query;
            string UserId, userPass;
            char delimiter;
            ss>>UserId>>delimiter>>userPass;

            if(id == UserId && password == userPass){
                found = true;

                cout<<"\tPlease Wait";
                for(int i = 0; i<3; i++){
                    cout<<".";
                    Sleep(800);
                }
                system("cls");
                cout<<"\tWelcome to Chatify"<<endl;
            }
        }
        if(!found){
            cout<<"\tIncorrect Username or Password"<<endl;
        }
    }
    infile.close();
    Sleep(3000);
}

int main(){
    Login user;
    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to the Registration Portal"<<endl;
        cout<<"\t**********************************"<<endl;
        cout<<"\t1. Register"<<endl;
        cout<<"\t2. Login"<<endl;
        cout<<"\t3. Exit"<<endl;
        cout<<"\tSelect Option: "<<endl;
        cin>>val;

        if(val == 1){
            register_User(user);
        }else if(val == 2){
            login_user();
        }else if(val == 3){
            system("cls");
            exit = true;
            Sleep(3000);
        }else{
            cout<<"Incorrect Option!";
        }
        Sleep(3000);
    }
}