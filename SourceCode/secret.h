#ifndef PRACTICECPP_SECRET_H
#define PRACTICECPP_SECRET_H

#endif //PRACTICECPP_SECRET_H

void assignSecretID(){
    int currentSecretNum;
    std::ifstream currentSecretFile ("currentSecret.txt", std::ios::in);
    if( !currentSecretFile.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    currentSecretFile >> currentSecretNum;
    currentSecretFile.close();

    std::ofstream currentSecretNew ("currentSecret.txt", std::ios::out);
    if( !currentSecretNew.is_open() ){
        std::cerr << "Can’t open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    ++currentSecretNum;
    currentSecretNew << currentSecretNum;
    currentSecretNew.close();

    std::string secretID = "SEC_";
    std::string str1 = std::to_string(currentSecretNum);
    secretID += str1;
    hidden.secreteID = secretID;

    std::string fileSecretFormat = hidden.secreteID + ".txt";
    //Create a secret file for specific user
    std::ofstream currentSecretCreate (fileSecretFormat, std::ios::out);
}

void addSecret(){

}
