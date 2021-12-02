#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Indication {
	int steps;
	std::string direction;
};

std::vector<Indication> parse_input(){
	int steps;
	std::string direction;
	Indication parsed_indication;
	std::ifstream infile("./input/input.txt");
	std::vector<Indication> directions;

	while (infile >> direction >> steps) {
		parsed_indication.steps = steps;
		parsed_indication.direction = direction;

		directions.push_back(parsed_indication);
	}

	return directions;
}

std::pair<int, int> part_one(std::vector<Indication> input_directions){
	std::pair<int, int> coordinates;
	coordinates.first = 0;
	coordinates.second = 0;

	for (Indication indication: input_directions) {
		if (indication.direction == "down") {
			coordinates.second += indication.steps;
		} else if (indication.direction == "up") {
			coordinates.second -= indication.steps;
		} else {
			coordinates.first  += indication.steps;
		}
	}

	return coordinates;
}

int main() {

	std::vector<Indication> input = parse_input();
	std::pair<int, int> sol1 = part_one(input);
	std::cout << "X: " << sol1.first << ", depth: " << sol1.second << ". Solution is: " << sol1.first*sol1.second << std::endl;
	return 0;
}


