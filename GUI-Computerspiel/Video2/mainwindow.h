#pragma once

#include <string>
#include <utility>
#include <vector>

#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>


using Position = std::pair<unsigned int, unsigned int>;
using GameState = std::vector<std::vector<QLabel *>>;
using Obstacles = std::vector<Position>;

constexpr unsigned int NUM_OBSTACLES = 3;
constexpr unsigned int LEN_X = 5;
constexpr unsigned int LEN_Y = 5;
constexpr Position START = {0, 0};

enum class ConsoleInput : int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ConsoleInput map_user_input(char user_input);

    void update_game_state();

    void move_player();

    void move_obstacles();

    void generate_random_obstacles();

    bool is_dead();

    bool is_finished();

    unsigned int random_uint(const unsigned int lower,
                             const unsigned int upper);

    Position random_position(const unsigned int lower_x,
                             const unsigned int upper_x,
                             const unsigned int lower_y,
                             const unsigned int upper_y);

private slots:
    void start_game();
    void keyPressEvent(QKeyEvent *event);

private:
    ConsoleInput m_move = ConsoleInput::INVALID;
    bool m_in_game = false;
    unsigned int m_points = 0;

    Ui::MainWindow *ui;

    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;

    QPushButton *m_play_button;
    QGridLayout *m_field_grid_layout;
    QLabel *m_points_label;

    const QString m_ressources_path =
        "C:/Users/Jan/Dropbox/_Coding/UdemyCpp/GUI-Computerspiel/ressources/";
    const QString m_field_icon_path = m_ressources_path + "FieldIcon.png";
    const QString m_player_icon_path = m_ressources_path + "PlayerIcon.png";
    const QString m_obstacle_icon_path = m_ressources_path + "ObstacleIcon.png";
    const QString m_goal_icon_path = m_ressources_path + "GoalIcon.png";
};
