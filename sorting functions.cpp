#include <vector>
template <class ItemType>
unsigned int smallestItemIndex (
	const std::vector <ItemType>& items,
	const unsigned int& startIndex,
	const unsigned int& endIndex
)
// Post: Function value = index of the smallest value
// in values [start] . . values [end].
{
	unsigned int smallestItemIndex = startIndex;
	const ItemType* smallestItem = &items [startIndex];
	const ItemType* currentItem;
	for (
		unsigned int currentIndex = startIndex + 1 ;
		currentIndex <= endIndex;
		currentIndex++
	) {
		currentItem = & items [currentIndex];
		if (*currentItem < *smallestItem) {
			smallestItemIndex = currentIndex;
			smallestItem = & items [currentIndex];
		}
	}
	return smallestItemIndex;
}
template <class ItemType>
void swap (
	std::vector <ItemType>& items,
	const unsigned int& indexA,
	const unsigned int& indexB
)
{
	ItemType temp = items [indexA];
	items [indexA] = items [indexB];
	items [indexB] = temp;
}
template <class ItemType>
void selectionSort (
	std::vector <ItemType>& items
)
// Post: Sorts array values[0 . . numValues-1 ]
// into ascending order by key
{
	unsigned int amountOfItems = items.size ();
	unsigned int lastItemIndex;
	unsigned int m_smallestItemIndex;
	if (amountOfItems == 0)
		lastItemIndex = 0;
	else
		lastItemIndex = amountOfItems - 1;
	for (
		unsigned int currentIndex = 0;
		currentIndex < lastItemIndex;
		currentIndex++
	) {
		m_smallestItemIndex = smallestItemIndex (items, currentIndex, lastItemIndex);
		swap (items, currentIndex, m_smallestItemIndex);
	}
}