/****************************************************************************
** Meta object code from reading C++ file 'trunfoui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "trunfoui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trunfoui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrunfoUI_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrunfoUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrunfoUI_t qt_meta_stringdata_TrunfoUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TrunfoUI"
QT_MOC_LITERAL(1, 9, 21), // "on_buttonPlay_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(4, 54, 29), // "on_buttonInstructions_clicked"
QT_MOC_LITERAL(5, 84, 7), // "partGps"
QT_MOC_LITERAL(6, 92, 11), // "titMundiais"
QT_MOC_LITERAL(7, 104, 8), // "vitorias"
QT_MOC_LITERAL(8, 113, 13), // "polePositions"
QT_MOC_LITERAL(9, 127, 9) // "gpsPodios"

    },
    "TrunfoUI\0on_buttonPlay_clicked\0\0"
    "on_quitButton_clicked\0"
    "on_buttonInstructions_clicked\0partGps\0"
    "titMundiais\0vitorias\0polePositions\0"
    "gpsPodios"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrunfoUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrunfoUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrunfoUI *_t = static_cast<TrunfoUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonPlay_clicked(); break;
        case 1: _t->on_quitButton_clicked(); break;
        case 2: _t->on_buttonInstructions_clicked(); break;
        case 3: _t->partGps(); break;
        case 4: _t->titMundiais(); break;
        case 5: _t->vitorias(); break;
        case 6: _t->polePositions(); break;
        case 7: _t->gpsPodios(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TrunfoUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TrunfoUI.data,
      qt_meta_data_TrunfoUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrunfoUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrunfoUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrunfoUI.stringdata0))
        return static_cast<void*>(const_cast< TrunfoUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TrunfoUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
