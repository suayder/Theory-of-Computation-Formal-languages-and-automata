#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QChar>

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

void MainWindow::on_insertButton_clicked()
{
    QMessageBox msg;
    this->alphabet = ui->InputAlphabet->text();
    this->alphabet.remove(QChar(' '), Qt::CaseSensitive);
    if(!(this->alphabet[0]=='{') || !(this->alphabet[(this->alphabet.size()-1)]=='}') || (this->alphabet[(this->alphabet.size()-2)]==',')){
        msg.setText("Error Alphabet Input");
        msg.exec();
        this->alphabet="";
    }
    else{
        int i;
        for(i=1;i<(this->alphabet.size()-1);i++){
            if((i%2)==0 && this->alphabet[i]==',');
            else if((i%2)!=0 && this->alphabet[i].isLetterOrNumber()){
               if(this->alphabet.count(this->alphabet[i], Qt::CaseSensitive)>1){
                   msg.setText("Not allowed repeated characters ");
                   msg.exec();
                   this->alphabet = "";
               }
           }
           else{
               msg.setText("There is a not allowed character");
               msg.exec();
               this->alphabet = "";
           }
        }
    }
    if(this->alphabet!=""){
        ui->listWidget->addItem(this->alphabet);
        ui->InputAlphabet->clear();
    }
}

void MainWindow::on_merge_clicked()
{
    this->alphabet=ui->listWidget->item(0)->text();
    ui->listWidget->removeItemWidget((ui->listWidget->takeItem(0)));
    int i, j;
    QString tempalphabet;
    while(ui->listWidget->count()>0){
        tempalphabet = ui->listWidget->item(0)->text();
        for(j=1;j<tempalphabet.size();j++){
            if(this->alphabet.contains(tempalphabet[j], Qt::CaseSensitive));
            else{
                this->alphabet.insert((this->alphabet.size()-1), ',');
                this->alphabet.insert((this->alphabet.size()-1),tempalphabet[j]);
            }
        }
        ui->listWidget->removeItemWidget((ui->listWidget->takeItem(0)));
    }
    ui->listWidget->addItem(this->alphabet);
}

void MainWindow::on_check_clicked()
{
    QMessageBox msg;
    this->alphabet = ui->wordTest->text();
    int i, j=0;
    bool aux = false;
    while(ui->listWidget->count()>j){
        for(i=0;i<this->alphabet.size();i++){
            if(!(ui->listWidget->item(j)->text().contains(this->alphabet[i], Qt::CaseSensitive))){
                i=-1;
                break;
            }
        }
        if(i==(this->alphabet.size()) && !(this->alphabet.contains(',', Qt::CaseSensitive) || this->alphabet.contains('{', Qt::CaseSensitive) || this->alphabet.contains('}', Qt::CaseSensitive))){
            msg.setText("This word belong to the " +ui->listWidget->item(j)->text()+ " alphabet");
            msg.exec();
            aux=true;
        }
        j++;
    }
    if(aux==false){
        msg.setText("This word doesn't belong to the any alphabet");
        msg.exec();
    }
}

void MainWindow::on_prefixe_clicked()
{
    this->alphabet = ui->wordTest->text();
    this->prefixes.clear();
    QMessageBox msg;
    bool test = false;
    int i, j=0;
    while(ui->listWidget->count()>j){
        for(i=0;i<this->alphabet.size();i++){
            if(!(ui->listWidget->item(j)->text().contains(this->alphabet[i], Qt::CaseSensitive))){
                i=-1;
                test=false;
                break;
            }
            test = true;
        }
        if(test == true) break;
        j++;
    }
    if(test == false && (i==-1 || this->alphabet.contains(',', Qt::CaseSensitive) || this->alphabet.contains('{', Qt::CaseSensitive) || this->alphabet.contains('}', Qt::CaseSensitive))){
        msg.setText("This word doesn't belong to the any alphabet");
        msg.exec();
    }
    else{
        for(i=0;i<this->alphabet.size();i++){
            for(j=0;j<=i;j++) this->prefixes.append(this->alphabet[j]);
            this->prefixes.append('\n');
        }
        msg.setText("&\n"+this->prefixes);
        msg.exec();
    }

}

void MainWindow::on_suffixe_clicked()
{
    this->alphabet = ui->wordTest->text();
    this->sufixes.clear();
    QMessageBox msg;
    bool test = false;
    int i, j=0;
    while(ui->listWidget->count()>j){
        for(i=0;i<this->alphabet.size();i++){
            if(!(ui->listWidget->item(j)->text().contains(this->alphabet[i], Qt::CaseSensitive))){
                i=-1;
                test=false;
                break;
            }
            test = true;
        }
        if(test == true) break;
        j++;
    }
    if(test == false && (i==-1 || this->alphabet.contains(',', Qt::CaseSensitive) || this->alphabet.contains('{', Qt::CaseSensitive) || this->alphabet.contains('}', Qt::CaseSensitive))){
        msg.setText("This word doesn't belong to the any alphabet");
        msg.exec();
    }
    else{
        for(i=(this->alphabet.size()-1);i>=0;i--){
            for(j=i;j<this->alphabet.size();j++) this->sufixes.append(this->alphabet[j]);
            this->sufixes.append('\n');
        }
        msg.setText("&\n"+this->sufixes);
        msg.exec();
    }

}

void MainWindow::on_subword_clicked()
{
    this->alphabet = ui->wordTest->text();
    QMessageBox msg;
    QVector<QString> vector;
    vector.clear();
    QString aux1;
    aux1.clear();

    if(this->alphabet!=NULL){
        bool test = false;
        int i, j=0;
        while(ui->listWidget->count()>j){
            for(i=0;i<this->alphabet.size();i++){
                if(!(ui->listWidget->item(j)->text().contains(this->alphabet[i], Qt::CaseSensitive))){
                    i=-1;
                    test=false;
                    break;
                }
                test = true;
            }
            if(test == true) break;
            j++;
        }
        if(test == false && (i==-1 || this->alphabet.contains(',', Qt::CaseSensitive) || this->alphabet.contains('{', Qt::CaseSensitive) || this->alphabet.contains('}', Qt::CaseSensitive))){
            msg.setText("This word doesn't belong to the any alphabet");
            msg.exec();
        }
        else{
            for(i = 1; i<=this->alphabet.size();i++){
                for(j = 0; j<this->alphabet.size();j++){
                    aux1.clear();
                    if(j+i<this->alphabet.size()+1){
                        for(int k = 0;k<i; k++){
                            aux1.append(this->alphabet[j+k]);
                        }
                        if(!vector.contains(aux1))
                            vector.append(aux1);
                    }
                }
            }
            aux1.clear();
            foreach (QString s, vector) {
               aux1.append(s+'\n');
            }
            msg.setText("&\n"+aux1);
            msg.exec();
        }
    }
    else{
        msg.setText("ERROR");
        msg.exec();
    }
}
