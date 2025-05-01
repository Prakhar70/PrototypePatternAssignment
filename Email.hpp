#ifndef EMAIL_HPP
#define EMAIL_HPP

#include "ICloneable.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

class Email : public ICloneable<Email>{
    private:
        std::string m_subject;
        std::string m_filePath;
        std::string m_reciever;
        std::string m_sender;
        std::string m_body;
        std::string m_template;
    public:
        // normal constructor
        Email(const std::string& subject, const std::string& filePath, const std::string& sender);
    
        //copy-constructor
        Email(const Email& other);

        //TCloneable
        virtual std::unique_ptr<Email> clone() override;
        
        virtual void personalise(const std::string& userName);

        //print
        virtual void print() const;

        virtual ~Email() = default;
};
#endif