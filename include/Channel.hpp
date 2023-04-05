#pragma once

#include "User.hpp"
#include <string>
#include <iostream>
#include <list>

class Channel {
    public:
        Channel();
        Channel(const Channel& other);
        Channel(const std::string name);
        ~Channel();

        Channel& operator=(const Channel& other);

        int             getId() const;
        std::string     getName() const;
        std::list<User> getUsers() const;
        std::list<User> getOperators() const;
        std::list<User> getAdmins() const;
        std::list<User> getOwners() const;
        std::list<User> getBanned() const;
        std::list<User> getMuted() const;

        void setId(const int id);
        void setName(const std::string name);
        void addUser(const User user);
        void addOperator(const User user);
        void addAdmin(const User user);
        void addOwner(const User user);
        void addBanned(const User user);
        void addMuted(const User user);
        void removeUser(User user);
        void removeOperator(User user);
        void removeAdmin(User user);
        void disownUser(User user);
        void unbanUser(User user);
        void unmuteUser(User user);
        
    private:
        int                     _id;
        std::string             _name;
        std::list<User>   _users;
        std::list<User>   _operators;
        std::list<User>   _admins;
        std::list<User>   _owners;
        std::list<User>   _banned;
        std::list<User>   _muted;
};