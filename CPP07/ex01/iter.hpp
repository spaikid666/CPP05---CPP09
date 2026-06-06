#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter (T *addr, const std::size_t length, F fctn)
{
	if (!addr)
		return;
	for (std::size_t i = 0; i < length; i++)
		fctn(addr[i]);
}

#endif