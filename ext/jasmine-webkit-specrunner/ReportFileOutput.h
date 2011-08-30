#ifndef JHW_REPORT_FILE_OUTPUT
#define JHW_REPORT_FILE_OUTPUT

#include <QObject>
#include <iostream>
#include <QStack>

class ReportFileOutput : public QObject {
  public:
    ReportFileOutput();

    void passed(const QString &specDetail);
    void failed(const QString &specDetail);
    void errorLog(const QString &msg, int lineNumber, const QString &sourceID);
    void internalLog(const QString &note, const QString &msg);
    void consoleLog(const QString &msg);
    void logSpecFilename(const QString &name);
    void logSpecResult(const QString &result);

    void reportFailure(const QString &totalTests, const QString &failedTests, const QString &duration);
    void reportSuccess(const QString &totalTests, const QString &failedTests, const QString &duration);
    void reportSuccessWithJSErrors(const QString &totalTests, const QString &failedTests, const QString &duration);

    std::ostream *outputIO;
    QStack<QString> successes;
    QStack<QString> failures;
};

#endif
