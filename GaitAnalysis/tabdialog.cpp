#include <QtWidgets>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QList>
#include <QStringList>
#include <QAbstractScrollArea>

//3D Graph
#include <QtDataVisualization/qscatterdataproxy.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qscatter3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include <QtCore/qmath.h>


#include "tabdialog.h"

using namespace QtDataVisualization;

ResultsTab::ResultsTab(QWidget *parent)
    : QWidget(parent)
{

    //Layout Set-Up
    windowLayout = new QVBoxLayout;
    topLayout = new QHBoxLayout;
    bottomLayout = new QHBoxLayout;
    chartLayout = new QGridLayout;
    groupBoxLayout = new QVBoxLayout;
    configLayout = new QGridLayout;
    featureBasedLayout = new QVBoxLayout;
    timeBasedLayout = new QVBoxLayout;

    windowLayout->addLayout(topLayout);
    windowLayout->addLayout(bottomLayout);
    topLayout->addLayout(chartLayout);
    bottomLayout->addLayout(groupBoxLayout);
   // bottomLayout->addLayout(featureBasedLayout);
  //  bottomLayout->addLayout(configLayout);


        //Containers
        selectedConfigBox = new QGroupBox("Selected");
        selectedConfigBox->setLayout(configLayout);
        bottomLayout->addWidget(selectedConfigBox);

        //Container (Feature-List)
        featureList = new QListWidget;
        QListWidgetItem * newItem = new QListWidgetItem;
        newItem->setText("No Items Added");
        featureList->insertItem(0,newItem);
        featureBasedBox = new QGroupBox("Feature Based");
        featureBasedBox->setLayout(featureBasedLayout);
        bottomLayout->addWidget(featureBasedBox);
        featureBasedLayout->addWidget(featureList);

        //Container (Time Series -List)
        timeSeriesList = new QListWidget;
        QListWidgetItem * newItem2 = new QListWidgetItem;
        newItem2->setText("No Items Added");
        timeSeriesList->insertItem(0,newItem2);
        timeBasedBox = new QGroupBox("Time Series Similarity");
        timeBasedBox->setLayout(timeBasedLayout);
        bottomLayout->addWidget(timeBasedBox);
        timeBasedLayout->addWidget(timeSeriesList);


    //Adding Buttons to Layout
    selectFileButton = new QPushButton("&Select File");
    plotButton = new QPushButton("&Plot");
    groupBoxLayout->addWidget(selectFileButton);
    groupBoxLayout->addWidget(plotButton);

    //Setting up charts
    categories<<"Accuracy"<<"Memory"<<"Time-To-Train"<<"Time-To-Test";

    //Accuracy chart
    seriesAccuracy = new QBarSeries();
    setAccuracyFeature = new QBarSet("Feature Based");
    setAccuracyTime = new QBarSet("Time Series");

    *setAccuracyFeature<<0;
    *setAccuracyTime<<0;

    seriesAccuracy->append(setAccuracyFeature);
    seriesAccuracy->append(setAccuracyTime);

    accuracyChart = new QChart();
    accuracyChart->addSeries(seriesAccuracy);
    accuracyChart->setAnimationOptions(QChart::SeriesAnimations);
    accuracyAxis = new QBarCategoryAxis();
    accuracyAxis->append(categories.at(0));
    accuracyChart->createDefaultAxes();
    accuracyChart->setAxisX(accuracyAxis,seriesAccuracy );
    accuracyChart->legend()->setVisible(true);
    accuracyChart->legend()->setAlignment(Qt::AlignBottom);
    accuracyView = new QChartView(accuracyChart);
    accuracyView->setRenderHint(QPainter::Antialiasing);
    accuracyView->setRubberBand(QChartView::RectangleRubberBand);
    //Accuracy chart

    //Memory chart
        seriesMemory = new QBarSeries();
        setMemoryFeature = new QBarSet("Feature Based");
        setMemoryTime = new QBarSet("Time Series");

        *setMemoryFeature<<0;
        *setMemoryTime<<0;

        seriesMemory->append(setMemoryFeature);
        seriesMemory->append(setMemoryTime);

        memoryChart = new QChart();
        memoryChart->addSeries(seriesMemory);
        memoryChart->setAnimationOptions(QChart::SeriesAnimations);
        memoryAxis = new QBarCategoryAxis();
        memoryAxis->append(categories.at(1));
        memoryChart->createDefaultAxes();
        memoryChart->setAxisX(memoryAxis,seriesMemory );
        memoryChart->legend()->setVisible(true);
        memoryChart->legend()->setAlignment(Qt::AlignBottom);
        memoryView = new QChartView(memoryChart);
        memoryView->setRenderHint(QPainter::Antialiasing);
        memoryView->setRubberBand(QChartView::RectangleRubberBand);
        //Memory chart

            //Train chart
            seriesTrain = new QBarSeries();
            setTrainFeature = new QBarSet("Feature Based");
            setTrainTime = new QBarSet("Time Series");

            *setTrainFeature<<0;
            *setTrainTime<<0;

            seriesTrain->append(setTrainFeature);
            seriesTrain->append(setTrainTime);

            trainChart = new QChart();
            trainChart->addSeries(seriesTrain);
            trainChart->setAnimationOptions(QChart::SeriesAnimations);
            trainAxis = new QBarCategoryAxis();
            trainAxis->append(categories.at(2));
            trainChart->createDefaultAxes();
            trainChart->setAxisX(trainAxis,seriesTrain );
            trainChart->legend()->setVisible(true);
            trainChart->legend()->setAlignment(Qt::AlignBottom);
            trainView = new QChartView(trainChart);
            trainView->setRenderHint(QPainter::Antialiasing);
            trainView->setRubberBand(QChartView::RectangleRubberBand);
            //Train chart

            //Test chart
                seriesTest = new QBarSeries();
                setTestFeature = new QBarSet("Feature Based");
                setTestTime = new QBarSet("Time Series");

                *setTestFeature<<0;
                *setTestTime<<0;

                seriesTest->append(setTestFeature);
                seriesTest->append(setTestTime);

                testChart = new QChart();
                testChart->addSeries(seriesTest);
                testChart->setAnimationOptions(QChart::SeriesAnimations);
                testAxis = new QBarCategoryAxis();
                testAxis->append(categories.at(3));
                testChart->createDefaultAxes();
                testChart->setAxisX(testAxis,seriesTest );
                testChart->legend()->setVisible(true);
                testChart->legend()->setAlignment(Qt::AlignBottom);
                testView = new QChartView(testChart);
                testView->setRenderHint(QPainter::Antialiasing);
                testView->setRubberBand(QChartView::RectangleRubberBand);
                //Test chart

    // Setting up Config File Variables
        trueStyle = "QLabel {background-color : green; color : white;}";
        falseStyle = "QLabel {background-color : red; color : white;}";


        isPatternSelected = new QLabel("Pattern Based");
        isMemorySelected = new QLabel("Memory Based");
        isTimeSeriesSelected = new QLabel("Time Series");
        isTimetoTrainSelected = new QLabel("Time-To-Train");
        isStdDevSelected = new QLabel("STD DEV");
        isEDforTimeSelected = new QLabel("ED Time Series");
        isAccuracySelected = new QLabel("Accuracy Based");
        isFeatureSelected = new QLabel("Feature Based");
        isHrSelected = new QLabel("Horizontal Range");
        isFnSelected = new QLabel("First-N Time Series");
        isEDforFeatureSelected = new QLabel("ED Feature");
        isVrSelected = new QLabel("Vertical Range");
        isMeanSelected = new QLabel("Mean");
        isTimetoTestSelected = new QLabel("Time-To-Test");

                //Labels(2)
                TF1 = new QLabel("N/A");
                TF2 = new QLabel("N/A");
                TF3 = new QLabel("N/A");
                TF4 = new QLabel("N/A");
                TF5 = new QLabel("N/A");
                TF6 = new QLabel("N/A");
                TF7 = new QLabel("N/A");
                TF8 = new QLabel("N/A");
                TF9 = new QLabel("N/A");
                TF10 = new QLabel("N/A");
                TF11 = new QLabel("N/A");
                TF12 = new QLabel("N/A");
                TF13 = new QLabel("N/A");
                TF14 = new QLabel("N/A");

        configLayout->addWidget(isPatternSelected, 0, 0);
        configLayout->addWidget(isMemorySelected, 1, 0);
        configLayout->addWidget(isTimeSeriesSelected, 2, 0);
        configLayout->addWidget(isTimetoTrainSelected, 3, 0);
        configLayout->addWidget(isStdDevSelected, 4, 0);
        configLayout->addWidget(isEDforTimeSelected, 5, 0);
        configLayout->addWidget(isAccuracySelected, 6, 0);
        configLayout->addWidget(isFeatureSelected, 7, 0);
        configLayout->addWidget(isHrSelected, 8, 0);
        configLayout->addWidget(isFnSelected, 9, 0);
        configLayout->addWidget(isEDforFeatureSelected, 10, 0);
        configLayout->addWidget(isVrSelected, 11, 0);
        configLayout->addWidget(isMeanSelected, 12, 0);
        configLayout->addWidget(isTimetoTestSelected, 13, 0);

        configLayout->addWidget(TF1, 0, 1);
        configLayout->addWidget(TF2, 1, 1);
        configLayout->addWidget(TF3, 2, 1);
        configLayout->addWidget(TF4, 3, 1);
        configLayout->addWidget(TF5, 4, 1);
        configLayout->addWidget(TF6, 5, 1);
        configLayout->addWidget(TF7, 6, 1);
        configLayout->addWidget(TF8, 7, 1);
        configLayout->addWidget(TF9, 8, 1);
        configLayout->addWidget(TF10, 9, 1);
        configLayout->addWidget(TF11, 10, 1);
        configLayout->addWidget(TF12, 11, 1);
        configLayout->addWidget(TF13, 12, 1);
        configLayout->addWidget(TF14, 13, 1);


    //Adding Chart Widgets to Grid
    chartLayout->addWidget(accuracyView, 0, 0);
    chartLayout->addWidget(memoryView, 0, 1);
    chartLayout->addWidget(trainView, 0, 2);
    chartLayout->addWidget(testView, 0, 3);
    setLayout(windowLayout);


    //Connections
    connect(selectFileButton, SIGNAL(clicked(bool)), this, SLOT(selectFile()));
    connect(plotButton, SIGNAL(clicked(bool)), this, SLOT(plotFile()));
}

