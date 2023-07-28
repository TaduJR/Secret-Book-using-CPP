#ifndef PRACTICECPP_AUTHENTICATION_H
#define PRACTICECPP_AUTHENTICATION_H

#endif //PRACTICECPP_AUTHENTICATION_H
std::string fetchedUserID;
std::string fetchedPass;
std::string fetchedUserName;
std::string fetchedDateCreated;
std::string secreteID;

std::string fetchedNetPass;
std::string oldUserName;

int passwordLine;

int loginUserName(){
    //Asks the user to enter his username login and returns the file line of its match
    std::string userNameTemp;
    system("cls");
    std::cout << "=========================================\n" <<
                 "         Welcome to Login Section        \n" <<
                 "=========================================\n";
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    LOOP1:std::cout << "Username: ";
    getline(std::cin, userNameTemp);

    int lineCounter = 0;

    std::cin.sync();
    std::string fetchedUserStr;
    std::string checkUserName;

    while(currentUserFile){
        ++lineCounter;
        getline(currentUserFile, fetchedUserStr);
        if (fetchedUserStr.find("Username: ") != std::string::npos) {
            checkUserName.assign(fetchedUserStr,10,std::string::npos);

            if (checkUserName == userNameTemp){
                oldUserName = userNameTemp;
                break;
            }

        }
    }

    currentUserFile.close();
    return lineCounter;
}

int numberOfline(){
    //Calculates the number of line in a given file
    int endOfFile = 0;
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cin.sync();
    std::string fetchCounter;
    while(!currentUserFile.eof() ){
        getline(currentUserFile, fetchCounter);
        ++endOfFile;
    }
    currentUserFile.close();
    return endOfFile;
}

void loginPassword(){
    //Fetches the password from from fetchedNetPass then it removes unnecessary strs.
    lineFetcher(passwordLine);
    fetchedNetPass.assign(fetchedPass,10,std::string::npos);
}

void userIDFetcher(int lineToFetch){
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    int fetchedLine = 0;
    while(currentUserFile){
        ++fetchedLine;
        getline(currentUserFile, fetchedUserID, '\n');
        if (fetchedLine == lineToFetch)
            break;
    }
    currentUserFile.close();
}

void userNameFetcher(int lineToFetch){
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    int fetchedLine = 0;
    while(currentUserFile){
        ++fetchedLine;
        getline(currentUserFile, fetchedUserName, '\n');
        if (fetchedLine == lineToFetch)
            break;
    }
    currentUserFile.close();
}

void lineFetcher(int lineToFetch){
    //Fetches specific line from its function argument
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    int fetchedLine = 0;
    while(currentUserFile){
        ++fetchedLine;
        getline(currentUserFile, fetchedPass, '\n');
        if (fetchedLine == lineToFetch)
            break;
    }
    currentUserFile.close();
}

void login(){
    std::cin.sync();
    int loginUserNameInt = loginUserName();
    passwordLine = loginUserNameInt;
    int userIDline = loginUserNameInt;
    ++passwordLine;
    --userIDline;

    int numberOflineInt = numberOfline();
    std::string tempPass;
    if(loginUserNameInt == numberOflineInt){
        std::cout << "Invalid Username.\nUnregistered user.\n";
        system("pause");
        welcomePage();
    } else{
        std::cin.sync();
        loginPassword();
        std::cout << "Password: ";
        getline(std::cin, tempPass);

        if(tempPass == fetchedNetPass){
            std::cout << std::endl;
            system("cls");
            std::cout << "Login Success." << std::endl;

            std::ifstream currentUserFile ("currentUser.txt", std::ios::in);
            if( !currentUserFile.is_open() ){
                std::cerr << "Can’t open file." << std::endl;
                exit(EXIT_FAILURE);
            }
            userIDFetcher(userIDline);
            ++userIDline;
            userNameFetcher(userIDline);
            list.userID = fetchedUserID;
            list.userName = fetchedUserName;
            list.password = fetchedPass;
            assignLoginDate(); //list.logdate
            //list.dateCreated = ;

            currentUserFile.close();
            handleDisplayBoard();
        } else{
            std::cout << std::endl;
            std::cout << "Login Failed.\nInvalid Password." << std::endl;
            system("pause");
            welcomePage();
        }
    }

}
