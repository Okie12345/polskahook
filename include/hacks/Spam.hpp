/*
 * Spam.h
 *
 *  Created on: Jan 21, 2017
 *      Author: nullifiedcat
 */

#pragma once
#include <string>
#include <vector>

class CatCommand;

namespace hacks::spam
{
extern const std::vector<std::string> builtin_default;
extern const std::vector<std::string> builtin_lennyfaces;
extern const std::vector<std::string> builtin_nonecore;
extern const std::vector<std::string> builtin_lmaobox;
extern const std::vector<std::string> builtin_cowhook;
extern const std::vector<std::string> builtin_rosnehook;

bool isActive();
void init();
} // namespace hacks::spam
