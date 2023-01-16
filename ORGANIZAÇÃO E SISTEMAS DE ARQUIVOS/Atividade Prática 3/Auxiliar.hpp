#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include <iostream>
#include "library.hpp"

using namespace std;

// Remove um registro da classe e depois no arquivo
void removeRecord(string showID, unsigned &currentRecordSize, Buffer &buff, NetflixTitles *netflixTitles);
// Adiciona um registro
void addRecord(string showID, string type, string title, string country, string release, unsigned &currentRecordSize, Buffer &buff, NetflixTitles *netflixTitles);
// Ordena um registro
void sortRecord(NetflixTitles *netflixTitles, unsigned &currentRecordSize);
// Armazena um array apenas com o número do showID (sem o "s" ou "*")
vector<int> getIDNumber(NetflixTitles *netflixTitles, unsigned &currentRecordSize);
// Obtem um array de showID
string getShowID(Buffer &buff);

#endif // !AUXILIAR_HPP