#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("border: 1px solid black");
    //ui->graphicsView->setFixedHeight(902);
    //ui->graphicsView->setFixedWidth(902);
    //ui->open_button->setVisible(false);
    previousSelect=0;
    cellSize=9;
    framerange=10;
    ui->progressBar->setValue(0);
    ui->pause_button->setEnabled(false);
    timers.resize(0);
    animations.resize(0);
    balls.resize(0);
    agent_colors.clear();
    //filename=QString::fromStdString("D:/SVN/MovingsVisualizer2/MovingsVisualizer2/astar_log.xml");
    //visualize();

}

 void MainWindow::setLogFile(QString filename, int size)
 {
     this->filename=filename;
     cellSize = size;
     ui->left_button->setEnabled(false);
     ui->right_button->setEnabled(false);
     previousSelect = 0;
     //if(scene)
     //   scene->clear();
     visualize();
 }

MainWindow::~MainWindow()
{
    for(int i=0; i<balls.size(); i++)
        delete balls[i];
    delete scene;
    delete ui;

}

void MainWindow::on_pause_button_clicked()
{
    if(ui->pause_button->text()=="Pause")
    {
        //ui->listWidget->clear();
        for(int i=0; i<timers.size(); i++)
        {
            if(timers[i]->state() != QTimeLine::NotRunning)
                timers[i]->setPaused(true);
            ui->listWidget->item(i)->setText("AGENT:"+QString::number(i+1)+"  X:"+QString::number(balls[i]->pos().x()/cellSize)+"  Y:"+QString::number(balls[i]->pos().y()/cellSize));
        }
        ui->pause_button->setText("Resume");
        ui->left_button->setEnabled(true);
        ui->right_button->setEnabled(true);
    }
    else
    {
        for(int i=0; i<timers.size(); i++)
            if(timers[i]->state() != QTimeLine::NotRunning)
                timers[i]->setPaused(false);
        ui->pause_button->setText("Pause");
        ui->left_button->setEnabled(false);
        ui->right_button->setEnabled(false);
    }
}

void MainWindow::on_restart_button_clicked()
{

    ui->left_button->setEnabled(false);
    ui->right_button->setEnabled(false);
    ui->restart_button->setText("Restart");
    if(!ui->pause_button->isEnabled())
        ui->pause_button->setEnabled(true);

    for(int i=0; i<timers.size(); i++)
    {
        timers[i]->stop();
        //if(paths[i][0].length>0)
        //    balls[i]->setActive(4);
        //else
            balls[i]->setActive(2);
        timers[i]->start();
    }
    if(ui->listWidget->currentRow() >= 0 && ui->listWidget->currentRow() < timers.size())
        this->on_listWidget_currentRowChanged(ui->listWidget->currentRow());
    ui->pause_button->setText("Pause");
    for(int i=0; i<paths.size(); i++)
        ui->listWidget->item(i)->setText("AGENT:"+QString::number(i+1)+"  X:"+QString::number(paths[i][0].sx)+"  Y:"+QString::number(paths[i][0].sy));
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow>=0)
    {
        if(balls[previousSelect]->pos().x()/cellSize==paths[previousSelect][paths[previousSelect].size()-1].fx+5 && balls[previousSelect]->pos().y()/cellSize==paths[previousSelect][paths[previousSelect].size()-1].fy+5)
        {
            balls[previousSelect]->setActive(3);
            balls[previousSelect]->update();
        }
        else
        {
            //if(balls[previousSelect]->pos().x()/cellSize==paths[previousSelect][0].sx && balls[previousSelect]->pos().y()/cellSize==paths[previousSelect][0].sy && paths[previousSelect][0].length>0)
            //    balls[previousSelect]->setActive(4);
            //else
                balls[previousSelect]->setActive(2);
            balls[previousSelect]->update();
        }
        balls[currentRow]->setActive(1);
        balls[currentRow]->update();
        previousSelect=currentRow;
    }
}