void ResultsTab::selectFile()
{

 resultsFileName = QFileDialog::getOpenFileName(this,"Select File:", QDir::homePath());
 QMessageBox::information(this, "Selection...",resultsFileName );

}

void ResultsTab::plotFile()
{
QFile file(resultsFileName);
QStringList rowElements;
QVariant cast;
file.open(QIODevice::ReadOnly);

    while (!file.atEnd()){
            QByteArray line = file.readLine();
            rowElements.append(line.split(',').first());

            if (rowElements[0] == "Accuracy"){

                cast = line.split(',').at(1);
                setAccuracyFeature->replace(0, cast.toDouble());

                cast = line.split(',').at(2);
                setAccuracyTime->replace(0, cast.toDouble());

                    accuracyChart->createDefaultAxes();
                    accuracyAxis = new QBarCategoryAxis();
                    accuracyAxis->append(categories.at(0));
                    QBarSeries *newSeries = new QBarSeries();
                    newSeries = seriesAccuracy;
                    accuracyChart->removeSeries(seriesAccuracy);
                    seriesAccuracy = newSeries;
                    accuracyChart->addSeries(seriesAccuracy);
                    accuracyChart->createDefaultAxes();
                    accuracyChart->setAxisX(accuracyAxis,seriesAccuracy);

                 }

            if (rowElements[0] == "MemoryRequired"){

                            cast = line.split(',').at(1);
                            setMemoryFeature->replace(0, cast.toDouble());

                            cast = line.split(',').at(2);
                            setMemoryTime->replace(0, cast.toDouble());

                                memoryChart->createDefaultAxes();
                                memoryAxis = new QBarCategoryAxis();
                                memoryAxis->append(categories.at(1));
                                QBarSeries *newSeries = new QBarSeries();
                                newSeries = seriesMemory;
                                memoryChart->removeSeries(seriesMemory);
                                seriesMemory = newSeries;
                                memoryChart->addSeries(seriesMemory);
                                memoryChart->createDefaultAxes();
                                memoryChart->setAxisX(memoryAxis,seriesMemory);

                             }

            if (rowElements[0] == "TimeToTrain"){

                        cast = line.split(',').at(1);
                        setTrainFeature->replace(0, cast.toDouble());

                        cast = line.split(',').at(2);
                        setTrainTime->replace(0, cast.toDouble());

                            trainChart->createDefaultAxes();
                            trainAxis = new QBarCategoryAxis();
                            trainAxis->append(categories.at(2));
                            QBarSeries *newSeries = new QBarSeries();
                            newSeries = seriesTrain;
                            trainChart->removeSeries(seriesTrain);
                            seriesTrain = newSeries;
                            trainChart->addSeries(seriesTrain);
                            trainChart->createDefaultAxes();
                            trainChart->setAxisX(trainAxis,seriesTrain);

                         }

            if (rowElements[0] == "TimeToTest"){

                            cast = line.split(',').at(1);
                            setTestFeature->replace(0, cast.toDouble());

                            cast = line.split(',').at(2);
                            setTestTime->replace(0, cast.toDouble());

                                testChart->createDefaultAxes();
                                testAxis = new QBarCategoryAxis();
                                testAxis->append(categories.at(3));
                                QBarSeries *newSeries = new QBarSeries();
                                newSeries = seriesTest;
                                testChart->removeSeries(seriesTest);
                                seriesTest = newSeries;
                                testChart->addSeries(seriesTest);
                                testChart->createDefaultAxes();
                                testChart->setAxisX(testAxis,seriesTest);

                             }

            if (rowElements[0] == "IsPatternBasedSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF1->setStyleSheet(trueStyle);
                           TF1->setText(tfValue);
                       }
                       else{
                           TF1->setStyleSheet(falseStyle);
                           TF1->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsMemorySelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF2->setStyleSheet(trueStyle);
                           TF2->setText(tfValue);
                       }
                       else{
                           TF2->setStyleSheet(falseStyle);
                           TF2->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsTimeSeriesSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF3->setStyleSheet(trueStyle);
                           TF3->setText(tfValue);
                       }
                       else{
                           TF3->setStyleSheet(falseStyle);
                           TF3->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsTimeToTrainSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF4->setStyleSheet(trueStyle);
                           TF4->setText(tfValue);
                       }
                       else{
                           TF4->setStyleSheet(falseStyle);
                           TF4->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsStdDevSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF5->setStyleSheet(trueStyle);
                           TF5->setText(tfValue);
                       }
                       else{
                           TF5->setStyleSheet(falseStyle);
                           TF5->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsEDSelectedForTimeSeries"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF6->setStyleSheet(trueStyle);
                           TF6->setText(tfValue);
                       }
                       else{
                           TF6->setStyleSheet(falseStyle);
                           TF6->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsAccuracySelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF7->setStyleSheet(trueStyle);
                           TF7->setText(tfValue);
                       }
                       else{
                           TF7->setStyleSheet(falseStyle);
                           TF7->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsFeatureBasedSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF8->setStyleSheet(trueStyle);
                           TF8->setText(tfValue);
                       }
                       else{
                           TF8->setStyleSheet(falseStyle);
                           TF8->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsHorizontalRangeSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF9->setStyleSheet(trueStyle);
                           TF9->setText(tfValue);
                       }
                       else{
                           TF9->setStyleSheet(falseStyle);
                           TF9->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsFirstNSelectedForTimeSeries"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF10->setStyleSheet(trueStyle);
                           TF10->setText(tfValue);
                       }
                       else{
                           TF10->setStyleSheet(falseStyle);
                           TF10->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsEDSelectedForFeatureBased"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF11->setStyleSheet(trueStyle);
                           TF11->setText(tfValue);
                       }
                       else{
                           TF11->setStyleSheet(falseStyle);
                           TF11->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsVerticalRangeSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF12->setStyleSheet(trueStyle);
                           TF12->setText(tfValue);
                       }
                       else{
                           TF12->setStyleSheet(falseStyle);
                           TF12->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsMeanSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF13->setStyleSheet(trueStyle);
                           TF13->setText(tfValue);
                       }
                       else{
                           TF13->setStyleSheet(falseStyle);
                           TF13->setText(tfValue);
                       }

                }

            if (rowElements[0] == "IsTimeToTestSelected"){

                       cast = line.split(',').at(1);
                       QString tfValue = cast.toString();

                       if (tfValue == "TRUE"){
                           TF14->setStyleSheet(trueStyle);
                           TF14->setText(tfValue);
                       }
                       else{
                           TF14->setStyleSheet(falseStyle);
                           TF14->setText(tfValue);
                       }

                }

            if (rowElements[0] == "ClassificationResults"){

                int i = 0;
                featureList->clear();

                        while (rowElements[0] != "TimeSeriesSimilarity"){


                            line = file.readLine();
                            cast = line.split(',').first();

                            QListWidgetItem * newItem = new QListWidgetItem;
                            newItem->setText(cast.toString());
                            featureList->insertItem(i,newItem);
                            ++i;
                            rowElements.clear();
                            rowElements.append(line.split(',').first());

                        }

                        //May cause unexpected behavior in Memory
                        delete featureList->takeItem(0);
                        delete featureList->takeItem(i - 2);
                        delete featureList->takeItem(i - 3);

                        i = 0;
                        timeSeriesList->clear();

                        while (rowElements[0] != "EndOfClassificationResults"){

                              line = file.readLine();
                              cast = line.split(',').first();

                              QListWidgetItem * newItem = new QListWidgetItem;
                              newItem->setText(cast.toString());
                              timeSeriesList->insertItem(i,newItem);
                              ++i;
                              rowElements.clear();
                              rowElements.append(line.split(',').first());

                          }

                        //May cause unexpected behavior in Memory
                        delete timeSeriesList->takeItem(i - 1);
                        delete timeSeriesList->takeItem(i - 2);


                }



     rowElements.clear();
    }



