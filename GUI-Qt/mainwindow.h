#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

using Position = std::pair<std::uint32_t, std::uint32_t>;
using GameState = std::vector<std::vector<QLabel *>>;
using Obstacles = std::vector<Position>;

constexpr auto NUM_OBSTACLES = std::uint32_t{3};
constexpr auto LEN_X = std::uint32_t{5};
constexpr auto LEN_Y = std::uint32_t{5};
constexpr auto START = Position{0, 0};

enum class ConsoleInput
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

    void update_game_state();

    void move_player();

    void move_obstacles();

    void generate_random_obstacles();

    bool is_dead();

    bool is_finished();

    std::uint32_t random_uint(const std::uint32_t lower, const std::uint32_t upper);

    Position random_position(const std::uint32_t lower_x,
                             const std::uint32_t upper_x,
                             const std::uint32_t lower_y,
                             const std::uint32_t upper_y);

private slots:
    void start_game();
    void keyPressEvent(QKeyEvent *event);

private:
    ConsoleInput m_move = ConsoleInput::INVALID;
    bool m_in_game = false;
    std::uint32_t m_points = 0;

    Ui::MainWindow *ui;

    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;

    QPushButton *m_play_button;
    QGridLayout *m_field_grid_layout;
    QLabel *m_points_label;

    const QString m_current_path =
        QString::fromStdString("C:/Users/Jan/Dropbox/_Coding/UdemyCpp/GUI-Qt/");
    const QString m_ressources_path = m_current_path + "ressources/";
    const QString m_field_icon_path = m_ressources_path + "FieldIcon.png";
    const QString m_player_icon_path = m_ressources_path + "PlayerIcon.png";
    const QString m_obstacle_icon_path = m_ressources_path + "ObstacleIcon.png";
    const QString m_goal_icon_path = m_ressources_path + "GoalIcon.png";
};
