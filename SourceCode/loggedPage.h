#ifndef PRACTICECPP_LOGGEDPAGE_H
#define PRACTICECPP_LOGGEDPAGE_H

#endif //PRACTICECPP_LOGGEDPAGE_H

int displayUserBoard(){
    std::cin.sync();
    int option;
    LOOP3:
    std::cout << "1. Update my username" << std::endl;
    std::cout << "2. Add new Secret" << std::endl;
    std::cout << "3. Update Secret" << std::endl;
    std::cout << "4. View Secret" << std::endl;
    std::cout << "5. View Account Info" << std::endl;
    std::cout << "6. Back To Authentication" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Input: ";
    std::cin >> option;
    if (option < 1 || option > 7){
        std::cout << "Invalid Option." << std::endl;
        goto LOOP3;
    }
    return option;
}

void handleDisplayBoard(){
    std::cin.sync();
    int option = displayUserBoard();
    if(option == 1)
        userNameUpdater();
        //else if(option == 2)
        //addNewSecret();
    else if(option == 5)
        viewAccountInfo();
    else if(option == 6)
        login();
    else if(option == 7)
        farewell();
}

void userNameUpdater(){
    std::cin.sync();
    std::string newUserName;
    std::cout << "Enter New Username(10 Char Max): ";
    getline(std::cin, newUserName);
    newUserName = "Username: " + newUserName;
    oldUserName = "Username: " + oldUserName; //String to search

    std::ifstream filein("userField.txt"); //File to read from
    std::ofstream fileout("userFieldTemp.txt"); //Temporary file
    if(!filein || !fileout) //if both files are not available
    {
        std::cout << "Error opening files!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string strTemp;

    while(getline(filein, strTemp))//it will check line from test to strTemp string
    {
        if(strTemp == oldUserName)//if your word found then replace
        {
            strTemp = newUserName;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
    }
    filein.close();
    fileout.close();
    fetchedUserName = newUserName;
    remove("userField.txt");
    if (rename("userFieldTemp.txt", "userField.txt") != 0){
        std::cout << "Can't rename a file" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void viewAccountInfo(){
    std::cout << "==============================================" << std::endl;
    std::cout << "              Your Account Info               " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << list.userID << std::endl;
    std::cout << list.userName << std::endl;
    std::cout << list.password << std::endl;
    std::cout << "Last Success Login Date: " << list.loggedDate << std::endl;
    std::cout << "==============================================" << std::endl;
    system("pause");
    handleDisplayBoard();
}

int viewSecreteBoard(){
    std::cout << "1. View All" << std::endl;
    std::cout << "2. View By Date" << std::endl;
    std::cout << "3. View By Key" << std::endl;
}