#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#define DEFAULT_LENGTH 15
#define DEFAULT_DEVIATION 5

bool is_int(const std::string &s) {
	bool not_empty  = !s.empty();
	bool is_numeric = std::find_if(
        s.begin(),
        s.end(),
        [](unsigned char c) {return !std::isdigit(c);}
	) == s.end(); 

	return not_empty && is_numeric;
}

int use_default_len(int offset) {
	std::cout
		<< "No password length specified, using default length "
		<< DEFAULT_LENGTH + offset
		<< std::endl;
	return DEFAULT_LENGTH + offset;
}

char random_char(bool verbose) {
	char c = (char) (rand() % 93) + 33; // 33 to 126
	if (verbose) std::cout << "Char: " << c << std::endl;
	return c;
}

int main(int argc, char **argv) {
	// Use current time as seed so it is different each time
	srand(time(0));

	int random_offset = (rand() % DEFAULT_DEVIATION * 2) - DEFAULT_DEVIATION;
	
	int pass_length;
	// Check if there have been parsed args
	if (argc > 1) {
		// Check if first arg is number
		if (is_int(std::string(argv[1]))) {
			int len = atoi(argv[1]);
			std::cout << "Using specified length " << len << std::endl;
			pass_length = len;
		} else {
			pass_length = use_default_len(random_offset);
		}
	} else {
		pass_length = use_default_len(random_offset);
	}

	std::string password("");
	
	for (int i = 0; i < pass_length; i++) {
		password += random_char(false);
	}

	std::cout << "Pass: \n" << password << std::endl;
	
}
