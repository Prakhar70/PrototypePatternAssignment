#include "ICloneable.hpp"
#include "Email.hpp"
#include <string>

class PremiumEmail:public Email{
    private:
    std::string m_cc;
    std::string m_bcc;
    public:
    PremiumEmail(const std::string& subject,
        const std::string& filePath,
        const std::string& sender,
        const std::string& bcc,
        const std::string& cc);

    PremiumEmail(const PremiumEmail& other);
    virtual std::unique_ptr<Email> clone();
    virtual void print() const;
};