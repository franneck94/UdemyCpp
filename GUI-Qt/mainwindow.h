#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

constexpr uint32_t LEN_X = 5;
constexpr uint32_t LEN_Y = 5;
constexpr uint32_t NUM_OBSTACLES = 3U;

enum class ConsoleInput
{
    INVALID,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

using Position = std::pair<uint32_t, uint32_t>;
using GameState = std::vector<std::vector<QLabel *>>;
using Obstacles = std::vector<Position>;

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

    static uint32_t random_uint(const uint32_t lower, const uint32_t upper);

    static Position random_position(const uint32_t lower_x,
                                    const uint32_t upper_x,
                                    const uint32_t lower_y,
                                    const uint32_t upper_y);

    void update_game_state();

    void move_player();

    bool is_dead();

    bool is_finished();

    void move_obstacles();

    void generate_random_obstacles();

private slots:
    void start_game();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QPushButton *m_play_button;
    QGridLayout *m_field_grid_layout;
    QLabel *m_points_label;

    const QString m_ressources_path =
        QString::fromStdString("C:/Users/Jan/OneDrive/_Coding/UdemyCpp/GUI-Qt/ressources/");
    const QString m_field_icon_path = m_ressources_path + "FieldIcon.png";
    const QString m_player_icon_path = m_ressources_path + "PlayerIcon.png";
    const QString m_obstacle_icon_path = m_ressources_path + "ObstacleIcon.png";
    const QString m_goal_icon_path = m_ressources_path + "GoalIcon.png";

    const Position m_goal = std::make_pair(4U, 4U);
    const Position m_start = std::make_pair(0U, 0U);

    ConsoleInput m_move = ConsoleInput::INVALID;
    bool m_in_game = false;
    std::uint32_t m_points = 0;
    Position m_player = std::make_pair(0U, 0U);
    GameState m_game_state;
    Obstacles m_obstacles = std::vector<Position>{NUM_OBSTACLES};
};
#endif // MAINWINDOW_H