file.close();
}


TimeSeriesTab::TimeSeriesTab(QWidget *parent)
    : QWidget(parent)
{

    //Layout Set-Up
    windowLayout = new QHBoxLayout;
    graphLayout = new QVBoxLayout;
    optionsLayout = new QVBoxLayout;

    windowLayout->addLayout(optionsLayout);
    windowLayout->addLayout(graphLayout);

    //Creating Widgets

    //Buttons
    selectFileButton =  new QPushButton("&Select File");
    plotButton = new QPushButton("&Plot");

    optionsLayout->addWidget(selectFileButton);
    optionsLayout->addWidget(plotButton);

    //(Time Series Chart)
    timeSeriesChart = new QChart();
    timeSeriesChartView = new QChartView(timeSeriesChart);
    timeSeries = new QBarSeries();
    seriesSet = new QBarSet("No Person Added");
    seriesAxis = new QBarCategoryAxis();

    *seriesSet<<0;
    timeSeries->append(seriesSet);
    timeSeriesChart->addSeries(timeSeries);
    categories.append("No Person Added");
    seriesAxis->append(categories.at(0));

    timeSeriesChart->createDefaultAxes();
    timeSeriesChart->setAxisX(seriesAxis,timeSeries );

        //Chart Properties
        timeSeriesChart->setTitle("Time Series Similarity");
        timeSeriesChart->setAnimationOptions(QChart::SeriesAnimations);
        timeSeriesChart->legend()->setVisible(true);
        timeSeriesChart->legend()->setAlignment(Qt::AlignBottom);
        timeSeriesChartView->setRenderHint(QPainter::Antialiasing);
        timeSeriesChartView->setRubberBand(QChartView::RectangleRubberBand);
        timeSeriesChartView->setDragMode(QGraphicsView::ScrollHandDrag);

        graphLayout->addWidget(timeSeriesChartView);



     //Combo Box
        fromOptions = new QComboBox;

        optionsLayout->addWidget(fromOptions);


    setLayout(windowLayout);

    //Connections
    connect(selectFileButton, SIGNAL(clicked(bool)), this, SLOT(selectFile()));
    connect(plotButton, SIGNAL(clicked(bool)), this, SLOT(plotFile()));

}

