#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#include "swap.hpp"
template <class ItemType>
void moveUp (
	std::vector <ItemType>& items,
	const unsigned int& indexOfItemToMoveUp,
	const unsigned int& indexOfFirstItem
)
{
	unsigned int indexOfItemMoving = indexOfItemToMoveUp;
	while (indexOfFirstItem < indexOfItemMoving) {
		swap (items, indexOfItemMoving, indexOfItemMoving - 1);
		indexOfItemMoving--;
	}
}
template <class ItemType>
void merge (
	std::vector <ItemType>& items,
	const unsigned int& indexOfFirstItemToMerge,
	const unsigned int& indexOfLastItemToMerge,
	const unsigned int& indexOfLastItemInFirstHalf
) {
	bool finished = false;
	unsigned int indexOfFirstItemInSecondHalf = indexOfLastItemInFirstHalf + 1;
	ItemType firstItemInSecondHalf = items [indexOfFirstItemInSecondHalf];
	unsigned int indexOfItemToCompare = indexOfFirstItemToMerge;
	while (finished == false) {
		if (
			firstItemInSecondHalf <
			items [indexOfItemToCompare]
		) {
			moveUp (items, indexOfFirstItemInSecondHalf, indexOfItemToCompare);
			indexOfFirstItemInSecondHalf++;
			if (indexOfFirstItemInSecondHalf <= indexOfLastItemToMerge)
				firstItemInSecondHalf = items [indexOfFirstItemInSecondHalf];
			else
				finished = true;
		}
		indexOfItemToCompare++;
		if (indexOfFirstItemInSecondHalf <= indexOfItemToCompare)
			finished = true;
	}
}
template <class ItemType>
void mergeSortSpecific (
	std::vector <ItemType>& items,
	const unsigned int& indexOfFirstItemToSort,
	const unsigned int& indexOfLastItemToSort
)
{
	int middle;
	if (indexOfFirstItemToSort < indexOfLastItemToSort) // general case
	{
		middle = (indexOfFirstItemToSort + indexOfLastItemToSort) / 2;
		mergeSortSpecific (items, indexOfFirstItemToSort, middle);
		mergeSortSpecific (items, middle + 1, indexOfLastItemToSort);
		// now merge two subarrays
		// values [ first . . . middle ] with
		// values [ middle + 1, . . . last ].
		merge (items, indexOfFirstItemToSort, indexOfLastItemToSort, middle);
	}
}
template <class ItemType>
void mergeSort (
	std::vector <ItemType>& items
)
{
	mergeSortSpecific (items, 0, items.size () - 1);
}
#endif