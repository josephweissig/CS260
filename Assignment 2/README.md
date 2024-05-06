# CS 260 Assignment 2

## Queue data structure design

Functions likely required:

- Constructor taking in an argument for max queue size.
- Add an entry to the end of the queue.
- Remove an entry from the front of the queue.
- Peek the value of the front of the queue without removing it.
- Check if the queue is empty.
- Check if the queue is full.

Values likely required:

- The list of elements in the queue.
- The maximum size of the queue, given in the constructor.
- A pointer to the first element (front) of the queue.
- A pointer to the last element (rear) of the queue.
- The current size of the list of elements (maybe provided by the list of elements itself based on the language we're using?)

## Arbitrary list data structure design

> [!NOTE]
> Note that for this to work, the elements/nodes will need a pointer to the "next" element in the list, for us to keep track of where we are in the list.

Functions likely required:

- Constructor taking an argument for max list size.
- Add a node at the given position.
- Remove a node at the given position.
- Get the value of a node at the given position.
- Check if the list is empty.
- Check if the list is full.

Values required:

- The list of elements in the list.
- The maximum size of the list, given in the constructor.
- A pointer to the first node (head) of the list.