void TimeSeriesTab::selectFile()
{
    timeSeriesFileName = QFileDialog::getOpenFileName(this,"Select File:", QDir::homePath());
    QMessageBox::information(this, "Selection...",timeSeriesFileName );

    QFile file(timeSeriesFileName);
    file.open(QIODevice::ReadOnly);
    file.readLine();
    timeSeriesHash.clear();
    distanceFromListSort.clear();

    while(!file.atEnd()){

        QByteArray line = file.readLine();
        QVariant distanceFrom = line.split(',').first();
        QVariant distanceTo = line.split(',').at(1);
        QVariant distance = line.split(',').at(2);

        QString distanceString = distance.toString();

        timeSeriesHash.insert(distanceFrom.toString(),qMakePair(distanceTo.toString(),distanceString.toDouble()));
        distanceFromListSort.insert(distanceFrom.toString(), 0);

    }

   fromOptions->clear();
   for(MapDataType::iterator it = distanceFromListSort.begin();it != distanceFromListSort.end();++it )
        fromOptions->addItem(it.key());

   file.close();
}

void TimeSeriesTab::plotFile()
{
    int item = fromOptions->currentIndex();
    QString itemText = fromOptions->itemText(item);

    timeSeriesChart->createDefaultAxes();
    seriesAxis = new QBarCategoryAxis();
    QBarSeries * newSeries = new QBarSeries();
    QBarSet * newSet = new QBarSet(itemText);
    categories.clear();

    HashDataType::iterator it = timeSeriesHash.find(itemText);
    while (it != timeSeriesHash.end() && it.key() == itemText ){

        newSet->append(it.value().second);
        categories.append(it.value().first);
        ++it;
    }



       seriesAxis->append(categories);
       newSeries->append(newSet);
       timeSeriesChart->removeSeries(timeSeries);
       timeSeries = newSeries;
       timeSeriesChart->addSeries(timeSeries);
       timeSeriesChart->createDefaultAxes();
       timeSeriesChart->setAxisX(seriesAxis, timeSeries);
       newSet->setColor("#a7143c");


}

