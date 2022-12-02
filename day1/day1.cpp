#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part1() {
    std::ifstream my_file("day1/day1.txt");
    std::string file_contents;

    int max = 0;
    int current_sum = 0;

    if (my_file.is_open()) {
        std::string line;
        if (my_file.is_open()) {
            while (my_file) {
                std::getline(my_file, line);
                if (line.empty()) {
                    max = std::max(max, current_sum);
                    current_sum = 0;
                } else {
                    current_sum += std::stoi(line);
                }
            }
        }
    }
    my_file.close();
    std::cout << "Part 1 Answer: " << max << std::endl;
}

void part2() {
    std::ifstream my_file("day1/day1.txt");
    std::string file_contents;

    std::vector<int> sums;
    int current_sum = 0;

    if (my_file.is_open()) {
        std::string line;
        if (my_file.is_open()) {
            while (my_file) {
                std::getline(my_file, line);
                if (line.empty()) {
                    int index = 0;
                    bool loop = true;
                    while (loop && index < sums.size()) {
                        if (sums[index] < current_sum) {
                            sums.insert(sums.begin() + index, current_sum);
                            loop = false;
                        }
                        index++;
                    }

                    if (loop) {
                        sums.insert(sums.begin() + index, current_sum);
                    }

                    if (sums.size() > 3) {
                        sums.pop_back();
                    }

                    current_sum = 0;
                } else {
                    current_sum += std::stoi(line);
                }
            }
        }
    }

    int sum = sums[0] + sums[1] + sums[2];
    my_file.close();
    std::cout << "Part 2 Answer: " << sum << std::endl;
}

void max_elves() {
    part1();
    part2();
}
