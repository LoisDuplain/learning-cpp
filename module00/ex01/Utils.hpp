#pragma once

#include <iostream>

bool		contains_digit(std::string str);
bool		contains_alpha(std::string str);

bool		is_valid_field_entry(std::string field_entry, bool can_contains_alpha, bool can_contains_digit, size_t size);

std::string	ask_field(std::string field_name, bool can_contains_alpha, bool can_contains_digit);
std::string	ask_field(std::string field_name, bool can_contains_alpha, bool can_contains_digit, size_t size);