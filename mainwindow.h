#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_passwordNumberPick_editingFinished();

    void on_pushButton_2_clicked();

    QString on_word1_text_textChanged();

    QString on_word2_text_textChanged();

    QString on_word3_text_textChanged();

    QString passwordAlgorithm(QString word1);

    void handleHelpAction();

private:
    int length;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
