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
    QPushButton *m_calc_button;
    QLineEdit *m_input_edit;
    QLineEdit *m_output_edit;
};