InputTab::InputTab(QWidget *parent)
    : QWidget(parent)
{
    //Layout Set-Up
    windowLayout = new QHBoxLayout;
   // graphLayout = new QVBoxLayout;
    optionsLayout = new QVBoxLayout;
    jointLayout = new QVBoxLayout;
    plotLayout = new QVBoxLayout;

    windowLayout->addLayout(optionsLayout);
   // windowLayout->addLayout(graphLayout);
   // optionsLayout->addLayout(jointLayout);
   // optionsLayout->addLayout(plotLayout);


   //Containers (Joint List)
    jointList = new QListWidget;
    QListWidgetItem * newItem = new QListWidgetItem;
    newItem->setText("No Joints Added");
    jointList->insertItem(0,newItem);
    jointBox = new QGroupBox("Joints");
    jointBox->setLayout(jointLayout);
    optionsLayout->addWidget(jointBox);
    jointLayout->addWidget(jointList);
    jointList->setSelectionMode(QAbstractItemView::SingleSelection);
    jointList->setDragEnabled(true);
    jointList->viewport()->setAcceptDrops(true);
    jointList->setDropIndicatorShown(true);
    jointList->setDragDropMode(QAbstractItemView::InternalMove);

    jointList->installEventFilter(this);

    //Containers (Plot List)
     plotList = new QListWidget;
     QListWidgetItem * newItem2 = new QListWidgetItem;
     newItem2->setText("No Plots Added");
     plotList->insertItem(0,newItem2);
     plotBox = new QGroupBox("Plot");
     plotBox->setLayout(plotLayout);
     optionsLayout->addWidget(plotBox);
     plotLayout->addWidget(plotList);
     plotList->setSelectionMode(QAbstractItemView::SingleSelection);
     plotList->setDragEnabled(true);
     plotList->viewport()->setAcceptDrops(true);
     plotList->setDropIndicatorShown(true);
     plotList->setDragDropMode(QAbstractItemView::InternalMove);

    plotList->installEventFilter(this);


     //Buttons
     selectFileButton = new QPushButton("&Select File");
     optionsLayout->addWidget(selectFileButton);

     //Graph
     graph = new Q3DScatter();
     QWidget *container = QWidget::createWindowContainer(graph);
     windowLayout->addWidget(container,1);

     QSize screenSize = graph->screen()->size();
     container->setMinimumSize(QSize(screenSize.width()/2, screenSize.height()/1.5));
     container->setMaximumSize(screenSize);
     container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     container->setFocusPolicy(Qt::StrongFocus);

     //Setting Colors
     QStringList colorStringList = QColor::colorNames();
     QList<QColor> colorList;
     foreach(QString s, colorStringList)
         colorList << QColor(s);

     graph->activeTheme()->setBaseColors(colorList);

    setAcceptDrops(true);

    setLayout(windowLayout);


    //Connections
    connect(selectFileButton, SIGNAL(clicked(bool)), this, SLOT(selectFile()));
}