void MainWindow::updateList(int curTime)
{
    std::vector<double> offsets;
    offsets.resize(paths.size());
    for(int i = 0; i < paths.size(); i++)
        offsets[i] = (0.5 - paths[i][0].size);
    for(int i = 0; i < paths.size(); i++)
    {
        ui->listWidget->item(i)->setText("AGENT:"+QString::number(i+1)+"  X:"+QString::number(balls[i]->pos().x()/cellSize-offsets[i])
                                         +"  Y:"+QString::number(balls[i]->pos().y()/cellSize-offsets[i]));
        if(fabs(balls[i]->pos().x()/cellSize-offsets[i]-paths[i].back().fx - paths[i][0].size)<0.05 && fabs(balls[i]->pos().y()/cellSize-offsets[i]-paths[i].back().fy - paths[i][0].size)<0.05)
        {
            if(ui->listWidget->currentRow()==i)
                balls[i]->setActive(1);
            else
                balls[i]->setActive(3);
            balls[i]->update();
        }
        else if(balls[i]->pos().x()/cellSize==paths[i][0].sx && balls[i]->pos().y()/cellSize==paths[i][0].sy && paths[i][0].length>0)
        {
            if(ui->listWidget->currentRow()==i)
                balls[i]->setActive(1);
            //else
            //    balls[i]->setActive(4);
            balls[i]->update();
        }
        else if(i!=ui->listWidget->currentRow())
        {
            balls[i]->setActive(2);
            balls[i]->update();
        }
        /*for(int j=0; j<target_poses[i].size(); j++)
            //if(curTime>10)
            if(fabs(balls[i]->pos().x()/cellSize - offsets[i] - target_poses[i][j].first- paths[i][0].size) < 0.2 && fabs(balls[i]->pos().y()/cellSize - offsets[i] - target_poses[i][j].second- paths[i][0].size) < 0.2)
            if(fabs(1.0*curTime/framerange - target_timings[i][j]/maxduration) < 0.05)
            {
                targets[i][j]->setActive(1);
                targets[i][j]->update();
            }*/
    }
    ui->progressBar->setValue(curTime*100/framerange);

}

bool less(const QVector<section> &p1, const QVector<section> &p2)
{
    return p1.back().g < p2.back().g;
}

bool MainWindow::getData(QString filename)
{
    QFile logfile(filename);
    logfile.open(QIODevice::ReadOnly | QIODevice::Text);

    QDomDocument xml;
    paths.clear();
    xml.setContent(&logfile);
    QVector<section> path;
    section cur;

    if(xml.elementsByTagName("agent").size() == 0)
        return false;

    target_poses.resize(xml.elementsByTagName("agent").count());
    target_timings.resize(xml.elementsByTagName("agent").count());
    agent_colors.resize(xml.elementsByTagName("agent").count());
    maxduration = 0;

    for(int j = 0; j < xml.elementsByTagName("agent").size(); j++)
    {
        double curtime(0);
        path.clear();
        QDomElement hplevel = xml.elementsByTagName("agent").at(j).toElement();

        // Read color element if present
        QDomElement colorElem = hplevel.firstChildElement("color");
        if (!colorElem.isNull())
        {
            if (colorElem.hasAttribute("RGB"))
            {
                QString rgbValue = colorElem.attribute("RGB");
                rgbValue = rgbValue.remove("(").remove(")");
                QStringList rgbList = rgbValue.split(",");
                if (rgbList.size() == 3)
                {
                    int r = rgbList.at(0).toInt();
                    int g = rgbList.at(1).toInt();
                    int b = rgbList.at(2).toInt();
                    // Process RGB values as needed
                    agent_colors[j] = QColor(r, g, b);
                }
            }
        }
        QDomElement pathelem = hplevel.firstChildElement("path").firstChildElement();

        while(!pathelem.attribute("start_i").isNull())
        {
            cur.sy = pathelem.attribute("start_i").toDouble();
            cur.sx = pathelem.attribute("start_j").toDouble();
            cur.fy = pathelem.attribute("goal_i").toDouble();
            cur.fx = pathelem.attribute("goal_j").toDouble();
            cur.sheading = 0;//pathelem.attribute("start.heading").toDouble();
            cur.gheading = 0;//pathelem.attribute("goal.heading").toDouble();
            cur.length = pathelem.attribute("duration").toDouble();
            curtime += cur.length;
            cur.g = curtime;
            target_poses[j] = {std::make_pair(cur.sx, cur.sy)};
            cur.size = 0.33;
            path.push_back(cur);
            pathelem = pathelem.nextSiblingElement();
        }
        paths.push_back(path);
        maxduration = fmax(curtime, maxduration);
    }
    for(int j = 0; j < xml.elementsByTagName("obstacle").size(); j++)
    {
        path.clear();
        QDomElement hplevel = xml.elementsByTagName("obstacle").at(j).toElement();
        QDomElement pathelem = hplevel.firstChildElement();
        int k=0;
        while(!pathelem.attribute("start.x").isNull())
        {
            cur.sx = pathelem.attribute("start.x").toDouble();
            cur.sy = pathelem.attribute("start.y").toDouble();
            cur.fx = pathelem.attribute("goal.x").toDouble();
            cur.fy = pathelem.attribute("goal.y").toDouble();
            cur.sheading = 0;//pathelem.attribute("start.heading").toDouble();
            cur.gheading = 0;//pathelem.attribute("goal.heading").toDouble();
            cur.length = pathelem.attribute("duration").toDouble();
            cur.size = 0.33;
            path.push_back(cur);
            pathelem = pathelem.nextSiblingElement();
        }
        paths.push_back(path);
    }
    std::sort(paths.begin(), paths.end(), less);
    return true;
}



