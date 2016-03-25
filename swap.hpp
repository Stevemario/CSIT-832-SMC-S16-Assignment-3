#ifndef SWAP_HPP
#define SWAP_HPP
#include <vector>
template <class ItemType>
void swap (
	std::vector <ItemType>& items,
	const unsigned int& indexOfItemA,
	const unsigned int& indexOfItemB
)
{
	ItemType tempItem = items [indexOfItemA];
	items [indexOfItemA] = items [indexOfItemB];
	items [indexOfItemB] = tempItem;
}
#endif