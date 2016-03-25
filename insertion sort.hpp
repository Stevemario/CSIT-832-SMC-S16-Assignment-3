#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP
#include "swap.hpp"
template <class ItemType>
void insertItem (
	std::vector <ItemType>& items,
	const unsigned int& indexOfItemToInsert,
	const unsigned int& indexThatInsertionCanBubbleUpTo
)
{
	bool finished = false ;
	int indexOfItemToInsertNow = indexOfItemToInsert;

	while (finished == false &&
		indexOfItemToInsertNow != indexThatInsertionCanBubbleUpTo
	)
	{
		if (items [indexOfItemToInsertNow] < items [indexOfItemToInsertNow - 1]) {
			swap (items, indexOfItemToInsertNow, indexOfItemToInsertNow - 1);
			indexOfItemToInsertNow--;
		} else
			finished = true;
	}
}
template <class ItemType>
void insertionSort (
	std::vector <ItemType>& items
)
{
	unsigned int nItems = items.size ();
	for (
		unsigned int nSortedItems = 1;
		nSortedItems < nItems;
		nSortedItems++
	)
		insertItem (items, nSortedItems, 0);
}
#endif