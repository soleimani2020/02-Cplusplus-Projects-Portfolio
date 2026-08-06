# LeetCode 881: Boats to Save People (Medium)

## 🧩 Problem Statement

You are given an array `people` where:

- `people[i]` represents the weight of the `i-th` person.
- Each boat can carry at most **two people**.
- The total weight of people in a boat cannot exceed `limit`.

Return the minimum number of boats needed to rescue everyone.

---

# Example 1

## Input

```text
people = [1,2]
limit = 3
```

## Output

```text
1
```

## Explanation

The two people can share one boat:

```text
1 + 2 = 3 <= limit
```

---

# Example 2

## Input

```text
people = [3,2,2,1]
limit = 3
```

## Output

```text
3
```

## Explanation

Possible arrangement:

```text
[3]
[1,2]
[2]
```

Total boats:

```text
3
```

---

# Example 3

## Input

```text
people = [3,5,3,4]
limit = 5
```

## Output

```text
4
```

## Explanation

No two people can share a boat:

```text
[5]
[4]
[3]
[3]
```

---

# Constraints

- `1 <= people.length <= 50000`
- `1 <= people[i] <= limit <= 30000`

---

# 💡 Approach: Two Pointers (Greedy)

## Observation

To minimize the number of boats:

- The heaviest person should always be placed in a boat.
- If possible, pair the heaviest person with the lightest person.

Why?

If the heaviest person cannot pair with the lightest person, then they cannot pair with anyone else.

---

# Algorithm

1. Sort the array.
2. Use two pointers:
   - `light` → smallest weight person.
   - `heavy` → largest weight person.
3. While there are people left:
   - The heaviest person always uses a boat.
   - If the heaviest person can share with the lightest person:
     - Move `light++`.
   - Move `heavy--`.
   - Increment boat count.

---

# Example Walkthrough

Input:

```text
people = [3,2,2,1]
limit = 3
```

Sort:

```text
[1,2,2,3]
```

---

### Step 1

```
light = 1
heavy = 3
```

Check:

```text
1 + 3 = 4 > 3
```

The person with weight `3` needs a separate boat.

```
boats = 1
heavy--
```

---

### Step 2

```
light = 1
heavy = 2
```

Check:

```text
1 + 2 = 3 <= 3
```

They share a boat.

```
boats = 2
light++
heavy--
```

---

### Step 3

Remaining person:

```text
[2]
```

Needs one boat.

Final answer:

```text
boats = 3
```

# 🔍 Complexity Analysis

## Time Complexity

Sorting:

\[
O(n \log n)
\]

Two pointer traversal:

\[
O(n)
\]

Total:

\[
\boxed{O(n \log n)}
\]

---

## Space Complexity

The algorithm uses only constant extra variables:

\[
\boxed{O(1)}
\]

---

# ✅ Key Takeaways

- Sorting enables the greedy strategy.
- Pair the heaviest person with the lightest possible person.
- If the heaviest cannot pair with the lightest, they cannot pair with anyone.
- The heaviest person always consumes one boat.

---

# Topics

- Array
- Two Pointers
- Greedy Algorithm
- Sorting

---

# Company Tags

- Amazon
- Google
- Microsoft
- Facebook
- Bloomberg
- Apple

---

# Follow Up

Can you solve it without using extra space?

Yes.

The solution performs the sorting in-place and uses:

```text
Time Complexity:  O(n log n)
Space Complexity: O(1)
```

Video Tutorial : https://www.youtube.com/watch?v=PCGdb-46H_w&t=63s
