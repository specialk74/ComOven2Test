#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void connectSlot();
    void setTextConnectButton();
    void cmdSlot();
    void erroSocketSlot(QAbstractSocket::SocketError);
    void readyRead();
    void sendCmd1();

private:
    Ui::MainWindow *ui;
    QTcpSocket m_socket;
    QTimer m_timer;
    QTimer m_timerSend;
    bool m_TimerAttivo;

    void insertBufferOnPlainText (const QByteArray& buffer, const QString& testo);

};

#endif // MAINWINDOW_H
