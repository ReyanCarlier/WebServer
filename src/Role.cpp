#include "Role.hpp"

Role::Role() {
    this->_id = 0;
    this->_name = "";
}

Role::Role(const Role& other) {
    this->_id = other._id;
    this->_name = other._name;
}

Role::Role(const int id, const std::string name) {
    this->_id = id;
    this->_name = name;
}

Role::~Role() {}

Role& Role::operator=(const Role& other) {
    if (this == &other)
        return *this;
    this->_id = other._id;
    this->_name = other._name;
    return *this;
}

int Role::getId() const {
    return this->_id;
}

std::string Role::getName() const {
    return this->_name;
}

void Role::setId(const int id) {
    this->_id = id;
}

void Role::setName(const std::string name) {
    this->_name = name;
}