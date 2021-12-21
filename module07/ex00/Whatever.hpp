#pragma once

#include<iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&min(T &a, T &b)
{
	if (a > b)
		return b;
	return a;
}

template<typename T>
T const	&max(T &a, T &b)
{
	if (a > b)
		return a;
	return b;
}