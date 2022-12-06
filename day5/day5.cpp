#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cmath>

namespace day5 {
    std::vector<int> get_matches(std::string string, const std::regex& regex) {
        std::vector<int> matches;
        std::sregex_iterator the_match(string.begin(), string.end(), regex);
        std::smatch match = *the_match;
        matches.push_back(stoi(match.str(1)));
        matches.push_back(stoi(match.str(2)));
        matches.push_back(stoi(match.str(3)));

        return matches;
    }

    void part1() {
        std::regex regex(R"(move (\d+) from (\d+) to (\d+))");
        std::ifstream my_file("day5/day5.txt");

        std::vector<std::vector<char>> towers;

        int line_num = 0;
        for (std::string line; getline(my_file, line);) {
            if (line_num == 0) {
                for (int i = 0; i < ceil((int) line.length() / 4.0) + 1; i++) {
                    towers.emplace_back();
                }
            }

            if (line.contains('[')) {
                int crate = 1;
                for (int i = 1; i < line.length(); i += 4) {
                    if (line[i] != ' ') {
                        std::vector<char> *tower = &towers[crate];
                        tower->insert(tower->begin(), line[i]);
                    }

                    crate++;
                }
            } else if (std::regex_match(line, regex)) {
                std::vector<int> matches = get_matches(line, regex);

                for (int i = 0; i < matches[0]; i++) {
                    char c = towers[matches[1]].back();
                    towers[matches[1]].pop_back();
                    towers[matches[2]].push_back(c);
                }
            }
            line_num++;
        }

        std::cout << "Part 1 Answer: ";
        for (int i = 1; i < towers.size(); i++) {
            std::cout << towers[i].back();
        }
        std::cout << std::endl;
    }

    void part2() {
        std::regex regex(R"(move (\d+) from (\d+) to (\d+))");
        std::ifstream my_file("day5/day5.txt");

        std::vector<std::vector<char>> towers;

        int line_num = 0;
        for (std::string line; getline(my_file, line);) {
            if (line_num == 0) {
                for (int i = 0; i < ceil((int) line.length() / 4.0) + 1; i++) {
                    towers.emplace_back();
                }
            }

            if (line.contains('[')) {
                int crate = 1;
                for (int i = 1; i < line.length(); i += 4) {
                    if (line[i] != ' ') {
                        std::vector<char> *tower = &towers[crate];
                        tower->insert(tower->begin(), line[i]);
                    }

                    crate++;
                }
            } else if (std::regex_match(line, regex)) {
                std::vector<int> matches = get_matches(line, regex);

                for (int i = matches[0]; i > 0; i--) {
                    std::vector<char> *curr_tower = &towers[matches[1]];
                    int index = (int) curr_tower->size() - i;
                    char c = curr_tower->at(index);
                    curr_tower->erase(curr_tower->begin() + index);
                    towers[matches[2]].push_back(c);
                }
            }
            line_num++;
        }

        std::cout << "Part 2 Answer: ";
        for (int i = 1; i < towers.size(); i++) {
            std::cout << towers[i].back();
        }
        std::cout << std::endl;
    }

    void crates() {
        part1();
        part2();
    }
}