void InputTab::selectFile()
{
    skeletonFileName = QFileDialog::getOpenFileName(this,"Select File:", QDir::homePath());
    QMessageBox::information(this, "Selection...",skeletonFileName );

    clearListWidgets();
    clearMaps();
    clearSeriesGraph();
    readFileData();
    populateVariantList();
    createGraph();




}

void InputTab::readFileData()
{
    QFile file(skeletonFileName);
    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()){

           QByteArray line = file.readLine();
           QVariant variantName = line.split(';').first();
           QVariant variantPosX = line.split(';').at(1);
           QVariant variantPosY = line.split(';').at(2);
           QVariant variantPosZ = line.split(';').at(3);

           QString PosX = variantPosX.toString();
           QString PosY = variantPosY.toString();
           QString PosZ = variantPosZ.toString();

           gaitMap.insert(variantName.toString(), QVector3D(PosX.toFloat(), PosY.toFloat(), PosZ.toFloat()));
           seriesMap.insert(variantName.toString(), NULL);
         // qDebug()<<variantName<<" "<<PosX<<" "<<PosY<<" "<<PosZ;

       }


   // for (SeriesMapType::iterator it=seriesMap.begin(); it!=seriesMap.end(); ++it)
     //   qDebug()<< it.key() << " => " << it.value() << '\n';


    file.close();

}

