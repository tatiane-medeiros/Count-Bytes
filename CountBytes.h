#ifndef CONTBYTES_H
#define CONTBYTES_H
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <iostream>



int* countbytes( QString name){
    int* array = new int[256];

    for(int i = 0; i<256; ++i) array[i] = 0;

    QFile file(name);

    Q_ASSERT_X(file.open(QIODevice::ReadOnly), "ContBytes::contbytes", "file not found.");

    while (!file.atEnd()) {
         QByteArray line = file.readLine();
              for(int i = 0; i < line.size(); ++i) {
                 ++array[(unsigned char) line.at(i)];
              }
     }
    file.close();
    return array;

}


void show(int *array){
    for(int i=0; i<256; ++i){
        bool ok;
        uchar a = QByteArray::number(i).toInt(&ok,16);

        if(array[i] != 0) std::cout <<i<<' '<< a<<' '<< array[i]<< std::endl;
           //qDebug()<< i<< qPrintable(QByteArray::fromHex(QByteArray::number(i))) << "freq:"<< array[i];
    }

   std::cout <<"\n\n";

}



#endif // CONTBYTES_H

