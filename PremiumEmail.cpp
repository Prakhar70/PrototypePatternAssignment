#include "PremiumEmail.hpp"

PremiumEmail::PremiumEmail(const std::string& subject,
    const std::string& filePath,
    const std::string& sender,
    const std::string& bcc,
    const std::string& cc):Email(subject, filePath, sender),m_cc(cc),m_bcc(bcc){}

PremiumEmail::PremiumEmail(const PremiumEmail& other)
    :Email(other),
    m_cc(other.m_cc),
    m_bcc(other.m_bcc){}

std::unique_ptr<Email> PremiumEmail::clone() {
    return std::make_unique<PremiumEmail>(*this);
}
void PremiumEmail::print() const{
    Email::print();
    std::cout<<m_cc<<std::endl;
    std::cout<<m_bcc<<std::endl;
}


