/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_pushButton_clear_all_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 21), // "on_actionGrid_toggled"
QT_MOC_LITERAL(4, 66, 4), // "arg1"
QT_MOC_LITERAL(5, 71, 29), // "on_SmartDeviceButtons_clicked"
QT_MOC_LITERAL(6, 101, 16), // "QAbstractButton*"
QT_MOC_LITERAL(7, 118, 10), // "button_ptr"
QT_MOC_LITERAL(8, 129, 23), // "on_ShapeButtons_clicked"
QT_MOC_LITERAL(9, 153, 6), // "button"
QT_MOC_LITERAL(10, 160, 50), // "on_actionCreate_doors_from_se..."
QT_MOC_LITERAL(11, 211, 25), // "on_actionDesign_triggered"
QT_MOC_LITERAL(12, 237, 29), // "on_radioButton_Design_toggled"
QT_MOC_LITERAL(13, 267, 7), // "checked"
QT_MOC_LITERAL(14, 275, 46), // "on_actionSet_color_of_selecte..."
QT_MOC_LITERAL(15, 322, 30) // "on_actionEnvironment_triggered"

    },
    "MainWindow\0on_pushButton_clear_all_clicked\0"
    "\0on_actionGrid_toggled\0arg1\0"
    "on_SmartDeviceButtons_clicked\0"
    "QAbstractButton*\0button_ptr\0"
    "on_ShapeButtons_clicked\0button\0"
    "on_actionCreate_doors_from_selected_rect_triggered\0"
    "on_actionDesign_triggered\0"
    "on_radioButton_Design_toggled\0checked\0"
    "on_actionSet_color_of_selected_rooms_triggered\0"
    "on_actionEnvironment_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,
      14,    0,   74,    2, 0x08 /* Private */,
      15,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clear_all_clicked(); break;
        case 1: _t->on_actionGrid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_SmartDeviceButtons_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->on_ShapeButtons_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 4: _t->on_actionCreate_doors_from_selected_rect_triggered(); break;
        case 5: _t->on_actionDesign_triggered(); break;
        case 6: _t->on_radioButton_Design_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_actionSet_color_of_selected_rooms_triggered(); break;
        case 8: _t->on_actionEnvironment_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
