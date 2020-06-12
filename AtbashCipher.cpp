#include <iostream>

std::string atbash(std::string str) {
	std::string result = "";
	char newChar;

	for (int i = 0; i < str.size(); i++) {
		//capital letters

		if (str[i] > 64 && str[i] < 91) {
			newChar = (0 - (str[i] - 64)) + 27 + 64;
		}

		//lowercase letters
		else if (str[i] > 96 && str[i] < 123) {
			newChar = (0 - (str[i] - 96)) + 27 + 96;
		}

		else {
			newChar = str[i];
		}

		result += newChar;

	}
	return result;
}

int main(){
	std::cout << atbash("The quick brown fox jumps over the lazy dog") << std::endl;
}