#include <iostream>
#include <random>

#include "Game.h"

std::uint32_t Game::random_uint(const std::uint32_t lower, const std::uint32_t upper)
{
    auto gen = std::random_device{};
    auto dist = std::uniform_int_distribution<std::uint32_t>(lower, upper);

    return dist(gen);
}

Position Game::random_position(const std::uint32_t lower_x,
                               const std::uint32_t upper_x,
                               const std::uint32_t lower_y,
                               const std::uint32_t upper_y)
{
    return std::make_pair(random_uint(lower_x, upper_x),
                          random_uint(lower_y, upper_y));
}

ConsoleInput Game::map_user_input(const char user_input)
{
    switch (user_input)
    {
    case 'w':
    {
        return ConsoleInput::UP;
    }
    case 'a':
    {
        return ConsoleInput::LEFT;
    }
    case 's':
    {
        return ConsoleInput::DOWN;
    }
    case 'd':
    {
        return ConsoleInput::RIGHT;
    }
    default:
    {
        return ConsoleInput::INVALID;
    }
    }
}

Game::Game()
{
    for (auto &obs : m_obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
    }
}

void Game::execute_move(Position &player, const ConsoleInput move)
{
    switch (move)
    {
    case ConsoleInput::LEFT:
    {
        if (player.second > 0)
        {
            player.second--;
        }
        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (player.second < LEN_Y - 1)
        {
            player.second++;
        }
        break;
    }
    case ConsoleInput::UP:
    {
        if (player.first > 0)
        {
            player.first--;
        }
        break;
    }
    case ConsoleInput::DOWN:
    {
        if (player.first < LEN_X - 1)
        {
            player.first++;
        }
        break;
    }
    case ConsoleInput::INVALID:
    default:
    {
        break;
    }
    }
}

void Game::print_game_state(const Position &player, const Obstacles &obstacles)
{
    auto game_state = GameState(LEN_X, std::string(LEN_Y, '.'));

    game_state[m_start.first][m_start.second] = '|';
    game_state[m_goal.first][m_goal.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (const auto &obs : obstacles)
    {
        game_state[obs.first][obs.second] = 'X';
    }

    for (std::uint32_t i = 0; i < LEN_X; i++)
    {
        for (std::uint32_t j = 0; j < LEN_Y; j++)
        {
            std::cout << game_state[i][j] << " ";
        }

        std::cout << std::endl;
    }
}


void Game::move_obstacles()
{
    for (auto &obs : m_obstacles)
    {
        const auto offset = random_position(-1, 1, -1, 1);

        if (obs.first + offset.first < LEN_X && obs.second + offset.second < LEN_Y)
        {
            obs.first += offset.first;
            obs.second += offset.second;
        }
    }
}

bool Game::is_dead(const Position &player, const Obstacles &obstacles)
{
    for (const auto &obs : obstacles)
    {
        if (player == obs)
            return true;
    }

    return false;
}

bool Game::is_finished(const Position &player)
{
    return player == m_goal;
}

void Game::execute()
{
    char user_input = 0;

    while (true)
    {
        if (is_finished(m_player) || is_dead(m_player, m_obstacles))
        {
            break;
        }

        print_game_state(m_player, m_obstacles);
        std::cin >> user_input;
        const auto console_input = map_user_input(user_input);
        execute_move(m_player, console_input);
        move_obstacles();
    }
}
