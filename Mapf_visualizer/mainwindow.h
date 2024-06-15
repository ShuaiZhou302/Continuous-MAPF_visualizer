#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsView>
#include <QMessageBox>
#include <QDomDocument>
#include <QFile>
#include <QVector>
#include <QGraphicsItem>
#include <QPainter>
#include "agent.h"
#include "settings.h"
#include <math.h>
#include <vector>
#include <fstream>

struct section
{
    double sx;
    double sy;
    double fx;
    double fy;
    double length;
    double size;
    double sheading;
    double gheading;
    double g;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

    void openSettings();

private slots:

    void on_pause_button_clicked();

    void on_restart_button_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void updateList(int curTime);

    bool getData(QString filename);

    void on_open_button_clicked();

    void setLogFile(QString filename, int size);


    void on_left_button_clicked();

    void on_right_button_clicked();

    void on_paths_button_clicked();

private:

    void createMap();
    void visualize();
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    std::vector<agent*> balls;
    std::vector<std::vector<target*>> targets;
    std::vector<std::vector<std::pair<int, int>>> target_poses;
    std::vector<std::vector<double>> target_timings;
    std::vector<QGraphicsItemAnimation*> animations;
    std::vector<QGraphicsItemAnimation*> target_animations;
    std::vector<QTimeLine*> timers;
    QVector<QVector<section> > paths;
    std::vector<double> length;
    QString filename;
    int previousSelect;
    int cellSize;
    int framerange;
    QPixmap img, imgpaths;
    QPainter painter;
    int width;
    int height;
    int maxl_i;
    double maxduration;
    QVector<QColor> agent_colors;
};

#endif // MAINWINDOW_H
