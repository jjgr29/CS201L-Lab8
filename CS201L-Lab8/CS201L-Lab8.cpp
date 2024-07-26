// CS201L-Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Functions.h"
#include "Media.h"

using namespace std;

int main() {

    ifstream inList, inCommands;
    ofstream outFile, outErr;

    try {
        inList.exceptions(ifstream::failbit);
        inList.open("mediaList.txt");
        inCommands.exceptions(ifstream::failbit);
        inCommands.open("mediaCommands.txt");
        outFile.exceptions(ofstream::failbit);
        outFile.open("mediaReport.txt");
        outErr.exceptions(ofstream::failbit);
        outErr.open("mediaError.txt");
    }
    catch (ifstream::failure& fail) {
        cout << "Could not open input file" << endl;
        cout << fail.what() << endl;
        cout << fail.code() << endl;
        exit(1);
    }

    vector <Media*> myLib;

    // read data into myLib
    readMediaList(inList, outErr, myLib);
    inList.close();


    // prepare to read the commands
    string commandRecord, token;
    vector<string> tokens;


    getline(inCommands, commandRecord);
    char choice = commandRecord[0];
    cout << "+++++++" << endl;

    while (choice != 'Q') {
        //parse input record into tokens
        //read data in string vector

        tokens.clear();
        tokens.push_back(commandRecord);  //this is NOT the way to parse this input (use stringstream to separate on commas)

        if (tokens.size() == 1 &&
            (tokens[0][0] == 'M' || tokens[0][0] == 'B' || tokens[0][0] == 'S' || tokens[0][0] == 'A'))
            cout << "CALL: printReport(tokens, outFile, outErr, myLib)" << endl;

        else if (tokens.size() == 1 && tokens[0][0] == 'T')
            cout << "CALL: printTotals(outFile)" << endl;

        else if (tokens.size() == 2 &&
            (tokens[0][0] == 'M' || tokens[0][0] == 'B' || tokens[0][0] == 'S' || tokens[0][0] == 'A')) {
            cout << "CALL:printReportGenre(tokens, outFile, outErr, myLib);" << endl;
            cout << "OR CALL:printReportRating(tokens, outFile, outErr, myLib);" << endl;
        }

        else if (tokens.size() > 2 && tokens[0][0] == 'N') {
            cout << "CALL: addNewMedia(tokens, outFile, outErr, myLib); " << endl;
        }

        else if (choice == 'Q') {
            cout << "Thank You for Using Media Everywhere" << endl;
            break;
        }

        else {
            cout << "There is an error in the input command: " << commandRecord << "\n";
        }

        getline(inCommands, commandRecord);
        choice = commandRecord[0];
    }

    inCommands.close();
    outFile.close();
    outErr.close();
}
