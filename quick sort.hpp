#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include "swap.hpp"
template <class ItemType>
void split (
	std::vector <ItemType>& items,
	const unsigned int& indexOfFirstItemToSort,
	const unsigned int& indexOfLastItemToSort,
	unsigned int& indexOfSortedItem
)
{
	indexOfSortedItem = indexOfFirstItemToSort;
	for (
		unsigned int indexOfComparisonItem = indexOfFirstItemToSort + 1;
		indexOfComparisonItem <= indexOfLastItemToSort;
		indexOfComparisonItem++
	) {
		if (items [indexOfComparisonItem] < items [indexOfSortedItem]) {
			swap (items, indexOfComparisonItem, indexOfSortedItem + 1);
			swap (items, indexOfSortedItem, indexOfSortedItem + 1);
			indexOfSortedItem++;
		}
	}
}
template <class ItemType>
void quickSortSpecific (
	std::vector <ItemType>& items,
	const unsigned int& indexOfFirstItemToSort,
	const unsigned int& indexOfLastItemToSort
)
{
	unsigned int indexOfSortedItem;
	if (indexOfFirstItemToSort < indexOfLastItemToSort) // general case
	//if they are the same, no work will be done
	{
		split (items, indexOfFirstItemToSort, indexOfLastItemToSort, indexOfSortedItem);
		// values [first]..values[splitPoint - 1] <= splitVal
		// values [splitPoint] = splitVal
		// values [splitPoint + 1]..values[last] > splitVal
		quickSortSpecific (items, indexOfFirstItemToSort, indexOfSortedItem == 0 ? 0 : indexOfSortedItem - 1);
		quickSortSpecific (items, indexOfSortedItem + 1, indexOfLastItemToSort);
	}
}
template <class ItemType>
void quickSort (
	std::vector <ItemType>& items
)
{
	quickSortSpecific (items, 0, items.size () - 1);
}
#endif