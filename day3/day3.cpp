#include <iostream>
#include <fstream>
#include <string>

#define ull unsigned long long

namespace day3 {
    void part1() {
        std::ifstream my_file("day3/day3.txt");

        int total_score = 0;
        if (my_file.is_open()) {
            outer: for (std::string line; getline(my_file, line);) {
                ull len = line.size() / 2;
                std::string first = line.substr(0, len);
                std::string second = line.substr(len);
                for (char c : first) {
                    if (second.contains(c)) {
                        if (c > 'Z') {
                            total_score += c - 'a' + 1;
                        } else {
                            total_score += c - 'A' + 27;
                        }
                        goto outer;
                    }
                }
            }
        }
        my_file.close();
        std::cout << "Part 1 Answer: " << total_score << std::endl;
    }

    void part2() {
        std::ifstream my_file("day3/day3.txt");

        int total_score = 0;
        if (my_file.is_open()) {
            outer: for (std::string line1; getline(my_file, line1);) {
                std::string line2; getline(my_file, line2);
                std::string line3; getline(my_file, line3);

                for (char c : line1) {
                    if (line2.contains(c) && line3.contains(c)) {
                        if (c > 'Z') {
                            total_score += c - 'a' + 1;
                        } else {
                            total_score += c - 'A' + 27;
                        }
                        goto outer;
                    }
                }
            }
        }
        my_file.close();
        std::cout << "Part 2 Answer: " << total_score << std::endl;
    }

    void rucksacks() {
        part1();
        part2();
    }
}