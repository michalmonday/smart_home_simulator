/****************************************************************************
** Meta object code from reading C++ file 'environment_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../environment_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'environment_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnvironmentWindow_t {
    QByteArrayData data[13];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnvironmentWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnvironmentWindow_t qt_meta_stringdata_EnvironmentWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "EnvironmentWindow"
QT_MOC_LITERAL(1, 18, 27), // "on_dateTimeEdit_dateChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "date"
QT_MOC_LITERAL(4, 52, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(5, 85, 5), // "value"
QT_MOC_LITERAL(6, 91, 7), // "OnTimer"
QT_MOC_LITERAL(7, 99, 43), // "on_comboBox_weather_type_curr..."
QT_MOC_LITERAL(8, 143, 4), // "arg1"
QT_MOC_LITERAL(9, 148, 34), // "on_comboBox_weather_type_acti..."
QT_MOC_LITERAL(10, 183, 35), // "on_spinBox_temperature_valueC..."
QT_MOC_LITERAL(11, 219, 31), // "on_checkBox_freeze_time_toggled"
QT_MOC_LITERAL(12, 251, 7) // "checked"

    },
    "EnvironmentWindow\0on_dateTimeEdit_dateChanged\0"
    "\0date\0on_horizontalSlider_valueChanged\0"
    "value\0OnTimer\0on_comboBox_weather_type_currentTextChanged\0"
    "arg1\0on_comboBox_weather_type_activated\0"
    "on_spinBox_temperature_valueChanged\0"
    "on_checkBox_freeze_time_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnvironmentWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   12,

       0        // eod
};

void EnvironmentWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EnvironmentWindow *_t = static_cast<EnvironmentWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dateTimeEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnTimer(); break;
        case 3: _t->on_comboBox_weather_type_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_weather_type_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_temperature_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_freeze_time_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EnvironmentWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EnvironmentWindow.data,
      qt_meta_data_EnvironmentWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnvironmentWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironmentWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EnvironmentWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
