#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->title->setAlignment(Qt::AlignCenter);

    QFont title_font = ui->title->font();
    title_font.setPixelSize(50);
    title_font.setFamily("Courier");
    ui->title->setFont(title_font);

    QFont title_font2 = ui->add_recipe_title->font();
    title_font2.setPixelSize(20);
    title_font2.setFamily("Courier");
    ui->add_recipe_title->setFont(title_font2);
    ui->edit_recipe_title->setFont(title_font2);
    ui->find_recipe_title->setFont(title_font2);
    ui->delete_recipe_title->setFont(title_font2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findby_activated(int index)
{
    if(index == 0){
        ui->search_value->setPlaceholderText("Enter Name");
    }
    else if (index == 1){
        ui->search_value->setPlaceholderText("Enter Ingredients");
    }
    else{
        ui->search_value->setPlaceholderText("Enter Name");
    }
    // qDebug() << index ;
}

