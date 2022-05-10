/****************************************************************************
** Meta object code from reading C++ file 'sideBar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/qt/extensions/sideBar.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sideBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sideBar_t {
    const uint offsetsAndSize[14];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_sideBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_sideBar_t qt_meta_stringdata_sideBar = {
    {
QT_MOC_LITERAL(0, 7), // "sideBar"
QT_MOC_LITERAL(8, 9), // "rollDices"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 8), // "passTurn"
QT_MOC_LITERAL(28, 13), // "renderPlayers"
QT_MOC_LITERAL(42, 19), // "std::vector<Player>"
QT_MOC_LITERAL(62, 7) // "players"

    },
    "sideBar\0rollDices\0\0passTurn\0renderPlayers\0"
    "std::vector<Player>\0players"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sideBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    0,   33,    2, 0x06,    2 /* Public */,
       4,    1,   34,    2, 0x06,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void sideBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sideBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rollDices(); break;
        case 1: _t->passTurn(); break;
        case 2: _t->renderPlayers((*reinterpret_cast< std::vector<Player>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (sideBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sideBar::rollDices)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (sideBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sideBar::passTurn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (sideBar::*)(std::vector<Player> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sideBar::renderPlayers)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject sideBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_sideBar.offsetsAndSize,
    qt_meta_data_sideBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_sideBar_t
, QtPrivate::TypeAndForceComplete<sideBar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<Player>, std::false_type>



>,
    nullptr
} };


const QMetaObject *sideBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sideBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sideBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int sideBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void sideBar::rollDices()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sideBar::passTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void sideBar::renderPlayers(std::vector<Player> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
