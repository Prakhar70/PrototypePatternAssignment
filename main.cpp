#include "Email.hpp"
#include "PremiumEmail.hpp"
#include <memory>

int main(){
    std::unique_ptr<Email> sample = std::make_unique<Email>("Greeting","example.txt","Prakhar Agarwal");

    std::unique_ptr<Email> prakhar_copy = sample->clone();
    prakhar_copy->personalise("Prakhar");
    prakhar_copy->print();

    std::unique_ptr<Email> sugam_copy = sample->clone();
    sugam_copy->personalise("Sugam");
    sugam_copy->print();

    std::unique_ptr<Email> kishan_copy = sample->clone();
    kishan_copy->personalise("Kishan");
    kishan_copy->print();

    std::unique_ptr<PremiumEmail> sample_pre = std::make_unique<PremiumEmail>("Premium Greeting","example.txt","Prakhar Agarwal","Manjeet", "Shehzan");
    std::unique_ptr<Email> prakhar_pre_copy = sample_pre->clone();
    prakhar_pre_copy->personalise("Prakhar Premium");
    prakhar_pre_copy->print();
   
    // Email * sample = new Email("Greetings","example.txt","Prakhar");
    
    // if(PremiumEmail* pre_email = dynamic_cast<PremiumEmail*>(sample)){
    //     PremiumEmail * prakhar_copy = new PremiumEmail(*pre_email);
    //     prakhar_copy->personalise("Prakhar Premium");
    //     prakhar_copy->print();
    //     delete prakhar_copy;
    // }else{
    //     Email * prakhar_copy = new Email(*sample);
    //     prakhar_copy->personalise("Prakhar Normal");
    //     prakhar_copy->print();
    //     delete prakhar_copy;
    // }
    // delete sample;
}