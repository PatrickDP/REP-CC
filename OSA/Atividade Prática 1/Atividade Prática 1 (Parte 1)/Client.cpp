
#include "Client.hpp"

Client::Client() {
    client_name = "empty_client";
}
Client::~Client() {}

void Client::set_client(string new_clientName) {
    client_name = new_clientName;  
}

string Client::get_client() const {
    return client_name;
}

void Client::print_client() {
    cout << client_name;
}