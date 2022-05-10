/****************************************************************************
** Meta object code from reading C++ file 'Board_qt.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/qt/extensions/components/mainView/Board_qt.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Board_qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Board_qt_t {
    const uint offsetsAndSize[22];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Board_qt_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Board_qt_t qt_meta_stringdata_Board_qt = {
    {
QT_MOC_LITERAL(0, 8), // "Board_qt"
QT_MOC_LITERAL(9, 6), // "render"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 19), // "std::vector<Player>"
QT_MOC_LITERAL(37, 3), // "buy"
QT_MOC_LITERAL(41, 6), // "buyOff"
QT_MOC_LITERAL(48, 7), // "buyTrue"
QT_MOC_LITERAL(56, 8), // "buyFalse"
QT_MOC_LITERAL(65, 9), // "rendering"
QT_MOC_LITERAL(75, 6), // "buying"
QT_MOC_LITERAL(82, 9) // "buyingOff"

    },
    "Board_qt\0render\0\0std::vector<Player>\0"
    "buy\0buyOff\0buyTrue\0buyFalse\0rendering\0"
    "buying\0buyingOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board_qt[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       5,    0,   68,    2, 0x06,    5 /* Public */,
       6,    0,   69,    2, 0x06,    6 /* Public */,
       7,    0,   70,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   71,    2, 0x08,    8 /* Private */,
       9,    1,   74,    2, 0x08,   10 /* Private */,
      10,    0,   77,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Board_qt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Board_qt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->render((*reinterpret_cast< std::vector<Player>(*)>(_a[1]))); break;
        case 1: _t->buy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->buyOff(); break;
        case 3: _t->buyTrue(); break;
        case 4: _t->buyFalse(); break;
        case 5: _t->rendering((*reinterpret_cast< std::vector<Player>(*)>(_a[1]))); break;
        case 6: _t->buying((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->buyingOff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Board_qt::*)(std::vector<Player> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board_qt::render)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Board_qt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board_qt::buy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Board_qt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board_qt::buyOff)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Board_qt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board_qt::buyTrue)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Board_qt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board_qt::buyFalse)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Board_qt::staticMetaObject = { {
    QMetaObject::SuperData::link<QGridLayout::staticMetaObject>(),
    qt_meta_stringdata_Board_qt.offsetsAndSize,
    qt_meta_data_Board_qt,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Board_qt_t
, QtPrivate::TypeAndForceComplete<Board_qt, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<Player>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<Player>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Board_qt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board_qt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Board_qt.stringdata0))
        return static_cast<void*>(this);
    return QGridLayout::qt_metacast(_clname);
}

int Board_qt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Board_qt::render(std::vector<Player> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board_qt::buy(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board_qt::buyOff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Board_qt::buyTrue()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Board_qt::buyFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
