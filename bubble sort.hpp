#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP
#include "swap.hpp"
template <class ItemType>
void bubbleUp(
	std::vector <ItemType>& items,
	const unsigned int& indexOfItemToBubbleUp,
	const unsigned int& indexToBubbleUpTo
)
{
	for (
		unsigned int indexOfItemToBubbleUpNow = indexOfItemToBubbleUp;
		indexOfItemToBubbleUpNow > indexToBubbleUpTo;
		indexOfItemToBubbleUpNow--
	)
		if (items [indexOfItemToBubbleUpNow] < items [indexOfItemToBubbleUpNow - 1])
			swap (items, indexOfItemToBubbleUpNow, indexOfItemToBubbleUpNow - 1);
}
template <class ItemType>
void bubbleSort (
	std::vector <ItemType>& items
)
{
	unsigned int amountOfItems = items.size ();
	unsigned int indexOfLastItemToCheck = amountOfItems == 0 ? 0 : amountOfItems - 1;
	for (
		unsigned int indexOfCurrentItem = 0;
		indexOfCurrentItem < indexOfLastItemToCheck;
		indexOfCurrentItem++
	) {
		bubbleUp (items, indexOfLastItemToCheck, indexOfCurrentItem);
	}
}
#endif