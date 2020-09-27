#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void handle();
private slots:
	void on_btn_files_clicked();
    void on_btn_process();
    void on_lineEdit(QString q1);
    void on_lineEdit_2(QString q1);
private:
    QString fileName, outfileName;
    int n1 = 5, n2 = 9;
    Ui::MainWindow *ui;
    
};

#endif // MAINWINDOW_H
