# Implement Stack Using a Single Queue

**Difficulty:** Easy  
**Topics:** Queue, Stack, Design

## Problem

Implement a last-in-first-out (LIFO) stack using only **one queue**.

The implemented stack should support:

- `push(x)` — Pushes `x` onto the stack.
- `pop()` — Removes and returns the top element.
- `top()` — Returns the top element.
- `empty()` — Returns whether the stack is empty.

## Approach

Use a single queue.

The important idea is to make the **newest element always stay at the front** of the queue.

When we push a new element:

1. Add the new element to the back of the queue.
2. Rotate all previous elements from the front to the back.
3. The new element is now at the front.

### Video 

https://www.youtube.com/watch?v=Eh2gTUHL8Hs
  
