/****************************************************************************
** Meta object code from reading C++ file 'mytask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/mytask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTask_t {
    QByteArrayData data[5];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTask_t qt_meta_stringdata_MyTask = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyTask"
QT_MOC_LITERAL(1, 7, 8), // "loggedIn"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "MyClient*"
QT_MOC_LITERAL(4, 27, 12) // "keyGenerated"

    },
    "MyTask\0loggedIn\0\0MyClient*\0keyGenerated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       4,    3,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,

       0        // eod
};

void MyTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTask *_t = static_cast<MyTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggedIn((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< MyClient*(*)>(_a[2]))); break;
        case 1: _t->keyGenerated((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< MyClient*(*)>(_a[2])),(*reinterpret_cast< MyClient*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyClient* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyClient* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTask::*_t)(QByteArray , MyClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTask::loggedIn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyTask::*_t)(QByteArray , MyClient * , MyClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTask::keyGenerated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MyTask::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyTask.data,
      qt_meta_data_MyTask,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTask::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTask.stringdata0))
        return static_cast<void*>(const_cast< MyTask*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< MyTask*>(this));
    return QObject::qt_metacast(_clname);
}

int MyTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyTask::loggedIn(QByteArray _t1, MyClient * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTask::keyGenerated(QByteArray _t1, MyClient * _t2, MyClient * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE