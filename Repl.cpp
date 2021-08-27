
#include <Chess.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

bool test(const std::string& pgn)
{
	return [=] {
		std::ifstream stream(pgn, std::ios::in);
		if (stream.is_open()) {
			const std::string code{
				std::istreambuf_iterator<char>(stream),
				std::istreambuf_iterator<char>()
			};
			return read(code);
		}
		return false;
	}();
}

int main(int, char* [])
{
	std::vector<bool> tests{
		test("test.pgn")
	};

	std::cout << tests.size() << " tests executed." << std::endl;
	std::cout << std::ranges::count(tests, false) << " tests failed." << std::endl;
	std::cout << std::ranges::count(tests, true) << +" tests passed." << std::endl;

	std::cout << "Pgn REPL" << std::endl;

	while (true) {
		try {
			std::cout << "> ";
			std::string input;
			std::getline(std::cin, input);
			std::cout << read(input) << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
