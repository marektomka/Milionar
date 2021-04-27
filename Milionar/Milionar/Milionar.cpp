#include "Milionar.h"

using namespace std;
int i = 0, num = 0, predcasne = 0, body = 0;
int randNum[10] = { 0,1,2,3,4,5,6,7,8,9 };

Milionar::Milionar(QWidget *parent): QMainWindow(parent){
    ui.setupUi(this);
}

void Milionar::on_comboBox_currentIndexChanged(){
    // nastavenie obiažnosti //
    if (ui.comboBox->currentIndex() == 0) {
        ui.pushButton_3->setHidden(false);
        ui.pushButton_4->setHidden(false);
        ui.pushButton_5->setHidden(false);
    }
    if (ui.comboBox->currentIndex() == 1) {
        ui.pushButton_3->setHidden(false);
        ui.pushButton_4->setHidden(true);
        ui.pushButton_5->setHidden(false);
    }
    if (ui.comboBox->currentIndex() == 2) {
        ui.pushButton_3->setHidden(true);
        ui.pushButton_4->setHidden(false);
        ui.pushButton_5->setHidden(true);
    }
}

void Milionar::on_pushUkoncit_clicked(){
    // upravenie prostredia do stavu novej hry //
    ui.lineEdit->setReadOnly(false);
    ui.label->clear();
    ui.label->setEnabled(true);
    ui.label_4->setHidden(true);
    ui.label_5->setHidden(true);
    ui.label_6->setHidden(true);
    ui.label_7->setHidden(true);
    ui.radioButton->setHidden(true);
    ui.radioButton_2->setHidden(true);
    ui.radioButton_3->setHidden(true);
    ui.radioButton_4->setHidden(true);
    ui.pushButton_3->setHidden(false);
    ui.pushButton_4->setHidden(false);
    ui.pushButton_5->setHidden(false);
    ui.pushButton_3->setEnabled(false);
    ui.pushButton_4->setEnabled(false);
    ui.pushButton_5->setEnabled(false);
    ui.pushButton_6->setEnabled(false);
    ui.pushButton_7->setEnabled(false);
    ui.checkBox->setEnabled(false);
    ui.comboBox->setEnabled(false);
    ui.textEdit->setHidden(true);
    // odpocitanie bodov za predcasne ukoncenie //
    predcasne = (9 - num);
    ui.doubleSpinBox->stepBy(-predcasne);
    num = 0;
    ui.pushUkoncit->setEnabled(false);
}

void Milionar::on_lineEdit_textEdited(){ 
    // nastavenie tlaèitok po zmene textu v kolonke "meno"
    if (ui.lineEdit->text() != "") {
        ui.pushNova->setEnabled(true);
        ui.comboBox->setEnabled(true);
        ui.checkBox->setEnabled(true);
        ui.doubleSpinBox->setValue(0);
    }
}

void Milionar::on_pushNova_clicked(){
   // zaciatok novej hry //
    ui.pushNova->setEnabled(false);
    ui.lineEdit->setReadOnly(true);
    ui.label_4->setHidden(false);
    ui.label_5->setHidden(false);
    ui.label_6->setHidden(false);
    ui.label_7->setHidden(false);
    ui.radioButton->setHidden(false);
    ui.radioButton_2->setHidden(false);
    ui.radioButton_3->setHidden(false);
    ui.radioButton_4->setHidden(false);
    ui.pushButton_3->setEnabled(true);
    ui.pushButton_4->setEnabled(true);
    ui.pushButton_5->setEnabled(true);
    ui.pushButton_6->setEnabled(true);
    ui.pushButton_7->setEnabled(true);
    ui.comboBox->setEnabled(false);
    ui.checkBox->setEnabled(false);
    ui.textEdit->setHidden(false); 
    ui.pushUkoncit->setEnabled(true);
    // nastavenie èi otázky budú random alebo postupne //
    if (ui.checkBox->isChecked()) {
        random_shuffle(begin(randNum), end(randNum));
    }
    else {
        for (int i = 0; i < 10; i++)
            randNum[i] = i;
    }
    // vypisanie otázky a odpovedí //
    ui.textEdit->setText(changeQuestion(randNum[num]));
    ui.label_4->setText(changeAnswer(randNum[num], 0));
    ui.label_5->setText(changeAnswer(randNum[num], 1));
    ui.label_6->setText(changeAnswer(randNum[num], 2));
    ui.label_7->setText(changeAnswer(randNum[num], 3));

}

