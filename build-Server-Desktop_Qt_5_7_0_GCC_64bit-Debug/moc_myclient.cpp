/****************************************************************************
** Meta object code from reading C++ file 'myclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/myclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyClient_t {
    QByteArrayData data[10];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClient_t qt_meta_stringdata_MyClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyClient"
QT_MOC_LITERAL(1, 9, 6), // "msgRcv"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "MyClient*"
QT_MOC_LITERAL(4, 27, 15), // "cliDisconeccted"
QT_MOC_LITERAL(5, 43, 10), // "logMessage"
QT_MOC_LITERAL(6, 54, 9), // "connected"
QT_MOC_LITERAL(7, 64, 12), // "disconnected"
QT_MOC_LITERAL(8, 77, 9), // "readyRead"
QT_MOC_LITERAL(9, 87, 5) // "ready"

    },
    "MyClient\0msgRcv\0\0MyClient*\0cliDisconeccted\0"
    "logMessage\0connected\0disconnected\0"
    "readyRead\0ready"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       4,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyClient *_t = static_cast<MyClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgRcv((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< MyClient*(*)>(_a[2]))); break;
        case 1: _t->cliDisconeccted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->logMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->readyRead(); break;
        case 6: _t->ready(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyClient::*_t)(QByteArray , MyClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::msgRcv)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::cliDisconeccted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::logMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MyClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyClient.data,
      qt_meta_data_MyClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyClient.stringdata0))
        return static_cast<void*>(const_cast< MyClient*>(this));
    return QObject::qt_metacast(_clname);
}

int MyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyClient::msgRcv(QByteArray _t1, MyClient * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyClient::cliDisconeccted(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyClient::logMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
