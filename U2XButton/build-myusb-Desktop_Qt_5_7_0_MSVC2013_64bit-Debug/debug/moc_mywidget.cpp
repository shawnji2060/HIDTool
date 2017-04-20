/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myusb/mywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myWidget_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myWidget_t qt_meta_stringdata_myWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "myWidget"
QT_MOC_LITERAL(1, 9, 11), // "SendMessage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "char*"
QT_MOC_LITERAL(4, 28, 3), // "tmp"
QT_MOC_LITERAL(5, 32, 3), // "num"
QT_MOC_LITERAL(6, 36, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 60, 10), // "autoScroll"
QT_MOC_LITERAL(8, 71, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(9, 95, 12), // "NumberUpdate"
QT_MOC_LITERAL(10, 108, 4), // "date"
QT_MOC_LITERAL(11, 113, 12), // "DateShowSlot"
QT_MOC_LITERAL(12, 126, 23), // "on_pushButton_3_toggled"
QT_MOC_LITERAL(13, 150, 7) // "checked"

    },
    "myWidget\0SendMessage\0\0char*\0tmp\0num\0"
    "on_pushButton_2_clicked\0autoScroll\0"
    "on_pushButton_4_clicked\0NumberUpdate\0"
    "date\0DateShowSlot\0on_pushButton_3_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void myWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myWidget *_t = static_cast<myWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendMessage((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->autoScroll(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->NumberUpdate((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 5: _t->DateShowSlot((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (myWidget::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myWidget::SendMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject myWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myWidget.data,
      qt_meta_data_myWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myWidget.stringdata0))
        return static_cast<void*>(const_cast< myWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int myWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void myWidget::SendMessage(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
