#pragma once

#include <QMainWindow>

#include <string>
#include <utility>
#include <vector>


#include "Helper.h"

typedef unsigned int unsigned int;
typedef char ConsoleInput;
typedef std::pair<unsigned int, unsigned int> Position;
typedef std::vector<std::string> GameState;
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
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    /*********************************/
    /*         GAME FUNCTIONS        */
    /*********************************/

    void start_game();

    void update_game_state();

    void move_player(ConsoleInput &move, bool &finished);

    void move_obstacles();

    void generate_random_obstacles();

    /*********************************/
    /*      GAME LOGIC FUNCTIONS     */
    /*********************************/

    bool is_killed(Position &pos);

    bool is_inbounds(Position &pos);

    bool is_finished();

    bool is_occupied(Position &pos);

  private:
    const unsigned int LEN_X;
    const unsigned int LEN_Y;
    GameState m_game_state;
    Position m_player;
    Position m_goal;
    unsigned int m_num_obstacles;
    Obstacles m_obstacles;

  private:
    Ui::GameWindow *ui;
};
