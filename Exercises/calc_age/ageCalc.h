#ifndef GUARD_ageCalc_h
#define GUARD_ageCalc_h

#include <iostream>
#include <vector>
#include <string>


std::vector<int> read_b_date(std::istream&);
std::vector<int> read_f_date(std::istream&);
std::string calc_age(const std::vector<int>&, const std::vector<int>&);


#endif
