#ifndef GUARD_statistics_h
#define GUARD_statistics_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

void calc_avg(const std::vector<double>&);
double calc_median(std::vector<double>&);
void calc_quartiles(std::vector<double>&);
void add_data(std::istream&, std::vector<double>&);
void remove_data(std::vector<double>&);


#endif

