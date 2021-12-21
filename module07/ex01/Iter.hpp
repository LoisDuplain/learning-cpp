#pragma once

#include<iostream>

template <typename T>
void	iter(T const *address, unsigned int const len, void(*fun)(T const &src))
{
	for (unsigned int i = 0 ; i < len; i++)
		fun(address[i]);
}