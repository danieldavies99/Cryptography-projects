#include <iostream>

//decrypt
std::string baconify(std::string msg) {
    std::string result = "";
    std::string noPunctuation = "";
    std::string chunk;
    std::string debug = "";
    char count = 0;
    //A = 65, B = 90
    //a = 97, b = 122

    //removes punctuation
    for (int i = 0; i < msg.size(); i++) {
        if ((msg[i] > 64 && msg[i] < 91) || (msg[i] > 96 && msg[i] < 123)) {
            noPunctuation += msg[i];
        }
    }

    for (int i = 0; i <= noPunctuation.size(); i++) {

        if (count == 5) {

            if (chunk == "uuuuu") {
                result += "a";
            }
            else if (chunk == "uuuul") {
                result += "b";
            }
            else if (chunk == "uuulu") {
                result += "c";
            }
            else if (chunk == "uuull") {
                result += "d";
            }
            else if (chunk == "uuluu") {
                result += "e";
            }
            else if (chunk == "uulul") {
                result += "f";
            }
            else if (chunk == "uullu") {
                result += "g";
            }
            else if (chunk == "uulll") {
                result += "h";
            }
            else if (chunk == "uluuu") {
                result += "i";
            }
            else if (chunk == "uluul") {
                result += "j";
            }
            else if (chunk == "ululu") {
                result += "k";
            }
            else if (chunk == "ulull") {
                result += "l";
            }
            else if (chunk == "ulluu") {
                result += "m";
            }
            else if (chunk == "ullul") {
                result += "n";
            }
            else if (chunk == "ulllu") {
                result += "o";
            }
            else if (chunk == "ullll") {
                result += "p";
            }
            else if (chunk == "luuuu") {
                result += "q";
            }
            else if (chunk == "luuul") {
                result += "r";
            }
            else if (chunk == "luulu") {
                result += "s";
            }
            else if (chunk == "luull") {
                result += "t";
            }
            else if (chunk == "luluu") {
                result += "u";
            }
            else if (chunk == "lulul") {
                result += "v";
            }
            else if (chunk == "lullu") {
                result += "w";
            }
            else if (chunk == "lulll") {
                result += "x";
            }
            else if (chunk == "lluuu") {
                result += "y";
            }
            else if (chunk == "lluul") {
                result += "z";
            }
            else if (chunk == "llllu") {
                result += ".";
            }
            else if (chunk == "lllll") {
                result += " ";
            }
            else {
                result += "error";
            }

            chunk = "";
            count = 0;
        }

        if (noPunctuation[i] > 96 && noPunctuation[i] < 123) {
            chunk += "l";
            count++;
        }

        else if (noPunctuation[i] > 64 && noPunctuation[i] < 91) {
            chunk += "u";
            count++;
        }

    }

    return result;
}





std::string baconify(std::string msg, std::string mask) {

    std::string result = "";
    std::string chunk;
    std::string DEBUGCHUNK;

    int progress = 0;
    int position = 0;

    for (int i = 0; i < msg.size(); i++) {

        if (msg[i] == 97 || msg[i] == 65) {
            chunk = "uuuuu";
        }
        else if (msg[i] == 98 || msg[i] == 66) {
            chunk = "uuuul";
        }
        else if (msg[i] == 99 || msg[i] == 67) {
            chunk = "uuulu";
        }
        else if (msg[i] == 100 || msg[i] == 68) {
            chunk = "uuull";
        }
        else if (msg[i] == 101 || msg[i] == 69) {
            chunk = "uuluu";
        }
        else if (msg[i] == 102 || msg[i] == 70) {
            chunk = "uulul";
        }
        else if (msg[i] == 103 || msg[i] == 71) {
            chunk = "uullu";
        }
        else if (msg[i] == 104 || msg[i] == 72) {
            chunk = "uulll";
        }
        else if (msg[i] == 105 || msg[i] == 73) {
            chunk = "uluuu";
        }
        else if (msg[i] == 106 || msg[i] == 74) {
            chunk = "uluul";
        }
        else if (msg[i] == 107 || msg[i] == 75) {
            chunk = "ululu";
        }
        else if (msg[i] == 108 || msg[i] == 76) {
            chunk = "ulull";
        }
        else if (msg[i] == 109 || msg[i] == 77) {
            chunk = "ulluu";
        }
        else if (msg[i] == 110 || msg[i] == 78) {
            chunk = "ullul";
        }
        else if (msg[i] == 111 || msg[i] == 79) {
            chunk = "ulllu";
        }
        else if (msg[i] == 112 || msg[i] == 80) {
            chunk = "ullll";
        }
        else if (msg[i] == 113 || msg[i] == 81) {
            chunk = "luuuu";
        }
        else if (msg[i] == 114 || msg[i] == 82) {
            chunk = "luuul";
        }
        else if (msg[i] == 115 || msg[i] == 83) {
            chunk = "luulu";
        }
        else if (msg[i] == 116 || msg[i] == 84) {
            chunk = "luull";
        }
        else if (msg[i] == 117 || msg[i] == 85) {
            chunk = "luluu";
        }
        else if (msg[i] == 118 || msg[i] == 86) {
            chunk = "lulul";
        }
        else if (msg[i] == 119 || msg[i] == 87) {
            chunk = "lullu";
        }
        else if (msg[i] == 120 || msg[i] == 88) {
            chunk = "lulll";
        }
        else if (msg[i] == 121 || msg[i] == 89) {
            chunk = "lluuu";
        }
        else if (msg[i] == 122 || msg[i] == 90) {
            chunk = "lluul";
        }
        else if (msg[i] == 46) {
            chunk = "llllu";
        }
        else if (msg[i] == 32) {
            chunk = "lllll";
        }
        else {
            continue;
        }

        int count = 0;
        //position within chunk
        int j = 0;
        //position in mask
        position = j + progress;

        while (count < 5) {

            if (position > mask.size()) {
                break;
            }

            // mask is a letter
            if ((mask[position] > 64 && mask[position] < 91) || (mask[position] > 96 && mask[position] < 123)) {

                //uppercase to lowercase
                if ((mask[position] > 64 && mask[position] < 91) && chunk[count] == 108) {
                    result += mask[position] + 32;
                }

                //lowercase to uppercase
                else if ((mask[position] > 96 && mask[position] < 123) && chunk[count] == 117) {
                    result += mask[position] - 32;
                }

                //already correct
                else {
                    result += mask[position];
                }
                count++;
            }

            //mask is punctuation
            else {
                result += mask[position];
            }

            j++;
            position = j + progress;
        }
        progress += j;
    }
    //l = 108, u = 117
    while (result.size() < mask.size()) {
        result += mask[position];
        position++;
    }
    return result;
}

int main()
{
    std::cout << baconify("Help me.", "Man prefers to believe what he prefers to be true.") << std::endl;
    std::cout << baconify("MAn prEFeRS To BelIeve what he PreFERS tO Be truE.") << std::endl;
}