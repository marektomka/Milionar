#pragma once

#include <QtWidgets>
#include "ui_Milionar.h"
#include <iostream>
#include <algorithm>

class Question
{
protected:
    QString otazky[10];
    QString odpovede[10][4];

public:
    Question() { for (int i = 0; i < 10; i++) otazky[i] = ""; }
    Question(QString otazky1[10], QString odpovede1[10][4]) {
        for (int i = 0; i < 10; i++) 
            otazky[i] = otazky1[i]; 
            for (int i = 0; i < 10; i++){ 
                for (int j = 0; j < 4; j++){ 
                    odpovede[i][j] = odpovede1[i][j]; 
                }
            }
    };
    QString changeQuestion(int a) {
        otazky[0] = "V ktorom roku sa potopil Titanic?";
        otazky[1] = "Ake je hlavne mesto Portugalska?";
        otazky[2] = "Aka je zivotnost vazky?";
        otazky[3] = "Kolko hracov je v time vodneho pola?";
        otazky[4] = "Ktory spevak bol znamy okrem ineho ako Kral popu a The Gloved One?";
        otazky[5] = "Kde sa nachadza Stonehenge?";
        otazky[6] = "Kedy nastal koniec prvej svetovej vojny?";
        otazky[7] = "Ake mal Michael Jackson stredne meno?";
        otazky[8] = "Kedy nastal koniec druhej svetovej vojny?";
        otazky[9] = "Kto vyhral volby v USA v roku 2020?";
        return otazky[a];
    }
    QString changeAnswer(int a, int b) {
        odpovede[0][0] = "1936"; odpovede[0][1] = "1865"; odpovede[0][2] = "1912"; odpovede[0][3] = "1918";
        odpovede[1][0] = "Porto"; odpovede[1][1] = "Barcelona"; odpovede[1][2] = "Guimaraes"; odpovede[1][3] = "Lisabon";
        odpovede[2][0] = "15 hodin"; odpovede[2][1] = "24 hodin"; odpovede[2][2] = "45 minut"; odpovede[2][3] = "1 rok";
        odpovede[3][0] = "4"; odpovede[3][1] = "10"; odpovede[3][2] = "7"; odpovede[3][3] = "6";
        odpovede[4][0] = "Michael Jackson"; odpovede[4][1] = "Justin Bieber"; odpovede[4][2] = "Palo Habera"; odpovede[4][3] = "Karel Gott";
        odpovede[5][0] = "Rusko"; odpovede[5][1] = "Finsko"; odpovede[5][2] = "Brazilia"; odpovede[5][3] = "Spojene Kralovstvo";
        odpovede[6][0] = "1918"; odpovede[6][1] = "1945"; odpovede[6][2] = "1896"; odpovede[6][3] = "1913";
        odpovede[7][0] = "Joseph"; odpovede[7][1] = "James"; odpovede[7][2] = "John"; odpovede[7][3] = "Andrew";
        odpovede[8][0] = "1918"; odpovede[8][1] = "1989"; odpovede[8][2] = "1945"; odpovede[8][3] = "1939";
        odpovede[9][0] = "Vladimir Putin"; odpovede[9][1] = "Joe Biden"; odpovede[9][2] = "Donald Trump"; odpovede[9][3] = "Barack Obama";
        return odpovede[a][b];
    }
};

class Milionar : public QMainWindow, public Question
{
    Q_OBJECT

public:
    Milionar(QWidget *parent = Q_NULLPTR);

private:
    Ui::MilionarClass ui;

private slots:
    void on_comboBox_currentIndexChanged();
    void on_pushUkoncit_clicked();
    void on_lineEdit_textEdited();
    void on_pushNova_clicked();
    void on_pushButton_6_clicked(); 
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    
    
};



