#include <iostream>
#include <string>

int main() {

    std::string short_form[] = {"CU", ":-)", ":-(", ";-)", ":-P", "(~.~)",
                                "TA", "CCC", "CUZ", "TY", "YW", "TTYL"};

    std::string translation[] = {"see you", "I'm happy", "I'm unhappy",
                                 "wink", "stick out my tongue", "sleepy",
                                 "totally awesome",
                                 "Canadian Computing Competition", "because",
                                 "thank-you", "you're welcome",
                                 "talk to you later"};

     std::string input;

    while(input != "TTYL") {

        std::cin >> input;

        bool is_short_form = false;

        int i = 0;
        for(i = 0; i < 12; i++) {
            if(input == short_form[i]) {
                is_short_form = true;
                break;
            }
        }

        if(is_short_form) {
            std::cout << translation[i] << std::endl;
        }else {
            std::cout << input << std::endl;
        }
    }


    return 0;
}