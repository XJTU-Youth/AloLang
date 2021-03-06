/*
 * utils.h
 *
 *  Created on: May 2, 2020
 *      Author: zbc
 */

#ifndef COMPILER_UTILS_H_
#define COMPILER_UTILS_H_

#include <sstream>

bool isSyntax(char c);
void skipSpace(const std::vector<std::string> &words, long unsigned int& i);
void skipSpace(std::istream& in);


#endif /* COMPILER_UTILS_H_ */
