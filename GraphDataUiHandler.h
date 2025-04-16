#ifndef GRAPHDATAUIHANDLER_H
#define GRAPHDATAUIHANDLER_H

#include <QObject>
#include <QVector>
#include <QVariantList>
#include <QPointF>

class GraphDataUiHandler : public QObject {
    Q_OBJECT

    Q_PROPERTY(QVariantList points READ getPoints NOTIFY pointsChanged)

    Q_PROPERTY(double minX READ getMinX NOTIFY minXChanged)
    Q_PROPERTY(double maxX READ getMaxX NOTIFY maxXChanged)

    Q_PROPERTY(double minY READ getMinY NOTIFY minYChanged)
    Q_PROPERTY(double maxY READ getMaxY NOTIFY maxYChanged)

public:
    explicit GraphDataUiHandler(QObject *parent = nullptr) : QObject(parent)
    {}

    QVariantList getPoints() const;

    double getMinX() const {return m_minX;}
    double getMaxX() const {return m_maxX;}

    double getMinY() const {return m_minY;}
    double getMaxY() const {return m_maxY;}

    Q_INVOKABLE void setData(const QVector<double>& x, const QVector<double>& y);

signals:
    void pointsChanged();

    void minXChanged();
    void maxXChanged();

    void minYChanged();
    void maxYChanged();

private:
    QVector<double> m_xAxis;
    QVector<double> m_yAxis;

    double m_minX;
    double m_maxX;

    double m_minY;
    double m_maxY;

    void calculateBounds();
};

#endif // GRAPHDATAUIHANDLER_H
