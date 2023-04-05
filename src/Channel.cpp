#include "Channel.hpp"

Channel::Channel() {
    this->_id = 0;
    this->_name = "";
}

Channel::Channel(const Channel& other) {
    this->_id = other._id;
    this->_name = other._name;
    this->_users = other._users;
    this->_operators = other._operators;
    this->_admins = other._admins;
    this->_owners = other._owners;
    this->_banned = other._banned;
    this->_muted = other._muted;
}

Channel::Channel(const std::string name) {
    this->_id = 0;
    this->_name = name;
}

Channel::~Channel() {}

Channel& Channel::operator=(const Channel& other) {
    if (this == &other)
        return *this;
    this->_id = other._id;
    this->_name = other._name;
    this->_users = other._users;
    this->_operators = other._operators;
    this->_admins = other._admins;
    this->_owners = other._owners;
    this->_banned = other._banned;
    this->_muted = other._muted;
    return *this;
}

int Channel::getId() const {
    return this->_id;
}

std::string Channel::getName() const {
    return this->_name;
}

std::list<User> Channel::getUsers() const {
    return this->_users;
}

std::list<User> Channel::getOperators() const {
    return this->_operators;
}

std::list<User> Channel::getAdmins() const {
    return this->_admins;
}

std::list<User> Channel::getOwners() const {
    return this->_owners;
}

std::list<User> Channel::getBanned() const {
    return this->_banned;
}

std::list<User> Channel::getMuted() const {
    return this->_muted;
}

void Channel::setId(const int id) {
    this->_id = id;
}

void Channel::setName(const std::string name) {
    this->_name = name;
}

void Channel::addUser(const User user) {
    this->_users.push_back(user);
}

void Channel::addOperator(const User user) {
    this->_operators.push_back(user);
}

void Channel::addAdmin(const User user) {
    this->_admins.push_back(user);
}

void Channel::addOwner(const User user) {
    this->_owners.push_back(user);
}

void Channel::addBanned(const User user) {
    this->_banned.push_back(user);
}

void Channel::addMuted(const User user) {
    this->_muted.push_back((User)user);
}

void Channel::removeUser(User user) {
    for (std::list<User>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_users.erase(it);
            break;
        }
    }
}

void Channel::removeOperator(User user) {
    for (std::list<User>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_operators.erase(it);
            break;
        }
    }
}

void Channel::removeAdmin(User user) {
    for (std::list<User>::iterator it = this->_admins.begin(); it != this->_admins.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_admins.erase(it);
            break;
        }
    }
}

void Channel::disownUser(User user) {
    for (std::list<User>::iterator it = this->_owners.begin(); it != this->_owners.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_owners.erase(it);
            break;
        }
    }
}

void Channel::unbanUser(User user) {
    for (std::list<User>::iterator it = this->_banned.begin(); it != this->_banned.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_banned.erase(it);
            break;
        }
    }
}

void Channel::unmuteUser(User user) {
    for (std::list<User>::iterator it = this->_muted.begin(); it != this->_muted.end(); it++) {
        if (it->getId() == user.getId()) {
            this->_muted.erase(it);
            break;
        }
    }
}
