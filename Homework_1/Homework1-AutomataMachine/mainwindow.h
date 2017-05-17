#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

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
    void on_insertButton_clicked();

    void on_merge_clicked();

    void on_check_clicked();

    void on_prefixe_clicked();

    void on_suffixe_clicked();

    void on_subword_clicked();

private:
    Ui::MainWindow *ui;
    QString alphabet;
    QString sufixes;
    QString prefixes;
};

#endif // MAINWINDOW_H
