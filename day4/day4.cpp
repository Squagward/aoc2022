#include <iostream>
#include <fstream>
#include <string>

namespace day4 {
    void part1() {
        std::ifstream my_file("day4/day4.txt");

        int enclosed_pairs = 0;
        if (my_file.is_open()) {
            for (std::string line; getline(my_file, line);) {
                std::string delimiter = ",";
                std::string first = line.substr(0, line.find(delimiter));
                std::string second = line.substr(line.find(delimiter) + 1);

                std::string range_delimiter = "-";
                int start1 = stoi(first.substr(0, first.find(range_delimiter)));
                int end1 = stoi(first.substr(first.find(range_delimiter) + 1));
                int start2 = stoi(second.substr(0, second.find(range_delimiter)));
                int end2 = stoi(second.substr(second.find(range_delimiter) + 1));

                if ((start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1)) {
                    enclosed_pairs++;
                }
            }
        }
        my_file.close();
        std::cout << "Part 1 Answer: " << enclosed_pairs << std::endl;
    }

    void part2() {
        std::ifstream my_file("day4/day4.txt");

        int overlaps = 0;
        if (my_file.is_open()) {
            for (std::string line; getline(my_file, line);) {
                std::string delimiter = ",";
                std::string first = line.substr(0, line.find(delimiter));
                std::string second = line.substr(line.find(delimiter) + 1);

                std::string range_delimiter = "-";
                int start1 = stoi(first.substr(0, first.find(range_delimiter)));
                int end1 = stoi(first.substr(first.find(range_delimiter) + 1));
                int start2 = stoi(second.substr(0, second.find(range_delimiter)));
                int end2 = stoi(second.substr(second.find(range_delimiter) + 1));

                if ((start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1) ||
                        (start1 <= start2 && end1 >= start2) || (start2 <= start1 && end2 >= start1)) {
                    overlaps++;
                }
            }
        }
        my_file.close();
        std::cout << "Part 2 Answer: " << overlaps << std::endl;
    }

    void pairs() {
        part1();
        part2();
    }
}
