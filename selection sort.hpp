#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP
#include "swap.hpp"
template <class ItemType>
unsigned int indexOfSmallestItem (
	const std::vector <ItemType>& items,
	const unsigned int& indexOfFirstItemToCheck,
	const unsigned int& indexOfLastItemToCheck
)
{
	unsigned int indexOfSmallestItem = indexOfFirstItemToCheck;
	const ItemType* smallestItem = & items [indexOfFirstItemToCheck];
	const ItemType* currentItem;
	for (
		unsigned int indexOfCurrentItem = indexOfFirstItemToCheck + 1 ;
		indexOfCurrentItem <= indexOfLastItemToCheck;
		indexOfCurrentItem++
	) {
		currentItem = & items [indexOfCurrentItem];
		if (*currentItem < *smallestItem) {
			indexOfSmallestItem = indexOfCurrentItem;
			smallestItem = & items [indexOfCurrentItem];
		}
	}
	return indexOfSmallestItem;
}
template <class ItemType>
void selectionSort (
	std::vector <ItemType>& items
)
{
	unsigned int nItems = items.size ();
	unsigned int indexOfLastItemToCheck = nItems == 0 ? 0 : nItems - 1;
	unsigned int indexOfSmallestItemLeft;
	for (
		unsigned int indexOfCurrentItem = 0;
		indexOfCurrentItem < indexOfLastItemToCheck;
		indexOfCurrentItem++
	) {
		indexOfSmallestItemLeft = indexOfSmallestItem (items, indexOfCurrentItem, indexOfLastItemToCheck);
		swap (items, indexOfCurrentItem, indexOfSmallestItemLeft);
	}
}
#endif