#include <iostream>
#include <string>

char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int combo_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
std::string combos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int values[7] = {1, 5, 10, 50, 100, 500, 1000};

int char_index(char c, char* arr, int size) {
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i] == c) {
            index = i;
            break;
        }
    }
    return index;
}

int roman_to_int(std::string r) {
    int total = 0;
    for(int i = r.length() - 1; i >= 0; i--) {
        total += values[char_index(r.at(i), symbols, 7)];
    }
    for(int i = 0; i < r.length()-1; i++) {
        if(r.at(i) == 'I' && (r.at(i+1) == 'V' || r.at(i+1) == 'X')) {
            total -= 2;
        }else if(r.at(i) == 'X' && (r.at(i+1) == 'L' || r.at(i+1) == 'C')) {
            total -= 20;
        }else if(r.at(i) == 'C' && (r.at(i+1) == 'D' || r.at(i+1) == 'M')) {
            total -= 200;
        }
    }
    return total;
}

std::string int_to_roman(int num) {
    std::string roman = "";
    int i = 0;
    while(true) {
        if(num == 0) {
            break;
        }
        if(num >= combo_values[i]) {
            num -= combo_values[i];
            roman += combos[i];
        }else {
            i++;
        }
    }

    return roman;
}

int main() {

    int n;
    std::cin >> n;

    while(n--) {
        std::string roman;
        std::cin >> roman;

        std::string first_roman = roman.substr(0, roman.find('+'));
        std::string second_roman = roman.substr(roman.find('+')+1, roman.length()-(roman.find('+')+1)-1);
        int result_num = roman_to_int(first_roman)+roman_to_int(second_roman);

        std::string result = result_num > 1000 ? "CONCORDIA CUM VERITATE" : int_to_roman(result_num);
        std::cout << first_roman << "+" << second_roman << "=" << result << std::endl;
    }

    return 0;
}