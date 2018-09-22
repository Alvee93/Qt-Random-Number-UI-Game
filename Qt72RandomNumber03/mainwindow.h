#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_count_clicked();
    void on_pushButton_start_clicked();

    void on_pushButton_reset_clicked();
    void write_log(std::string data);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
