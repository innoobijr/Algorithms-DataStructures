// Array-based List Implementation
#include "ListADT.h"

template <typename E>
class AList :  public List<E>
{
	private:
		int maxSize;				// Maximum size of the list
		int listSize;				// Number of list items now
		int curr;				// Position of current element
		E* listArray;				// Array holding list elements
	
	public:
		AList(int size=defaultSize) {	// Constructor
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];	
		}

		~AList() { delete [] listArray; }	// Destructor
		
		void clear() 			// Reinitialize the list
		{	
			delete[] listArray;		// Remove the array
			listSize = curr = 0;		// Reset the size
			listArray = new E[maxSize];	// Recreate array 
		}

		// Insert "it" at current position
		void insert(const E &it)
		{
			Assert(listSize < maxSize, "List capacity exceeded");
			for( int i=listSize, i>curr; i--)	// Shift elements up
				listArray[i] = listArray[i-1];
			listArray[curr] = it;
			listSize++;				// Increment list size
		}

		void append(const E &it)
		{
			Assert(listSize < maxSize. "List capacity exceeded");
			listArray[listSize++] = it;
		}

		// Remove and return the current element
		E remove() 
		{
			Assert((curr>=0) && (curr < listSize), "No element");
			for(int i=curr; i<listSize-1;i++)
				listArray[i] = listArray[i+1];
			listSize--;
			return it;
		}
		
		void moveToStart() { curr = 0;	}		// Resert position
		void moveToEnd() { curr = listSize; }		// Set at end
		void prev() { if (curr != 0) curr--; }		// Back up
		void next() { if (curr < listSize) curr++; }	// Next

		// Return list size
		int length() const { return listSize; }
		
		// Return current positin
		int currPos() const { return curr; }
		
		// Set current list position to "pos"
		void moveToPos(int pos) {
			Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
			curr = pos;
		}
		
		const E& getValue() const {	// Return current element
			Assert ((curr>0=)&&(curr<listSize), "No current element");
			return listArray[curr];
		}
};
