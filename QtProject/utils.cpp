#include "utils.h"

utils::utils(){

}

void utils::getFrequency(const char c, float& frequencyLeft, float& frequencyUp){
    switch(c){
        case '1': case '2': case '3': case 'A': {
            frequencyLeft = constants::sideFrequencies[0];
            break;
        }
        case '4': case '5': case '6': case 'B': {
            frequencyLeft = constants::sideFrequencies[1];
            break;
        }
        case '7': case '8': case '9': case 'C': {
            frequencyLeft = constants::sideFrequencies[2];
            break;
        }
        case '*': case '0': case '#': case 'D': {
            frequencyLeft = constants::sideFrequencies[3];
            break;
        }
        default:{
                break;
        }
    }

    switch(c){
        case '1': case '4': case '7': case '*': {
            frequencyUp = constants::upperFrequencies[0];
            break;
        }
        case '2': case '5': case '8': case '0': {
            frequencyUp = constants::upperFrequencies[1];
            break;
        }
        case '3': case '6': case '9': case '#': {
            frequencyUp = constants::upperFrequencies[2];
            break;
        }
        case 'A': case 'B': case 'C': case 'D': {
            frequencyUp = constants::upperFrequencies[3];
            break;
        }
        default:{
                break;
        }
    }
}

char utils::getChar(int i, int j){
    return constants::digits[j+4*i];
}

std::string utils::filterNumber(std::string input){
    int i = 0;
    char lastChar = 0;
    std::string pivot = "";
    std::string result = "";
    for(char c : input){
        if(c != lastChar){
            pivot += c;
        }
        lastChar = c;
    }
    char d;
    if(pivot.length() > 5) d = '5';
    else d = '1';
    for(char c : pivot){
        result += c;
        if(c == d){
            result += d;
        }
    }
    return result;

}

std::string utils::called(std::string input){

    if (input.find("#911") != std::string::npos) {
        return "#911";
    }
    else if(input.find(constants::number) != std::string::npos) {
        return constants::number;
    }
    else return "";
}

void utils::writeFileLines(std::string fileName, float* input, int size){
    std::ofstream myfile(fileName.c_str(), std::ios_base::app | std::ios_base::out);
    std::string str;
    if(myfile.is_open()){
        for(int i = 0; i < size; ++i){
            str = std::to_string(input[i]);
            int commaPos = str.find(",");
            str.replace(commaPos, 1, ".");
            myfile << str << std::endl;
        }
        myfile.close();
    }
    else std::cerr<<"Unable to open file";
}
