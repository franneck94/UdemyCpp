#include <iostream>

constexpr unsigned int LEN_X = 10;
constexpr unsigned int START = 0;
constexpr unsigned int GOAL = LEN_X - 1;

constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';

void print_game_state(unsigned int player)
{
    char game_state[LEN_X];

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        game_state[i] = '.';
    }

    game_state[START] = '|';
    game_state[GOAL] = '|';
    game_state[player] = 'P';

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        std::cout << game_state[i];
    }
}

unsigned int execute_move(unsigned int player, char move)
{
    if (LEFT == move)
    {
        if (player > START)
        {
            player--;

            std::cout << "You moved to the left!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else if (RIGHT == move)
    {
        if (player < GOAL)
        {
            player++;

            std::cout << "You moved to the right!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }
    }
    else
    {
        std::cout << "Unrecognized move!" << std::endl;
    }

    return player;
}

bool is_finished(unsigned int player)
{
    bool finished = false;

    if (player == GOAL)
    {
        finished = true;

        std::cout << "You won the game!" << std::endl;
    }

    return finished;
}

void game()
{
    unsigned int player = 0;
    char move;
    bool finished = false;

    while (!finished)
    {
        print_game_state(player);
        std::cin >> move;
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player);
    }
}
