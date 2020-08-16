#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

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

