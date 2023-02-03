#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui -> setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_licz_clicked() {
  double lewar = ui -> lewar -> value();
  double wartosc = ui -> wartosc_2 -> value();
  double entry = ui -> entry -> value();
  double tp = ui -> tp -> value();
  double sl = ui -> sl -> value();

  double roznica = tp / entry;
  double stop = sl / entry;

  double cena = wartosc * 100;
  double USD = roznica * cena - cena;
  double loss = stop * cena - cena;
  QString cena1 = "MARIGN: ";
  QString lewar1 = QString::number(USD * lewar * 10);

  cena1.append(QString::number(cena));
  cena1.append(" TP: ");
  cena1.append(lewar1);

  cena1.append(" SL: ");
  cena1.append(QString::number(loss * lewar * 10));

  ui -> wynik -> setText(cena1);

}
