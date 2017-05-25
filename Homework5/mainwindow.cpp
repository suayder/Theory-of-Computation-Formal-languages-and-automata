#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

QString MainWindow::transictionFunction(QString word, QString initialState)
{
    QPair<QString, QChar> p;
    for(int i =0; i< word.length(); i++){
        p.first = initialState;
        p.second = word[i];
        initialState = this->map.find(p).value();
    }
    return initialState;
}

QString MainWindow::extendedTransictionFunction(QString word, QString initialState)
{
    if(word.isEmpty()) return initialState;
    else{        
        return transictionFunction(word.at(word.length()-1), extendedTransictionFunction(word.left(word.length()-1), initialState));
    }
}

void MainWindow::fillMap()
{
    for(int i = 0; i<ui->spinBox->value();i++){
        for(int j =0; j<this->alphabet.length();j++){
            QComboBox *myCB = qobject_cast<QComboBox*>(ui->adjacenceTable->cellWidget(i,j));
            map.insert(qMakePair(ui->adjacenceTable->verticalHeaderItem(i)->text(), this->alphabet.at(j)), myCB->currentText());
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msg;
    ui->result->clear();
    this->map.clear();

    if(ui->alphabet->text().isEmpty() || ui->spinBox->value()==0){
        msg.warning(0,"Warning", "Complete all fields");
    }
    else{
        this->alphabet.clear();
        this->alphabet = ui->alphabet->text();
        this->alphabet.remove(QChar(' '), Qt::CaseSensitive);
        if(!(this->alphabet[0]=='{') || !(this->alphabet[(this->alphabet.size()-1)]=='}') || (this->alphabet[(this->alphabet.size()-2)]==',')){
            msg.setText("Error Alphabet Input\nStandard example: {a,b,c}");
            msg.exec();
            this->alphabet="";
        }
        else{
            int i;
            for(i=1;i<(this->alphabet.size()-1);i++){
                if((i%2)==0 && this->alphabet[i]==',');
                else if((i%2)!=0 && this->alphabet[i].isLetterOrNumber()){
                   if(this->alphabet.count(this->alphabet[i], Qt::CaseSensitive)>1){
                       msg.warning(0, "Warning", "Not allowed repeated characters ");
                       this->alphabet = "";
                   }
               }
               else{
                   msg.warning(0, "Warning","There is a not allowed character");
                   this->alphabet = "";
               }
            }
        }
        if(this->alphabet!=""){

            this->alphabet.remove(QChar(','), Qt::CaseSensitive);
            this->alphabet.remove(QChar('{'), Qt::CaseSensitive);
            this->alphabet.remove(QChar('}'), Qt::CaseSensitive);
            ui->adjacenceTable->setRowCount(ui->spinBox->value());
            ui->adjacenceTable->setColumnCount(this->alphabet.length());
            QStringList str;
            for(int i=0; i<this->alphabet.length(); i++) {
                str.append(this->alphabet.at(i));
            }
            ui->adjacenceTable->setHorizontalHeaderLabels(str);
            str.clear();
            for(int i=0; i<ui->spinBox->value();i++){
                if(ui->comboBox->currentIndex()==i){
                    str.append("->"+(ui->comboBox->itemText(i)));
                    if(ui->comboBox_2->itemText(i)==ui->comboBox->currentText() && !ui->comboBox_2->itemText(i).contains("->")) ui->comboBox_2->setItemText(i, "->"+ui->comboBox_2->itemText(i));
                }
                else
                    str.append(ui->comboBox->itemText(i));
            }
            ui->adjacenceTable->setVerticalHeaderLabels(str);
            for(int i=0; i<this->alphabet.length();i++){
                for(int j = 0; j<ui->spinBox->value(); j++){
                    QComboBox *comb = new QComboBox();
                    comb->addItems(str);
                    ui->adjacenceTable->setCellWidget(j,i, comb);
                }
            }
        }
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->result->clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i = 0; i<ui->spinBox->value();i++){
        ui->comboBox->addItem("Q"+QString::number(i));
        ui->comboBox_2->addItem("Q"+QString::number(i));
    }
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    ui->listWidget->addItem(ui->comboBox_2->currentText());
    ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
    ui->listWidget->sortItems(Qt::AscendingOrder);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->comboBox_2->addItem(ui->listWidget->currentItem()->text());
    delete (ui->listWidget->takeItem(ui->listWidget->row(item)));
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msg;
    ui->result->clear();
    if(ui->lineEdit->text().isEmpty())
        msg.warning(0, "Warning", "Fill the field!");
    else{
        bool a = true;
        foreach (QChar c, ui->lineEdit->text()){
            if(!this->alphabet.contains(c,Qt::CaseSensitive)){
                msg.warning(0, "Warning", "This word doesn't belong to this alphabet");
                a = false;
                break;
            }
        }
        if(a==true){
            this->fillMap();
            bool aux= false;
            QString finalstate = this->extendedTransictionFunction(ui->lineEdit->text(),"->"+ui->comboBox->currentText());
            for(int i=0;i<ui->listWidget->count();i++){
                if(ui->listWidget->item(i)->text() == finalstate){
                    ui->result->setText("Sucess, Recognized!");
                    aux=true;
                    break;
                }
             }
            if(aux==false)
                ui->result->setText("Not Recognized!");
        }
    }
}
