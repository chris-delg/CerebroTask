#include "../include/UserTxtData.hpp"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void UserTxtData::writeData(string fileName){
    writeTxt.open(fileName, ios::out);

    if(writeTxt.is_open()){
        for(auto& iter : loginInfo){
            string info = iter.first + " " + iter.second + "\n";
            writeTxt << info;
        }
    }

    writeTxt.close();
}

void UserTxtData::readData(string fileName){
    readTxt.open(fileName, ios::in);
    
    if(readTxt.is_open()){
        string line;
        while(getline(readTxt, line)){
            string key = "";
            string val = "";
            bool spaceFound = false;

            for(int i = 0; i < line.length(); i++){
                if(line[i] == ' '){
                    spaceFound = true;
                    continue;
                } 

                if(spaceFound){
                    val += line[i];
                }
                else{
                    key += line[i];
                }
            }
            
            loginInfo[key] = val;
        }
    }

    readTxt.close();
}
