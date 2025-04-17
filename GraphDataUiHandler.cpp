#include <algorithm>

#include "GraphDataUiHandler.h"

void GraphDataUiHandler::setSeries(QtCharts::QLineSeries* series) {
    m_series = series;
}

void GraphDataUiHandler::updateSeries(QtCharts::QLineSeries* series, const QVector<double>& xAxis, const QVector<double>& yAxis) {
    if (!series)
        return;

    series->setUseOpenGL(true);

    QVector<QPointF> points;

    points.reserve(xAxis.size());
    for (int i = 0; i < xAxis.size(); ++i) {
        points.append(QPointF(xAxis[i], yAxis[i]));
    }
    series->replace(points);

    _calculateBounds(xAxis, yAxis);

    emit minXChanged();
    emit maxXChanged();
    emit minYChanged();
    emit maxYChanged();
}

void GraphDataUiHandler::setData(const QVector<double>& xAxis, const QVector<double>& yAxis) {
    if (m_series)
        updateSeries(m_series, xAxis, yAxis);
    else {
        _calculateBounds(xAxis, yAxis);

        emit minXChanged();
        emit maxXChanged();
        emit minYChanged();
        emit maxYChanged();
    }
}

void GraphDataUiHandler::_calculateBounds(const QVector<double>& xAxis, const QVector<double>& yAxis) {
    if (xAxis.isEmpty())
        m_minX = m_maxX = 0;
    else {
        auto [minX, maxX] = std::minmax_element(xAxis.begin(), xAxis.end());

        m_minX = *minX;
        m_maxX = *maxX;
    }

    if (yAxis.isEmpty())
        m_minY = m_maxY = 0;
    else {
        auto [minY, maxY] = std::minmax_element(yAxis.begin(), yAxis.end());

        m_minY = *minY;
        m_maxY = *maxY;
    }
}
