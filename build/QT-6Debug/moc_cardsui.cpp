/****************************************************************************
** Meta object code from reading C++ file 'cardsui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/cardsui.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardsui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_cardsui_t {
    uint offsetsAndSizes[10];
    char stringdata0[8];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_cardsui_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_cardsui_t qt_meta_stringdata_cardsui = {
    {
        QT_MOC_LITERAL(0, 7),  // "cardsui"
        QT_MOC_LITERAL(8, 18),  // "on_pb_next_clicked"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 18),  // "on_pb_stop_clicked"
        QT_MOC_LITERAL(47, 23)   // "on_pb_translate_clicked"
    },
    "cardsui",
    "on_pb_next_clicked",
    "",
    "on_pb_stop_clicked",
    "on_pb_translate_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_cardsui[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject cardsui::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_cardsui.offsetsAndSizes,
    qt_meta_data_cardsui,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_cardsui_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<cardsui, std::true_type>,
        // method 'on_pb_next_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_translate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void cardsui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cardsui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pb_next_clicked(); break;
        case 1: _t->on_pb_stop_clicked(); break;
        case 2: _t->on_pb_translate_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *cardsui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cardsui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cardsui.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int cardsui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
