#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Functions.h"
#include "Media.h"

using namespace std;

bool isDigits(string str1) {
    return (str1.find_first_not_of("1234567890") == string::npos);
}

void updateMediaCount(char type) {
    if (type == 'M')  mediaCounts[0] ++;
    else if (type == 'B')  mediaCounts[1] ++;
    else if (type == 'S')  mediaCounts[2] ++;
}

int readMediaList(istream &inFile, ostream &outFile, vector<Media*> &mediaLib){
  string inLine, tempStr, testChar, title, genre, name;
  int rating, year, length;
  vector<string> row;
  char choice = ' ', type = ' ';

  while (getline(inFile, inLine)) {
      cout << inLine << endl;
      testChar = inLine.substr(0, 1);
      if (testChar == "Q")
          break;

  }
  return 0;
}

void printReport(vector<string> tokens, ostream& outFile, ostream& outErr, vector<Media*>& m) {
    char printType = tokens[0][0];
    
    outFile << setw(20) << "TITLE" << setw(21) << "TYPE" << setw(15) << "YEAR" << setw(10) << "RATING" << endl;
    for (int i = 0; i < m.size(); i++) {



    }
    outFile << endl << endl << endl;
}

void printReportGenre(vector<string> tokens, ostream& outFile, ostream& outErr, vector<Media*>& m) {
    char printType = tokens[0][0];
    string genre = tokens[1];
    bool genreFound = false;
    outFile << left << setw(40) << "TITLE" << setw(8) << "TYPE" << setw(10) << "YEAR" << setw(10) << "GENRE" << endl;


    for (int i = 0; i < m.size(); i++) {
    }
    if (!genreFound) 
        outFile << "Unable to process command.  There was not item of genre: " << genre << " in your list.\n\n\n";
    else
        outFile << endl << endl << endl;
}

void printReportRating(vector<string> tokens, ostream& outFile, ostream& outErr, vector <Media*> &m ){
    char printType = tokens[0][0];

    int rating = stoi(tokens[1]);
    if (rating <= 0 || rating > 10) {
        outErr << "Unable to process command. The rating of: " << rating << " is invalid\n\n\n";
        return;
    }

    bool ratingFound = false;
    outFile << left << setw(40) << "TITLE" << setw(8) << "TYPE" << setw(10) << "YEAR" << setw(10) << "RATING"  << endl;
    for (int i = 0; i < m.size(); i++) {


    }
    if (!ratingFound)  
        outFile << "Unable to process command.  There was not item with a rating of : " << rating << " or more in your list.\n\n\n";
    else
        outFile << endl << endl << endl;
}
 
void printTotals(ostream& out){
    out << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    out << right << setw (5) << "YOUR MEDIA LIBRARY\n";
    out << "# " << setw(5) << "  TYPE"  <<endl;
    int total = mediaCounts[0]+mediaCounts[1] + mediaCounts[2];
    out << left <<setw(5) << mediaCounts[0] << left << setw(10) << "Movies" <<endl;
    out << left <<setw(5) << mediaCounts[1] << left << setw(10) << "Books" <<endl;
    out << left <<setw(5) << mediaCounts[2] << left << setw(10) << "Songs" <<endl;
    out << left <<setw(5) << total << left << setw(10) << "Items" <<endl;
    out << endl << endl << endl;
}

void addNewMedia(vector<string> tokens, ostream& out, ostream& outErr, vector<Media*>& m){

    int rating, year, length;

    //parse input data
 

    try {
 
         





        out << " was added to your list\n\n\n";
    }
    catch (invalid_argument& e) {
        string msg = "ERROR: " + tokens[2] + "," + tokens[2] + "," + tokens[3];
        outErr << msg << "\nPrevious record has an " << e.what() << " error\n\n\n";
    }
    catch (runtime_error& e) {
        string msg = "ERROR: " + tokens[2] + "," + tokens[2] + "," + tokens[3];
        outErr << msg << "\nThere was an invalid value entered for " << e.what() << "\n\n\n";
    }
    catch (...) {
        outErr << "ERROR: " << tokens[2] + "," + tokens[2] + "," + tokens[3] << "\n\n\n";
    }

}