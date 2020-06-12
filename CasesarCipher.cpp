#include <iostream>

std::string caesarCipher(std::string s, int k) {
	//a = 97, z = 122
	//A = 65, Z = 90
	//using int as char is too small
	int newChar;
	std::string result;
	for (int i = 0; i < s.size(); i++) {
		//lower case
		if (s[i] > 96 && s[i] < 123) {
			newChar = s[i] + k;
			if (newChar > 122) {
				newChar = 96 + ((newChar - 122) % 26);
				if (newChar == 96) { newChar = 122; }
			}

		}
		//upper case
		else if (s[i] > 64 && s[i] < 91) {
			newChar = s[i] + k;
			if (newChar > 90) {
				newChar = 64 + ((newChar - 90) % 26);
				if (newChar == 64) { newChar = 90; }
			}
		}
		//non letters
		else {
			newChar = s[i];
		}
		result += newChar;
	}
	return result;
}

int main(){
	std::cout << caesarCipher("the quick brown fox jumped over the lazy dog.", 5) << std::endl;
}
