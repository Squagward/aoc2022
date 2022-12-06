#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace day6 {
    bool has_duplicates(std::vector<char> &chars) {
        for (int i = 0; i < chars.size(); i++) {
            for (int j = i + 1; j < chars.size(); j++) {
                if (chars[i] == chars[j] && i != j) return true;
            }
        }
        return false;
    }
    
    int helper(int size) {
        std::ifstream my_file("day6/day6.txt");
        std::string line;
        getline(my_file, line);

        std::vector<char> chars(size);

        int i = 0;
        bool looping = true;
        while (i < line.size() && looping) {
            if (i < size || has_duplicates(chars)) {
                chars.push_back(line[i]);
                chars.erase(chars.begin() + 0);
                i++;
            } else {
                looping = false;
            }
        }
        return i;
    }

    void signals() {
        std::cout << "Part 1 Answer: " << helper(4) << std::endl;
        std::cout << "Part 2 Answer: " << helper(14) << std::endl;
    }
}