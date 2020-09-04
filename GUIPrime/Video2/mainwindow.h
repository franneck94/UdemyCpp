#pragma once

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void compute();

  private:
    Ui::MainWindow *ui;
};
