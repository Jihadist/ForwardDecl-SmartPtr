#pragma once

#include <QObject>
#include <memory>
namespace QtHelper {
struct deleteLaterDeletor {
  void operator()(QObject *object) const {
    if (object) {
      object->deleteLater();
    }
  }
};
} // namespace QtHelper

template <typename T>
using UniquePointer = std::unique_ptr<T, QtHelper::deleteLaterDeletor>;
class ClassA;

class ClassB : public QObject {
public:
  ClassB(QObject *parent = nullptr);

private:
  UniquePointer<ClassA> internal;
};
