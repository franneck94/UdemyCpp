#include <iostream>
#include <random>

#include <QRandomGenerator>

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
    m_play_button = ui->playButton;
    m_field_grid_layout = ui->fieldGridLayout;
    m_points_label = ui->pointsLabel;
    connect(m_play_button, SIGNAL(released()), this, SLOT(start_game()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (m_in_game)
    {
        switch(event->key())
        {
        case Qt::Key_A:
        {
            m_move = ConsoleInput::LEFT;
            break;
        }
        case Qt::Key_D:
        {
            m_move = ConsoleInput::RIGHT;
            break;
        }
        case Qt::Key_W:
        {
            m_move = ConsoleInput::UP;
            break;
        }
        case Qt::Key_S:
        {
            m_move = ConsoleInput::DOWN;
            break;
        }
        default:
        {
            m_move = ConsoleInput::INVALID;
            break;
        }
        }

        if(ConsoleInput::INVALID != m_move)
        {
            m_points++;

            move_player();
            move_obstacles();
            update_game_state();

            if(is_dead())
            {
                m_in_game = false;

                std::cout << "You died!" << std::endl;
            }
            else if(is_finished())
            {
                m_in_game = false;

                std::cout << "You won the game!" << std::endl;
            }
        }
     }
}

void MainWindow::update_game_state()
{
    for (unsigned int i = 0; i < LEN_X; ++i)
    {
        for (unsigned int j = 0; j < LEN_Y; ++j)
        {
            m_game_state[i][j]->setPixmap(QPixmap(m_field_icon_path));
        }
    }

    for(auto &obs : m_obstacles)
    {
        m_game_state[obs.first][obs.second]->setPixmap(QPixmap(m_obstacle_icon_path));
    }

    m_game_state[m_player.first][m_player.second]->setPixmap(QPixmap(m_player_icon_path));
    m_game_state[m_goal.first][m_goal.second]->setPixmap(QPixmap(m_goal_icon_path));
    m_points_label->setText(QString::number(m_points));
}

void MainWindow::move_player()
{
    switch(m_move)
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
    std::uniform_int_distribution<unsigned int> dist(lower, upper);

    return dist(*QRandomGenerator::global());
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
    m_points = 0;
    m_points_label->setText(QString::number(m_points));
    m_in_game = true;

    m_player = Position(0, 0);
    m_goal = random_position(2, LEN_X - 1, 2, LEN_Y - 1);
    generate_random_obstacles();

    for (unsigned int i = 0; i < LEN_X; ++i)
    {
        for (unsigned int j = 0; j < LEN_Y; ++j)
        {
            QString field_name = "Field" + QString::number(i) + "_" + QString::number(j);
            m_game_state[i][j] = MainWindow::findChild<QLabel *>(field_name);
        }
    }

    update_game_state();
}
