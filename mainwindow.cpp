#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mytreewidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenTriggered);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onOpenTriggered() {
    ui->statusBar->showMessage("Open triggered", 1000);
    clearLayout(ui->horizontalLayout);

    MyTreeWidget *myTreeWidget = new MyTreeWidget(this);
    ui->horizontalLayout->addWidget(myTreeWidget);
}

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}
