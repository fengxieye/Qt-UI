#ifndef CLICKABLETEXTLABEL_H
#define CLICKABLETEXTLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QRect>

class ClickableTextLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableTextLabel(QWidget *parent = nullptr);
    ~ClickableTextLabel();
    void setText(QString text);
    void setTextPos(int x,int y);
    void setTextFont(QFont font);
    void setTextColor(QColor color);

    void setTextShadowRect(int x, int y, int width, int height);
    void setFrameWidth(int width);
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QString m_text;
    int m_x;
    int m_y;
    int m_widthFrame;
    QFont m_font;
    QColor m_color;
    QRect m_rectShadow;


signals:
    void sigClicked();
public slots:

};

#endif // CLICKABLELABEL_H
