#pragma once

#include <string>

class Role {
    public:
        Role();
        Role(const Role& other);
        Role(const int id, const std::string name);
        ~Role();

        Role& operator=(const Role& other);

        int           getId() const;
        std::string   getName() const;

        void setId(const int id);
        void setName(const std::string name);

    private:
        int         _id;
        std::string _name;
};
