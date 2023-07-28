#ifndef PRACTICECPP_USERFIELD_H
#define PRACTICECPP_USERFIELD_H

#endif //PRACTICECPP_USERFIELD_H

void assignUserID(){
    int currentUserNum;
    std::ifstream currentUserFile ("currentUser.txt", std::ios::in);
    if( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    currentUserFile >> currentUserNum;
    currentUserFile.close();

    std::ofstream currentUserNew ("currentUser.txt", std::ios::out);
    if( !currentUserNew.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    ++currentUserNum;
    currentUserNew << currentUserNum;
    currentUserNew.close();

    std::string userID = "USR_";
    std::string str1 = std::to_string(currentUserNum);
    userID += str1;
    list.userID = userID;
}

void assignUserName(){
    LOOP1:
    std::cin.sync();
    std::cout << "Username(10 Char Max): ";
    getline(std::cin, list.userName);

    for (int i = 0; list.userName[i] != '\0'; ++i) {
        if (i > 10){
            system("cls");
            std::cout << "Invalid Username.\nUsername must have 10 char Max." << std::endl;
            goto LOOP1;
        }
    }
    for (int i = 0; list.userName[i] != '\0'; ++i){
        if (list.userName[i] == ' '){
            std::cout << "Invalid Username.\nUsername must have no space." << std::endl;
            goto LOOP1;
        }
    }

    std::string fetchedStr;
    std::string checkUserName;
    std::ifstream currentUserFile ("userField.txt", std::ios::in);
    if ( !currentUserFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    while(currentUserFile){
        getline(currentUserFile, fetchedStr);
        if (fetchedStr.find("Username: ") != std::string::npos) {
            for (int i = 10; i < 50; ++i) {
                checkUserName.assign(fetchedStr,10,std::string::npos);
            }

            if (checkUserName == list.userName) {
                std::cout << "Username already exist.\nEnter another username.\n" << std::endl;
                goto LOOP1;
            }
        }
    }
    currentUserFile.close();
}

void assignPassword(){

    LOOP2:
    std::cin.sync();
    std::cout << "Password: ";
    getline(std::cin, list.password);

    for (int i = 0; list.password[i] != '\0'; ++i){
        if (list.password[i] == ' '){
            std::cout << "Invalid Password.\nPassword must have no space." << std::endl;
            goto LOOP2;
        }
    }
}

void assignUserDate(){
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);
    list.dateCreated = std::to_string(local_time->tm_mday) + '-' + std::to_string(1 + local_time->tm_mon)
                       + '-' + std::to_string(1900 + local_time->tm_year) + " "
                       + std::to_string(1 + local_time->tm_hour) + ':'
                       + std::to_string(1 + local_time->tm_min);
}

void assignLoginDate(){
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);
    list.loggedDate = std::to_string(local_time->tm_mday) + '-' + std::to_string(1 + local_time->tm_mon)
                       + '-' + std::to_string(1900 + local_time->tm_year) + " "
                       + std::to_string(1 + local_time->tm_hour) + ':'
                       + std::to_string(1 + local_time->tm_min);
}
void registerUser(){
    system("cls");
    std::cout << "=========================================\n" <<
                 "      Welcome to Registration Section    \n" <<
                 "=========================================\n";
    assignUserName();
    assignPassword();
    assignUserDate();
    assignUserID();
    assignSecretID();

    std::ofstream registerUser ("userField.txt", std::ios::app);
    if( !registerUser.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    registerUser << "=====================================================\n"
                    "UserID: " << list.userID << "\n" <<
                    "Username: " << list.userName << "\n" <<
                    "Password: " << list.password << "\n" <<
                    "Date Created: " << list.dateCreated << "\n" <<
                    "Last Login: " << list.dateCreated << "\n" <<
                    "SecretID: " << hidden.secreteID << "\n";

    std::cout << "Successfully registered." << std::endl;
    registerUser.close();
    system("pause");
    welcomePage();
}
