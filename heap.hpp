#ifndef HEAP_HPP
#define HEAP_HPP
#include "swap.hpp"
unsigned int nHeapParentsOf (
	const unsigned int& index
)
{
	unsigned int nParents = 0;
	unsigned int factor = 2;
	while ((index / (factor - 1)) > 0) {
		nParents++;
		factor *= 2;
	}
	return nParents;
}
template <class ItemType>
void reheapDown (
	std::vector <ItemType>& items,
	const unsigned int& indexOfItemToMove,
	unsigned int nGenerationsToChange,
	const unsigned int& nItemsThatCanChange
)
//This function checks
//if a node has lesser priority than a number of its children, and
//if it does,
//it swaps the node's place in the heap with its successor.
{
	unsigned int indexOfLeftChild;
	unsigned int indexOfRightChild;
	unsigned int indexOfChildWithHigherPriority;

	indexOfLeftChild = 2 * indexOfItemToMove + 1;
	indexOfRightChild = 2 * indexOfItemToMove + 2;

	if (indexOfItemToMove < nItemsThatCanChange  && nGenerationsToChange > 0) {
	//if the node's index is an index for a placed node, and
	//   the number of generations to heap up is positive.

		if (indexOfLeftChild <= nItemsThatCanChange - 1) {
		//if the left child is within the heap

			if (indexOfLeftChild == nItemsThatCanChange - 1)
			//if the left child is the last element

				indexOfChildWithHigherPriority = indexOfLeftChild;
				//the right child is not within the heap, so
				//the left child is the higher priority valid child

			else {
			//if the left child is not the last element, meaning
			//both left and right children could be promoted

				if (items [indexOfLeftChild] < items [indexOfRightChild])
				//if the left child's priority
				//is lesser than
				//the right child's priority

					indexOfChildWithHigherPriority = indexOfRightChild;
					//the right child is the higher priority child

				else
				//if the left child's priority
				//is not lesser than
				//the right child's priority

					indexOfChildWithHigherPriority = indexOfLeftChild;
					//the left child is the higher priority child,
					//in this case, due the job class member
					//job will prevent equal priority.
					//in other cases, ties are possible,
					//but not important, left child is chosen
					//just because one has to be chosen.
			}
			if (items [indexOfItemToMove] < items [indexOfChildWithHigherPriority]) {
			//if the node's priority
			//is lesser than
			//the child's priority
				
				//the heap's rules are violated.
				//To fix that we

				swap (items, indexOfItemToMove, indexOfChildWithHigherPriority);
				//swap the node with it's bigger child

				nGenerationsToChange--;
				//note that we've gone down a generation

				reheapDown (
					items,
					indexOfChildWithHigherPriority, //note that the item we want to move is at the index its child was at before
					nGenerationsToChange,
					nItemsThatCanChange
				);
				//and repeat until the requirements are met.
			}
		}
	}
}
template <class ItemType>
void heapSort (
	std::vector <ItemType>& items
)
{
	unsigned int nItems = items.size ();
	if (nItems != 0) {
		unsigned int indexOfItemToSort =
			(nItems - 1) //last item's index
			- 1 / 2;     //'s parent
		//ie. the last parent.

		unsigned int heapHeight = nHeapParentsOf (nItems - 1) + 1;
		bool haveHeap =
			nItems == 1; //All size 1 vectors are valid heaps.
		//ie. if, and only if, the vector is size 1, don't do next step.

		while (haveHeap == false) {
			//Make a heap.
			reheapDown (
				items,
				indexOfItemToSort, //some parent
				heapHeight - nHeapParentsOf (indexOfItemToSort), //each of its children
				nItems
			);
			if (indexOfItemToSort == 0)
				haveHeap = true;
			else
				indexOfItemToSort--; //sort every parent, in descending index order
		}

		//Sort the heap.
		for (
			indexOfItemToSort = nItems - 1;
			indexOfItemToSort > 0;
			indexOfItemToSort--
		) {
			swap (items, 0, indexOfItemToSort);
			reheapDown (
				items,
				0, //root
				heapHeight - 1, //each child
				indexOfItemToSort //don't change the items in proper position
			);
		}
	}
}
#endif