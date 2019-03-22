#include "ClickableTextLabel.h"

ClickableTextLabel::ClickableTextLabel(QWidget *parent) : QLabel(parent)
  ,m_text("")
  ,m_x(10)
  ,m_y(10)
  ,m_widthFrame(0)
  ,m_rectShadow(0,0,0,0)
{

}

ClickableTextLabel::~ClickableTextLabel()
{

}

void ClickableTextLabel::setText(QString text)
{
    m_text = text;
}

//需要注意的是控件的高度可能在构造函数里的时候是不对的
//可以尝试加定时器，父控件的构造函数结束后再设置
void ClickableTextLabel::setTextPos(int x, int y)
{
    m_x = x;
    m_y = y;
}

void ClickableTextLabel::setTextFont(QFont font)
{
    m_font = font;
    setFont(m_font);
}

void ClickableTextLabel::setTextColor(QColor color)
{
    m_color = color;
    QPalette pe;
    pe.setColor(QPalette::WindowText,m_color);
    setPalette(pe);
}

void ClickableTextLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit sigClicked();
    }
}

//暂时不是自己画边框，先不用。现在还是qss设置边框
void ClickableTextLabel::setFrameWidth(int width)
{
    m_widthFrame = width;
}


void ClickableTextLabel::setTextShadowRect(int x,int y,int width,int height)
{
    m_rectShadow.setRect(x,y,width,height);
}


void ClickableTextLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event) ;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen = painter.pen();

    //设置文字上的阴影
    painter.setPen(Qt::NoPen);
    QLinearGradient linear(m_rectShadow.x(),m_rectShadow.y(),
                           m_rectShadow.x(),
                           m_rectShadow.y()+m_rectShadow.height());

    linear.setColorAt(0,QColor(0,0,0,0));
    linear.setColorAt(1,QColor(0,0,0,100));
    painter.setBrush(QBrush(linear));
    painter.drawRect(m_rectShadow.x(),m_rectShadow.y()
                     , m_rectShadow.width(), m_rectShadow.height()-2);


    if(pixmap() == NULL)
    {
        qInfo()<<"this";
    }

    painter.setPen(pen);
    painter.setFont(m_font);
    painter.drawText(QPoint(m_x,m_y),m_text);
    return ;
}



