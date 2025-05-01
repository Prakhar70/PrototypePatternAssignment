#include "Email.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

Email::Email(const std::string& subject, const std::string& filePath,const std::string& sender):
m_subject {std::move(subject)}, 
m_filePath {std::move(filePath)}, 
m_sender{std::move(sender)},
m_template(),
m_body(),
m_reciever()
{
    std::ifstream file(m_filePath);
    if (!file) {
        throw std::runtime_error("Failed to open template: " + m_filePath);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    m_template = std::move(content);
    file.close();
}

Email::Email(const Email& other):
    m_template{other.m_template},
    m_subject{other.m_subject},
    m_sender{other.m_sender},
    m_filePath{other.m_filePath},
    m_body{other.m_body},
    m_reciever{other.m_reciever}{}


std::unique_ptr<Email> Email::clone() {
    return std::make_unique<Email>(*this);
}

void Email::personalise(const std::string& userName) {
    const std::string placeholder = "{{name}}";
    std::string modified = m_template;  // make a copy of the original template

    size_t pos = 0;
    while ((pos = modified.find(placeholder, pos)) != std::string::npos) {
        modified.replace(pos, placeholder.length(), userName);
        pos += userName.length(); // move past the replaced part
    }

    m_body = std::move(modified); // store the result in m_body
}

void Email::print() const{
    std::cout<<m_subject<<"\n"<<std::endl;
    std::cout<<m_body<<"\n"<<std::endl;
}