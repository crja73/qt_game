#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_name_textChanged(const QString &arg1);


    
    void on_power_textChanged(const QString &arg1);
    void my_func();

    void on_dexterity_textChanged(const QString &arg1);

    void on_intelligence_textChanged(const QString &arg1);

    void on_luck_textChanged(const QString &arg1);

    void on_create_clicked();

    void on_clean_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
