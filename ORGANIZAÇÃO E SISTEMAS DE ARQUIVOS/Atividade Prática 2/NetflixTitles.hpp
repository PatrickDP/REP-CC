#ifndef NETFLIXTITLES_HPP
#define NETFLIXTITLES_HPP

#define TOTAL_MAX_RECORDS 7788

#include <iostream>
#include "library.hpp"

using namespace std;

class DateAdded {
private:
};

class NetflixTitles {
private:
string showID;
string type;
string title;
string director;
// Vetor de elecno (INICIALIZA VAZIO)
vector<string> cast;
string country;
string dateAdded;
string release;
string rating;
string duration;
// Vetor de categorias (INICIALIZA VAZIO)
vector<string> listedin;
string description;

public:
NetflixTitles();
~NetflixTitles();

// INICIALIZA OS ATRIBUTOS
void initNetflixTitles();

void setShowID(string showID);
string getShowID() const;

void setType(string type);
string getType() const;

void setTitle(string title);
string getTitle() const;

void setDirector(string director);
string getDirector() const;

void setCast(string cast);
string getCast(unsigned index) const;

void setCountry(string country);
string getCountry() const;

void settdateAdded(string dateAdded);
string getdateAdded() const;

void setRelease(string release);
string getRelease() const;

void setRating(string rating);
string getRating() const;

void setDuration(string duration);
string getDuration() const;

void setListedin(string listedin);
string getListedin(unsigned index) const;

void setDescription(string description);
string getDescription() const;

void printData() const;

// Envia os campos para o buffer
void packBuffer(Buffer &buff);
void unPackBuffer(Buffer &buff);

string concatStringFunction(vector<string> &arrString, char delimiter);
void splitString(string concatString, vector<string> &rrString, char delimiter);
};


#endif // !NETFLIXTITLES_HPP