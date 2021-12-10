#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> parse_input(std::string file_path){
	std::string line;
	std::ifstream input(file_path);
	std::vector<std::string> lines;

	while(std::getline(input, line)){
		lines.push_back(line);
		line.clear();
	}

	return lines;
}

int part_one(std::vector<std::string>& input_lines){
	int n_numbers = 0;
	for(const auto& line: input_lines){
		int pos = line.find('|');
		int count = 0;

		for (int i = pos+2; i < line.size(); ++i) {
			if (line[i] == ' '){
				if (count == 2 || count == 4 || count == 3 || count == 7)
					n_numbers++;
				count = 0;
			} else {
				count++;
			}
		}

		if (count == 2 || count == 4 || count == 3 || count == 7)
			n_numbers++;
		count = 0;
	}

	return n_numbers;
}


int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		std::cerr << "No input file provided" << std::endl;
		exit(-1);
	}
	
	std::string input_file = argv[1];

	std::vector<std::string> input = parse_input(input_file);
	int sol1 = part_one(input);
	std::cout << sol1 << std::endl;
	return 0;
}
