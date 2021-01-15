#include <iostream>
#include <random>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_player(Position(0, 0)),
    m_goal(random_position(2, LEN_X - 1, 2, LEN_Y - 1)),
    m_game_state(GameState(LEN_X, std::vector<QLabel *>(LEN_Y))),
    m_obstacles(Obstacles(NUM_OBSTACLES, Position(0, 0)))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

ConsoleInput MainWindow::map_user_input(char user_input)
{
    switch(user_input)
    {
    case 'a':
    {
        return ConsoleInput::LEFT;
    }
    case 'd':
    {
        return ConsoleInput::RIGHT;
    }
    case 'w':
    {
        return ConsoleInput::UP;
    }
    case 's':
    {
        return ConsoleInput::DOWN;
    }
    default:
    {
        return ConsoleInput::INVALID;
    }
    }
}

void MainWindow::update_game_state()
{

}

void MainWindow::move_player(ConsoleInput move)
{
    switch(move)
    {
    case ConsoleInput::LEFT:
    {
        if (m_player.second > START.second)
        {
            m_player.second--;

            std::cout << "You moved to the left!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }

        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (m_player.second < LEN_Y)
        {
            m_player.second++;

            std::cout << "You moved to the right!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }

        break;
    }
    case ConsoleInput::UP:
    {
        if (m_player.first > START.first)
        {
            m_player.first--;

            std::cout << "You moved upwards!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }

        break;
    }
    case ConsoleInput::DOWN:
    {
        if (m_player.first < LEN_X)
        {
            m_player.first++;

            std::cout << "You moved downwards!" << std::endl;
        }
        else
        {
            std::cout << "You bounced!" << std::endl;
        }

        break;
    }
    case ConsoleInput::INVALID:
    default:
    {
        std::cout << "Unrecognized move!" << std::endl;

        break;
    }
    }
}

void MainWindow::move_obstacles()
{
    for (auto &obs : m_obstacles)
    {
        Position offset = random_position(-1, 1, -1, 1);

        if (obs.first + offset.first < LEN_X
            && obs.second + offset.second < LEN_Y
            && obs.first + offset.first != m_player.first
            && obs.second + offset.second != m_player.second
            && obs.first + offset.first != m_goal.first
            && obs.second + offset.second != m_goal.second)
        {
            obs.first += offset.first;
            obs.second += offset.second;
        }
    }
}

void MainWindow::generate_random_obstacles()
{
    for (auto &obs : m_obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
    }
}

bool MainWindow::is_dead()
{
    for (const auto &obs : m_obstacles)
    {
        if(m_player == obs)
        {
            return true;
        }
    }

    return false;
}

bool MainWindow::is_finished()
{
    bool finished = false;

    if (m_goal == m_player)
    {
        finished = true;
    }

    return finished;
}

unsigned int MainWindow::random_uint(const unsigned int lower,
                               const unsigned int upper)
{
    std::random_device gen;
    std::uniform_int_distribution<unsigned int> dist(lower, upper);

    return dist(gen);
}

Position MainWindow::random_position(const unsigned int lower_x,
                               const unsigned int upper_x,
                               const unsigned int lower_y,
                               const unsigned int upper_y)
{
    Position pos(random_uint(lower_x, upper_x), random_uint(lower_y, upper_y));

    return pos;
}

void MainWindow::start_game()
{
    char user_input;
    ConsoleInput move;
    bool finished = false;

    generate_random_obstacles();

    while(!finished)
    {
        update_game_state();
        print_game_state();
        std::cin >> user_input;
        move = map_user_input(user_input);
        system("clear");
        move_player(move);
        move_obstacles();

        if(is_dead())
        {
            finished = true;

            std::cout << "You died!" << std::endl;
        }
        else if(is_finished())
        {
            finished = true;

            std::cout << "You won the game!" << std::endl;
        }
    }
}
