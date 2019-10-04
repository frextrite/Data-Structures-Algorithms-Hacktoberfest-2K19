# Stack Implementation using c++

Implemented using linked list concept
The node class is a self referential class
Each node has two members, data (holding the data) and next (pointer to the next node in the linked list)

## Usage

Declaration : `Stack<dataType> st;`

Pushing into the stack : `st.push(data);`

Getting the value at the top of the stack : `dataType x = st.top();`

Popping from the stack : `st.pop();`

(Note : replace "dataType" with the type of the data you are using, example:  `Stack<int> st;`)

All the operation are performed in O(1) time complexity.

## In order to use the file as a header file

1. Rename the file with ".h" extension (header file extension)

2. Remove the `main()` function from the file
