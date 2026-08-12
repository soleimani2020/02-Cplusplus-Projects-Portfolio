# Implement Stack Using Queues

**Difficulty:** Easy  
**Topics:** Queue, Stack, Design

## Problem

Implement a last-in-first-out (LIFO) stack using only two queues.

The implemented stack should support all the functions of a normal stack:

- `push(x)` — Pushes element `x` onto the stack.
- `pop()` — Removes and returns the element on top of the stack.
- `top()` — Returns the element on top of the stack.
- `empty()` — Returns `true` if the stack is empty, otherwise `false`.

## Approach

Use two queues:

- `input` — stores the elements.
- `output` — temporarily stores elements while rearranging the queue.

To implement `push(x)`:

1. Add `x` to `input`.
2. Move all existing elements from `input` to `output`.
3. Swap the two queues.

This ensures that the newest element is always at the **front** of the queue.

Therefore, `pop()` and `top()` can directly operate on the front element.
