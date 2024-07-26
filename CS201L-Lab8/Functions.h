#pragma once
#include <vector>
#include "Media.h"
using namespace std;

bool isDigits(string str1);
int  readMediaList(istream &i, ostream &o, vector<Media*> &m);
void printReport (vector<string> tokens, ostream& outFile, ostream& outErr, vector<Media*>& m);
void printReportGenre(vector<string> tokens, ostream& outFile, ostream& outErr, vector<Media*>& m);
void printReportRating(vector<string> tokens, ostream& outFile, ostream& outErr, vector<Media*>& m);

void printTotals(ostream& outFile);

void addNewMedia(vector<string> tokens, ostream &o, ostream &err, vector<Media*>& m);


static int mediaCounts[3] = {0,0,0};