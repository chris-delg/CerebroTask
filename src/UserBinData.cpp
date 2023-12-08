#include "../include/UserBinData.hpp"
#include "../include/UserData.hpp"
#include "../include/Task.hpp"

#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void UserBinData::writeData(string fileName){
    writeBin.open(fileName, ios::out | ios::binary);

    if(writeBin.is_open()){
        writeBin.write(reinterpret_cast<char*>(getUser()->getTasks()), 50 * sizeof(Task));
    }

    writeBin.close();
}

void UserBinData::readData(string fileName){
    readBin.open(fileName, ios::in | ios::binary);
    Task binFileTasks[50];

    if(readBin.is_open()){
        readBin.read(reinterpret_cast<char*>(binFileTasks), 50 * sizeof(Task));
    }

    memcpy(getUser()->getTasks(), binFileTasks, 50 * sizeof(*(getUser()->getTasks())));

    readBin.close();
}