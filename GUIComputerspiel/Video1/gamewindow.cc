#include <iostream>

#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    LEN_X(5), LEN_Y(5)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

/*********************************/
/*         GAME FUNCTIONS        */
/*********************************/

void GameWindow::start_game()
{
    m_player = Position(0, 0);
    m_goal = random_position(2, LEN_X - 1, 2, LEN_Y - 1);
    generate_random_obstacles();
    m_game_state = GameState();

    ConsoleInput move;
    bool finished = false;

    while (!finished)
    {
        update_game_state();
        move_player(move, finished);
        move_obstacles();
        if (is_finished())
            finished = true;
    }
}

void GameWindow::update_game_state()
{
    m_game_state = GameState(LEN_X, std::string(LEN_Y, '.'));

    for (auto &obs : m_obstacles)
    {
        m_game_state[obs.first][obs.second] = 'X';
    }

    m_game_state[m_player.first][m_player.second] = 'P';
    m_game_state[m_goal.first][m_goal.second] = 'O';
}

void GameWindow::move_player(
    ConsoleInput &move,
    bool &finished)
{
    Position new_pos;

    if (move == LEFT)
    {
        new_pos = Position(m_player.first, m_player.second - 1);
    }
    else if (move == RIGHT)
    {
        new_pos = Position(m_player.first, m_player.second + 1);
    }
    else if (move == UP)
    {
        new_pos = Position(m_player.first - 1, m_player.second);
    }
    else if (move == DOWN)
    {
        new_pos = Position(m_player.first + 1, m_player.second);
    }

    if (is_killed(new_pos))
    {
        std::cout << "You died!" << std::endl;
        finished = true;
    }
    else if (is_inbounds(new_pos))
    {
        std::cout << "You moved!" << std::endl;
        m_player = new_pos;
    }
    else
    {
        std::cout << "You bounced!" << std::endl;
    }
}

void GameWindow::move_obstacles()
{
    std::vector<char> move_set = { LEFT, UP, RIGHT, DOWN };

    for (auto &obs : m_obstacles)
    {
        UInt random_move_idx = random_uint(0, 3);
        char move = move_set[random_move_idx];
        Position new_pos;

        if (move == LEFT)
        {
            new_pos = Position(obs.first, obs.second - 1);
        }
        else if (move == RIGHT)
        {
            new_pos = Position(obs.first, obs.second + 1);
        }
        else if (move == UP)
        {
            new_pos = Position(obs.first - 1, obs.second);
        }
        else if (move == DOWN)
        {
            new_pos = Position(obs.first + 1, obs.second);
        }

        if (is_inbounds(new_pos)
            && !is_occupied(new_pos)
            && new_pos != m_player
            && new_pos != m_goal)
        {
            obs = new_pos;
        }
    }
}

void GameWindow::generate_random_obstacles()
{
    m_obstacles = Obstacles(m_num_obstacles, Position(0, 0));

    for (auto &obs : m_obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
    }
}

/*********************************/
/*      GAME LOGIC FUNCTIONS     */
/*********************************/

bool GameWindow::is_killed(
    Position &pos)
{
    for (auto &obs : m_obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}

bool GameWindow::is_inbounds(
    Position &pos)
{
    if (pos.first < LEN_X && pos.second < LEN_Y)
        return true;
    else
        return false;
}

bool GameWindow::is_finished()
{
    if (m_player == m_goal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GameWindow::is_occupied(
    Position &pos)
{
    for (auto &obs : m_obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}
