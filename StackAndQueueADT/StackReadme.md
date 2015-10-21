Implementation of a stack using a dynamically resizable array.
StackItem defines the kind of data that the stack will contain. Being public, it can be accessed directly as DynamicStack::StackItem.
StackItem EMPTY_STACK defines a constant that will be used to indicate an empty stack. Being public, it can be accessed directly as DynamicStack::EMPTY_STACK.
 
Member variables:
1. items_: An array of stack items.
2. capacity_: Maximum number of elements allowed in the current stack.
3. size_: Current number of elements in the stack.
4. init_capacity_: Initial capacity of the array (i.e., the capacity used in the constructor). This is used by pop() to determine if we should decrease the capacity.

Constructors and Destructor:
1. DynamicStack(): Default constructor of the class DynamicStack. It uses 16 as the initial capacity of the array, and allocates the required memory space for the stack. The function appropriately initializes the fields of the created empty stack.
2. DynamicStack(unsigned int capacity): Parametric constructor of the class DynamicStack. It allocates the required memory space for the stack of the given capacity. The function appropriately initializes the fields of the created empty stack.
3. ~DynamicStack(): Destructor of the class DynamicStack. It deallocates the memory space allocated for the stack.

Constant member functions:
1. int size() const: Returns the number of items in the stack.
2. bool empty() const: Returns true if the stack is empty, and false otherwise.
3. void print() const: Prints the stack items sequentially and in order, from the top to the bottom of the stack.
4. StackItem peek() const: Returns the value at the top of the stack without removing it. If the stack is empty, it returns the EMPTY_STACK constant instead.

Non-constant member functions:
1. void push(StackItem value): Takes as an argument a StackItem value. If the stack is not full, the value is pushed onto the stack. Otherwise, the capacity of the stack is doubled, and the item is then pushed onto the resized stack.
2. StackItem pop(): Removes and returns the top item from the stack as long as the stack is not empty. If the number of items remaining in the stack after
popping is less than or equal to one quarter of the capacity of the array, then the array is halved. However, if the new halved capacity is less than the initial
capacity, then no resizing takes place. Finally, If the stack is empty before the pop, the EMPTY_STACK constant is returned.
