This C++ program determines whether a given number is a "happy number" by repeatedly replacing the number with the sum of the squares of its digits, using Floyd's cycle detection algorithm to identify if the sequence reaches 1 (happy) or enters a loop (sad). It encapsulates the logic in a class, allowing user input and output to display the result.

Side Note: A happy number is a number which eventually reaches 1 when replaced by the sum of the squares of its digits, repeatedly. If it enters a cycle that does not include 1, it is not a happy number.


✅ Example 1: Happy Number (19)

Start: 19

Step 1: 1² + 9² = 82  
Step 2: 8² + 2² = 68  
Step 3: 6² + 8² = 100  
Step 4: 1² + 0² + 0² = 1   ← Stops here

Path: 19 → 82 → 68 → 100 → 1  
                            ↑
                            └── goal reached (happy)




❌ Example 2: Unhappy Number (20)

Start: 20

Step 1: 2² + 0² = 4  
Step 2: 4² = 16  
Step 3: 1² + 6² = 37  
Step 4: 3² + 7² = 58  
Step 5: 5² + 8² = 89  
Step 6: 8² + 9² = 145  
Step 7: 1² + 4² + 5² = 42  
Step 8: 4² + 2² = 20   ← cycle detected

Cycle: 20 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → ...  
                                                     ↑
                                                    cycle


For unhappy number:

   slow: 20 → 4 → 16 → 37 → ...
   fast: 20 → 16 → 58 → 145 → ...

Eventually:
   slow == fast (somewhere in the loop)
   slow != 1 ⇒ not happy




