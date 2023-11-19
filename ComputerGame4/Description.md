# Computer Game 4

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Wir werden jetzt unseren "game" Code in mehrere Funktionen auslagern:

```cpp
bool is_finished(const std::uint32_t player)

void print_game_state(const std::uint32_t player)

void execute_move(std::uint32_t &player, const char move)

void game()
```

Das heißt in unserer "game" Funktionen werden:

- is_finished
- print_game_state
- execute_move

aufgerufen.
