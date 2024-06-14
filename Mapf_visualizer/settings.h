#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QFileDialog>
namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:

    explicit Settings(QWidget *parent = 0);

    ~Settings();

signals:

    void sendData(QString str, int size);

private slots:

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *event);

    void on_cancel_button_clicked();

    void on_load_button_clicked();

    void openSettings();

private:
    Ui::Settings *ui;
    QWidget *parent;
    int cellSize;
};

#endif // SETTINGS_H
