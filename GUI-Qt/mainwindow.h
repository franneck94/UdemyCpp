#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QPushButton>

using Position = std::pair<std::uint32_t, std::uint32_t>;
using GameState = std::vector<std::vector<QLabel *>>;
using Obstacles = std::vector<Position>;

constexpr std::uint32_t NUM_OBSTACLES = 3;
constexpr std::uint32_t LEN_X = 5;
constexpr std::uint32_t LEN_Y = 5;
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
namespace Ui { class MainWindow; }
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
    Ui::MainWindow *ui;
    QPushButton *m_play_button;
    QGridLayout *m_field_grid_layout;
    QLabel *m_points_label;

    ConsoleInput m_move = ConsoleInput::INVALID;
    bool m_in_game = false;
    std::uint32_t m_points = 0;
    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;

    const QString m_ressources_path = QString::fromStdString("C:/Users/Jan/Desktop/GuiQt/ressources/");
    const QString m_field_icon_path = m_ressources_path + "FieldIcon.png";
    const QString m_player_icon_path = m_ressources_path + "PlayerIcon.png";
    const QString m_obstacle_icon_path = m_ressources_path + "ObstacleIcon.png";
    const QString m_goal_icon_path = m_ressources_path + "GoalIcon.png";
};
#endif // MAINWINDOW_H
