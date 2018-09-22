#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <QProcess>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int r_num;
bool is_found = 0;
int lim = 0;
int r_db[1000];
unsigned short int i=1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    ui->pushButton_count->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_count_clicked()
{
    bool got_jp = 0;
    while(!got_jp){
        r_num = rand() %100;

        for (int j=0; j<i; j++){
            if (r_db[j] == r_num) {
                is_found = 1;
                break;
            }
        }
        if (is_found==1){

            is_found = 0;
        }
        else if (is_found!=1) {
            r_db[i] = r_num;
            cout << r_db[i] << endl;

            ui->label->setNum(r_db[i]);
            write_log(to_string(r_db[i]));
            lim++;
            got_jp = 1;
        }
        if (lim==98) {
            QMessageBox messageBox;
            messageBox.information(0,"Hold on there!","99 Numbers are over! :)");
            messageBox.setFixedSize(1200,550);
            ui->pushButton_count->setEnabled(false);
            //break;
        }

        i++;
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    r_num = rand() %100 +1; //
    while (r_num==100){
        r_num = rand() %100 +1;
    }
    cout << r_num << endl; // ///////////////////////////////
    ui->label->setNum(r_num);

    write_log(to_string(r_num));

    r_db[0] = r_num;

    ui->pushButton_start->setEnabled(false); //hide();
    ui->pushButton_count->setEnabled(true);
}

void MainWindow::on_pushButton_reset_clicked()
{
    r_num=0;
    is_found = 0;
    lim = 0;
    r_db[100];
    i=1;
    ui->label->setText("~ ~");
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_count->setEnabled(false);

    ofstream ofs;
    ofs.open("log.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void MainWindow::write_log(string data)
{
    ofstream outfile;
    outfile.open("log.txt", ios::app);
    outfile << data << endl;
    outfile.close();
}
