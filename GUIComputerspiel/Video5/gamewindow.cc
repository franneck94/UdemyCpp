#include <iostream>

#include "Helper.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GameWindow), LEN_X(5), LEN_Y(5), m_max_num_obstacles(3)
{
    ui->setupUi(this);

    m_play_button = ui->playButton;
    m_field_grid_layout = ui->fieldGridLayout;
    m_points_label = ui->pointsLabel;
    m_obstacles_combo_box = ui->obstaclesComboBox;

    for (unsigned int i = m_max_num_obstacles; i > 0; --i)
    {
        m_obstacles_combo_box->addItem(QString::number(i));
    }

    connect(m_play_button, SIGNAL(released()), this, SLOT(start_game()));
}

GameWindow::~GameWindow()
{
    delete ui;
}

/*********************************/
/*      WIDGET FUNCTIONS         */
/*********************************/
void GameWindow::start_game()
{
    UInt active_num_obstacles = m_obstacles_combo_box->currentText().toUInt();
    std::cout << "Start Game with: " << active_num_obstacles << " Obstacles!" << std::endl;

    m_points_label->setText("0");
    m_points = 0;

    m_player = Position(0, 0);
    m_goal = random_position(2, LEN_X - 1, 2, LEN_Y - 1);
    generate_random_obstacles(active_num_obstacles);
    m_game_state = GameState(LEN_X, std::vector<QLabel *>(LEN_Y));

    for (unsigned int i = 0; i < LEN_X; ++i)
    {
        for (unsigned int j = 0; j < LEN_Y; ++j)
        {
            QString field_name = "Field" + QString::number(i) + "_" + QString::number(j);
            m_game_state[i][j] = GameWindow::findChild<QLabel *>(field_name);
        }
    }

    update_game_state();
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
}

/*********************************/
/*         GAME FUNCTIONS        */
/*********************************/

void GameWindow::update_game_state()
{
    for (unsigned int i = 0; i < LEN_X; ++i)
    {
        for (unsigned int j = 0; j < LEN_Y; ++j)
        {
            m_game_state[i][j]->setPixmap(QPixmap(m_field_icon_path));
        }
    }

    for (auto &obs : m_obstacles)
    {
        m_game_state[obs.first][obs.second]->setPixmap(QPixmap(m_obstacle_icon_path));
    }

    m_game_state[m_player.first][m_player.second]->setPixmap(QPixmap(m_player_icon_path));
    m_game_state[m_goal.first][m_goal.second]->setPixmap(QPixmap(m_goal_icon_path));
}

void GameWindow::move_player(KeyboardInput &move)
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
        m_in_game = false;
    }
    else if (is_inbounds(new_pos))
    {
        m_player = new_pos;
        m_points++;

        if (is_finished())
        {
            std::cout << "You won!" << std::endl;
            m_in_game = false;
        }
    }
}

void GameWindow::move_obstacles()
{
    std::vector<char> move_set = {LEFT, UP, RIGHT, DOWN};

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

        if (is_inbounds(new_pos) && !is_occupied(new_pos) && new_pos != m_player && new_pos != m_goal)
        {
            obs = new_pos;
        }
    }
}

void GameWindow::generate_random_obstacles(UInt &num_obstacles)
{
    m_obstacles = Obstacles(num_obstacles, Position(0, 0));

    for (auto &obs : m_obstacles)
    {
        obs = random_position(1, LEN_X - 1, 1, LEN_Y - 1);
        std::cout << obs.first << " " << obs.second << std::endl;
    }
}

/*********************************/
/*      GAME LOGIC FUNCTIONS     */
/*********************************/

bool GameWindow::is_killed(Position &pos)
{
    for (auto &obs : m_obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}

bool GameWindow::is_inbounds(Position &pos)
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

bool GameWindow::is_occupied(Position &pos)
{
    for (auto &obs : m_obstacles)
    {
        if (pos == obs)
            return true;
    }

    return false;
}
