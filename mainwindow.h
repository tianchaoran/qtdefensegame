#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}


class AudioPlayer;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void getHpDamage(int damage = 1);
    void awardGold(int gold);

    AudioPlayer* audioPlayer() const;


    void setCheckPoint(int);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);


public slots:
    void gameStart();

private slots:
    void updateMap();
    void on_pushButton_clicked();

private:
    void loadTowerPositions();
    void addWayPoints();
    bool loadWave();
    bool canBuyTower() const;
    void drawWave(QPainter *painter);
    void drawHP(QPainter *painter);
    void drawPlayerGold(QPainter *painter);
    void doGameOver();
    void preLoadWavesInfo();

private:
    Ui::MainWindow *		ui;
    int						m_waves=0;
    int						m_playerHp;
    int						m_playrGold;
    bool					m_gameEnded;
    bool					m_gameWin;
    AudioPlayer *			m_audioPlayer;

    int checkPoint;
    QTimer *timer;
};

#endif // MAINWINDOW_H
