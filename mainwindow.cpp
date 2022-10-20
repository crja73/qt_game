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
int pol = 0;

void MainWindow::my_func()
{
    QString neww;
    neww = ui->name->text();
    int counter = neww.count();
    if(counter < 3){ //проверка на ограничение имени
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Неверное количество символов");
    }
   else
        {
        ui->erro_label->setVisible(false);

    }

    if (ui->male->isChecked()){
        pol = 0;
    }
    if (ui->woman->isChecked()){
        pol = 1;
    }
    ui->erro_label->setVisible(false);
    ui->point_label->show();
    double points = 20;
    bool flag, flag2, flag3, flag4;
    double pow, dexter, intellekt, udacha;
    pow=ui->power->text().toInt(&flag);  // снимаем значение силы


    if(!flag || pow < 1 || pow > 10){  //
        ui->label_3->setText("<font color='black'>Сила</font>");
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Вы ввели неверное значение или оставили окно пустым");
    }
    else{
        if (pow < 4){
            ui->label_3->setText("<font color='red'>Сила</font>");
        }
        else if (pow > 3 & pow < 7){
            ui->label_3->setText("<font color='yellow'>Сила</font>");
        }
        else{
            ui->label_3->setText("<font color='green'>Сила</font>");
        }
        ui->erro_label->setVisible(false);
        ui->point_label->setText(QString("%1").arg(points - pow, 0, 'f', 1));  // выводим сотавшуюся сумму очков
        points = points - pow; // сохраняем количество оставшихся очков
    }


    dexter = ui->dexterity->text().toInt(&flag2); //  снимаем очки ловкости
    if(!flag2 || dexter < 1 || dexter > 10){
        ui->label_4->setText("<font color='black'>Ловкость</font>");
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Вы ввели неверное значение или оставили окно пустым");
    }
    else{
        if (dexter < 4){
            ui->label_4->setText("<font color='red'>Ловкость</font>");
        }
        else if (dexter > 3 & dexter < 7){
            ui->label_4->setText("<font color='yellow'>Ловкость</font>");
        }
        else{
            ui->label_4->setText("<font color='green'>Ловкость</font>");
        }
        ui->point_label->setText(QString("%1").arg(points - dexter, 0, 'f', 1));  //  выводим оставшиеся очки с учетом ловкости
         ui->erro_label->setVisible(false);
         points = points - dexter;  //  сохряняем оставшееся количество очков



    }
    intellekt = ui->intelligence->text().toInt(&flag3);  // интеллект
    if(!flag3 || intellekt < 1 || intellekt > 10){
        ui->label_5->setText("<font color='black'>Интеллект</font>");
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Вы ввели неверное значение или оставили окно пустым");
    }
    else{
        if (intellekt < 4){
            ui->label_5->setText("<font color='red'>Интеллект</font>");
        }
        else if (intellekt > 3 & intellekt < 7){
            ui->label_5->setText("<font color='yellow'>Интеллект</font>");
        }
        else{
            ui->label_5->setText("<font color='green'>Интеллект</font>");
        }
        ui->point_label->setText(QString("%1").arg(points - intellekt, 0, 'f', 1));  //  выводим с учетом интеллекта
        points -= intellekt;
    }


    udacha = ui->luck->text().toInt(&flag4);  //  очки удачи
    if(!flag4 || udacha < 1 || udacha > 10){
        ui->label_6->setText("<font color='black'>Удача</font>");
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Вы ввели неверное значение или оставили окно пустым");
    }
    else{
        if (udacha < 4){
            ui->label_6->setText("<font color='red'>Удача</font>");
        }
        else if (udacha > 3 & udacha < 7){
            ui->label_6->setText("<font color='yellow'>Удача</font>");
        }
        else{
            ui->label_6->setText("<font color='green'>Удача</font>");
        }
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
     my_func();

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


void MainWindow::on_create_clicked()
{

    QString neww;
    neww = ui->name->text();
    int counter = neww.count();
    ui->erro_label->setVisible(true);
    if (ui->male->isChecked()){
        pol = 0;
    }
    if (ui->woman->isChecked()){
        pol = 1;
    }
    bool flag, flag2, flag3, flag4;
    bool q_flag=true;
    double pow, dexter, intellekt, udacha, pow2, dexter2, intellekt2, udacha2;
    double health, mana, atack, protect;
    pow=ui->power->text().toInt(&flag);
    if(flag & pow > 0 & pow < 11){
        pow2 = pow;
    }
    else{
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя создать персонажа");
        q_flag=false;
    }

    dexter = ui->dexterity->text().toInt(&flag2);
    if(flag2 & dexter > 0 & dexter < 11){
        dexter2 = dexter;

    }
    else{
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя создать персонажа");
        q_flag=false;
    }

    intellekt = ui->intelligence->text().toInt(&flag3);
    if(flag3 & intellekt > 0 & intellekt < 11){
        intellekt2 = intellekt;
    }
    else{
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя создать персонажа");
        q_flag=false;
    }
    udacha = ui->luck->text().toInt(&flag4);
    if(flag4 & udacha > 0 & udacha < 11){
        udacha2 = udacha;
    }
    else{
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя создать персонажа");
        q_flag=false;
    }
    health = (4 * pow2) + (2 * dexter2) + intellekt2 + udacha2;
    mana = (3 * pow) + dexter2 + (4 * intellekt2) + udacha;
    atack = (5 * pow2) + (3 * dexter2) + intellekt2 + (2 * udacha2);
    protect = pow2+ (3 * dexter2) + (4 * intellekt2) + (2 * udacha2);
    ui->health_label->setNum(health);
    ui->mana_label->setNum(mana);
    ui->atack_label->setNum(atack);
    ui->protect_label->setNum(protect);
    if(q_flag & pow2+dexter2+intellekt2+udacha2 <= 20 & counter > 2){
        ui->erro_label->setVisible(false);
        ui->class_inf->setVisible(true);
        ui->name_label->setText(neww);
        if (pol == 0){
            if (pow2 > 5 & intellekt2 < 5){
                ui->class_inf->setText("Воин");
            }

            else if (pow2 > 5 & intellekt2 > 5){
                ui->class_inf->setText("Воин - ученый");
            }
            else if (pow2 > 4 & intellekt2 > 8){
                ui->class_inf->setText("Десница");
            }
            else if (pow2 < 4 & intellekt2 > 8){
                 ui->class_inf->setText("Советник");
            }
            else if(pow2 < 5 & intellekt2 > 6 & dexter2 < 4){
                ui->class_inf->setText("Доктор");
            }
            else if(pow2 < 5 & dexter2 > 4){
                ui->class_inf->setText("Шут");
            }
            else if(pow2 > 4 & dexter2 > 4){
                ui->class_inf->setText("Шут - качок");
            }
            else if(pow2 < 5 & intellekt2 > 6 & dexter2 > 3){
                ui->class_inf->setText("Доктор - спортсмен");
            }
            else if(pow2 < 4 & intellekt2 < 4 & dexter2 < 4 & udacha2 < 4){
                ui->class_inf->setText("Крестьянин");
            }
            else if(pow2 < 6 & pow2 > 3 & intellekt2 < 6 & intellekt2 > 3 & dexter2 < 6 & dexter2 > 3 & udacha2 < 6){
                ui->class_inf->setText("Стражник");
            }
            else if (udacha2 > 3 & mana > 4){
                ui->class_inf->setText("Колдун");
            }
            else if (udacha2 < 4 & mana > 4){
                ui->class_inf->setText("Колдун - ученик");
            }
            else{
                ui->class_inf->setText("Разнорабочий");
            }
        }
        else{
            if (pow2 > 5 & intellekt2 < 5){
                ui->class_inf->setText("Дева-воительница");
            }

            else if (pow2 > 5 & intellekt2 > 5){
                ui->class_inf->setText("Воительница - ученый");
            }
            else if (pow2 > 4 & intellekt2 == 10){
                ui->class_inf->setText("Десница");
            }
            else if (pow2 < 4 & intellekt2 == 10){
                 ui->class_inf->setText("Советница");
            }
            else if(pow2 < 5 & intellekt2 > 8 & dexter2 < 4){
                ui->class_inf->setText("Доктор");
            }
            else if(pow2 < 5 & dexter2 > 4){
                ui->class_inf->setText("Служанка");
            }
            else if(pow2 > 4 & dexter2 > 4){
                ui->class_inf->setText("Служанка - спортсменка");
            }
            else if(pow2 < 5 & intellekt2 > 6 & dexter2 > 3){
                ui->class_inf->setText("Доктор - спортсменка");
            }
            else if(pow2 < 4 & intellekt2 < 4 & dexter2 < 4 & udacha2 < 4){
                ui->class_inf->setText("Крестьянка");
            }
            else if(pow2 < 6 & pow2 > 3 & intellekt2 < 6 & intellekt2 > 3 & dexter2 < 6 & dexter2 > 3 & udacha2 < 6){
                ui->class_inf->setText("Стражница");
            }
            else if (udacha2 > 3 & mana > 4){
                ui->class_inf->setText("Колдунья");
            }
            else if (udacha2 < 4 & mana > 4){
                ui->class_inf->setText("Колдунья - ученица");
            }
            else{
                ui->class_inf->setText("Разнорабочая");
            }

        }

    }
    else{
        ui->class_inf->setVisible(false);
        ui->erro_label->setVisible(true);
        ui->erro_label->setText("Нельзя создать персонажа");
    }









}


void MainWindow::on_clean_clicked()
{
    ui->power->clear();
    ui->label_3->setText("<font color='black'>Сила</font>");
    ui->dexterity->clear();
    ui->label_4->setText("<font color='black'>Ловкость</font>");
    ui->intelligence->clear();
    ui->label_5->setText("<font color='black'>Интеллект</font>");
    ui->luck->clear();
    ui->label_6->setText("<font color='black'>Удача</font>");

}

