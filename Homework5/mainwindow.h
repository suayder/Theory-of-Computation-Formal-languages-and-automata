#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QMap>
#include <QPair>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString transictionFunction(QString word, QString initialState);

    QString extendedTransictionFunction(QString word, QString initialState);

    void fillMap();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString alphabet;
    QMap <QPair<QString, QChar>,QString> map;
};

#endif // MAINWINDOW_H
