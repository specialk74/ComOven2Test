#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectSlot()));
    connect(ui->cmd1Button, SIGNAL(clicked()), this, SLOT(cmdSlot()));
    connect(ui->cmd2Button, SIGNAL(clicked()), this, SLOT(cmdSlot()));
    connect(ui->cmd3Button, SIGNAL(clicked()), this, SLOT(cmdSlot()));

    connect (&m_socket, SIGNAL(connected()), this, SLOT(setTextConnectButton()));
    connect (&m_socket, SIGNAL(disconnected()), this, SLOT(setTextConnectButton()));
    connect (&m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect (&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erroSocketSlot(QAbstractSocket::SocketError)));

    connect (&m_timer, SIGNAL(timeout()), this, SLOT(connectSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
    disconnect(&m_socket);
    m_socket.close();
}

void MainWindow::connectSlot()
{
    if (m_socket.isOpen())
    {
        m_socket.close();
        setTextConnectButton();
    }
    else
    {
        m_socket.connectToHost(QHostAddress (ui->addressServer->text()), ui->portServer->text().toInt());
        m_timer.stop();
    }
}

void MainWindow::setTextConnectButton()
{
    if (m_socket.isOpen())
        ui->connectButton->setText(tr("&Disconnect"));
    else
        ui->connectButton->setText(tr("&Connect"));
}

void MainWindow::cmdSlot()
{
    if (!m_socket.isOpen())
        return;

    QByteArray bufferOut;
    QByteArray bufferIn;
    QDataStream stream(&bufferIn, QIODevice::WriteOnly);
    // Lo trasformo in modo che i Client possano leggerlo corretamente

    QPushButton *button = (QPushButton *) sender();
    if (button == ui->cmd1Button)
    {
        stream << (quint8) 11;
        quint32 lunghezza = _htonl(5);
        stream << (quint32) lunghezza;
    }
    else if (button == ui->cmd2Button)
    {

    }
    else if (button == ui->cmd3Button)
    {

    }

    encode (bufferIn, bufferOut);
#if 0
    int val;
    QDebug debug = qDebug();
    foreach (val, bufferOut) {
        debug << hex << val ;
    }
#endif

    insertBufferOnPlainText (bufferOut, "Tx: ");
    m_socket.write(bufferOut);
}

void MainWindow::erroSocketSlot(QAbstractSocket::SocketError)
{
    m_timer.start(1000);
}


void MainWindow::readyRead()
{
    QByteArray bufferAll = m_socket.readAll();
    QByteArray decode;
    int idx = 0;
    static STATO_DECODER_TCPIP_MSG stato = STATO_TCPIP_DLE_STX;

    if (decodeTcpIpMsg(bufferAll, decode, idx, stato))
        insertBufferOnPlainText (bufferAll, "Rx: ");
}

void MainWindow::insertBufferOnPlainText (const QByteArray& buffer, const QString& header)
{
    quint8 var;
    QString testo = header;
    QChar carFill = '0';
    foreach (var, buffer) {
        testo.append(QString(" %1").arg(var, 2, 16, carFill));
    }

    ui->plainTextEdit->appendPlainText(testo);
}
