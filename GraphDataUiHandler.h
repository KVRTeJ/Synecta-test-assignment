#ifndef GRAPHDATAUIHANDLER_H
#define GRAPHDATAUIHANDLER_H

#include <QObject>

#include <QVector>
#include <QPointF>

#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

class GraphDataUiHandler : public QObject {
    Q_OBJECT

    Q_PROPERTY(double minX READ getMinX NOTIFY minXChanged)
    Q_PROPERTY(double maxX READ getMaxX NOTIFY maxXChanged)
    Q_PROPERTY(double minY READ getMinY NOTIFY minYChanged)
    Q_PROPERTY(double maxY READ getMaxY NOTIFY maxYChanged)

public:
    explicit GraphDataUiHandler(QObject *parent = nullptr) : QObject(parent), m_series(nullptr)
    {}

    Q_INVOKABLE void updateSeries(QtCharts::QLineSeries* series, const QVector<double>& xAxis, const QVector<double>& yAxis);
    Q_INVOKABLE void setData(const QVector<double>& xAxis, const QVector<double>& yAxis);
    Q_INVOKABLE void setSeries(QtCharts::QLineSeries* series);

    double getMinX() const { return m_minX; }
    double getMaxX() const { return m_maxX; }
    double getMinY() const { return m_minY; }
    double getMaxY() const { return m_maxY; }

signals:
    void minXChanged();
    void maxXChanged();
    void minYChanged();
    void maxYChanged();

private:
    void _calculateBounds(const QVector<double>& xAxis, const QVector<double>& yAxis);

private:
    QtCharts::QLineSeries* m_series;

    double m_minX;
    double m_maxX;
    double m_minY;
    double m_maxY;
};

#endif // GRAPHDATAUIHANDLER_H
