#ifndef MIDDLEWIDGETRIGHT_H
#define MIDDLEWIDGETRIGHT_H

#include "abstractwheelwidget.h"
#include "basewidget.h"
#include "lyricutil.h"

#include <QLabel>
#include <QMediaContent>

class LyricWidget:public AbstractWheelWidget
{
    Q_OBJECT
public:
    LyricWidget(QWidget *parent =0);
    ~LyricWidget(){}

    void setOriginState();
    void currentMediaChanged(const QString& mediaTitle,QMediaContent currentMedia);
    void onCurrentPositionChanged(qint64 positon);

    int itemHeight() const;
    int itemCount() const;
    virtual void paintItem(QPainter* painter, int index, QRect &rect);
    virtual void paintItemMask(QPainter *painter);
private:
    QMediaContent m_currentMedia;
    QLabel *m_lblTip;
    LyricUtil *m_lyricUtil;

    QColor m_lrcHightLight;
    float m_itemPrecent;

    void initLayout();
    void initData();

    void clearLrc();
private slots:
    void slot_timerWork();
};

#endif // MIDDLEWIDGETRIGHT_H
