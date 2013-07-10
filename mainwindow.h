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

private:
    Ui::MainWindow *ui;
    QTcpSocket m_socket;
    QTimer m_timer;

    void insertBufferOnPlainText (const QByteArray& buffer, const QString& testo);

};

#endif // MAINWINDOW_H
