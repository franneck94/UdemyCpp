# Computer Game 8

## Disclaimer

Ich werde meine Lösung Schritt-für-Schritt live programmieren.  
Deswegen müsst ihr diese nicht selber lösen, ihr könnt es aber gerne probieren.

## Exercise 1

Den Code vom Computer Game 7 werden wir jetzt eine eine Game Klasse packen.

```cpp
class Game
{
private:
    constexpr static auto NUM_OBSTACLES = 3U;
    constexpr static auto LEN_X = 5U;
    constexpr static auto LEN_Y = 5U;
    constexpr static auto START = Coordinate{.x = 0, .y = 0};
    constexpr static auto GOAL = Coordinate{.x = LEN_X - 1, .y = LEN_Y - 1};

    Coordinate player = {.x = 0, .y = 0};
    std::vector<Coordinate> obstacles;

public:
    Game() : obstacles(std::vector<Coordinate>(NUM_OBSTACLES, Coordinate{})){};
    ~Game() = default;

    void game();

private:
    static std::int32_t random_int(const std::int32_t lower,
                                   const std::int32_t upper);

    static std::uint32_t random_uint(const std::uint32_t lower,
                                     const std::uint32_t upper);

    static Coordinate random_coord(const std::uint32_t lower_x,
                                   const std::uint32_t upper_x,
                                   const std::uint32_t lower_y,
                                   const std::uint32_t upper_y);

    bool has_obstacle(const Coordinate &coord);

    void move_obstacles();

    bool is_finished();

    void print_game_state();

    void execute_move(const ConsoleInput move);
};
```

Ihr seht hier auch alle Member-Variablen aufgelistet.  
Deswegen muss der Code dahingehend angepasst werden, dass wir diese ja nicht mehr als Funktions-Argument übergeben müssen.
