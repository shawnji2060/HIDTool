/****************************************************************************
** Meta object code from reading C++ file 'u2x_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myusb/u2x_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'u2x_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_U2XThread_t {
    QByteArrayData data[9];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_U2XThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_U2XThread_t qt_meta_stringdata_U2XThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "U2XThread"
QT_MOC_LITERAL(1, 10, 13), // "buttonClicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "RecesiveData"
QT_MOC_LITERAL(4, 38, 5), // "char*"
QT_MOC_LITERAL(5, 44, 4), // "date"
QT_MOC_LITERAL(6, 49, 16), // "SendMessageSlots"
QT_MOC_LITERAL(7, 66, 3), // "tmp"
QT_MOC_LITERAL(8, 70, 3) // "num"

    },
    "U2XThread\0buttonClicked\0\0RecesiveData\0"
    "char*\0date\0SendMessageSlots\0tmp\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_U2XThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    7,    8,

       0        // eod
};

void U2XThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        U2XThread *_t = static_cast<U2XThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->RecesiveData((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->SendMessageSlots((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (U2XThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&U2XThread::buttonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (U2XThread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&U2XThread::RecesiveData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject U2XThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_U2XThread.data,
      qt_meta_data_U2XThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *U2XThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *U2XThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_U2XThread.stringdata0))
        return static_cast<void*>(const_cast< U2XThread*>(this));
    return QThread::qt_metacast(_clname);
}

int U2XThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void U2XThread::buttonClicked(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void U2XThread::RecesiveData(char * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
