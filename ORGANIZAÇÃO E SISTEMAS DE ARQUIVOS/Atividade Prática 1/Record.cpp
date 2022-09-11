#include "Record.hpp"

Record::Record() {
    strcpy(this->name_record, "EMPTY");
    strcpy(this->lastName_record, "EMPTY");
    strcpy(this->phone_record, "EMPTY");
    strcpy(this->birthDate_record, "EMPTY");
}

void Record::print_record() {
    cout << this->name_record << "   " << this->lastName_record << "   " << this->phone_record << "   " << this->birthDate_record << endl;
}