void MainWindow::on_open_button_clicked()
{
    this->setVisible(false);
    for(int i=0; i<timers.size(); i++)
    {
        if(timers[i]->state() != QTimeLine::NotRunning)
            timers[i]->setPaused(true);
        ui->listWidget->item(i)->setText("AGENT:"+QString::number(i+1)+"  X:"+QString::number(balls[i]->pos().x()/cellSize)+"  Y:"+QString::number(balls[i]->pos().y()/cellSize));
    }
    ui->pause_button->setText("Resume");
    emit openSettings();
}

void MainWindow::createMap()
{
    width = 0;
    height = 0;
    QFile logfile(filename);
    logfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QDomDocument xml;
    xml.setContent(&logfile);
    width = xml.elementsByTagName("grid").at(0).toElement().attribute("width").toInt();
    height = xml.elementsByTagName("grid").at(0).toElement().attribute("height").toInt();
    img = QPixmap(width*cellSize,height*cellSize);
    painter.begin(&img);
    int k = 0;
    int j = 0;
    QPen pen;

    pen.setColor(QColor("red"));
    pen.setWidth(cellSize);
    painter.setPen(pen);
    QPoint point;
    QDomElement elem;

    for(int i = 0; i < height; i++)
    {
        elem = xml.elementsByTagName("row").at(i).toElement();
        QString text = elem.text();
        k = 0;
        for(QString::iterator it = text.begin(); it != text.end(); it++)
        {
            point.setX(k);
            point.setY(j);
            if(*it != '0' && *it != ' ')
            {
                QString a = *it;
                int l = a.toInt();
                it++;
                if(it != text.end())
                    if(*it != ' ')
                    {
                        a = *it;
                        l = l*10+a.toInt();
                    }
                    if(l*10 > 200)
                        l = 20;
                pen.setColor(QColor::fromRgb(200-l*100,200-l*100,200-l*100));
                painter.setPen(pen);
                k++;
                painter.drawPoint(point.x()*cellSize+cellSize/2, point.y()*cellSize+cellSize/2);
                if(it == text.end())
                    break;
            }
            else if(*it=='0')
            {
                if(it!=text.begin())
                {
                    it--;
                    if(*it!=' ')
                    {
                        it++;
                        continue;
                    }
                    it++;
                }
                pen.setColor(QColor("white"));
                painter.setPen(pen);
                k++;
                painter.drawPoint(point.x()*cellSize+cellSize/2, point.y()*cellSize+cellSize/2);
            }
        }
        j++;
    }
    for(int i=0; i<xml.elementsByTagName("target").count(); i++)
    {
        elem = xml.elementsByTagName("target").at(i).toElement();
        point.setX(elem.attribute("j").toInt());
        point.setY(elem.attribute("i").toInt());
        pen.setColor(QColor("blue"));
        painter.setPen(pen);
        painter.drawPoint(point.x()*cellSize+cellSize/2, point.y()*cellSize+cellSize/2);
    }
    pen.setColor(QColor("black"));
    pen.setWidth(1);
    painter.setPen(pen);

    /*for(int i = 0; i < std::max(height,width); i++)
    {
        painter.drawLine(0, int(i*cellSize), int(width*cellSize), int(i*cellSize));
        painter.drawLine(int(i*cellSize), 0, int(i*cellSize), int(height*cellSize));
    }*/
    painter.save();
    painter.end();
    imgpaths = img;
    painter.begin(&imgpaths);
    //pen.setColor(QColor("grey"));
    pen.setWidth(2);
    pen.setStyle(Qt::DashLine);
    //painter.setPen(pen);
    for(int i = 0; i < paths.size(); i++)
    {
        pen.setColor(agent_colors[i]); // 使用 agent_colors 中的颜色
        painter.setPen(pen);
        for(int j = 0; j < paths[i].size() - 1; j++)
            painter.drawLine(paths[i][j].sx*cellSize+cellSize/2, paths[i][j].sy*cellSize+cellSize/2,paths[i][j+1].sx*cellSize+cellSize/2,paths[i][j+1].sy*cellSize+cellSize/2);
        painter.drawLine(paths[i][paths[i].size()-1].sx*cellSize+cellSize/2, paths[i][paths[i].size()-1].sy*cellSize+cellSize/2,paths[i][paths[i].size()-1].fx*cellSize+cellSize/2,paths[i][paths[i].size()-1].fy*cellSize+cellSize/2);
    }
    painter.save();
    painter.end();
    logfile.close();
}

