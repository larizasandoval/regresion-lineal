#ifndef EVALUARPUNTODIALOG_H
#define EVALUARPUNTODIALOG_H
#include <qdebug.h>
#include <QDialog>

namespace Ui {
class evaluarPuntoDialog;
}

class evaluarPuntoDialog : public QDialog
{
    Q_OBJECT


public:
    explicit evaluarPuntoDialog(QWidget *parent = nullptr);
    ~evaluarPuntoDialog();
    void recibirA(double a);
    void recibirB(double b);

private slots:

    void on_EvaluarPushButton_clicked();

private:
    Ui::evaluarPuntoDialog *ui;
    double A_;
    double B_;
};

#endif // EVALUARPUNTODIALOG_H
