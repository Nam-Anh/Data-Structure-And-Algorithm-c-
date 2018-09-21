#include <iostream>
#include <fstream>
#include <vector>
#include "../Singly_Linked_List.h"
#include <string>
#include <limits.h>
#include <unistd.h>
#include <complex>

using namespace std;
/*---------------------------- Prototype -------------------------------------*/
/*-------------------------- I/O Functions -----------------------------------*/
void readFromFile(const char* fileName, int num_of_line, vector<char>& storing_vect);
void writeToFile(const char* fileName, vector<string>& result);
/*---------------------- Processing functions --------------------------------*/
void moveUnreadToRead(float num, SSL<float>& Unread, SSL<float>& Trash);
void moveReadToTrash(float num, SSL<float>& Unread, SSL<float>& Trash);
void moveUnreadToTrash(float num, SSL<float>& Unread, SSL<float>& Trash);
void moveTrashToRead(float num, SSL<float>& Unread, SSL<float>& Trash);
void manageMove(string choice, string mail_key,
        SSL<float>& Unread, SSL<float>& Read, SSL<float>& Trash);
void finalStep(vector<char> property, vector<char> all_character,
        SSL<float>& Unread, SSL<float>& Read, SSL<float>& Trash);

/*---------------------- Supporting functions --------------------------------*/
int convertToInt(string str);
float convertToFloat(string str);
vector<string> convertToString(vector<char> list_of_char);
void normalize(vector<char>& list_character);

std::string getexepath() {
    char result[ PATH_MAX ];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return std::string(result, (count > 0) ? count : 0);
}

/*------------------------ Functions Details ---------------------------------*/
/*Integer conversion*/
int convertToInt(string str) {
    int num;
    std::string::size_type sz;
    num = std::stoi(str, &sz);

    return num;
}

/*Float conversion*/
float convertToFloat(string str) {
    float num;
    std::string::size_type sz;
    num = std::stof(str, &sz);

    return num;
}

/*String conversion*/
vector<string> convertToString(vector<char> list_of_char) {
    /*Create ending mark to vector of char
     Cause when reaching over the last element, the loop is automatically out
     So the last created string has not been added to the list of string
     By creating this mark, the last string will be considered and added to the list*/
    list_of_char.push_back(' ');

    //Main processing
    bool started = false;
    vector<string> list_of_str;
    string str;
    for (int i = 0; i < list_of_char.size(); ++i) {
        //Check if current char is number or not
        if ((list_of_char[i] >= '0') && (list_of_char[i] <= '9')) {
            started = true;
        } else {
            if (!str.empty()) {
                list_of_str.push_back(str);
                str.clear();
            }
            started = false;
        }
        //Create new string
        if (started) {
            str.push_back(list_of_char[i]);
        }
    }

    return list_of_str;
}

/*Read data from file*/
void readFromFile(const char* fileName, int num_of_line, vector<char>& storing_vect) {
    ifstream in;
    in.open(fileName, ios::in);
    if (!in.is_open()) {
        cout << "This file does not exist to read\n";
        return;
    }
    char character;
    int count = 0;
    while (!in.eof()) {
        //Get in character
        in.get(character);
        //Get all character after two newline
        if (count == num_of_line) {
            storing_vect.push_back(character);
        }
        if (character == '\n') count++;
    }
    in.close();
}

/*Write output which is the mail system result to file*/
void writeToFile(const char* fileName, vector<string> result) {
    ofstream out;
    out.open(fileName, ios::out);
    if (!out.is_open()) {
        cout << "Can not open file to write result\n";
        return;
    }
    for (int i = 0; i < result.size(); i++)
        out << result[i] << std::endl;
    out.close();
}

/*Move mail from Unread to Read*/
void moveUnreadToRead(float num, SSL<float>& Unread, SSL<float>& Read) {
    Node<float> n;
    n.set_info(num);
    n.set_next(NULL);

    /*--------------------- Moving processing --------------------------------*/
    Unread.deleteNode(n);
    Read.insertToTail(n);
    /*------------------------ Informing -------------------------------------*/
    cout << "Moving from Unread to Read successfully\n";
    return;
}