void MainWindow::visualize()
{
    ui->restart_button->setText("Start");
    ui->pause_button->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->listWidget->setCurrentRow(-1);
    ui->listWidget->clear();
    ui->paths_button->setText("Show paths");
    if(!getData(filename))
    {
        this->setVisible(false);
        for(int i = 0; i < timers.size(); i++)
        {
            timers[i]->setPaused(true);
            ui->listWidget->item(i)->setText("AGENT:"+QString::number(i+1)+"  X:"+QString::number(balls[i]->pos().x()/cellSize)+"  Y:"+QString::number(balls[i]->pos().y()/cellSize));
        }
        ui->pause_button->setText("Resume");
        emit openSettings();
        return;
    }
    std::vector<double> offsets;
    offsets.resize(paths.size());
    for(int i = 0; i < paths.size(); i++)
        offsets[i] = cellSize*(0.5 - paths[i][0].size);
    length.resize(paths.size());
    for(int i = 0; i<paths.size(); i++)
    {
        length[i] = 0;
        for(int j = 0; j < paths[i].size(); j++)
            length[i] += paths[i][j].length;;
    }
    targets.resize(target_poses.size());
    for(int i=0; i<target_poses.size(); i++)
        targets[i].resize(target_poses[i].size());
    balls.resize(paths.size());
    animations.resize(paths.size());
    timers.resize(paths.size());
    double maxlength = 0;
    maxl_i = 0;
    for(int i = 0; i < paths.size(); i++)
        if(maxlength < length[i])
        {
            maxlength = length[i];
            maxl_i = i;
        }
    framerange = 500;
    //std::ofstream out("log_out.txt", std::ios_base::app);
    for(int i = 0; i<paths.size(); i++)
    {
        QColor agentColor = agent_colors[i];
        if(cellSize > 2)
        {
            if(paths[i][0].size > 0.5)
                balls[i] = new agent(cellSize*2*paths[i][0].size-2, agentColor);
            else
                balls[i] = new agent(cellSize*2*paths[i][0].size-1, agentColor);
        }
        else
            balls[i] = new agent(cellSize*2*paths[i][0].size, agentColor);
        for(int j=0; j<targets[i].size(); j++)
            targets[i][j] = new target(cellSize-1);
        //balls[i]->setTransformOriginPoint(cellSize, cellSize);
        timers[i] = new QTimeLine(500*length[i]);
        timers[i]->setUpdateInterval(5);
        timers[i]->setFrameRange(0,framerange);
        timers[i]->setEasingCurve(QEasingCurve::Linear);
        animations[i] = new QGraphicsItemAnimation;
        animations[i]->setItem(balls[i]);
        animations[i]->setTimeLine(timers[i]);
        animations[i]->setTimeLine(timers[i]);
        animations[i]->setPosAt(0, QPointF(paths[i].back().fx*cellSize + offsets[i] + cellSize*paths[i].back().size, paths[i].back().fy*cellSize+ offsets[i] + cellSize*paths[i].back().size));
        ui->listWidget->addItem("AGENT:"+QString::number(i+1)+"  X:"+QString::number(paths[i][0].sx)+"  Y:"+QString::number(paths[i][0].sy));
        double curlength = 0.0;
        double curdirection = 0;
        for(int j = 0; j < paths[i].size(); j++)
        {
            double rotate;
            if(length[i] != 0)
            {
                if(fabs(paths[i][j].gheading - paths[i][j].sheading) > 0)
                {
                    rotate = paths[i][j].sheading - paths[i][j].gheading;
                    if(rotate < -180)
                        rotate +=360;
                    if(rotate > 180)
                        rotate -=360;

                    curdirection += rotate;
                }
                animations[i]->setTranslationAt(curlength/length[i], cellSize*paths[i].back().size, cellSize*paths[i].back().size);
                animations[i]->setRotationAt((curlength+paths[i][j].length)/length[i], curdirection);

                animations[i]->setTranslationAt(curlength/length[i], -cellSize*paths[i].back().size, -cellSize*paths[i].back().size);
                animations[i]->setPosAt(curlength/length[i], QPointF(paths[i][j].sx*cellSize + offsets[i] + cellSize*paths[i].back().size, paths[i][j].sy*cellSize+ offsets[i] +  cellSize*paths[i].back().size));

            }
            else
                animations[i]->setPosAt(curlength, QPointF(paths[i][j].sx*cellSize+offsets[i], paths[i][j].sy*cellSize+ offsets[i]));
            curlength += paths[i][j].length;
        }
        animations[i]->setPosAt(1.0, QPointF(paths[i].back().fx*cellSize + offsets[i] + cellSize*paths[i].back().size, paths[i].back().fy*cellSize+ offsets[i] + cellSize*paths[i].back().size));
        //for(int k=0; k<20;k++)
         //   out<<animations[i]->rotationAt(float(k)/20.0)<<"\n";
    }
    //out.close();
    createMap();
    this->resize(width*cellSize+300,height*cellSize+100);
    QObject::connect(timers[maxl_i], SIGNAL(frameChanged(int)), this, SLOT(updateList(int)));
    ui->listWidget->show();
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width*cellSize, height*cellSize);
    scene->setBackgroundBrush(QBrush(img));
    ui->graphicsView->resize(height*cellSize+2, width*cellSize+2);
    if(cellSize<3)
    {
        ui->graphicsView->setMinimumHeight(height*cellSize+2);
        ui->graphicsView->setMinimumWidth(width*cellSize+2);
    }
    ui->graphicsView->setMaximumHeight(height*cellSize+2);
    ui->graphicsView->setMaximumWidth(width*cellSize+2);

    for(int i=0; i<paths.size(); i++)
    {
        balls[i]->setTransformOriginPoint(cellSize*paths[i][0].size, cellSize*paths[i][0].size);
        balls[i]->setPos(QPointF(paths[i][0].sx*cellSize + offsets[i], paths[i][0].sy*cellSize+ offsets[i]));
        balls[i]->setRotation(360-paths[i][0].sheading);
        //if(paths[i][0].length > 0)
        //    balls[i]->setActive(4);


        scene->addItem(balls[i]);
    }

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_left_button_clicked()
{
    if(filename!="")
        if(timers[0]->currentTime()>0 && timers[maxl_i]->state() != QTimeLine::NotRunning)
        {
            timers[maxl_i]->setCurrentTime(timers[maxl_i]->currentTime()-300);
            for(int i = 0; i<paths.size(); i++)
            {
                if(timers[i]->state() == QTimeLine::NotRunning && timers[maxl_i]->currentTime() <= timers[i]->duration())
                    timers[i]->start();
                if(timers[i]->state() != QTimeLine::NotRunning)
                {
                    timers[i]->setPaused(true);
                    timers[i]->setCurrentTime(timers[maxl_i]->currentTime());
                    balls[i]->update();
                }
            }
        }
}

void MainWindow::on_right_button_clicked()
{
    if(filename!="")
        for(int i=0; i<paths.size(); i++)
            if(timers[i]->state()!=QTimeLine::NotRunning)
            {
                timers[i]->setPaused(true);
                timers[i]->setCurrentTime(timers[i]->currentTime()+300);
                balls[i]->update();
            }
}

void MainWindow::on_paths_button_clicked()
{
    if(filename!="")
    {
        if(ui->paths_button->text() == "Show paths")
        {
            scene->setBackgroundBrush(QBrush(imgpaths));
            ui->paths_button->setText("Hide paths");
        }
        else
        {
            scene->setBackgroundBrush(QBrush(img));
            ui->paths_button->setText("Show paths");
        }
        ui->graphicsView->setScene(scene);
    }
}
