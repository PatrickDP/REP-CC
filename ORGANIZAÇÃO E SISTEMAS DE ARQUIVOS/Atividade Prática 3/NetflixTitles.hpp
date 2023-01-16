#ifndef NETFLIXTITLES_HPP
#define NETFLIXTITLES_HPP

#define TOTAL_MAX_RECORDS 7788

#include <iostream>
#include "library.hpp"

using namespace std;

// Quantidade atual do total de registros
static unsigned currentRecordSize = 0;

class NetflixTitles {
private:
string type;
string title;
string country;
string release;

public:
string showID;

NetflixTitles();
~NetflixTitles();

void initNetflixTitles();

void setShowID(string showID);
string getShowID() const;

void setType(string type);
string getType() const;

void setTitle(string title);
string getTitle() const;

void setCountry(string country);
string getCountry() const;

void setRelease(string release);
string getRelease() const;

void printData() const;

void packBuffer(Buffer &buff);
void unPackBuffer(Buffer &buff);

string concatStringFunction(vector<string> &arrString, char delimiter);
void splitString(string concatString, vector<string> &rrString, char delimiter);

// Novas funções (Trabalho 3)

// Procura um showID ou um "*"
bool findSomething(string str1, string str2);
// Seta de maneira geral os dados na classe
void setDataNetflix(string showID, string type, string title, string country, string release);
};

#endif // !NETFLIXTITLES_HPP