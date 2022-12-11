#include <iostream>
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"
#include "day8/day8.h"

int main() {
    day1::max_elves();
    std::cout << std::endl;
    day2::rock_paper_scissors();
    std::cout << std::endl;
    day3::rucksacks();
    std::cout << std::endl;
    day4::pairs();
    std::cout << std::endl;
    day5::crates();
    std::cout << std::endl;
    day6::signals();
    std::cout << std::endl;
    day8::trees();
    return 0;
}
