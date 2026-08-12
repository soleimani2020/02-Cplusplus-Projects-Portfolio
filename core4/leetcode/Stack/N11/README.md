# Implement Queue using Stacks

**Difficulty:** Easy  
**Topics:** Stack, Queue, Design

## Problem

Implement a first in first out (FIFO) queue using only two stacks.

The implemented queue should support all the functions of a normal queue:

- `push(x)` — Adds element `x` to the back of the queue.
- `pop()` — Removes the element from the front of the queue and returns it.
- `peek()` — Returns the element at the front of the queue.
- `empty()` — Returns `true` if the queue is empty, otherwise `false`.

## Approach

Use two stacks:

- `input` — stores newly added elements.
- `output` — stores elements in queue order.

When `output` is empty, move all elements from `input` to `output`.

This reverses the order of the elements and makes the oldest element available at the top of `output`.

## Video

https://www.youtube.com/watch?v=0ZUM0yhBtPI
