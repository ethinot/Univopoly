/****************************************************************************
** Meta object code from reading C++ file 'mainView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/qt/extensions/mainView.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainView_t {
    const uint offsetsAndSize[16];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_mainView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_mainView_t qt_meta_stringdata_mainView = {
    {
QT_MOC_LITERAL(0, 8), // "mainView"
QT_MOC_LITERAL(9, 11), // "renderBoard"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 19), // "std::vector<Player>"
QT_MOC_LITERAL(42, 7), // "players"
QT_MOC_LITERAL(50, 7), // "buyMenu"
QT_MOC_LITERAL(58, 10), // "buyMenuOff"
QT_MOC_LITERAL(69, 7) // "buyTrue"

    },
    "mainView\0renderBoard\0\0std::vector<Player>\0"
    "players\0buyMenu\0buyMenuOff\0buyTrue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    1,   41,    2, 0x06,    3 /* Public */,
       6,    0,   44,    2, 0x06,    5 /* Public */,
       7,    1,   45,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void mainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->renderBoard((*reinterpret_cast< std::vector<Player>(*)>(_a[1]))); break;
        case 1: _t->buyMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->buyMenuOff(); break;
        case 3: _t->buyTrue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mainView::*)(std::vector<Player> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainView::renderBoard)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mainView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainView::buyMenu)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mainView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainView::buyMenuOff)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mainView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainView::buyTrue)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject mainView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_mainView.offsetsAndSize,
    qt_meta_data_mainView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_mainView_t
, QtPrivate::TypeAndForceComplete<mainView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<Player>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>



>,
    nullptr
} };


const QMetaObject *mainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void mainView::renderBoard(std::vector<Player> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mainView::buyMenu(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mainView::buyMenuOff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void mainView::buyTrue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
