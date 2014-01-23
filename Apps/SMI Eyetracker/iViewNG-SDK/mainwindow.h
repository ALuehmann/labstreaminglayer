#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <string>
#include <vector>

// LSL API
#include <lsl_cpp.h>

// iViewNG API
#include <iViewNG-Core.h>
#include <iViewNG-Calibration.h>
#include <iViewNG-Connection.h>
#include <iViewNG-DataAcquisition.h>
#include <iViewNG-Device-ETG.h>
#include <iViewNG-Utility.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent, const std::string &config_file);
    ~MainWindow();
    
private slots:
    // config file dialog ops (from main menu)
    void load_config_dialog();
    void save_config_dialog();

    // link button
    void link();

    // close event (potentially disabled)
    void closeEvent(QCloseEvent *ev);

private:
    // raw config file IO
    void load_config(const std::string &filename);
    void save_config(const std::string &filename);

	Ui::MainWindow *ui;
	// callback tickets
	iViewTicket *gTicketStartAcquisition, *gTicketConnect, *gTicketAddLicense, *gTicketDeviceParameters;
	iViewTicket *gTicketSubscriptionGaze, *gTicketSubscriptionLeftEye, *gTicketSubscriptionRightEye;
	iViewTicket *gTicketSubscriptionScene, *gTicketUnsubscription, *gTicketStopAcquisition, *gTicketCalibration;
	// server
	iViewHost gServer;
	// User-provided flags
	iViewSamplingRate gSamplingRate;
	// Local data for calibration
	char gCalibrating;
};

#endif // MAINWINDOW_H