/*Move mail from Read to Trash*/
void moveReadToTrash(float num, SSL<float>& Read, SSL<float>& Trash) {
    Node<float> n;
    n.set_info(num);
    n.set_next(NULL);

    /*--------------------- Moving processing --------------------------------*/
    Read.deleteNode(n);
    Trash.insertToTail(n);
    /*------------------------ Informing -------------------------------------*/
    cout << "Moving from Read to Trash successfully\n";
    return;
}

/*Move mail from Unread to Trash*/
void moveUnreadToTrash(float num, SSL<float>& Unread, SSL<float>& Trash) {
    Node<float> n;
    n.set_info(num);
    n.set_next(NULL);

    /*--------------------- Moving processing --------------------------------*/
    Unread.deleteNode(n);
    Trash.insertToTail(n);
    /*------------------------ Informing -------------------------------------*/
    cout << "Moving from Unread to Trash successfully\n";
    return;
}

/*Move mail from Trash to Read*/
void moveTrashToRead(float num, SSL<float>& Trash, SSL<float>& Read) {
    Node<float> n;
    n.set_info(num);
    n.set_next(NULL);

    /*--------------------- Moving processing --------------------------------*/
    Trash.deleteNode(n);
    Read.insertToTail(n);
    /*------------------------ Informing -------------------------------------*/
    cout << "Moving from Trash to Read successfully\n";
    return;
}

/*Manage moving duty*/
void manageMove(string choice, string mail_key,
        SSL<float>& Unread, SSL<float>& Read, SSL<float>& Trash) {
    //Convert from char to float
    
    float num;
    num = convertToFloat(mail_key);
    int option;
    option = convertToInt(choice);
    //Make moves
    switch (option) {
        case 1:
            moveUnreadToRead(num, Unread, Read);
            break;
        case 2:
            moveReadToTrash(num, Read, Trash);
            break;
        case 3:
            moveUnreadToTrash(num, Unread, Trash);
            break;
        case 4:
            moveTrashToRead(num, Trash, Read);
            break;
        default:
            cout << "This is not possible option\n";
    }
    cout << "--------------------------------------------------\n";
    Unread.show();
    cout << "--------------------------------------------------\n";
    Read.show();
    cout << "--------------------------------------------------\n";
    Trash.show();
}

void normalize(vector<char>& list_character) {
    //Remove all non numerical or not space character
    for (int i = 0; i < list_character.size(); ++i) {
        if ( ((list_character[i] < '0') || (list_character[i] > '9')) 
                && (list_character[i] != ' ') ) {
            list_character.erase(list_character.begin() + i);
            i--;
        }
    }
}

/*The final step. Take all command and make decision*/
void finalStep(vector<char> property, vector<char> all_character,
        SSL<float>& Unread, SSL<float>& Read, SSL<float>& Trash) {
    /*-------------------- Normalize vectors ---------------------------------*/
    normalize(property);
    normalize(all_character);

    /*-------------------- Analyze property ----------------------------------*/
    //Split the whole property char_sequence to seperate strings
    vector<string> prop;
    prop = convertToString(property);
    //The first string is the number of id 
    //(According to Excersise's requirements)
    float total_mail_id = convertToFloat(prop[0]);
    
    /*------------------- Insert all to Unread -------------------------------*/
    //Insert all id to the Unread list
    for (float i = 0; i < total_mail_id; ++i) {
        Node<float> n;
        n.set_info(i);
        n.set_next(NULL);
        Unread.insertToTail(n);
    }
    
    /*-------------------- Take commands -------------------------------------*/
    //Convert char-sequence to seperate strings
    vector<string> query_info;
    query_info = convertToString(all_character);
    //With each string, do one equivalent query
    for (int i = 0; i < query_info.size() - 1; i += 2) {
        //Make changes with wach list of Mail
        manageMove(query_info[i], query_info[i + 1], Unread, Read, Trash);
    }
    return;
}

/*----------------------------------------------------------------------------*/
int main(int argc, char** argv) {
    SSL<float> Unread;
    SSL<float> Read;
    SSL<float> Trash;
    vector<char> property;
    vector<char> all_character;

    readFromFile("File/input.txt", 1, property);
    readFromFile("File/input.txt", 2, all_character);
    finalStep(property, all_character, Unread, Read, Trash);

    return 0;
}



