🔄 Circular Queue Implementation Using Array in C++

Efficient Circular Queue data structure implemented with a fixed-size array in C++.
⚙️ Features:

    ➕ Enqueue: Adds elements at the rear, wraps around when reaching the end.

    ➖ Dequeue: Removes elements from the front, supports circular wrap.

    🔄 Circular Logic: Utilizes modulo arithmetic to reuse array space efficiently.

    🚫 Full/Empty Checks: Properly detects when the queue is full or empty.

    📄 Display: Prints current elements in queue order.

🔍 Overview:

    Fixed size queue using circular buffering technique.

    Prevents wasted space common in linear array queues.

    Front and rear pointers wrap around array bounds.

    Supports seamless enqueue and dequeue operations with O(1) time complexity.

💡 Use Cases:

    Buffer management (e.g., data streams, IO buffers).

    Real-time task scheduling.

    Situations requiring fixed memory usage with FIFO behavior.
