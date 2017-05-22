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

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msg;
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
            for(int i=0; i<ui->spinBox->value(); i++){
                if(ui->comboBox->currentIndex()==i)
                    str.append("->"+(ui->comboBox->itemText(i)));
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
    ui->comboBox->clear();
    for(int i = 0; i<ui->spinBox->value();i++){
        ui->comboBox->addItem("Q"+QString::number(i));
    }
}
