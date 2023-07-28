#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>

void welcomePage();

int numberOfline();
void assignUserID();
void assignUserName();
void assignPassword();
void assignUserDate();
void assignLoginDate();
void registerUser();

void login();
int loginUserName();
void loginPassword();
void lineFetcher(int);
void userIDFetcher();
void viewAccountInfo();
void userNameFetcher();

int displayUserBoard();
void handleDisplayBoard();
int viewSecreteBoard();
void userNameUpdater();

void addNewSecret();
void assignSecretID();

void farewell();

struct user {
    std::string userID;
    std::string password;
    std::string userName;
    std::string dateCreated;
    std::string loggedDate;
}list;

struct secrete {
    std::string secreteID;
    std::string dateCreated;
    std::string lastUpdate;
}hidden;

int main() {

    welcomePage();


    system("pause");
    return 0;
}

#include "authentication.h"
#include "userField.h"
#include "loggedPage.h"
#include "secret.h"

void welcomePage(){
    int option;
    system("cls");
    LOOP1:std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Input: ";
    std::cin >> option;
    if(option < 1 || option > 3)
        goto LOOP1;

    do{
        if(option == 1)
            registerUser();
        else if(option == 2)
            login();
        else if(option == 3){
            farewell();
            break;
        }
    }while(true);
}

void farewell(){
    std::cout << "===================================================\n" <<
              "Exiting...\n" <<
              "Thank you for using our application.\n" <<
              "Made by Natnael.T and Ruth.E.\nPowered by CLion.\n" <<
              "====================================================" << std::endl;
    system("pause");
    exit(EXIT_SUCCESS);
}

