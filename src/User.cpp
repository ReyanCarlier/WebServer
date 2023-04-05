#include "User.hpp"

User::User() {
    this->_id = 0;
    this->_username = "";
    this->_password = "";
    this->_email = "";
}

User::User(const User& other) {
    this->_id = other._id;
    this->_username = other._username;
    this->_password = other._password;
    this->_email = other._email;
}

User::User(const int id, const std::string username, const std::string password, const std::string email) {
    this->_id = id;
    this->_username = username;
    this->_password = password;
    this->_email = email;
}

User::~User() {}

User& User::operator=(const User& other) {
    if (this == &other)
        return *this;
    this->_id = other._id;
    this->_username = other._username;
    this->_password = other._password;
    this->_email = other._email;
    return *this;
}

int User::getId() const {
    return this->_id;
}

std::string User::getUsername() const {
    return this->_username;
}

std::string User::getPassword() const {
    return this->_password;
}

std::string User::getEmail() const {
    return this->_email;
}

std::string User::getNickname() const {
    return this->_nickname;
}

Role User::getRole() const {
    return this->_role;
}

void User::setId(const int id) {
    this->_id = id;
}

void User::setUsername(const std::string username) {
    this->_username = username;
}

void User::setPassword(const std::string password) {
    this->_password = password;
}

void User::setEmail(const std::string email) {
    this->_email = email;
}

void User::setNickname(const std::string nickname) {
    this->_nickname = nickname;
}

void User::setRole(const Role role) {
    this->_role = role;
}