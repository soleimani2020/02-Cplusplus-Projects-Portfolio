# LeetCode Problem: Decode String (Medium)

## 🧩 Problem Statement

Given an encoded string, decode it using the rule:

```
k[encoded_string]
```

The substring inside the brackets is repeated `k` times.

Example:

```
Input: s = "3[a2[c]]"

Output:
"accaccacc"
```

The challenge is handling **nested brackets**, so we use a stack to save the previous state.

---

# 💡 Main Idea

The problem is about handling unfinished work.

When we see:

```
[
```

we are entering a new level.

We save:
- The string before this bracket
- The repeat number

When we see:

```
]
```

we finish the current level:
- Get the repeat number
- Get the previous string
- Repeat the current string
- Merge the result with the previous string

---

# 🧠 Understanding `ans`

`ans` stores the **decoded string at the current nesting level**.

Think of `ans` as a scratchpad.

```
Before [

ans contains the string before entering a new level.

Example:

x3[a]

ans = "x"
num = 3

We save this state in the stacks.
```

```
After [

We enter a new level.

Reset:

ans = ""

Now ans starts collecting the inside of the brackets.
```

```
Before ]

ans contains the completed string inside the current brackets.

Example:

2[abc]

ans = "abc"
```

```
After ]

We repeat ans and merge it with the previous string.

Example:

x2[ab]

Current:
ans = "ab"

Repeat:
"abab"

Merge:
"x" + "abab"

Result:
"xabab"
```

---

# 🔑 Stack Operations

## When we see `[`

Save the current state:

```cpp
numbers.push(num);
letters.push(ans);
```

Reset for the new level:

```cpp
num = 0;
ans = "";
```

---

## When we see `]`

Retrieve the previous state:

```cpp
int repeat = numbers.top();
numbers.pop();

string previous = letters.top();
letters.pop();
```

Create the repeated string:

```cpp
string temp = "";

for(int i = 0; i < repeat; i++){
    temp += ans;
}
```

Merge:

```cpp
ans = previous + temp;
```

---

# 📝 Algorithm

1. Traverse the string character by character.
2. If the character is a digit:
   - Build the repeat number.
3. If the character is a letter:
   - Add it to `ans`.
4. If the character is `[`
   - Push `num` and `ans` into stacks.
   - Reset them.
5. If the character is `]`
   - Pop repeat count and previous string.
   - Expand current string.
   - Merge with previous string.
6. Return `ans`.



---

# ⏱ Complexity Analysis

Time Complexity:

```
O(n)
```

Each character is processed once.

Space Complexity:

```
O(n)
```

The stacks store previous states for nested expressions.

---

# 🔗 Video Explanation

https://www.youtube.com/watch?v=E9qHRcQXmDk&t=15s
