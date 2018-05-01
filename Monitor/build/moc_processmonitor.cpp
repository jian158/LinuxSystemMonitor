/****************************************************************************
** Meta object code from reading C++ file 'processmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processmonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProcessMonitor_t {
    QByteArrayData data[10];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessMonitor_t qt_meta_stringdata_ProcessMonitor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProcessMonitor"
QT_MOC_LITERAL(1, 15, 11), // "onItemClick"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 16), // "onEndActionClick"
QT_MOC_LITERAL(5, 51, 13), // "onContextMenu"
QT_MOC_LITERAL(6, 65, 1), // "p"
QT_MOC_LITERAL(7, 67, 6), // "update"
QT_MOC_LITERAL(8, 74, 13), // "onColumnClick"
QT_MOC_LITERAL(9, 88, 3) // "col"

    },
    "ProcessMonitor\0onItemClick\0\0index\0"
    "onEndActionClick\0onContextMenu\0p\0"
    "update\0onColumnClick\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       7,    0,   48,    2, 0x0a /* Public */,
       8,    1,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void ProcessMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessMonitor *_t = static_cast<ProcessMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onItemClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onEndActionClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->update(); break;
        case 4: _t->onColumnClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ProcessMonitor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProcessMonitor.data,
      qt_meta_data_ProcessMonitor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProcessMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessMonitor.stringdata0))
        return static_cast<void*>(const_cast< ProcessMonitor*>(this));
    return QWidget::qt_metacast(_clname);
}

int ProcessMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
