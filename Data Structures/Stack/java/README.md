# Stack Implementation using Java

Implemented using array concept
Uses a generic so it is applicable to many data types

## Example usage code

```java
public class main {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<Integer>();
        s.push(1);
        s.push(2);
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.pop());
    }
}
```