void Milionar::on_pushButton_6_clicked(){
    // button na potvrdenie odpovede //
    ui.radioButton->setHidden(false);
    ui.radioButton_2->setHidden(false);
    ui.radioButton_3->setHidden(false);
    ui.radioButton_4->setHidden(false);
    ui.label_4->setHidden(false);
    ui.label_5->setHidden(false);
    ui.label_6->setHidden(false);
    ui.label_7->setHidden(false);
    // vyhodnotenie èi je vybraná odpoveï správna alebo nie //
    if (randNum[num] == 0 && ui.radioButton_3->isChecked()) ui.doubleSpinBox->stepBy(2); //keïže defaultný krok v Qt mám nastavený na 0,5..
    if (randNum[num] == 0 && ui.radioButton_3->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 1 && ui.radioButton_4->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 1 && ui.radioButton_4->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 2 && ui.radioButton_2->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 2 && ui.radioButton_2->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 3 && ui.radioButton_3->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 3 && ui.radioButton_3->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 4 && ui.radioButton->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 4 && ui.radioButton->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 5 && ui.radioButton_4->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 5 && ui.radioButton_4->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 6 && ui.radioButton->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 6 && ui.radioButton->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 7 && ui.radioButton->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 7 && ui.radioButton->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 8 && ui.radioButton_3->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 8 && ui.radioButton_3->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    if (randNum[num] == 9 && ui.radioButton_2->isChecked()) ui.doubleSpinBox->stepBy(2);
    if (randNum[num] == 9 && ui.radioButton_2->isChecked() == false) ui.doubleSpinBox->stepBy(-2);
    num++;
    
    // vypísanie ïa¾šej otázky a odpovedí //
    if (num < 10) {
        ui.textEdit->setText(changeQuestion(randNum[num]));
        ui.label_4->setText(changeAnswer(randNum[num], 0));
        ui.label_5->setText(changeAnswer(randNum[num], 1));
        ui.label_6->setText(changeAnswer(randNum[num], 2));
        ui.label_7->setText(changeAnswer(randNum[num], 3));
    }

    // upravenie prostredia do stavu novej hry //
    if (num == 10) {
        ui.lineEdit->setReadOnly(false);
        ui.label->clear();
        ui.label->setEnabled(true);
        ui.label_4->setHidden(true);
        ui.label_5->setHidden(true);
        ui.label_6->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_2->setHidden(true);
        ui.radioButton_3->setHidden(true);
        ui.radioButton_4->setHidden(true);
        ui.pushButton_3->setHidden(false);
        ui.pushButton_4->setHidden(false);
        ui.pushButton_5->setHidden(false);
        ui.pushButton_3->setEnabled(false);
        ui.pushButton_4->setEnabled(false);
        ui.pushButton_5->setEnabled(false);
        ui.pushButton_6->setEnabled(false);
        ui.pushButton_7->setEnabled(false);
        ui.checkBox->setEnabled(false);
        ui.comboBox->setEnabled(false);
        ui.textEdit->setHidden(true);
        ui.doubleSpinBox->setValue(0);
        ui.pushUkoncit->setEnabled(false);
        num = 0;
    }

}  

void Milionar::on_pushButton_3_clicked(){ 
    // schovanie dvoch odpovedi //
    ui.pushButton_3->setHidden(true);
    if (randNum[num] == 0 || randNum[num] == 3 || randNum[num] == 8) {
        ui.label_5->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_2->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 1 || randNum[num] == 5) {
        ui.label_4->setHidden(true);
        ui.label_5->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_2->setHidden(true);
    }
    if (randNum[num] == 4 || randNum[num] == 6 || randNum[num] == 7) {
        ui.label_6->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_3->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 2 || randNum[num] == 9 ) {
        ui.label_4->setHidden(true);
        ui.label_6->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_3->setHidden(true);
    }
}

void Milionar::on_pushButton_4_clicked(){
    // schovanie dvoch odpovedi //
    ui.pushButton_4->setHidden(true);
    if (randNum[num] == 0 || randNum[num] == 3 || randNum[num] == 8) {
        ui.label_5->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_2->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 1 || randNum[num] == 5) {
        ui.label_4->setHidden(true);
        ui.label_5->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_2->setHidden(true);
    }
    if (randNum[num] == 4 || randNum[num] == 6 || randNum[num] == 7) {
        ui.label_6->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_3->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 2 || randNum[num] == 9) {
        ui.label_4->setHidden(true);
        ui.label_6->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_3->setHidden(true);
    }
}

void Milionar::on_pushButton_5_clicked(){
    // schovanie dvoch odpovedi //
    ui.pushButton_5->setHidden(true);
    if (randNum[num] == 0 || randNum[num] == 3 || randNum[num] == 8) {
        ui.label_5->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_2->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 1 || randNum[num] == 5) {
        ui.label_4->setHidden(true);
        ui.label_5->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_2->setHidden(true);
    }
    if (randNum[num] == 4 || randNum[num] == 6 || randNum[num] == 7) {
        ui.label_6->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton_3->setHidden(true);
        ui.radioButton_4->setHidden(true);
    }
    if (randNum[num] == 2 || randNum[num] == 9) {
        ui.label_4->setHidden(true);
        ui.label_6->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_3->setHidden(true);
    }
}

void Milionar::on_pushButton_7_clicked(){
    // button na preskocenie otazky //
    ui.doubleSpinBox->stepBy(-1); // keïže defaultny krok v Qt je nastavený na 0.5.. //
    num++;
    if (num < 10) {
        ui.textEdit->setText(changeQuestion(randNum[num]));
        ui.label_4->setText(changeAnswer(randNum[num], 0));
        ui.label_5->setText(changeAnswer(randNum[num], 1));
        ui.label_6->setText(changeAnswer(randNum[num], 2));
        ui.label_7->setText(changeAnswer(randNum[num], 3));
    }
    if (num == 10) {
        // upravenie prostredia do stavu novej hry //
        ui.lineEdit->setReadOnly(false);
        ui.label->clear();
        ui.label->setEnabled(true);
        ui.label_4->setHidden(true);
        ui.label_5->setHidden(true);
        ui.label_6->setHidden(true);
        ui.label_7->setHidden(true);
        ui.radioButton->setHidden(true);
        ui.radioButton_2->setHidden(true);
        ui.radioButton_3->setHidden(true);
        ui.radioButton_4->setHidden(true);
        ui.pushButton_3->setHidden(false);
        ui.pushButton_4->setHidden(false);
        ui.pushButton_5->setHidden(false);
        ui.pushButton_3->setEnabled(false);
        ui.pushButton_4->setEnabled(false);
        ui.pushButton_5->setEnabled(false);
        ui.pushButton_6->setEnabled(false);
        ui.pushButton_7->setEnabled(false);
        ui.checkBox->setEnabled(false);
        ui.comboBox->setEnabled(false);
        ui.textEdit->setHidden(true);
        ui.doubleSpinBox->setValue(0);
        ui.pushUkoncit->setEnabled(false);
        num = 0;
    }
}



