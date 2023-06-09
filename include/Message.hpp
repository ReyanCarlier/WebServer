#pragma once

#include <string>
#include "User.hpp"

class Message {
    public:
        Message();
        Message(const Message& other);
        Message(const std::string message, User *target);

        ~Message();

        Message& operator=(const Message& other);

        const std::string   getMessage() const;
        const User          *getTarget() const;
        const User          getSender() const;

        void setMessage(const std::string message);
        void setTarget(User *target);
        void setSender(const User sender);

        bool send();

    private:
        std::string m_message;
        User        *m_target;
        User        m_sender;
};
