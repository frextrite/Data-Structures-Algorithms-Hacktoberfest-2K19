// Stack data type implemented in Java
// Written by: @SLaGrave

public class Stack<T> {
    static final int MAX_ITEMS = 15000; // Max number of items in the stack
    private int top_of_stack; // Index of the top of the stack
    private T arr[]; // Array that represents the stack

    Stack() {
        top_of_stack = -1;
        arr  = (T[]) new Object[MAX_ITEMS];
    }

    boolean isEmpty() {
        return top_of_stack < 0;
    }

    void push(T input) {
        if (top_of_stack < MAX_ITEMS) {
            top_of_stack++;
            arr[top_of_stack] = input;
        }
        else {
            throw new IndexOutOfBoundsException("The max size of the stack has been reached");
        }
    }

    T pop() {
        if (top_of_stack >= 0) {
            T x = arr[top_of_stack];
            top_of_stack--;
            return x;
        }
        else {
            throw new IndexOutOfBoundsException("Tried to access element of empty stack");
        }
    }

    T peek() {
        if (top_of_stack >= 0) {
            T x = arr[top_of_stack];
            return x;
        }
        else {
            throw new IndexOutOfBoundsException("Tried to peek element of empty stack");
        }
    }
}
