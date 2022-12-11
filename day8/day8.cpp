#include <fstream>
#include <vector>
#include <iostream>

namespace day8 {
    void part1() {
        std::ifstream my_file("day8/day8.txt");

        std::vector<std::vector<int>> trees;

        bool initialized = false;
        int line_num = 0;
        for (std::string line; getline(my_file, line); line_num++) {
            if (!initialized) {
                for (int i = 0; i < line.size(); i++) {
                    trees.emplace_back();
                }
                initialized = true;
            }

            for (char i : line) {
                trees[line_num].push_back(i - '0');
            }
        }

        size_t count = 0;
        for (size_t r = 0; r < trees.size(); ++r) {
            for (size_t c = 0; c < trees[0].size(); ++c) {
                if (r == 0 || r == trees.size() - 1 || c == 0 || c == trees[0].size() - 1) {
                    count++;
                } else {
                    int tree_height = trees[r][c];
                    //                     top, bottom, left, right
                    bool can_be_seen[] = {true, true, true, true};

                    for (size_t i = 0; i < r; i++) {
                        if (trees[i][c] >= tree_height) {
                            can_be_seen[0] = false;
                            break;
                        }
                    }

                    for (size_t i = trees.size() - 1; i > r; i--) {
                        if (trees[i][c] >= tree_height) {
                            can_be_seen[1] = false;
                            break;
                        }
                    }

                    for (size_t i = 0; i < c; i++) {
                        if (trees[r][i] >= tree_height) {
                            can_be_seen[2] = false;
                            break;
                        }
                    }

                    for (size_t i = trees[0].size() - 1; i > c; i--) {
                        if (trees[r][i] >= tree_height) {
                            can_be_seen[3] = false;
                            break;
                        }
                    }

                    for (bool val : can_be_seen) {
                        if (val) {
                            count++;
                            break;
                        }
                    }
                }
            }
        }

        std::cout << "Part 1 Answer: " << count << std::endl;
    }

    void part2() {
        std::ifstream my_file("day8/day8.txt");

        std::vector<std::vector<int>> trees;

        bool initialized = false;
        int line_num = 0;
        for (std::string line; getline(my_file, line); line_num++) {
            if (!initialized) {
                for (int i = 0; i < line.size(); i++) {
                    trees.emplace_back();
                }
                initialized = true;
            }

            for (char i : line) {
                trees[line_num].push_back(i - '0');
            }
        }

        int max = 0;
        for (size_t r = 0; r < trees.size(); ++r) {
            for (size_t c = 0; c < trees[0].size(); ++c) {
                if (r == 0 || r == trees.size() - 1 || c == 0 || c == trees[0].size() - 1) {
                    continue;
                } else {
                    int tree_height = trees[r][c];

                    //                 top, bottom, left, right
                    int multiples[] = {0, 0, 0, 0};

                    for (int i = (int) r - 1; i >= 0; i--) {
                        multiples[0]++;
                        if (trees[i][c] >= tree_height) {
                            break;
                        }
                    }

                    for (size_t i = r + 1; i < trees.size(); i++) {
                        multiples[1]++;
                        if (trees[i][c] >= tree_height) {
                            break;
                        }
                    }

                    for (int i = (int) c - 1; i >= 0; i--) {
                        multiples[2]++;
                        if (trees[r][i] >= tree_height) {
                            break;
                        }
                    }

                    for (size_t i = c + 1; i < trees[0].size(); i++) {
                        multiples[3]++;
                        if (trees[r][i] >= tree_height) {
                            break;
                        }
                    }

                    max = std::max(max, multiples[0] * multiples[1] * multiples[2] * multiples[3]);
                }
            }
        }

        std::cout << "Part 2 Answer: " << max << std::endl;
    }

    void trees() {
        part1();
        part2();
    }
}