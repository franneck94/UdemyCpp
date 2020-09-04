#pragma once

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>


#include <string>
#include <utility>
#include <vector>


typedef unsigned int UInt;
typedef char ConsoleInput;
typedef std::pair<UInt, UInt> Position;
typedef std::vector<std::vector<QLabel *>> GameState;
typedef std::vector<Position> Obstacles;

enum
{
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's'
};

namespace Ui
{
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

  public:
    /*********************************/
    /*   CONSTRUCTOR / DESTRUCTOR    */
    /*********************************/
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    /*********************************/
    /*         GAME FUNCTIONS        */
    /*********************************/
    /*
    void start_game();

    void update_game_state();

    void move_player(
        ConsoleInput &move,
        bool &finished);

    void move_obstacles();

    void generate_random_obstacles();
    */
    /*********************************/
    /*      GAME LOGIC FUNCTIONS     */
    /*********************************/

    bool is_killed(Position &pos);

    bool is_inbounds(Position &pos);

    bool is_finished();

    bool is_occupied(Position &pos);

  private slots:
    /*********************************/
    /*         WIDGET VARS           */
    /*********************************/
    void start_game();

  private:
    /*********************************/
    /*         MEMBER VARS           */
    /*********************************/
    Ui::GameWindow *ui;

    QPushButton *m_play_button;
    QGridLayout *m_field_grid_layout;
    QLabel *m_points_label;
    QComboBox *m_obstacles_combo_box;

    const UInt LEN_X;
    const UInt LEN_Y;
    GameState m_game_state;
    Position m_player;
    Position m_goal;
    UInt m_max_num_obstacles;
    Obstacles m_obstacles;
};
