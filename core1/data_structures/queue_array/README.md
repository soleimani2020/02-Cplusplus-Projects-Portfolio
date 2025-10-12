➡️ Queue Using Array in C++

A simple Queue data structure implemented using a fixed-size array.
⚙️ Features:

    ➕ Enqueue: Adds elements to the rear of the queue.

    ➖ Dequeue: Removes elements from the front of the queue.

    🚫 Full/Empty Checks: Detects when the queue is full or empty.

    📊 Display: Prints the current elements in the queue.

🔍 How it works:

    Uses two pointers: head (front) and rear (end) to track queue status.

    Enqueue increments the rear pointer; Dequeue increments the head pointer.

    Linear queue without wrapping — once full, no reuse of emptied slots.

⚠️ Limitations:

    Not circular: once rear reaches the end of the array, the queue is full, even if there are free slots at the front.

💡 Ideal for:

    Learning basic queue mechanics.

    Scenarios where a fixed size and simple FIFO behavior is sufficient.
