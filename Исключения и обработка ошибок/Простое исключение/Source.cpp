#include <iostream>

int function(std::string str, int forbidden_length);

int main() {

	std::string word;
	int forbidden_lenth;

	std::cout << "Enter prohibited length: "; std::cin >> forbidden_lenth;
	while (true) {
		std::cout << "Enter a word:	"; std::cin >> word;
		try {
			int result = function(word, forbidden_lenth); 
			std::cout << "Word length = " << result << std::endl;
			
		}
		catch (int) {
			std::cerr << "You've entered a word of prohibited length! Goodbye." << std::endl;
			break;
		}
	}
	return 0;
}

int function(std::string str, int forbidden_lenth) {

	int lengh = str.length();
	if (lengh == forbidden_lenth) {
		throw 1;
	}

	return lengh;
}