void InputTab::createGraph()
{
    graph->axisX()->setTitle("X");
    graph->axisY()->setTitle("Y");
    graph->axisZ()->setTitle("Z");


    for(SeriesMapType::iterator it= seriesMap.begin(); it != seriesMap.end(); ++it){

    //SeriesMapType::iterator it= seriesMap.begin();
    QString variateKey = it.key();


    QScatterDataProxy *proxy = new QScatterDataProxy;
    QScatter3DSeries *series = new QScatter3DSeries(proxy);
    series->setName(variateKey);
    series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel : @seriesName"));
    series->setMeshSmooth(true);
    graph->addSeries(series);


    QScatterDataArray *dataArray = new QScatterDataArray;
    dataArray->resize(getVariateCount(it.key()));

    QScatterDataItem *ptrToDataArray = &dataArray->first();

    //Set Series Map Pointers

    //seriesMap.insert(variateKey, &dataArray->first());
    seriesMap[variateKey] = dataArray;
    seriesTable.insert(variateKey,series);

            GaitMapType::iterator i = gaitMap.find(variateKey);
            while (i != gaitMap.end() && i.key() == variateKey){

                ptrToDataArray->setPosition(i.value());
                ptrToDataArray++;
                ++i;

            }



    }

    showGraphSeries();
    hideAllSeries();
  // graph->seriesList().at(0)->dataProxy()->resetArray( dataArray);

}

void InputTab::clearListWidgets()
{
    jointList->clear();
    plotList->clear();

}

void InputTab::clearMaps()
{
    gaitMap.clear();
    seriesMap.clear();
    seriesTable.clear();

}

