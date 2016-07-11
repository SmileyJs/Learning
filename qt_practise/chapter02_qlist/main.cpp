#include <QList>
#include <QDebug>

int main()
{
/// Qlist
//    QList<QString> list;
//    {
//        QString str = "This is a test string!";
//        list << str;
//    }

//    qDebug() << list[0] << "How are you!";

/******************java*******************/
/// QListIterator
//    QList<int> list;
//    list << 1 << 2 << 3 << 4 << 5;

//    QListIterator<int> i(list);

//    while (i.hasNext()) {
//        qDebug() << i.next();
//    }

/// QMutableListIterator
//    QList<int> list;
//    QMutableListIterator<int> i(list);

//    for (int j = 0; j < 10; ++j) {
//        i.insert(j);
//    }

//    i.toFront();
//    while (i.hasNext()) {
//        qDebug() << i.next();
//    }

//    while (i.hasPrevious()) {
//        if (i.previous()%2 == 0) {
//            i.remove();
//        }
//        else {
//            i.peekNext() *= 10;
//        }
//    }

//    i.toFront();
//    while (i.hasNext()) {
//        qDebug() << i.next();
//    }

/*******************STL*********************/
    QList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.insert(list.end(), i);
    }

    QList<int>::iterator i;
    for (i = list.begin(); i != list.end(); ++i) {
        qDebug() << *i;
        *i *= 10;
    }

    QList<int>::const_iterator ci;
    for (ci = list.constBegin(); ci != list.constEnd(); ++ci) {
        qDebug() << *ci;
    }

    return 0;
}
