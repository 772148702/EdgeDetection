#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QIntValidator>
#include "hw.h"
#include "memory.h"
#define qDebug_Chinese(string) QString(QStringLiteral("%1")).arg(QString(QStringLiteral(string)));
#define ChString(string) (QString::fromLocal8Bit(string))
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
	QIntValidator* IntValidator = new QIntValidator;
	IntValidator->setBottom(1);
	IntValidator->setTop(20);
	ui->lineEdit->setValidator(IntValidator);

	QIntValidator* IntValidator2 = new QIntValidator;
	IntValidator->setBottom(9);
	IntValidator->setTop(100);
	ui->lineEdit_2->setValidator(IntValidator2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
	pic_data out;
	int res = decode_png(fileName.toLatin1().data(), &out);
	if (res != -1) {

		int lastidx = fileName.lastIndexOf(".");
		 outfileName = fileName;
		outfileName.insert(lastidx, "_out");
		std::shared_ptr<QImage> img = std::make_shared<QImage>();
		img->load(fileName);
		QPixmap  pixmap = QPixmap::fromImage(*img);
		pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio);
		ui->label->setScaledContents(true);
		ui->label->setPixmap(QPixmap::fromImage(*img));
		QString temp = ((QLineEdit)(ui->lineEdit)).text();

		
		write_png_file(outfileName.toLatin1().data(), &out, n1, n2);

		std::shared_ptr<QImage> img2 = std::make_shared<QImage>();
		img2->load(outfileName);
		QPixmap  pixmap2 = QPixmap::fromImage(*img2);
		pixmap.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
		ui->label_2->setScaledContents(true);
		ui->label_2->setPixmap(QPixmap::fromImage(*img2));
	}
	else {

		QMessageBox::information(this, tr("Error"), QStringLiteral("请确认输入文件在英文路径下并且是png格式"), QMessageBox::Ok);
	}
}

void MainWindow::on_btn_process()
{
	handle();
}


void MainWindow::on_btn_files_clicked()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this, tr(("open file")),
		"./",
		tr("Png Files (*.png)"));
	if (files.count()) {
		fileName = files[0];
		handle();
	}

}

void MainWindow::on_lineEdit(QString q1) {
	n1 = q1.toInt();
}
void MainWindow::on_lineEdit_2(QString q1) {
	n2 = q1.toInt();
}