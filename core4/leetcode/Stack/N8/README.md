```text
🧠 Key Idea: Understanding ans

ans is the current decoded string at the current nesting level.

Think of ans as a scratchpad:

Before [
→ ans contains the string before entering a new level.

Example:
x3[a]

Before [
ans = "x"
num = 3

We save this state in the stacks.


After [
→ We enter a new level, so we reset:

ans = ""

Now ans starts collecting only the content inside the brackets.


Before ]
→ ans contains the completed decoded string inside the current brackets.

Example:
2[abc]

Before ]
ans = "abc"


After ]
→ We repeat ans and merge it with the previous string.

Example:
x2[ab]

Inside:
ans = "ab"

Repeat:
"ab" + "ab" = "abab"

Merge:
"x" + "abab" = "xabab"


Memory Trick:

[  → Save the current state and go deeper.
]  → Restore the previous state, expand the current string, and continue.

In short:

ans always stores the decoded string at my current depth.
When I go deeper, I reset it.
When I come back, I merge it with the previous level.
```
