#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <math.h>
#include <stdint.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_input_edit = ui->inputLineEdit;
    m_input_edit->setText("2");
    m_output_edit = ui->outputLineEdit;
    m_output_edit->setText("Is Prime!");
    m_calc_button = ui->calcButton;

    connect(m_calc_button, SIGNAL(released()), this, SLOT(compute()));
}

bool is_prime(std::uint64_t val)
{
    if (val <= 1)
    {
        return false;
    }

    if ((val == 2) || (val == 3) | (val == 5))
    {
        return true;
    }

    if (val % 2 == 0)
    {
        std::cout << "Divisible by 2" << std::endl;
        return false;
    }

    if (val % 3 == 0)
    {
        std::cout << "Divisible by 3" << std::endl;
        return false;
    }

    if (val % 5 == 0)
    {
        std::cout << "Divisible by 5" << std::endl;
        return false;
    }

    for (int i = 7; i <= sqrt(val); i += 2)
    {
        if (val % i == 0)
        {
            std::cout << "Divisible by: " << i << std::endl;
            return false;
        }
    }

    return true;
}

void MainWindow::compute()
{
    QString val_text = m_input_edit->text();
    std::uint64_t val = val_text.toULongLong();

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
