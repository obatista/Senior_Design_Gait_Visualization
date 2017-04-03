
#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QComboBox>
#include <QDebug>


//DATA
#include <QMultiHash>
#include <QPair>
#include <QSet>
#include <QMap>
#include <QMultiMap>


//Events
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QDrag>
#include <QDropEvent>

//Charts
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE

//3D Charts
#include <QtDataVisualization/qabstract3dseries.h>
#include <QtDataVisualization/q3dscatter.h>

using namespace QtDataVisualization;


class QFileInfo;
class QTabWidget;



class ResultsTab : public QWidget
{
    Q_OBJECT

    //Layouts
    QVBoxLayout * windowLayout;
    QHBoxLayout * topLayout;
    QHBoxLayout * bottomLayout;
    QGridLayout * chartLayout;
    QVBoxLayout * groupBoxLayout;
    QGridLayout * configLayout;
    QVBoxLayout * featureBasedLayout;
    QVBoxLayout * timeBasedLayout;

    //Containers
    QGroupBox * selectedConfigBox;
    QGroupBox * featureBasedBox;
    QGroupBox * timeBasedBox;


public:
    explicit ResultsTab( QWidget *parent = 0);


private:

    //Buttons
    QPushButton * selectFileButton;
    QPushButton * plotButton;
    //Labels
        QLabel * isPatternSelected;
        QLabel * isMemorySelected;
        QLabel * isTimeSeriesSelected;
        QLabel * isTimetoTrainSelected;
        QLabel * isStdDevSelected;
        QLabel * isEDforTimeSelected;
        QLabel * isAccuracySelected;
        QLabel * isFeatureSelected;
        QLabel * isHrSelected;
        QLabel * isFnSelected;
        QLabel * isEDforFeatureSelected;
        QLabel * isVrSelected;
        QLabel * isMeanSelected;
        QLabel * isTimetoTestSelected;

        //Labels(2)
        QLabel * TF1;
        QLabel * TF2;
        QLabel * TF3;
        QLabel * TF4;
        QLabel * TF5;
        QLabel * TF6;
        QLabel * TF7;
        QLabel * TF8;
        QLabel * TF9;
        QLabel * TF10;
        QLabel * TF11;
        QLabel * TF12;
        QLabel * TF13;
        QLabel * TF14;


  //List Widgets
        QListWidget * featureList;
        QListWidget * timeSeriesList;


         //File Name
          QString resultsFileName;
          //Strings
          QStringList categories;
          QString trueStyle;
          QString falseStyle;


    //Charts-Accuracy
    QChart * accuracyChart;
    QChartView * accuracyView;
    QBarSeries *seriesAccuracy;
    QBarSet *setAccuracyFeature;
    QBarSet *setAccuracyTime;
    QBarCategoryAxis * accuracyAxis;
    //Charts-Memory
        QChart * memoryChart;
        QChartView * memoryView;
        QBarSeries *seriesMemory;
        QBarSet *setMemoryFeature;
        QBarSet *setMemoryTime;
        QBarCategoryAxis * memoryAxis;

        //Charts-Train
            QChart * trainChart;
            QChartView * trainView;
            QBarSeries *seriesTrain;
            QBarSet *setTrainFeature;
            QBarSet *setTrainTime;
            QBarCategoryAxis * trainAxis;

            //Charts-Test
                QChart * testChart;
                QChartView * testView;
                QBarSeries *seriesTest;
                QBarSet *setTestFeature;
                QBarSet *setTestTime;
                QBarCategoryAxis * testAxis;

private Q_SLOTS:
    void selectFile();
    void plotFile();

};



class TimeSeriesTab : public QWidget
{
    Q_OBJECT


    //Layouts
    QHBoxLayout * windowLayout;
    QVBoxLayout * graphLayout;
    QVBoxLayout * optionsLayout;

        //Containers
        QComboBox * fromOptions;
        QScrollArea * graphScrollArea;
        QScrollBar * graphScrollBar;


public:
    explicit TimeSeriesTab( QWidget *parent = 0);

private:

    //Buttons
    QPushButton * selectFileButton;
    QPushButton * plotButton;

    //Chart Time Series
    QChartView * timeSeriesChartView;
    QChart * timeSeriesChart;
    QBarSeries * timeSeries;
    QBarSet * seriesSet;
    QBarCategoryAxis * seriesAxis;
    QStringList categories;

    //Data Structures
    QMultiHash<QString,QPair<QString,double>> timeSeriesHash;
    QMap<QString, int> distanceFromListSort;

    //File Name
     QString timeSeriesFileName;

     //Typedef
     typedef QMultiHash<QString,QPair<QString,double>> HashDataType;
     typedef QMap<QString,int> MapDataType;

private Q_SLOTS:
    void selectFile();
    void plotFile();

protected :

virtual void resizeEvent(QResizeEvent *event){


        qDebug()<<"Event resized";
        qDebug()<<event->type();

    }


};


class InputTab: public QWidget
{
    Q_OBJECT

    //Layouts
    QHBoxLayout * windowLayout;
   // QVBoxLayout * graphLayout;
    QVBoxLayout * optionsLayout;
    QVBoxLayout * jointLayout;
    QVBoxLayout * plotLayout;

    //Containers
    QGroupBox * jointBox;
    QGroupBox * plotBox;


public:
    explicit InputTab(QWidget *parent = 0);

    void clearListWidgets();
    void clearMaps();
    void readFileData();
    void populateVariantList();
    void createGraph();
    int getVariateCount(QString inputVariate);
    void showGraphSeries();
    void hideAllSeries();
    void clearSeriesGraph();

private:

    //List Widgets
    QListWidget * jointList;
    QListWidget * plotList;

    //Buttons
    QPushButton * selectFileButton;

    //Data Structures
    QMultiMap<QString,QVector3D> gaitMap;
    QMap<QString,QScatterDataArray*> seriesMap;
    QMap<QString,QScatter3DSeries*> seriesTable;

    //File Name
    QString skeletonFileName;

    //TypeDef
    typedef QMultiMap<QString,QVector3D> GaitMapType;
    typedef QMap<QString,QScatterDataArray*> SeriesMapType;
    typedef QMap<QString,QScatter3DSeries*>  SeriesTableType;

    //Graph
    Q3DScatter * graph;



protected:

    //void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event) ;
    void dragLeaveEvent(QDragLeaveEvent *event) ;
    void dragMoveEvent(QDragMoveEvent *event) ;
    void dropEvent(QDropEvent *event) ;

    bool eventFilter(QObject *obj, QEvent *event);


private Q_SLOTS:
    void selectFile();




};

class FrequentPatternTab : public QWidget
{
    Q_OBJECT

public:
    explicit FrequentPatternTab( QWidget *parent = 0);
};



class FeatureBasedTab : public QWidget
{
    Q_OBJECT

public:
    explicit FeatureBasedTab( QWidget *parent = 0);
};



class TabDialog : public QDialog
{
    Q_OBJECT
    //Layouts
    QVBoxLayout *tabLayout;

public:
    explicit TabDialog(QWidget *parent = 0);

private:

    //Widgets
    QTabWidget *tabWidget;


};

#endif
