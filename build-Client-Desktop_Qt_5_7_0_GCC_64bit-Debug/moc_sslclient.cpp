/****************************************************************************
** Meta object code from reading C++ file 'sslclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/sslclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sslclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SslClient_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SslClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SslClient_t qt_meta_stringdata_SslClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SslClient"
QT_MOC_LITERAL(1, 10, 17), // "connectedToServer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "ServerMessage"
QT_MOC_LITERAL(4, 43, 21), // "connectionEstablished"
QT_MOC_LITERAL(5, 65, 10), // "errOccured"
QT_MOC_LITERAL(6, 76, 16), // "QList<QSslError>"
QT_MOC_LITERAL(7, 93, 5), // "error"
QT_MOC_LITERAL(8, 99, 9) // "readyRead"

    },
    "SslClient\0connectedToServer\0\0ServerMessage\0"
    "connectionEstablished\0errOccured\0"
    "QList<QSslError>\0error\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SslClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x0a /* Public */,
       5,    1,   46,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void SslClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SslClient *_t = static_cast<SslClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectedToServer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ServerMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->connectionEstablished(); break;
        case 3: _t->errOccured((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 4: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SslClient::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SslClient::connectedToServer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SslClient::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SslClient::ServerMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SslClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SslClient.data,
      qt_meta_data_SslClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SslClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SslClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SslClient.stringdata0))
        return static_cast<void*>(const_cast< SslClient*>(this));
    return QObject::qt_metacast(_clname);
}

int SslClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SslClient::connectedToServer(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SslClient::ServerMessage(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE