#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::my_func()
{
    ui->erro_label->setVisible(false);
    ui->point_label->show();
    double points = 20;
    bool flag, flag2, flag3, flag4;
    double pow, dexter, intellekt, udacha;
    pow=ui->power->text().toInt(&flag);  // снимаем значение силы
    if(!flag){  //
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя вводить текст или оставлять окно пустым");
    }
    else{
        ui->erro_label->setVisible(false);
        ui->point_label->setText(QString("%1").arg(points - pow, 0, 'f', 1));  // выводим сотавшуюся сумму очков

        points = points - pow; // сохраняем количество оставшихся очков
    }


    dexter = ui->dexterity->text().toInt(&flag2); //  снимаем очки ловкости
    if(!flag2){
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя вводить текст или оставлять окно пустым");
    }
    else{
        ui->point_label->setText(QString("%1").arg(points - dexter, 0, 'f', 1));  //  выводим оставшиеся очки с учетом ловкости



         ui->erro_label->setVisible(false);
         points = points - dexter;  //  сохряняем оставшееся количество очков



    }
    intellekt = ui->intelligence->text().toInt(&flag3);  // интеллект
    if(!flag3){
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя вводить текст или оставлять окно пустым");
    }
    else{
        ui->point_label->setText(QString("%1").arg(points - intellekt, 0, 'f', 1));  //  выводим с учетом интеллекта
        points -= intellekt;
    }


    udacha = ui->luck->text().toInt(&flag4);  //  очки удачи
    if(!flag4){
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя вводить текст или оставлять окно пустым");
    }
    else{
        ui->point_label->setText(QString("%1").arg(points - udacha, 0, 'f', 1));
        points -= udacha;
    }
    if (points < 0){  // делаем проверку на то, что у нас не привышен лимит по очкам
        ui->erro_label->setText("у вас есть только 20 очков!");
        ui->point_label->hide();
    }
    else{
        ui->point_label->setText(QString("%1").arg(points, 0, 'f', 1)); //  если не привышен, то отображаем
    }


}

void MainWindow::on_name_textChanged(const QString &arg1)
{
    if(arg1.count() > 20 || arg1.count() < 3){ //проверка на ограничение имени
        ui->erro_label->setVisible(true);

        ui->erro_label->setText("Неверное количество символов");
    }
   else
        {
        ui->erro_label->setVisible(false);

    }

}

void MainWindow::on_power_textChanged(const QString &arg1) // обработка параметра силы
{
   my_func();
}


void MainWindow::on_dexterity_textChanged(const QString &arg1)
{
    my_func();
}



void MainWindow::on_intelligence_textChanged(const QString &arg1)
{
    my_func();
}


void MainWindow::on_luck_textChanged(const QString &arg1)
{
    my_func();
}

