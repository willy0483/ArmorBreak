# ArmorBreak: Turn-Based Battle Sim - 7 Day Project Checklist

> **Goal:** Build a simple text-based turn-based battle game in C++ using structs, functions, loops, and math-based combat logic. Work 1–2 hours a day.

---

## 🗓️ Day 1: Character Setup

- ✅ Create a `Character` struct with:

  - `name` (string)
  - `hp` (int)
  - `atk` (int)
  - `def` (int)

- ✅  Initialize a `player` and `enemy` with values
- ✅  Print their stats using `cout`

**Learn:** Structs, variables, basic I/O
**Resources:**
[LearnCpp: Structs](https://www.learncpp.com/cpp-tutorial/introduction-to-structs-enumerations-and-classes/)
[Basic I/O](https://www.learncpp.com/cpp-tutorial/basic-input-and-output/)

---

## 🗓️ Day 2: Damage Function

- ✅ Write a function:

```cpp
int calculateDamage(int atk, int def);
```

- ✅ Prevent negative damage
- ✅ Subtract damage from enemy HP

**Learn:** Functions, conditionals
**Resources:**
[LearnCpp: Functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
[If statements](https://www.learncpp.com/cpp-tutorial/if-statements/)

---

## 🗓️ Day 3: Turn-Based Loop

- ✅ Add a battle loop using `while (player.hp > 0 && enemy.hp > 0)`
- ✅ Alternate turns between player and enemy
- ✅ Print HP after each turn

**Learn:** While loops, game logic
**Resources:**
[While Loops](https://www.learncpp.com/cpp-tutorial/while-statements/)

---

## 🗓️ Day 4: Player Choice

- ✅ Ask the player: (1) Attack (2) Defend
- ✅ Use `cin` to read input
- ✅ Implement defend logic (reduce damage)

**Learn:** User input, branching
**Resources:**
[Input with cin](https://www.learncpp.com/cpp-tutorial/basic-input-using-cin/)

---

## 🗓️ Day 5: Battle Log Output

- [ ] Print messages for attack/damage/HP
- [ ] Add turn counter
- [ ] Format for readability (lines, spacing)

**Learn:** Output formatting, string usage

---

## 🗓️ Day 6: Win/Loss & Replay

- [ ] End the game when someone’s HP ≤ 0
- [ ] Display win/loss message
- [ ] Ask if the player wants to play again
- [ ] Use a `do { } while()` loop for replay

**Learn:** Loops, game restart logic

---

## 🗓️ Day 7: Polish & Bonus Features

- [ ] Clean up code & add comments
- [ ] Add at least one bonus feature:

  - Critical hits (random double damage)
  - Healing (limited use)
  - Random enemy stats
  - Armor break mechanic

- [ ] Celebrate! You made a C++ turn-based game!

---

## ✨ Optional Extensions

- Add save/load system
- Track player win/loss record
- Build UI with SFML later using same logic
