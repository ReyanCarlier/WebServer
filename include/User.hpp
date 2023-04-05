#pragma once

#include "Role.hpp"
#include <string>

class User {
    public: 
        User();
        User(const User& other);
        User(const int id, const std::string username, const std::string password, const std::string email);
        ~User();

        User& operator=(const User& other);
    
        int           getId() const;
        std::string   getUsername() const;
        std::string   getPassword() const;
        std::string   getEmail() const;

        void setId(const int id);
        void setUsername(const std::string username);
        void setPassword(const std::string password);
        void setEmail(const std::string email);

    private:
        int         _id;
        std::string _username;
        std::string _password;
        std::string _email;
        Role        _role;
};
