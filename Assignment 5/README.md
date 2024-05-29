# CS 260 Assignment 5

## Auto-sorting data structure

Considering the array-based structure:

Naive way to do a sorted-insert is to use a for-loop, comparing each element against the element being inserted, and when we've found the right place, insert into the array at that point.

This gives us `O(n)` performance since at the worst case, we're iterating over the entire array to find a place to put the new element. Is there a better way? For basic arrays, probably not. For vectors? Hmm.

Considering the linked-list structure:

What if we used binary search trees for both searching *and* sorted-inserting, since sorted-inserting necessarily requires searching for the place to put the new value.

This would give us `O(log n)` performance since it's binary search, which is better than the array-based naive searching, but this comes at the cost of having more memory in use for each data value.