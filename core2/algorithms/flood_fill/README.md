🧠 Flood Fill Using Depth-First Search (DFS)

🚀 **Algorithm Summary:**

🔹 Start from a given cell `(x, y)` in the grid  
🔸 Check if the cell matches the target color/value  
🔹 If it does, replace it with the new color  
🔸 Recursively explore in 4 directions:  
  ↪ Up `(x - 1, y)`  
  ↪ Right `(x, y + 1)`  
  ↪ Down `(x + 1, y)`  
  ↪ Left `(x, y - 1)`  
🔹 Follows **Depth-First Search (DFS)**: explores deeply before backtracking  
🔸 Skip cells that are:  
  ⛔ Out of bounds  
  ⛔ Already filled with the replacement color  
  ⛔ Do not match the target color  
🔹 Stops when all connected matching cells are filled
