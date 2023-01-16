#include "library.hpp"

NetflixTitles::NetflixTitles() {
    initNetflixTitles();
}
NetflixTitles::~NetflixTitles() {}

void NetflixTitles::initNetflixTitles() {
    this->showID = "";
    this->type = "";
    this->title = "";
    this->country = "";
    this->release = "";
}

void NetflixTitles::setShowID(string showID) {
    this->showID = showID;
}
string NetflixTitles::getShowID() const {
    return this->showID;
}

void NetflixTitles::setType(string type) {
    this->type = type;
}
string NetflixTitles::getType() const {
    return this->type;
}

void NetflixTitles::setTitle(string title) {
    this->title = title;
}
string NetflixTitles::getTitle() const {
    return this->title;
}

void NetflixTitles::setCountry(string country) {
    this->country = country;
}
string NetflixTitles::getCountry() const {
    return this->country;
}

void NetflixTitles::setRelease(string release) {
    this->release = release;
}
string NetflixTitles::getRelease() const {
    return this->release;
}

void NetflixTitles::printData() const {
    cout << endl << "\t <<< PRINT DATA >>>\n\n";
    
    cout << "showID: " << showID << endl;
    cout << "type: " << type << endl;
    cout << "title: " << title << endl;
    cout << "country: " << country << endl;
    cout << "release: " << release << endl;
}

void NetflixTitles::packBuffer(Buffer &buff) {
    string concatString = "";

    buff.clearBuffer();

    buff.packBuffer(this->showID.c_str(), true); 
    buff.packBuffer(this->type.c_str(), true);
    buff.packBuffer(this->title.c_str(), true);
    buff.packBuffer(this->country.c_str(), true);
    buff.packBuffer(this->release.c_str(), true);
}

void NetflixTitles::unPackBuffer(Buffer &buff) {
    string concatString = "";

    buff.unPackBuffer(this->showID=""); 
    buff.unPackBuffer(this->type="");
    buff.unPackBuffer(this->title="");

    buff.unPackBuffer(this->country="");
    buff.unPackBuffer(this->country="");
    buff.unPackBuffer(this->country="");

    buff.unPackBuffer(this->release="");
    buff.unPackBuffer(this->release="");
}

string NetflixTitles::concatStringFunction(vector<string> &arrString, char delimiter) {
    string concatString = "";

    for(unsigned i = 0; i < arrString.size(); i++) {
        concatString += arrString[i];

        if(i < arrString.size() - 1)
            concatString += delimiter;
    }

    return concatString;
}

void NetflixTitles::splitString(string concatString, vector<string> &arrString, char delimiter) {
    string getField = "";

    stringstream concatStringFile(concatString);
    while(concatStringFile) {
        getline(concatStringFile, getField, delimiter);
        arrString.push_back(getField);   
    }

    arrString.pop_back();
}

bool NetflixTitles::findSomething(string str1, string str2) {
    if(str1 == str2) 
        return true;
    else    
        return false;
}

void NetflixTitles::setDataNetflix(string showID, string type, string title, string country, string release) {
    setShowID(showID); 
    setType(type);
    setTitle(title);
    setCountry(country);
    setRelease(release);
}