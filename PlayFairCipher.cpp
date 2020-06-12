#include <iostream>
#include <vector>
#include <string>

std::string playfair(std::string str, std::string keyword) {
    std::string result = "";

    std::string letter;
    std::vector<std::string> alphabet;

    //generate alphabet vector
    for (int i = 0; i < 26; i++) {
        if (i == 8) {
            alphabet.emplace_back("IJ");
            i++;
        }

        else {
            letter = 65 + i;
            alphabet.emplace_back(letter);
        }
    }

    //remove dupes
    std::string save;

    do {
        save = keyword;
        for (int i = 0; i < keyword.size(); i++) {
            for (int j = i + 1; j < keyword.size(); j++) {
                if (keyword[i] == keyword[j]) {
                    keyword.erase(keyword.begin() + j);
                }
            }
        }

    } while (keyword != save);

    // make grid;
    std::string grid[5][5];
    int keywordCount = 0;
    int alphaCount = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keywordCount < keyword.size()) {
                //capitalize
                if (keyword[keywordCount] > 96 && keyword[keywordCount] < 123) {
                    keyword[keywordCount] -= 32;
                }

                //add keyword to grid
                if (keyword[keywordCount] == 73 || keyword[keywordCount] == 74) {
                    grid[i][j] = "IJ";
                }
                else {
                    grid[i][j] = keyword[keywordCount];
                }

                //erase used letters
                for (int k = 0; k < alphabet.size(); k++) {
                    if (grid[i][j] == alphabet[k]) {
                        alphabet.erase(alphabet.begin() + k);
                        break;
                    }
                }
                //delete I or J
                if(grid[i][j] == "I" || grid[i][j] == "J") {
                    for (int k = 0; k < alphabet.size(); k++) {
                        if (alphabet[k] == "IJ") {
                            alphabet.erase(alphabet.begin() + k);
                            break;
                        }
                    }
                }

                keywordCount++;
            }

            else {
                grid[i][j] = alphabet[alphaCount];
                alphaCount++;
            }

        }
    }

    // remove punctuation, add spaces and determine if decyrpting or encrypting
    std::string strManip = "";
    short splitter = 0;
    // -1 = decrypt, 1 == encrypt

    short encrypt = -1;

    for (int i = 0; i < str.size(); i++) {
            //add spaces
            if (splitter == 2) {
                strManip += " ";
                splitter = 0;
            }

        //capitilize
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
            encrypt = 1;
        }

        //remove punctuation
        if ((str[i] > 64 && str[i] < 91)) {
            strManip += str[i];
            splitter++;
        }

    }

    short reSplitter = 0;
    //resolve doubles
    for (int i = 0; i < strManip.size(); i++) {
        if (strManip[i] == strManip[i + 1]) {
            strManip.insert(i + 1, "X");
            reSplitter = 1;
            //re-sort spaces
            for (int j = i + 1; j < strManip.size(); j++) {
                if (strManip[j] == 32) {
                    strManip.erase(strManip.begin() + j);
                }

                if (reSplitter == 2) {
                    strManip.insert(j, " ");
                    reSplitter = 0;
                }

                else {
                    reSplitter++;
                }

            }

            i++;
        }
    }

    if ((strManip.size() - 2) % 3 != 0) {
        strManip += "X";
    }

    std::string a;
    std::string b;

    short aX = 0;
    short aY = 0;

    short bX = 0;
    short bY = 0;


    // find IJ cords
    short IJX = 0;
    short IJY = 0;

    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            if (grid[j][k] == "IJ") {
                IJX = k;
                IJY = j;
            }
        }

    }

    for (int i = 0; i < strManip.size(); i += 3) {

        //get coordinates
        a = strManip[i];
        b = strManip[i + 1];

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (a == grid[j][k]) {
                    aX = k;
                    aY = j;
                }

                else if (b == grid[j][k]) {
                    bX = k;
                    bY = j;
                }

                else if (a == "I" || a == "J") {
                    aX = IJX;
                    aY = IJY;
                }

                else if (b == "I" || b == "J") {
                    bX = IJX;
                    bY = IJY;
                }

            }

        }

        //same row
        if (aY == bY) {
            if (aX == 4 && encrypt == 1) {
                result += grid[aY][0];
            }
            else if (aX == 0 && encrypt == -1) {
                result += grid[aY][4];
            }
            else {
                result += grid[aY][aX + encrypt];
            }

            if (bX == 4 && encrypt == 1) {
                result += grid[bY][0];
            }
            else if (bX == 0 && encrypt == -1) {
                result += grid[bY][4];
            }
            else {
                result += grid[bY][bX + encrypt];
            }
        }

        //same column
        else if (aX == bX) {
            if (aY == 4 && encrypt == 1) {
                result += grid[0][aX];
            }
            else if (aY == 0 && encrypt == -1) {
                result += grid[4][aX];
            }

            else {
                result += grid[aY + encrypt][aX];
            }

            if (bY == 4 && encrypt == 1) {
                result += grid[0][bX];
            }
            else if (bY == 0 && encrypt == -1) {
                result += grid[4][bX];
            }
            else {
                result += grid[bY + encrypt][bX];
            }

        }

        //neither
        else {
            result += grid[aY][bX];
            result += grid[bY][aX];
        }

    }

    //remove J's

    for (int i = 0; i < result.size(); i++) {
        if (result[i] == 74) {
            result.erase(result.begin() + i);
        }
    }

    return result;

}

int main() {

    std::cout << playfair("we attack tomorrow", "code") << std::endl;
    std::cout << playfair("YOEUUEBQRELDSWWFXY", "code") << std::endl;

}