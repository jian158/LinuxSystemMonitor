/****************************************************************************
** Meta object code from reading C++ file 'listview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../listview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProcessListView_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessListView_t qt_meta_stringdata_ProcessListView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProcessListView"
QT_MOC_LITERAL(1, 16, 11), // "onItemClick"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "index"
QT_MOC_LITERAL(4, 35, 16), // "onEndActionClick"
QT_MOC_LITERAL(5, 52, 13), // "onContextMenu"
QT_MOC_LITERAL(6, 66, 1), // "p"
QT_MOC_LITERAL(7, 68, 16) // "onscrollListener"

    },
    "ProcessListView\0onItemClick\0\0index\0"
    "onEndActionClick\0onContextMenu\0p\0"
    "onscrollListener"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,

       0        // eod
};

void ProcessListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessListView *_t = static_cast<ProcessListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onItemClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onEndActionClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->onscrollListener(); break;
        default: ;
        }
    }
}

const QMetaObject ProcessListView::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ProcessListView.data,
      qt_meta_data_ProcessListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProcessListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessListView.stringdata0))
        return static_cast<void*>(const_cast< ProcessListView*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ProcessListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
