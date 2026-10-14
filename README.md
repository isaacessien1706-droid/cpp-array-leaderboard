# Arcade Top-5 Leaderboard System (C++)

A console-based Leaderboard System built in C++ to demonstrate how **fixed-size 1D arrays** work in a real-world application.

## How Arrays Are Used in This App
* Fixed-Size 1D Array (`Player leaderboard[5]`):** Stores the Top 5 players and their scores in contiguous memory.
* Instant Rank Lookup: Since array indices start at `0`, a player's rank is calculated directly as `Rank = Index + 1`.
* Array Shifting & Insertion: When a new high score beats an existing score, lower scores are shifted one index to the right (`board[j] = board[j - 1]`) and the new score is inserted at its exact rank.
* Linear Search:Loops through the array indices to find a player by name and display their current rank.

## Menu Features
1. View Top 5 Leaderboard — Displays Ranks #1 to #5 alongside their exact array index (`board[0]` to `board[4]`).
2. Submit a New Score — Checks if a score qualifies for the Top 5 and updates the array.
3. Search Player Rank — Searches the array for a player's name and returns their rank and score.
