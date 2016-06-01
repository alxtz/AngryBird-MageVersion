/****************************************************************************
** Meta object code from reading C++ file 'Singleshot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameScene/Singleshot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Singleshot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Singleshot_t {
    QByteArrayData data[8];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Singleshot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Singleshot_t qt_meta_stringdata_Singleshot = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Singleshot"
QT_MOC_LITERAL(1, 11, 10), // "setNewBird"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "pull"
QT_MOC_LITERAL(4, 28, 1), // "x"
QT_MOC_LITERAL(5, 30, 1), // "y"
QT_MOC_LITERAL(6, 32, 7), // "release"
QT_MOC_LITERAL(7, 40, 7) // "shorten"

    },
    "Singleshot\0setNewBird\0\0pull\0x\0y\0release\0"
    "shorten"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Singleshot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x0a /* Public */,
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Singleshot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Singleshot *_t = static_cast<Singleshot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setNewBird(); break;
        case 1: _t->pull((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->release(); break;
        case 3: _t->shorten(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Singleshot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Singleshot::setNewBird)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Singleshot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Singleshot.data,
      qt_meta_data_Singleshot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Singleshot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Singleshot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Singleshot.stringdata0))
        return static_cast<void*>(const_cast< Singleshot*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Singleshot*>(this));
    return QObject::qt_metacast(_clname);
}

int Singleshot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Singleshot::setNewBird()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
