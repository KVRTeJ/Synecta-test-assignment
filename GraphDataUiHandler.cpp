#include "GraphDataUiHandler.h"

#include <algorithm>

QVariantList GraphDataUiHandler::getPoints() const {
    QVariantList list;

    int size = qMin(m_xAxis.size(), m_yAxis.size());
    for(int i = 0; i < size; ++i) {
        list.append(QPointF(m_xAxis[i], m_yAxis[i]));
    }

    return list;
}

void GraphDataUiHandler::setData(const QVector<double>& x, const QVector<double>& y) {
    m_xAxis = x;
    m_yAxis = y;

    calculateBounds();

    emit pointsChanged();

    emit minXChanged();
    emit maxXChanged();

    emit minYChanged();
    emit maxYChanged();
}

void GraphDataUiHandler::calculateBounds() {
    if (m_xAxis.isEmpty())
        m_minX = m_maxX = 0;
    else {
        auto [min, max] = std::minmax_element(m_xAxis.begin(), m_xAxis.end());
        m_minX = *min;
        m_maxX = *max;
    }

    if (m_yAxis.isEmpty())
        m_minY = m_maxY = 0;
    else {
        auto [min, max] = std::minmax_element(m_yAxis.begin(), m_yAxis.end());
        m_minY = *min;
        m_maxY = *max;
    }
}
