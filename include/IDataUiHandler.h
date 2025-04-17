#ifndef IDATAUIHANDLER_H
#define IDATAUIHANDLER_H

#include <QObject>

#include <QtCharts/QLineSeries>

class IDataUiHandler  : public QObject{
public:
    virtual ~IDataUiHandler() = default;

    Q_INVOKABLE virtual void updateSeries(QtCharts::QLineSeries* series, const QVector<double>& xAxis, const QVector<double>& yAxis) = 0;
    Q_INVOKABLE virtual void setData(const QVector<double>& xAxis, const QVector<double>& yAxis) = 0;
    Q_INVOKABLE virtual void setSeries(QtCharts::QLineSeries* series) = 0;
};

#endif // IDATAUIHANDLER_H
