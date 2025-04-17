#ifndef DATAUIMANAGER_H
#define DATAUIMANAGER_H

#include "DataHandler.h"
#include "IDataUiHandler.h"

class DataUiManager : public QObject {
    Q_OBJECT
public:
    DataUiManager(DataHandler dataHandler = {}, IDataUiHandler* dataUiHandler = nullptr)
        : m_dataHandler(dataHandler), m_dataUiHandler(dataUiHandler)
    {}
    ~DataUiManager() override = default;

    void setDataHandler(const DataHandler handler) {m_dataHandler = handler;}
    void setDataUiHandler(IDataUiHandler* handler);

    const DataHandler& getDataHandler() const {return m_dataHandler;}

public slots:
    void filePathChanged(const QString filePath);
    void handleFileOpenError(const QString& errorMessage);
    void handleFileFormatError(const QString& errorMessage);

signals:
    void sendErrorToQml(const QString& errorMessage);

private:
    DataHandler m_dataHandler;
    IDataUiHandler* m_dataUiHandler = nullptr;
};

#endif // DATAUIMANAGER_H
