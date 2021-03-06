#ifndef EDITORWINDOWWIDGET_H
#define EDITORWINDOWWIDGET_H

#include <QWidget>
#include "Logic/MarkovAlgorithm.h"

namespace Ui {
class EditorWindowWidget;
}

class EditorWindowWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit EditorWindowWidget(QWidget *parent = 0);
    ~EditorWindowWidget();

    /**
     * @brief Sets the source code for new document
     * @param source_code
     */
    void setDefaultSourceCode(QString source_code);
public slots:
    void newSourceCode(QString new_source);
    void undo();
    void redo();
    void selectAll();
    void copy();
    void paste();
    void cut();
    void deleteSelection();

    void showLineHighlight(int line_number);
    void removeLineHighlight();

signals:
    void canRun(bool);
    void sourceCodeChanged(QString);
    void markovAlgorithmChanged(MarkovAlgorithm);
    void redoAvailable(bool);
    void undoAvailable(bool);
    void copyAvailable(bool);

    void breakPointAdded(int line_number);
    void breakPointRemoved(int line_number);
private:
    Ui::EditorWindowWidget *ui;
};

#endif // EDITORWINDOWWIDGET_H
