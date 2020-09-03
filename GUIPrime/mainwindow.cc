#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_input_edit = ui->inputLineEdit;
    m_input_edit->setText("2");
    m_output_edit = ui->outputLineEdit;
    m_output_edit->setText("Is Prime!");
    m_calc_button = ui->calcButton;

    // widget = calcButton
    // Signal = released()
    // SLOT = compute()
    connect(m_calc_button, SIGNAL(released()), this, SLOT(compute()));
}

bool is_prime(int val)
{
    if (val < 0 || val == 0 || val == 1)
        return false;

    if (val == 2)
        return true;

    if (val % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(val); i += 2)
    {
        if (val % i == 0)
            return false;
    }

    return true;
}

void MainWindow::compute()
{
    QString val_text = m_input_edit->text();
    int val = val_text.toInt();

    if (is_prime(val))
    {
        m_output_edit->setText("Is Prime!");
    }
    else
    {
        m_output_edit->setText("Is not Prime!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
