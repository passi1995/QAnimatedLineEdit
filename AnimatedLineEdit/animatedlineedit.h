#ifndef ANIMATEDLINEEDIT_H
#define ANIMATEDLINEEDIT_H

#include <QLineEdit>

class QLabel;

class AnimatedLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit AnimatedLineEdit(QWidget *parent = nullptr);

    virtual void setPlaceholderText(const QString &);
    virtual void setFont(const QFont &);

    //we cant use the addAction function cause the actions wouldnt be centered cause of the contentMargin
    QToolButton *addActionButton(const QIcon &icon, const QString &text = QString(), ActionPosition pos = LeadingPosition);

    void setBorderRadius(int value);
    void setButtonSize(int value);
    void setAnimationSpeed(int animationSpeed);
    void setBorderColorFocus(const QColor &borderColorFocus);
    void setBorderColorNoFocus(const QColor &borderColorNoFocus);

protected:
    void resizeEvent(QResizeEvent *);
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
    void paintEvent(QPaintEvent*);

private:    
    QLabel *mPlaceholderLabel; //label which replaces the placeholder and moves to the top when focus in
    QRect mPlaceHolderRect; //position of the placeholderLabel

    QColor mBorderColorFocus = QColor("#F26026");
    QColor mBorderColorNoFocus = QColor("gray");

    int mBorderRadius = 5;
    int mButtonSize = 25;

    int mAnimationSpeed = 200;

    QPair<int, bool> placeholderTextFontSize = QPair<int, bool>(12, false); //pixelSize = false -> use to store old font size and type

    int textLeftMargin = 0;
    int textRightMargin = 0;

    QList<QToolButton*> leadingButtons;
    QList<QToolButton*> trailingButtons;

    void updateTextMargins();
};

#endif // ANIMATEDLINEEDIT_H