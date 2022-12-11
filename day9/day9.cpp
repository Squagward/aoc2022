#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

namespace day9 {
    struct coords_hash {
        template<class T1, class T2>
        std::size_t operator()(std::pair<T1, T2> const &v) const {
            return std::hash<T1>()(v.first) ^ std::hash<T2>()(v.second);
        }
    };

    void part1() {
        std::ifstream input("day9/day9.txt");
        std::vector<char> moves;

        for (std::string line; getline(input, line);) {
            int num_moves = stoi(line.substr(2));

            for (int i = 0; i < num_moves; ++i) {
                moves.emplace_back(line[0]);
            }
        }

        std::pair<int, int> head;
        std::pair<int, int> tail;

        switch (moves[0]) {
            case 'U':
                head.second++;
                break;
            case 'D':
                head.second--;
                break;
            case 'L':
                head.first--;
                break;
            case 'R':
                head.first++;
                break;
        }

        std::unordered_set<std::pair<int, int>, coords_hash> visited;

        for (char this_move : moves) {
            std::pair<int, int> copy(head);
            switch (this_move) {
                case 'U':
                    head.second++;
                    break;
                case 'D':
                    head.second--;
                    break;
                case 'L':
                    head.first--;
                    break;
                case 'R':
                    head.first++;
                    break;
            }

            // if head is diagonal
            double distance = std::sqrt(std::pow(head.first - tail.first, 2) + std::pow(head.second - tail.second, 2));
            if (distance > 1.5) {
                visited.insert(copy);
                tail = copy;
            }
        }

        std::cout << "Part 1 Answer: " << visited.size() << std::endl;
    }

    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

    void part2() {
        std::ifstream input("day9/day9.txt");
        std::vector<char> moves;

        for (std::string line; getline(input, line);) {
            int num_moves = stoi(line.substr(2));

            for (int i = 0; i < num_moves; ++i) {
                moves.emplace_back(line[0]);
            }
        }

        std::vector<std::pair<int, int>> rope;
        for (int i = 0; i < 10; ++i) {
            rope.emplace_back(std::pair(0, 0));
        }

        std::unordered_set<std::pair<int, int>, coords_hash> visited;

        for (char this_move : moves) {
            switch (this_move) {
                case 'U':
                    rope[0].second++;
                    break;
                case 'D':
                    rope[0].second--;
                    break;
                case 'L':
                    rope[0].first--;
                    break;
                case 'R':
                    rope[0].first++;
                    break;
            }

            for (int i = 1; i <= 9; i++) {
                std::pair<int, int> knot = rope[i];
                std::pair<int, int> prev_knot = rope[i - 1];

                int dx = prev_knot.first - knot.first;
                int dy = prev_knot.second - knot.second;

                if (abs(dx) + abs(dy) > 2)  {
                    rope[i] = std::pair(knot.first + sgn(dx), knot.second + sgn(dy));
                } else if (abs(dx) > 1)  {
                    rope[i] = std::pair(knot.first + sgn(dx), knot.second);
                } else if (abs(dy) > 1) {
                    rope[i] = std::pair(knot.first, knot.second + sgn(dy));
                }
            }

            visited.insert(rope.back());
        }

        std::cout << "Part 2 Answer: " << visited.size() << std::endl;
    }

    void ropes() {
        part1();
        part2();
    }
}
