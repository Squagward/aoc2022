#include <iostream>
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"

int main() {
    day1::max_elves();
    std::cout << std::endl;
    day2::rock_paper_scissors();
    std::cout << std::endl;
    day3::rucksacks();
    return 0;
}
