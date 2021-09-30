#pragma once
#include <QObject>

class ClassA : public QObject {
public:
  ClassA(QObject *parent = nullptr);
};
