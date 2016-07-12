#include <QList>
#include <QDebug>
#include <QColor>

int main()
{
#if 0
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
//    QList<int> list;
//    for (int i = 0; i < 10; ++i) {
//        list.insert(list.end(), i);
//    }

//    QList<int>::iterator i;
//    for (i = list.begin(); i != list.end(); ++i) {
//        qDebug() << *i;
//        *i *= 10;
//    }

//    QList<int>::const_iterator ci;
//    for (ci = list.constBegin(); ci != list.constEnd(); ++ci) {
//        qDebug() << *ci;
//    }


/******************QHash&QMap********************/
    QMap<QString, QString> map;

    map.insert("beijing", "011");
    map.insert("shanghai", "020");
    map.insert("jincheng", "0356");

/******************java*********************/
//    QMapIterator<QString, QString> i(map);

//    for (i.toFront();i.hasNext();) {
//        qDebug() << i.key() << "   " << i.next().value();
//    }

//    QMutableMapIterator<QString, QString> bi(map);

//    if (bi.findNext("011")) {
//        bi.setValue("010");
//    }

//    for (bi.toFront();bi.hasNext();) {
//        qDebug() << bi.key() << "   " << bi.next().value();
//    }

/******************STL*********************/
    QMap<QString, QString>::const_iterator i;

    for (i = map.constBegin(); i != map.constEnd(); ++i) {
        qDebug() << i.key() << "   " << i.value();
    }

    QMap<QString, QString>::iterator ci;

    ci = map.find("beijing");
    if (ci != map.end()) ci.value() = "010";

    for (ci = map.begin(); ci != map.end(); ++ci) {
        qDebug() << ci.key() << "   " << ci.value();
    }
#endif

/*****************QVariant********************/
    QVariant i(111);
    qDebug() << i.toInt();

    QVariant s("How are you!");
    qDebug() << s.toString();

    QMap<QString, QVariant> map;
    map["int"] = 111;
    map["string"] = "How are you!";
    map["double"] = 111.111;
    map["color"] = QColor(255, 0, 0);

    qDebug() << map["int"] << map["int"].toInt();
    qDebug() << map["string"] << map["string"].toString();
    qDebug() << map["double"] << map["double"].toDouble();
    qDebug() << map["color"] << map["color"].value<QColor>();

    QStringList sl;
    sl << "A" << "B" << "C" << "D";

    QVariant slv(sl);

    if (QVariant::StringList == slv.type()) {
        QStringList list = slv.toStringList();
        for (int i = 0; i < list.size(); ++i) {
            qDebug() << list.at(i);
        }
    }

    return 0;
}
