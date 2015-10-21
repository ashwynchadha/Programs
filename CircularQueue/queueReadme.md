Implementation of the Queue ADT using a circular array.

• QueueItem defines the kind of data that the queue will contain. Being public, it can be
accessed directly as CircularQueue::QueueItem.

• QueueItem EMPTY_QUEUE defines a constant that will be used to indicate an empty
queue. Being public, it can be accessed directly as CircularQueue::EMPTY_QUEUE.

• Member variables:
1. items_: An array of queue items.
2. head_: Index of the first element in the circular queue.
3. tail_: Index of the element after the last item in the circular queue.
4. capacity_: Maximum number of items in the queue.
5. size_: Current number of items in the queue.

• Constructors and Destructor:
1. CircularQueue(): Default constructor of the class CircularQueue. It uses
16 as the initial capacity of the array, and allocates the required memory space
for the queue. The function appropriately initializes the fields of the created
empty queue.
2. CircularQueue(unsigned int capacity): Parametric constructor of the
class CircularQueue. It allocates the required memory space for the queue of
the given capacity. The function appropriately initializes the fields of the created
empty queue.
3. ~CircularQueue(): Destructor of the class CircularQueue. It deallocates
the memory space allocated for the queue.

• Constant member functions:
1. int size() const: Returns the number of items in the queue.
2. bool empty() const: Returns true if the queue is empty, and false
otherwise.
3. bool full() const: Returns true if the queue is full, and false otherwise.
4. void print() const: Prints the queue items sequentially and in order, from
the front to the rear of the queue.
Assignment #2 Page 5
5. QueueItem peek() const: Returns the value at the front of the queue
without removing it from the queue. If the queue is empty, it returns the
EMPTY_QUEUE constant instead.

• Non-constant member functions:
1. bool enqueue(QueueItem value): Takes as an argument a QueueItem
value. If the queue is not at capacity, it inserts the value at the rear of the queue
after the last item, and returns true. If the insertion fails due to lack of space, it
returns false.
2. QueueItem dequeue():Removes the item from the front of the queue and
returns it. If the queue is empty, it returns the EMPTY_QUEUE constant instead.