void InputTab::populateVariantList()
{
    for (SeriesMapType::iterator it=seriesMap.begin(); it!=seriesMap.end(); ++it)
         jointList->addItem(it.key());

}

int InputTab::getVariateCount(QString inputVariate)
{
    int count = 0;

            GaitMapType::iterator i = gaitMap.find(inputVariate);
            while (i != gaitMap.end() && i.key() == inputVariate){

                ++count;
                ++i;
            }

         return count;
}

void InputTab::showGraphSeries()
{
    int seriesCounter = 0;

        for(SeriesMapType::iterator it= seriesMap.begin(); it != seriesMap.end(); ++it){

            graph->seriesList().at(seriesCounter)->dataProxy()->resetArray( it.value());

            ++seriesCounter;

        }

}

void InputTab::hideAllSeries()
{
    for(SeriesTableType::iterator it = seriesTable.begin(); it != seriesTable.end(); ++it )
        it.value()->setVisible(false);

}

void InputTab::clearSeriesGraph()
{
    QList<QScatter3DSeries*> seriesList = graph->seriesList();

    if(seriesList.isEmpty())
        qDebug()<<"This series is empty";

    else
    {
        while(!seriesList.isEmpty()){

            graph->removeSeries(seriesList.at(0));
            //delete seriesList.at(0);
            delete seriesList.takeFirst();

        }
        qDebug()<<"All series have been removed";

    }


}

/*
void InputTab::mousePressEvent(QMouseEvent *event)
{


qDebug()<<"Mouse Press Event";

} */

void InputTab::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    qDebug()<<"Drag Enter";
}

void InputTab::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
    qDebug()<<"Drag Leave";
}

void InputTab::dragMoveEvent(QDragMoveEvent *event)
{

    event->accept();
    qDebug()<<"Drag Move";
}

void InputTab::dropEvent(QDropEvent * event)
{

        event->accept();

    qDebug()<<"Drop Event";
}


bool InputTab::eventFilter(QObject *obj, QEvent *event)
{

    if ((obj == plotList) && (event->type() == QEvent::ChildRemoved) ){
        qDebug()<<"This filter works..Plot";
        qDebug()<<event->type();

        //Move Item to new list
        QListWidgetItem * newItem = new QListWidgetItem;
        newItem->setText(plotList->currentItem()->text());
        jointList->addItem(newItem);

        //Set Visible To Graph False
        SeriesTableType::iterator it = seriesTable.find(plotList->currentItem()->text());
        it.value()->setVisible(false);

        //Remove old Item
        plotList->removeItemWidget(plotList->currentItem());
        delete plotList->currentItem();

}
    if ((obj == jointList) && (event->type() == QEvent::ChildRemoved) ){
        qDebug()<<"This filter works...Joint";
        qDebug()<<event->type();

        //Move Item to new list
        QListWidgetItem * newItem = new QListWidgetItem;
        newItem->setText(jointList->currentItem()->text());
        plotList->addItem(newItem);

        //Set Visible To Graph True
        SeriesTableType::iterator it = seriesTable.find(jointList->currentItem()->text());
        it.value()->setVisible(true);

        //Remove old Item
        jointList->removeItemWidget(jointList->currentItem());
        delete jointList->currentItem();
}


    return false;
}

FrequentPatternTab::FrequentPatternTab(QWidget *parent)
    : QWidget(parent)
{

}


FeatureBasedTab::FeatureBasedTab(QWidget *parent)
    : QWidget(parent)
{

}

TabDialog::TabDialog(QWidget *parent)
    : QDialog(parent)
{

        tabWidget = new QTabWidget;
        tabWidget->addTab(new ResultsTab, tr("Results"));
        tabWidget->addTab(new TimeSeriesTab, tr("Time Series"));
        tabWidget->addTab(new InputTab, tr("Input"));
        tabWidget->addTab(new FrequentPatternTab, tr("Frequent Pattern"));
        tabWidget->addTab(new FeatureBasedTab, tr("Feature Based"));

        tabLayout = new QVBoxLayout;
        tabLayout->addWidget(tabWidget);
        setLayout(tabLayout);
        setWindowTitle(tr("Gait Analysis"));


}







