#include "Auxiliar.hpp"

unsigned Auxiliar::get_recordLength(Record &record) {
    unsigned name_length = strlen(record.name_record);
    unsigned lastName_length = strlen(record.lastName_record);
    unsigned phone_length = strlen(record.phone_record);
    unsigned birthDate_length = strlen(record.birthDate_record);

    unsigned record_length = name_length + lastName_length + phone_length + birthDate_length;
    
    return record_length;
}

fstream& Auxiliar::getLine_file(fstream& file, unsigned num_line) {
    file.seekg(ios::beg);
    
    for(unsigned i=0; i < num_line; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    return file;
}

void Auxiliar::setFieldsFile_record(vector<string> arr_fields, Record &record) {
    // Percorre uma unica vez os campos
    for(unsigned i = 0; i < 1; i++) {
        // Copia os campos do array através do strcpy nas variaveis da classe Record
        strcpy(record.name_record, arr_fields[i].c_str());
        strcpy(record.lastName_record, arr_fields[i + 1].c_str());
        strcpy(record.phone_record, arr_fields[i + 2].c_str());
        strcpy(record.birthDate_record, arr_fields[i + 3].c_str());
    }
}

void Auxiliar::open_file(fstream &file, string file_name) {
    // Abre o arquivo
    file.open(file_name, ios::in);

    // O arquivo não abriu
    if(!file.is_open()) {
        cerr << "ERROR OPENING FILE " << file_name << "! CLOSING..." << endl;
        exit(1); 
    } else {
        cout << "SUCCESSFULLY OPENED FILE " << file_name << "!" << endl;
    }
}

void Auxiliar::read_file(fstream &file, Record &record) {
    // Pega uma linha do arquivo
    string get_record;
    // Delimitador
    char delimiter = '|';
    // Pega campos do registro
    string get_field;
    // Arr para campos
    vector <string> arr_fields;
    
    // Pegue uma uma linha
    getline(file, get_record);

    // Transforma a string em um arquivo
    stringstream get_record_file(get_record);

    // Percorre o registro
    while(get_record_file) {
        // Quebra o registro em campos
        getline(get_record_file, get_field, delimiter);

        // Array armazena os campos
        arr_fields.push_back(get_field);
    }

    setFieldsFile_record(arr_fields, record);
}

void Auxiliar::generate_file(fstream& delimiterField_file, Record &record) {
    // Escreve no arquivo através do "<<"
    delimiterField_file << record.name_record << "|";
    delimiterField_file << record.lastName_record << "|";
    delimiterField_file << record.phone_record << "|";
    delimiterField_file << record.birthDate_record << endl;
}

void Auxiliar::read_fixedLengthField_file(fstream &file, Record &record, unsigned index) {
    getLine_file(file, index);

    file.read((char*) &record.name_record, sizeof(record.name_record));
    file.read((char*) &record.lastName_record, sizeof(record.lastName_record));
    file.read((char*) &record.phone_record, sizeof(record.phone_record));
    file.read((char*) &record.birthDate_record, sizeof(record.birthDate_record));
}

void Auxiliar::generate_fixedLengthField_file(fstream &fixLengthField_file, Record &record) {
    // Escreve em binário através de write
    fixLengthField_file.write((char*) &record.name_record, sizeof(record.name_record));
    fixLengthField_file.write((char*) &record.lastName_record, sizeof(record.lastName_record));
    fixLengthField_file.write((char*) &record.phone_record, sizeof(record.phone_record));
    fixLengthField_file.write((char*) &record.birthDate_record, sizeof(record.birthDate_record));
    fixLengthField_file << endl;
}

void Auxiliar::read_fixedrecordLength_file(fstream &file, Record &record, unsigned index) {
    getLine_file(file, index);
    file.read((char*) &record, sizeof(record));
}

void Auxiliar::generate_fixedrecordLength_file(fstream &fixrecordLength_file, Record &record) {
    fixrecordLength_file.write((char*) &record, sizeof(record));
    fixrecordLength_file << endl;
}

void Auxiliar::read_tagField_file(fstream &file, Record &record) {
    string get_record;
    char delimiter = '|';
    string get_field;
    vector <string> arr_fields;

    // Array de tags a ser substituiída
    vector<string> arr_tokens = {"Nome=", "Sobrenome=", "Telefone=", "Nascimento="};

    getline(file, get_record);

    stringstream get_record_file(get_record);

    while(get_record_file) {
        getline(get_record_file, get_field, delimiter);
        arr_fields.push_back(get_field);
    }

    // Percorre o for de arr_data
    for(unsigned i = 0; i < 1; i++) {
        // Percorre o for de arr_tokens
        for(unsigned j = 0; j < arr_tokens.size(); j++) {
            // Utiliza o método erase para apagar a tag do campo
            arr_fields[j + i].erase(0, arr_tokens[j].size());
        }
    }
    
    setFieldsFile_record(arr_fields, record);
}

void Auxiliar::generate_tagField_file(fstream &tagField_file, Record &record) {
    tagField_file << "Nome=" << record.name_record << "|";
    tagField_file << "Sobrenome=" << record.lastName_record << "|";
    tagField_file << "Telefone=" << record.phone_record << "|";
    tagField_file << "Nascimento=" << record.birthDate_record << endl;
 }

void Auxiliar::read_lengthIndicatorField_file(fstream &file, Record &record, unsigned index) {
    unsigned name_length = strlen(record.name_record);
    unsigned lastName_length = strlen(record.lastName_record);
    unsigned phone_length = strlen(record.phone_record);
    unsigned birthDate_length = strlen(record.birthDate_record);

    getLine_file(file, index);

    file.read((char*) &name_length, sizeof(unsigned));
    file.read((char*) &record.name_record, sizeof(record.name_record));
    
    file.read((char*) &lastName_length, sizeof(unsigned));
    file.read((char*) &record.lastName_record, sizeof(record.lastName_record));

    file.read((char*) &phone_length, sizeof(unsigned));
    file.read((char*) &record.phone_record, sizeof(record.phone_record));

    file.read((char*) &birthDate_length, sizeof(unsigned));
    file.read((char*) &record.birthDate_record, sizeof(record.birthDate_record));
    
}

void Auxiliar::generate_lengthIndicatorField_file(fstream &lengthIndicatorField_file, Record &record) {
    const char* name_length = to_string(strlen(record.name_record)).c_str();
    const char* lastName_length = to_string(strlen(record.lastName_record)).c_str();
    const char* phone_length = to_string(strlen(record.phone_record)).c_str();
    const char* birthDate_length = to_string(strlen(record.birthDate_record)).c_str();


    lengthIndicatorField_file.write(name_length, sizeof(unsigned));
    lengthIndicatorField_file.write((char*) &record.name_record, sizeof(record.name_record));

    lengthIndicatorField_file.write(lastName_length, sizeof(unsigned));
    lengthIndicatorField_file.write((char*) &record.lastName_record, sizeof(record.lastName_record));

    lengthIndicatorField_file.write(phone_length, sizeof(unsigned));
    lengthIndicatorField_file.write((char*) &record.phone_record, sizeof(record.phone_record));

    lengthIndicatorField_file.write(birthDate_length, sizeof(unsigned));
    lengthIndicatorField_file.write((char*) &record.birthDate_record, sizeof(record.birthDate_record));

    lengthIndicatorField_file << endl;

}

void Auxiliar::read_lengthIndicatorRecord_file(fstream &file, Record &record, unsigned index) {
    unsigned record_length = get_recordLength(record);
    
    getLine_file(file, index);

    file.read((char*) &record_length, sizeof(unsigned));
    file.read((char*) &record, sizeof(record));
}

void Auxiliar::generate_lengthIndicatorRecord_file(fstream &lengthIndicatorRecord_file, Record &record) {
    const char* record_length = to_string(get_recordLength(record)).c_str();

    lengthIndicatorRecord_file.write(record_length, sizeof(unsigned));
    lengthIndicatorRecord_file.write((char*) &record, sizeof(record));
    lengthIndicatorRecord_file << endl;    
}

void Auxiliar::print_record(Record *record) {
    for(unsigned i = 0; i < TOTAL_MAX_RECORD; i++) 
        record[i].print_record();

    cout << endl << endl << endl;
 }