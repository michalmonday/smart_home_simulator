/****************************************************************************
** Meta object code from reading C++ file 'controller_screen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../controller_screen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller_screen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControllerScreen_t {
    QByteArrayData data[8];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllerScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllerScreen_t qt_meta_stringdata_ControllerScreen = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ControllerScreen"
QT_MOC_LITERAL(1, 17, 6), // "reject"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 44), // "on_pushButton_setSelectedLigh..."
QT_MOC_LITERAL(4, 70, 42), // "on_pushButton_toggleSelectedL..."
QT_MOC_LITERAL(5, 113, 53), // "on_horizontalSlider_selectedL..."
QT_MOC_LITERAL(6, 167, 8), // "position"
QT_MOC_LITERAL(7, 176, 48) // "on_pushButton_toggleSelectedP..."

    },
    "ControllerScreen\0reject\0\0"
    "on_pushButton_setSelectedLightsColor_clicked\0"
    "on_pushButton_toggleSelectedLights_clicked\0"
    "on_horizontalSlider_selectedLightsOpacity_sliderMoved\0"
    "position\0on_pushButton_toggleSelectedPowerSockets_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllerScreen[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void ControllerScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControllerScreen *_t = static_cast<ControllerScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reject(); break;
        case 1: _t->on_pushButton_setSelectedLightsColor_clicked(); break;
        case 2: _t->on_pushButton_toggleSelectedLights_clicked(); break;
        case 3: _t->on_horizontalSlider_selectedLightsOpacity_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_toggleSelectedPowerSockets_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ControllerScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControllerScreen.data,
      qt_meta_data_ControllerScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ControllerScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControllerScreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ControllerScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
