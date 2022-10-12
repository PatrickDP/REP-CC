#include "library.hpp"

NetflixTitles::NetflixTitles() {
    initNetflixTitles();
}
NetflixTitles::~NetflixTitles() {}

void NetflixTitles::initNetflixTitles() {
    this->showID = "EMPTY";
    this->type = "EMPTY";
    this->title = "EMPTY";
    this->director = "EMPTY";
    // this->cast.push_back("EMPTY");
    this->country = "EMPTY";
    this->dateAdded = "EMPTY";
    this->release = "EMPTY";
    this->rating = "EMPTY";
    this->duration = "EMPTY";
    // this->listedin.push_back("EMPTY");

    this->description = "EMPTY";
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

void NetflixTitles::setDirector(string director) {
    this->director = director;
}
string NetflixTitles::getDirector() const {
    return this->director;
}

void NetflixTitles::setCast(string cast) {
    this->cast.push_back(cast);
}
string NetflixTitles::getCast(unsigned index) const {
    return this->cast[index];
}

void NetflixTitles::setCountry(string country) {
    this->country = country;
}
string NetflixTitles::getCountry() const {
    return this->country;
}

void NetflixTitles::settdateAdded(string dateAdded) {
    this->dateAdded = dateAdded;
}
string NetflixTitles::getdateAdded() const {
    return this->dateAdded;
}

void NetflixTitles::setRelease(string release) {
    this->release = release;
}
string NetflixTitles::getRelease() const {
    return this->release;
}

void NetflixTitles::setRating(string rating) {
    this->rating = rating;
}
string NetflixTitles::getRating() const {
    return this->rating;
}

void NetflixTitles::setDuration(string duration) {
    this->duration = duration;
}
string NetflixTitles::getDuration() const {
    return this->duration;
}

void NetflixTitles::setListedin(string listedin) { 
    this->listedin.push_back(listedin);
}
string NetflixTitles::getListedin(unsigned index) const {
    return this->listedin[index];
}

void NetflixTitles::setDescription(string description) {
    this->description = description;
}
string NetflixTitles::getDescription() const {
    return this->description;
}

void NetflixTitles::printData() const {
    cout << endl << "\t <<< PRINT DATA >>>\n\n";
    
    cout << "showID: " << showID << endl;
    cout << "type: " << type << endl;
    cout << "title: " << title << endl;
    cout << "director: " << director << endl;
    
    cout << "cast: ";

    if(cast.size() == 0)
        cout << "EMPTY";
    else {
        for(unsigned i = 0; i < cast.size(); i++) {
            cout << cast[i];

            if(i == cast.size() - 1)
                cout << ".";
            else
                cout << ", ";
        }
    }
    cout << endl;

    cout << "country: " << country << endl;
    cout << "dateAdded: " <<  dateAdded << endl;
    cout << "release: " << release << endl;
    cout << "rating: " << rating << endl;
    cout << "duration: " << duration << endl;
    
    cout << "listedin: ";

    if(listedin.size() == 0)
        cout << "EMPTY";
    else {
        for(unsigned i = 0; i < listedin.size(); i++) {
            cout << listedin[i];

            if(i == listedin.size() - 1)
                cout << ".";
            else
                cout << ", ";
        }
    }
    cout << endl;

    cout << "description: " << description << "\n";
}

void NetflixTitles::packBuffer(Buffer &buff) {
    string concatString = "";

    buff.clearBuffer();

    buff.packBuffer(this->showID.c_str(), true); 
    buff.packBuffer(this->type.c_str(), true);
    buff.packBuffer(this->title.c_str(), true);
    buff.packBuffer(this->director.c_str(), true);
    
    concatString = concatStringFunction(this->cast, ',');
    buff.packBuffer(concatString.c_str(), true);

    buff.packBuffer(this->country.c_str(), true);
    buff.packBuffer(this->dateAdded.c_str(), true);
    buff.packBuffer(this->release.c_str(), true);
    buff.packBuffer(this->rating.c_str(), true);
    buff.packBuffer(this->duration.c_str(), true);

    concatString = concatStringFunction(this->listedin, ',');
    buff.packBuffer(concatString.c_str(), true);
    
    buff.packBuffer(this->description.c_str(), false);
}

void NetflixTitles::unPackBuffer(Buffer &buff) {
    string concatString = "";

    buff.unPackBuffer(this->showID=""); 
    buff.unPackBuffer(this->type="");
    buff.unPackBuffer(this->title="");
    buff.unPackBuffer(this->director="");

    buff.unPackBuffer(concatString);  
    splitString(concatString, this->cast, ',');

    buff.unPackBuffer(this->country="");
    buff.unPackBuffer(this->dateAdded="");
    buff.unPackBuffer(this->release="");
    buff.unPackBuffer(this->rating="");
    buff.unPackBuffer(this->duration="");

    concatString = "";
    buff.unPackBuffer(concatString);
    splitString(concatString, this->listedin, ',');

    buff.unPackBuffer(this->description="");
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