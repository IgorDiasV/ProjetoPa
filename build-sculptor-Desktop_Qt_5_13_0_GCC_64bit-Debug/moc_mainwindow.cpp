/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sculptor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "mudarRaioEsfera"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "r"
QT_MOC_LITERAL(4, 30, 11), // "mudarDimBoX"
QT_MOC_LITERAL(5, 42, 4), // "dimx"
QT_MOC_LITERAL(6, 47, 11), // "mudarDimBoY"
QT_MOC_LITERAL(7, 59, 4), // "dimy"
QT_MOC_LITERAL(8, 64, 11), // "mudarDimBoZ"
QT_MOC_LITERAL(9, 76, 4), // "dimz"
QT_MOC_LITERAL(10, 81, 10), // "mudarRaioX"
QT_MOC_LITERAL(11, 92, 2), // "rx"
QT_MOC_LITERAL(12, 95, 10), // "mudarRaioY"
QT_MOC_LITERAL(13, 106, 2), // "ry"
QT_MOC_LITERAL(14, 109, 10), // "mudarRaioZ"
QT_MOC_LITERAL(15, 120, 2), // "rz"
QT_MOC_LITERAL(16, 123, 11), // "novoProjeto"
QT_MOC_LITERAL(17, 135, 11), // "mudarPlanoZ"
QT_MOC_LITERAL(18, 147, 1), // "z"
QT_MOC_LITERAL(19, 149, 5) // "cores"

    },
    "MainWindow\0mudarRaioEsfera\0\0r\0mudarDimBoX\0"
    "dimx\0mudarDimBoY\0dimy\0mudarDimBoZ\0"
    "dimz\0mudarRaioX\0rx\0mudarRaioY\0ry\0"
    "mudarRaioZ\0rz\0novoProjeto\0mudarPlanoZ\0"
    "z\0cores"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    1,   67,    2, 0x0a /* Public */,
       6,    1,   70,    2, 0x0a /* Public */,
       8,    1,   73,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
      14,    1,   82,    2, 0x0a /* Public */,
      16,    0,   85,    2, 0x0a /* Public */,
      17,    1,   86,    2, 0x0a /* Public */,
      19,    0,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mudarRaioEsfera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->mudarDimBoX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mudarDimBoY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mudarDimBoZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->mudarRaioX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->mudarRaioY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->mudarRaioZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->novoProjeto(); break;
        case 8: _t->mudarPlanoZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cores(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
