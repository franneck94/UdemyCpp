#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_input_edit = ui->inputLineEdit;
    m_input_edit->setText("2");
    m_output_edit = ui->outputLineEdit;
    m_output_edit->setText("Is Prime!");
    m_calc_button = ui->calcButton;
}

MainWindow::~MainWindow()
{
    delete ui;
}
