#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audioplayer.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QMessageBox>
#include <QTimer>
#include <QXmlStreamReader>
#include "endwindow.h"

static const int TowerCost = 300;
extern int towernum;
class Endwindow;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_waves(3)
    , m_playerHp(5)
    , m_playrGold(1000)
    , m_gameEnded(false)
    , m_gameWin(false)
{
    ui->setupUi(this);

    m_audioPlayer = new AudioPlayer(this);
    m_audioPlayer->startBGM();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::loadTowerPositions()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPixmap cachePix(":/image/Bg.png");
    QPainter cachePainter(&cachePix);


    drawWave(&cachePainter);
    drawHP(&cachePainter);
    drawPlayerGold(&cachePainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();

}

bool MainWindow::canBuyTower() const
{
    if (m_playrGold >= TowerCost)
        return true;
    return false;
}

void MainWindow::drawWave(QPainter *painter)
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(400, 5, 100, 25), QString("WAVE : %1").arg(m_waves + 1));
}

void MainWindow::drawHP(QPainter *painter)
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(30, 5, 100, 25), QString("HP : %1").arg(m_playerHp));
}

void MainWindow::drawPlayerGold(QPainter *painter)
{
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(200, 5, 200, 25), QString("GOLD : %1").arg(m_playrGold));
}

void MainWindow::doGameOver()
{
    if (!m_gameEnded)
    {
        m_gameEnded = true;
        // 此处应该切换场景到结束场景
        // 暂时以打印替代,见paintEvent处理
    }
}

void MainWindow::awardGold(int gold)
{
    m_playrGold += gold;
    update();
}

AudioPlayer *MainWindow::audioPlayer() const
{
    return m_audioPlayer;
}

void MainWindow::addWayPoints()
{
}

void MainWindow::getHpDamage(int damage/* = 1*/)
{
    m_audioPlayer->playSound(LifeLoseSound);
    m_playerHp -= damage;
    if (m_playerHp <= 0)
        doGameOver();
}
void MainWindow::updateMap()
{

    update();
}

bool MainWindow::loadWave()
{
    QString imgstr;
    if(checkPoint == 1){
        imgstr = QString(":/image/enemy1.png");
    }else{
        imgstr = QString(":/image/enemy.png");
    }

    if (m_waves >=7/*m_wavesInfo.size()*/)
        return false;



    return true;
}


void MainWindow::setCheckPoint(int value)
{
    checkPoint = value;
    loadTowerPositions();
    addWayPoints();
    timer->start(30);
    // 设置300ms后游戏启动
    QTimer::singleShot(300, this, SLOT(gameStart()));
}

void MainWindow::gameStart()
{
    loadWave();

}

void MainWindow::on_pushButton_clicked()
{

}
