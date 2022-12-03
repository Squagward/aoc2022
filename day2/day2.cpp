#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

namespace day2 {

    std::map<char, int> map{{'A', 1},
                            {'B', 2},
                            {'C', 3},
                            {'X', 1},
                            {'Y', 2},
                            {'Z', 3}};

    void part1() {
        std::ifstream my_file("day2/day2.txt");

        int total_score = 0;
        if (my_file.is_open()) {
            for (std::string line; getline(my_file, line);) {
                int their_move = map[line[0]];
                int my_move = map[line[2]];

                if (my_move == their_move) {
                    total_score += 3;
                } else {
                    int their_target = (their_move + 1) % 3;
                    if (their_target == 0) {
                        their_target += 3;
                    }
                    if (their_target == my_move) {
                        total_score += 6;
                    }
                }
                total_score += my_move;
            }
        }
        my_file.close();
        std::cout << "Part 1 Answer: " << total_score << std::endl;
    }

    enum Ending {
        Lose = 1,
        Tie = 2,
        Win = 3
    };

    void part2() {
        std::ifstream my_file("day2/day2.txt");

        int total_score = 0;
        if (my_file.is_open()) {
            for (std::string line; getline(my_file, line);) {
                int their_move = map[line[0]];
                int should_win = map[line[2]];

                if (should_win == Tie) {
                    total_score += 3;
                    total_score += their_move;
                } else if (should_win == Lose) {
                    int score = (their_move + 2) % 3;
                    if (score == 0) {
                        score += 3;
                    }
                    total_score += score;
                } else {
                    total_score += 6;

                    int score = (their_move + 1) % 3;
                    if (score == 0) {
                        score += 3;
                    }
                    total_score += score;
                }
            }
        }
        my_file.close();
        std::cout << "Part 2 Answer: " << total_score << std::endl;
    }

    void rock_paper_scissors() {
        part1();
        part2();
    }
}
