#ifndef GRAPHDATAUIHANDLER_H
#define GRAPHDATAUIHANDLER_H

#include "IDataUiHandler.h"

class GraphDataUiHandler : public IDataUiHandler {
    Q_OBJECT

    Q_PROPERTY(double minX READ getMinX NOTIFY minXChanged)
    Q_PROPERTY(double maxX READ getMaxX NOTIFY maxXChanged)
    Q_PROPERTY(double minY READ getMinY NOTIFY minYChanged)
    Q_PROPERTY(double maxY READ getMaxY NOTIFY maxYChanged)

public:
    GraphDataUiHandler() = default;
    ~GraphDataUiHandler() override = default;

    Q_INVOKABLE void updateSeries(QtCharts::QLineSeries* series, const QVector<double>& xAxis, const QVector<double>& yAxis) override;
    Q_INVOKABLE void setData(const QVector<double>& xAxis, const QVector<double>& yAxis) override;
    Q_INVOKABLE void setSeries(QtCharts::QLineSeries* series) override;

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
    QtCharts::QLineSeries* m_series = nullptr;

    double m_minX = 0;
    double m_maxX = 0;
    double m_minY = 0;
    double m_maxY = 0;
};

#endif // GRAPHDATAUIHANDLER_H
